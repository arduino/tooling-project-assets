/*
    Demonstrate use of Mbed OS FAT API for SD cards on Arduino Edge Control.
    Please, note that this example uses POSIX File and Filesyteam APIS.

    If your are looking for how to use the classic Arduino "SD" library with
    the Arduino Edge Control, check the CardInfo example.
    
    Please, look at Mbed OS documentation for details
        * https://os.mbed.com/docs/mbed-os/v6.7/apis/sdblockdevice.html
        * https://os.mbed.com/docs/mbed-os/v6.7/apis/fatfilesystem.html

    
    Ported from mbed-os-example-filesystem

    * Arduino Edge Control
    * MicroSD Memory Card
*/

#include <Arduino_EdgeControl.h>

#include <FATFileSystem.h>
#include <SDBlockDevice.h>
using namespace mbed;

SDBlockDevice bd(SD_MOSI, SD_MISO, SD_CLK, SD_CS);

// The parameter indicates the MbedOS-wide mount point
// where the root of the filesystem on the SD will be available at.
FATFileSystem fat("fat");

void setup()
{
    EdgeControl.begin();
    Power.on(PWR_3V3);

    Serial.begin(115200);
    while (!Serial)
        ;

    delay(2000);
    Serial.println("Arduino Edge Control w/ SD and FAT");

    Serial.print("Initializing SD Card:");
    int err = bd.init();
    if (err != 0) {
        Serial.print(" FAIL!");
        Serial.print("Please, check your SD Card.");
        while(true);
    }
    Serial.println(" SUCCESS!");
    Serial.print("SD size: ");
    Serial.println(bd.size());
    Serial.print("SD read size: ");
    Serial.println(bd.get_read_size());
    Serial.print("SD program size: ");
    Serial.println(bd.get_program_size());
    Serial.print("SD erase size: ");
    Serial.println(bd.get_erase_size());

    Serial.print("Mounting... ");
    err = fat.mount(&bd);
    Serial.println(err ? "Fail :(" : "OK");
    if (err) {
        Error();
        // Format and remount
        Serial.println("No filesystem found, formatting...");
        err = fat.reformat(&bd);
        if (err) {
            Error();
            while (1)
                ;
        }
    }

    Serial.println("Hello, FAT!");
    // Open the numbers file
    Serial.print("Opening \"/fat/numbers.txt\"... ");
    FILE* f = fopen("/fat/numbers.txt", "r+");
    Serial.println(!f ? "Fail :(" : "OK");
    if (!f) {
        // Create the numbers file if it doesn't exist
        Serial.print("No file found, creating a new file... ");
        f = fopen("/fat/numbers.txt", "w+");
        Serial.println(!f ? "Fail :(" : "OK");
        if (!f) {
            Error();
            while (1)
                ;
        }

        for (int i = 0; i < 10; i++) {
            Serial.println();
            Serial.print("Writing numbers (");
            Serial.print(i);
            Serial.print("/");
            Serial.print(10);
            Serial.print(")... ");
            err = fprintf(f, "    %d\n", i);
            if (err < 0) {
                Serial.println("Fail :(");
                Error();
            }
        }
        Serial.println();
        Serial.println("Writing numbers (10/10)... OK");

        Serial.print("Seeking file... ");
        err = fseek(f, 0, SEEK_SET);
        Serial.println(err < 0 ? "Fail :(" : "OK");
        if (err < 0) {
            Error();
        }
    }

    // Go through and increment the numbers
    Serial.println("Incrementing numbers:");
    for (int i = 0; i < 10; i++) {
        Serial.print("(");
        Serial.print(i);
        Serial.print("/");
        Serial.print(10);
        Serial.print("): ");

        // Get current stream position
        long pos = ftell(f);

        // Parse out the number and increment
        int32_t number;
        fscanf(f, "%d", &number);
        Serial.println(number);
        number += 1;

        // Seek to beginning of number
        fseek(f, pos, SEEK_SET);

        // Store number
        fprintf(f, "    %d\n", number);

        // Flush between write and read on same file
        fflush(f);
    }
    Serial.println("Done.");

    // Close the file which also flushes any cached writes
    Serial.print("Closing \"/fat/numbers.txt\"... ");
    err = fclose(f);
    Serial.println(err < 0 ? "Fail :(" : "OK");
    if (err < 0) {
        Error();
    }

    // Display the root directory
    Serial.print("Opening the root directory... ");
    DIR* d = opendir("/fat/");
    Serial.println(!d ? "Fail :(" : "OK");
    if (!d) {
        Error();
    }

    Serial.println("root directory:");
    while (true) {
        struct dirent* e = readdir(d);
        if (!e) {
            break;
        }

        Serial.print("    ");
        Serial.println(e->d_name);
    }

    Serial.print("Closing the root directory... ");
    err = closedir(d);
    Serial.println(err < 0 ? "Fail :(" : "OK");
    if (err < 0) {
        Error();
    }

    // Display the numbers file
    Serial.print("Opening \"/fat/numbers.txt\"... ");
    f = fopen("/fat/numbers.txt", "r");
    Serial.println(!f ? "Fail :(" : "OK");
    if (!f) {
        Error();
    }

    Serial.println("numbers:");
    while (!feof(f)) {
        int c = fgetc(f);
        Serial.print(c);
    }

    Serial.print("Closing \"/fat/numbers.txt\"... ");
    err = fclose(f);
    Serial.println(err < 0 ? "Fail :(" : "OK");
    if (err < 0) {
        Error();
    }

    // Tidy up
    Serial.print("Unmounting... ");
    err = fat.unmount();
    Serial.println(err < 0 ? "Fail :(" : "OK");
    if (err < 0) {
        Error();
    }

    Serial.println("Mbed OS filesystem example done!");
}

void loop()
{
    // put your main code here, to run repeatedly:
}

void Error()
{
    Serial.print("ERRNO: ");
    Serial.print(errno);
    Serial.print("(");
    Serial.print(strerror(errno));
    Serial.println(")");
}

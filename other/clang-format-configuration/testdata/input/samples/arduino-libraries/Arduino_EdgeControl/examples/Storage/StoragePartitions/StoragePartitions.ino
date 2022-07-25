#include <Arduino_EdgeControl.h>
#include <LittleFileSystem.h>
#include <MBRBlockDevice.h>
#include <SPIFBlockDevice.h>
#include <TDBStore.h>
#include <Ticker.h>
#include <Timer.h>

#include <chrono>
using namespace std::chrono_literals;

#include "edge_control_storage_limits.h"

using namespace mbed;

// Connect to the on-board serial flash device
// https://os.mbed.com/docs/mbed-os/v6.4/apis/spifblockdevice.html
// SPIFBlockDevice root(SPI_MOSI, SPI_MISO, SPI_SCK, SPI_SS, 40000000);
SPIFBlockDevice root(SPI_MOSI, SPI_MISO, SPI_SCK, SPI_SS, SPIF_FREQ);

constexpr int USER_DATA_PARTITION { 1 };
constexpr int TDBS_DATA_PARTITION { 2 };

// Define block devices for serial flash partitions
// https://os.mbed.com/docs/mbed-os/v6.4/apis/mbrblockdevice.html
// Partition for user filesystem (LittleFS)
MBRBlockDevice user_data(&root, USER_DATA_PARTITION);
// Partition for user keyvalu store (TDBStore)
MBRBlockDevice tdbs_data(&root, TDBS_DATA_PARTITION);

// Define the start and stop addresses of the partitions
// Start from the first user-available block...
constexpr bd_addr_t USER_DATA_PARTITION_START { USER_BLOCKS_START };
// ... reserve 4MB for user filesystem...
constexpr bd_addr_t USER_DATA_PARTITION_STOP { SPIF_SIZE / 2 };
// ... start keyvalue store space from there...
constexpr bd_addr_t TDBS_DATA_PARTITION_START { USER_DATA_PARTITION_STOP };
// ... and reserve all the ramaining space until last user-available block.
constexpr bd_addr_t TDBS_DATA_PARTITION_STOP { USER_BLOCKS_STOP };

// Filesystem for user data
// https://os.mbed.com/docs/mbed-os/v6.4/apis/littlefilesystem.html
//
// LittleFS is a fail-safe filesystem for embedded systems:
// this is the recommended filesystem for user data storage.
LittleFileSystem user_data_fs("user");

// KeyValue store for user data
// https://os.mbed.com/docs/mbed-os/v6.4/apis/kvstore.html
// ATTENTION, PLEASE!
// This is a very powerful API that can be used to create
// an EEPROM-style API using the on-board serial flash.
TDBStore tdb_store(&tdbs_data);

// Define MbesOS Tickers for recurring tasks
// https://os.mbed.com/docs/mbed-os/v6.4/apis/ticker.html
Ticker lister;
Ticker writer;
volatile bool doList { false };
volatile bool doWrite { false };

Timer t;

void setup()
{
    int err;

    Serial.begin(115200);
    while (!Serial)
        ;

    delay(1000);

    Serial.println("Starting Partitions and Storage Example.");

    EdgeControl.begin();

    Power.on(PWR_3V3);

    // Define partition for User LittleFS filesystem
    err = MBRBlockDevice::partition(&root, USER_DATA_PARTITION, 0x83, USER_DATA_PARTITION_START, USER_DATA_PARTITION_STOP);
    Serial.println("Partition " + String(USER_DATA_PARTITION) + (err == 0 ? " OK" : " KO") + " (" + String(err) + ")");

    // Define partition for User KeyValue store
    err = MBRBlockDevice::partition(&root, TDBS_DATA_PARTITION, 0x83, TDBS_DATA_PARTITION_START, TDBS_DATA_PARTITION_STOP);
    Serial.println("Partition " + String(TDBS_DATA_PARTITION) + (err == 0 ? " OK" : " KO") + " (" + String(err) + ")");

    Serial.print("Mount LittleFS filesystem on Partition " + String(USER_DATA_PARTITION) + ": ");
    err = user_data_fs.mount(&user_data);
    if (err) {
        Serial.print("No LittleFS filesystem found, formatting... ");
        err = user_data_fs.reformat(&user_data);
    }
    Serial.println("done");

    Serial.println("Init TinyDB Key Value store");
    err = tdb_store.init();
    Serial.println("TDB Init " + String(err == 0 ? "OK" : "KO") + " (" + String(err) + ")");

    // Store data every 1 second
    writer.attach([] { doWrite = true; }, 1s);

    // Display data every 5 seconds
    lister.attach([] { doList = true; }, 5s);

    // Init the RNG
    srand(t.elapsed_time().count());
}

void loop()
{
    if (doList) {
        doList = false;
        listDirs();
    }

    if (doWrite) {
        doWrite = false;
        storeData();
    }
}

void storeData()
{
    constexpr char data_key[] { "data_key" };
    uint8_t data_value { 0 };
    size_t _actual;

    int res;

    // Get stored data, if any. Increment and save on success.
    // Please, refer to https://os.mbed.com/docs/mbed-os/v6.4/apis/kvstore.html
    // for more API use examples.
    res = tdb_store.get(data_key, &data_value, sizeof(data_value), &_actual);
    if (res == MBED_SUCCESS) {
        Serial.print(data_key);
        Serial.print(": ");
        Serial.println(data_value);
        data_value++;
    }
    tdb_store.set(data_key, &data_value, sizeof(data_value), 0);

    // Store a random key with random data
    String random_key = "key_";
    random_key += String(rand(), HEX);
    auto random_data = rand();
    res = tdb_store.set(random_key.c_str(), &random_data, sizeof(random_data), 0);
    if (res == MBED_SUCCESS)
        Serial.println(random_key + ": " + String(random_data));

    // Append data to file on LittleFS filesystem
    // Any MbedOS filesystem exposes a POSIX-compliant API:
    // use the standard <cstdio> functions here.
    FILE* f = fopen("/user/numbers.csv", "a");
    if (f != nullptr) {
        String line;
        line += static_cast<uint32_t>(time(nullptr));
        line += ',';
        line += data_value;
        line += '\n';
        fputs(line.c_str(), f);
        fclose(f);
    }
}

void listDirs()
{
    DIR* dir;
    struct dirent* ent;

    Serial.println("Listing /user on LittleFS Filesystem");
    if ((dir = opendir("/user")) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            String fullname = "/user/" + String(ent->d_name);
            Serial.println(fullname);
        }
        closedir(dir);

        FILE* f = fopen("/user/numbers.csv", "r+");
        if (f != nullptr) {
            char buf[64] { 0 };
            while (std::fgets(buf, sizeof buf, f) != nullptr)
                Serial.print(buf);
            fclose(f);
        }
    }


    // Use a TDBStore iterator to retrieve all the keys 
    TDBStore::iterator_t it;
    TDBStore::info_t info;
    size_t actual_size;

    // Iterate over all the keys starting with name "key_"
    tdb_store.iterator_open(&it, "key_");
    char key[128] { 0 };
    while (tdb_store.iterator_next(it, key, sizeof(key)) != MBED_ERROR_ITEM_NOT_FOUND) {
        // Get info about the key and its contents
        tdb_store.get_info(key, &info);

        char buf[128];
        sprintf(buf, "Key: %-12s - Size: %d - ", key, info.size);
        Serial.print(buf);
        
        // Get the value using parameters from the info retrieved
        int out;
        tdb_store.get(key, &out, info.size, &actual_size);

        // Do something useful with the key-value pair...
        sprintf(buf, "Value (%d): %10d - ", actual_size, out);
        Serial.print(buf);

        
        // .. then (optionally) remove the key
        tdb_store.remove(key);
        Serial.println("Removed.");
    }
    // Close the iterator at the end of the cycle
    tdb_store.iterator_close(it);
}

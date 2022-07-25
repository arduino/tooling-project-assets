/*
    Blink LED via Dweet using an MKR connected board as network interface

    This example uses the OpenMV Arduino RPC Interface Library
    https://github.com/openmv/openmv-arduino-rpc to control an
    Arduino MKR WiFi 1010 board stacked on the MKR connector
    to send REST requests to the Dweet.io. Please, install the library
    from the repo as a zip library before compile the sketch.

    The code checks for a "led" key in the content payload of the Dweet
    response and sets the on-board LED accordingly.

    Requirements:
    * Arduino Edge Control powered via 12V power adapter or 12V lead-acid battery
    * Arduino MKR WiFi1010 stacked on connector MKR2 (the one next to the CR2032 battery holder)
    * OpenMV Arduino RPC Interface Library
    
    Steps:
    * Upload this sketch to Edge Control
    * Upload the "extras/RPC/RPC_DweetBlink_Remote" sketch to the MKR 1010
      (don't forget to configure your WiFi credentials)
    * Connect your favorite serial monitor or terminal emulator to both the boards
    * Retrieve the Serial Number (<SERIALNUMBER>) of the Edge Control by running the sketch
    * Send a Dweet to the Serial Number of the Edge Control board setting the value
      of the "led" key to "on" or "off" to blink the on-board LED. Eg.

        curl -X POST http://dweet.io/dweet/for/<SERIALNUMBER> -F led=on

    * Current status of the LED can be retrieved from Dweet at "SERIALNUMBER-status" path, eg.
        
        curl -i http://dweet.io/get/latest/dweet/for/<SERIALNUMBER>-status

    created 12 Feb 2021
    by Giampaolo Mancini  
*/

#include <Arduino_EdgeControl.h>
#include <Arduino_JSON.h>
#include <openmvrpc.h>

// Configure the RPC controller
openmv::rpc_scratch_buffer<256> scratch_buffer; // static memory buffer
openmv::rpc_hardware_serial1_uart_master rpc(115200);

constexpr uint32_t requestInterval { 20 * 1000 };
uint32_t requestNow {};

bool ledStatus { false };

String serialNumber;

void setup()
{
    Serial.begin(115200);
    const uint32_t startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;

    EdgeControl.begin();

    Power.on(PWR_3V3);

    // Enable the 5V power rail
    Power.on(PWR_VBAT);

    // Power on the MKR on connector 2
    Power.on(PWR_MKR2);
    // Wait for MKR2 to power-on
    delay(5000); 

    serialNumber = EdgeControl.serialNumber();
    Serial.print("Serial Number: ");
    Serial.println(serialNumber);

    // Init the I2C bus
    Wire.begin();
    delay(500);

    // Init the I/O Expander
    Serial.print("I/O Expander initializazion ");
    if (!Expander.begin()) {
        Serial.println("failed.");
        Serial.println("Please, be sure to enable gated 3V3 and 5V power rails");
        Serial.println("via Power.on(PWR_3V3) and Power.on(PWR_VBAT).");
    }
    Serial.println("succeeded.");

    // Configure the LED1 pin
    Expander.pinMode(EXP_LED1, OUTPUT);
    // LED1 is active low
    Expander.digitalWrite(EXP_LED1, HIGH);

    // Start the RPC controller
    rpc.begin();

    requestNow = millis();
}

void loop()
{
    if (millis() > requestNow) {

        // Post the status of the LED to Dweet using
        // the serial number as device ID
        rpcPostDweetFor(serialNumber);

        delay(1000);

        // Get the next status of the LED
        rpcGetLatestDweetFor(serialNumber);

        requestNow = millis() + requestInterval;
    }

    Expander.digitalWrite(EXP_LED1, ledStatus);
}

void rpcPostDweetFor(String deviceID)
{
    Serial.print("Posting Status Dweet For ");
    Serial.print(deviceID);
    Serial.print(" via RPC: ");

    // Pass data to remote RPC client in JSON format. YMMV.
    JSONVar data;
    data["deviceID"] = deviceID;
    // Pin LED is active low
    data["ledStatus"] = !ledStatus;

    auto dataString = JSON.stringify(data);
    Serial.println(dataString);

    // Call the "postDweetFor" callback on the MKR WiFi 1010
    // Remember to set large RPC timeouts: the Network is SLOW!
    //
    // Please, refer to openmv-rpc-arduino documentation for more
    // call() examples.
    auto ret = rpc.call("postDweetFor",
        (void*)dataString.c_str(), dataString.length(), // arguments
        NULL, 0,                                        // no returns
        false, 1000, 3000);                             // parameters

    if (ret == 0) {
        Serial.println("Error");
        return;
    }
}

void rpcGetLatestDweetFor(String deviceID)
{
    Serial.print("Getting Latest Dweet For ");
    Serial.print(deviceID);
    Serial.print(" via RPC: ");

    // buffer for return data from RPC client
    size_t bufferLen { scratch_buffer.buffer_size() };
    char buffer[bufferLen] {};

    // Call the "getLatestDweetFor" callback on the MKR WiFi 1010
    // Remember to set large RPC timeouts: the Network is SLOW!
    auto ret = rpc.call("getLatestDweetFor",
        (void*)deviceID.c_str(), deviceID.length(), // arguments
        buffer, bufferLen,                          // returns
        true, 1000, 3000);                          // parameters

    if (ret == 0) {
        Serial.println("Error");
        return;
    }

    // Data from Dweet is in JSON format
    Serial.println(buffer);
    JSONVar dweet = JSON.parse(buffer);

    // Extract next LED status
    JSONVar ledCommandJSON = dweet["with"][0]["content"]["led"];
    String ledCommand = (const char*)ledCommandJSON;

    // Pin LED is active low
    ledStatus = !(ledCommand == "on");
    Serial.print("LED ");
    Serial.println(ledStatus ? "Off" : "On");
}

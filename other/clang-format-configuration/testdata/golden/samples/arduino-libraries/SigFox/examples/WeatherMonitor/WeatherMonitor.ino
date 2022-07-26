/*
  SigFox Simple Weather Station

  This sketch demonstrates the usage of MKR Fox 1200 as a simple weather station.
  It uses
    the onboard temperature sensor
    HTU21D I2C sensor to get humidity
    Bosch BMP280 to get the barometric pressure
    TSL2561 Light Sensor to get luminosity

  Download the needed libraries from the following links
  http://librarymanager/all#BMP280&Adafruit
  http://librarymanager/all#HTU21D&Adafruit
  http://librarymanager/all#TSL2561&Adafruit
  http://librarymanager/all#adafruit&sensor&abstraction

  Since the Sigfox network can send a maximum of 120 messages per day (depending on your plan)
  we'll optimize the readings and send data in compact binary format

  This example code is in the public domain.
*/

#include <ArduinoLowPower.h>
#include <SigFox.h>
#include <Adafruit_HTU21DF.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_TSL2561_U.h>
#include "conversions.h"

// Set oneshot to false to trigger continuous mode when you finished setting up the whole flow
int oneshot = true;

Adafruit_BMP280 bmp;
Adafruit_HTU21DF htu = Adafruit_HTU21DF();
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

#define STATUS_OK 0
#define STATUS_BMP_KO 1
#define STATUS_HTU_KO 2
#define STATUS_TSL_KO 4

/*
    ATTENTION - the structure we are going to send MUST
    be declared "packed" otherwise we'll get padding mismatch
    on the sent data - see http://www.catb.org/esr/structure-packing/#_structure_alignment_and_padding
    for more details
*/
typedef struct __attribute__((packed)) sigfox_message {
  uint8_t status;
  int16_t moduleTemperature;
  int16_t bmpTemperature;
  uint16_t bmpPressure;
  uint16_t htuHumidity;
  uint16_t tlsLight;
  uint8_t lastMessageStatus;
} SigfoxMessage;

// stub for message which will be sent
SigfoxMessage msg;

void setup() {

  if (oneshot == true) {
    // Wait for the serial
    Serial.begin(115200);
    while (!Serial) {}
  }

  if (!SigFox.begin()) {
    // Something is really wrong, try rebooting
    // Reboot is useful if we are powering the board using an unreliable power source
    // (eg. solar panels or other energy harvesting methods)
    reboot();
  }

  //Send module to standby until we need to send a message
  SigFox.end();

  if (oneshot == true) {
    // Enable debug prints and LED indication if we are testing
    SigFox.debug();
  }

  // Configure the sensors and populate the status field
  if (!bmp.begin()) {
    msg.status |= STATUS_BMP_KO;
  } else {
    Serial.println("BMP OK");
  }

  if (!htu.begin()) {
    msg.status |= STATUS_HTU_KO;
  } else {
    Serial.println("HTU OK");
  }

  if (!tsl.begin()) {
    msg.status |= STATUS_TSL_KO;
  } else {
    Serial.println("TLS OK");
    tsl.enableAutoRange(true);
    tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);
  }
}

void loop() {
  // Every 15 minutes, read all the sensors and send them
  // Let's try to optimize the data format
  // Only use floats as intermediate representation, don't send them directly

  sensors_event_t event;

  float pressure = bmp.readPressure();
  msg.bmpPressure = convertoFloatToUInt16(pressure, 200000);
  float temperature = bmp.readTemperature();
  msg.bmpTemperature = convertoFloatToInt16(temperature, 60, -60);

  tsl.getEvent(&event);
  if (event.light) {
    msg.tlsLight = convertoFloatToUInt16(event.light, 100000);
  }

  float humidity = htu.readHumidity();
  msg.htuHumidity = convertoFloatToUInt16(humidity, 110);

  // Start the module
  SigFox.begin();
  // Wait at least 30 ms after first configuration (100 ms before)
  delay(100);

  // We can only read the module temperature before SigFox.end()
  temperature = SigFox.internalTemperature();
  msg.moduleTemperature = convertoFloatToInt16(temperature, 60, -60);

  if (oneshot == true) {
    Serial.println("Pressure: " + String(pressure));
    Serial.println("External temperature: " + String(temperature));
    Serial.println("Internal temp: " + String(temperature));
    Serial.println("Light: " + String(event.light));
    Serial.println("Humidity: " + String(humidity));
  }

  // Clears all pending interrupts
  SigFox.status();
  delay(1);

  SigFox.beginPacket();
  SigFox.write((uint8_t*)&msg, 12);

  msg.lastMessageStatus = SigFox.endPacket();

  if (oneshot == true) {
    Serial.println("Status: " + String(msg.lastMessageStatus));
  }

  SigFox.end();

  if (oneshot == true) {
    // spin forever, so we can test that the backend is behaving correctly
    while (1) {}
  }

  //Sleep for 15 minutes
  LowPower.sleep(15 * 60 * 1000);
}

void reboot() {
  NVIC_SystemReset();
  while (1)
    ;
}

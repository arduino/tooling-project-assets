/*
  HTS221 - Read Sensors Imperial

  This example reads data from the on-board HTS221 sensor of the
  Nano 33 BLE Sense then, prints the temperature and humidity sensor
  values in imperial units to the Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_HTS221.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
}

void loop() {
  // Passing in FAHRENHEIT as the unit parameter to HTS.readTemperature(...),
  // allows you to read the sensor values in imperial units
  float temperature = HTS.readTemperature(FAHRENHEIT);
  float humidity    = HTS.readHumidity();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °F");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

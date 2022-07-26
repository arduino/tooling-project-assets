/*
  LPS22HB - Read Pressure Imperial

  This example reads data from the on-board LPS22HB sensor of the
  Nano 33 BLE Sense and prints the temperature and pressure sensor
  value in imperial units to the Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_LPS22HB.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (1);
  }
}

void loop() {
  // Passing PSI to readPressure(...)
  // allows you to read the sensor values in imperial units
  float pressure = BARO.readPressure(PSI);

  // print the sensor value
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" psi");

  float temperature = BARO.readTemperature();

  // print the sensor value
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

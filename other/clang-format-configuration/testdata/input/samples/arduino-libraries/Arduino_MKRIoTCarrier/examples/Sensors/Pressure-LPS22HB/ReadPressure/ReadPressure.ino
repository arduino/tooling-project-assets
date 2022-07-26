/*
  LPS22HB - Read Pressure

  This example reads data from the on-board LPS22HB sensor of the
  Nano 33 BLE Sense and prints the pressure sensor value to the
  Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  carrier.noCase();
  if (!carrier.begin()) {
    Serial.println("Failed to initialize!");
    while (1);
  }
}

void loop() {
  // read the sensor value
  float pressure = carrier.Pressure.readPressure();

  // print the sensor value
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" kPa");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

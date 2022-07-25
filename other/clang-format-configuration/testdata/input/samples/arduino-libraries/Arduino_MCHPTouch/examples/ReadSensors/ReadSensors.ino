/*
  Arduino_MCHPTouch - Sensor data read example
  This example shows how to configure and read data
  from touch sensor buttons on MKR IoT Carrier and
  prints updates to the Serial Monitor.

  The circuit:
  - Arduino MKR board
  - MKR IoT Carrier

  This example code is in the public domain.
*/
#include "Arduino_MCHPTouch.h"

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;
  // QTouch initialization
  if (!TOUCH.begin())
  {
    Serial.println("Error in sensors initialization!");
    while (1)
      ;
  }
  Serial.println("Touch initialization Done!");
}

void loop()
{
  // polling the sensor for new data
  TOUCH.poll();

  // Checks if new data are available
  if (TOUCH.available())
  {
    //reads senseors
    Serial.print("Sensor 1 status: ");
    Serial.println(TOUCH.read(0));
    Serial.print("Sensor 2 status: ");
    Serial.println(TOUCH.read(1));
    Serial.print("Sensor 3 status: ");
    Serial.println(TOUCH.read(2));
    Serial.print("Sensor 4 status: ");
    Serial.println(TOUCH.read(3));
    Serial.print("Sensor 5 status: ");
    Serial.println(TOUCH.read(4));
    Serial.println();
  }
  delay(100);
}

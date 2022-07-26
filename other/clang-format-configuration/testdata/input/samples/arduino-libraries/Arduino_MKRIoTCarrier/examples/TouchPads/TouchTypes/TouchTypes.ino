/*
  Arduino_Qtouch - Sensor data read Example
  This example shows how to configure and read data
  from touch sensors buttons on MKR IoT Carrier and
  prints updates to the Serial Monitor.

  The circuit:
  - Arduino MKR baord;
  - MKR IoT carrier.

  This example code is in the public domain.
*/
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;


void setup() {
  Serial.begin(9600);
  while (!Serial);
  carrier.noCase();
  if (!carrier.begin()) {
    Serial.println("Error in sensors initialization!");
    while (1);
  }
  Serial.println("Touch initialization Done!");
}

void loop() {
  // polling the sensor for new measure
  carrier.Buttons.update();

  if (carrier.Buttons.onTouchDown(TOUCH0)) {
    Serial.println("Touched Down Button 0");
  }
  if (carrier.Buttons.onTouchUp(TOUCH1)) {
    Serial.println("Release Touch Button 1");
  }
  if (carrier.Buttons.onTouchChange(TOUCH2)) {
    Serial.println("Changed Touch Button 2");
  }
  if (carrier.Buttons.getTouch(TOUCH3)) {
    Serial.println("Touching Button 3");
  }
  if (carrier.Buttons.getTouch(TOUCH4)) {
    Serial.println("Touching Button 4");
  }
  delay(20);
}

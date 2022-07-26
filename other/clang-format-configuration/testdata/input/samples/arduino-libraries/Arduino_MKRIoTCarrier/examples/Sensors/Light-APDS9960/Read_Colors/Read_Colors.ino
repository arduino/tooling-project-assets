/*
  APDS9960 - Color Sensor
*/

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  carrier.noCase();
  carrier.begin();
}

void loop() {
  // check if a color reading is available
  while (! carrier.Light.colorAvailable()) {
    delay(5);
  }
  int r, g, b;

  // read the color
  carrier.Light.readColor(r, g, b);

  // print the values
  Serial.print("r = ");
  Serial.println(r);
  Serial.print("g = ");
  Serial.println(g);
  Serial.print("b = ");
  Serial.println(b);
  Serial.println();

  // wait a bit before reading again
  delay(1000);
}

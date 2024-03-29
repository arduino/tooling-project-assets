/*
  APDS9960 - All sensor data from APDS9960

  This example reads all data from the on-board APDS9960 sensor of the
  Nano 33 BLE Sense:
   - color RGB (red, green, blue)
   - proximity
   - gesture
  and prints updates to the Serial Monitor every 100 ms.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;  // Wait for serial monitor to open

  carrier.noCase();
  if (!carrier.begin()) {
    Serial.println("Error");
    while (true)
      ;  // Stop forever
  }
}

int proximity = 0;
int r = 0, g = 0, b = 0;
unsigned long lastUpdate = 0;

void loop() {

  // Check if a proximity reading is available.
  if (carrier.Light.proximityAvailable()) {
    proximity = carrier.Light.readProximity();
  }

  // check if a gesture reading is available
  if (carrier.Light.gestureAvailable()) {
    int gesture = carrier.Light.readGesture();
    switch (gesture) {
      case GESTURE_UP:
        Serial.println("Detected UP gesture");
        break;

      case GESTURE_DOWN:
        Serial.println("Detected DOWN gesture");
        break;

      case GESTURE_LEFT:
        Serial.println("Detected LEFT gesture");
        break;

      case GESTURE_RIGHT:
        Serial.println("Detected RIGHT gesture");
        break;

      default:
        // ignore
        break;
    }
  }

  // check if a color reading is available
  if (carrier.Light.colorAvailable()) {
    carrier.Light.readColor(r, g, b);
  }

  // Print updates every 100ms
  if (millis() - lastUpdate > 100) {
    lastUpdate = millis();
    Serial.print("PR=");
    Serial.print(proximity);
    Serial.print(" rgb=");
    Serial.print(r);
    Serial.print(",");
    Serial.print(g);
    Serial.print(",");
    Serial.println(b);
  }
}

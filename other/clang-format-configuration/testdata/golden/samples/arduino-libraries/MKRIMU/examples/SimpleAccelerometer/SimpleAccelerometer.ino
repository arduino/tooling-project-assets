/*
  MKR IMU Shield - Simple Accelerometer

  This example reads the acceleration values from the IMU
  on the MKR IMU Shield and continuously prints them to the 
  Serial Monitor.

  The circuit:
  - Arduino MKR board
  - Arduino MKR IMU Shield attached

  This example code is in the public domain.
*/

#include <MKRIMU.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}

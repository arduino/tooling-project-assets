/*
  MKR IMU Shield - Simple Magnetometer

  This example reads the magnetic field values from the IMU
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

  Serial.print("Magnetic Field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}

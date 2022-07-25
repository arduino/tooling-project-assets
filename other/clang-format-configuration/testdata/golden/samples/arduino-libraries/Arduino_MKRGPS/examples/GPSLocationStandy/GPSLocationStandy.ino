/*
  GPS Location Standby

  This sketch uses the GPS to determine the location of the board
  and prints it to the Serial Monitor.

  It puts the GPS into standby mode every 10 seconds, then wakes it up.

  Circuit:
   - MKR board
   - MKR GPS Shield attached via I2C cable

  This example code is in the public domain.
*/

#include <Arduino_MKRGPS.h>

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // If you are using the MKR GPS as shield, change the next line to pass
  // the GPS_MODE_SHIELD parameter to the GPS.begin(...)
  if (!GPS.begin()) {
    Serial.println("Failed to initialize GPS!");
    while (1);
  }
}

void loop() {
  // put the GPS in standby mode
  Serial.println("standby");
  GPS.standby();

  // wait for 10 seconds
  Serial.print("delay ");
  for (int i = 0; i < 10; i++) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();

  // wake up the GPS
  Serial.println("wakeup");
  GPS.wakeup();

  Serial.print("wait location ... ");

  // wait for new GPS data to become available
  unsigned long startMillis = millis();
  while (!GPS.available());
  unsigned long endMillis = millis();

  Serial.print(endMillis - startMillis);
  Serial.println(" ms");

  // read GPS values
  float latitude   = GPS.latitude();
  float longitude  = GPS.longitude();
  float altitude   = GPS.altitude();
  int   satellites = GPS.satellites();

  // print GPS values
  Serial.println();
  Serial.print("Location: ");
  Serial.print(latitude, 7);
  Serial.print(", ");
  Serial.println(longitude, 7);

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println("m");

  Serial.print("Number of satellites: ");
  Serial.println(satellites);

  Serial.println();
}

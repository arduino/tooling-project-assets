/*
  MKR ENV Shield - Read Sensors Imperial

  This example reads the sensors on-board the MKR ENV Shield
  and prints them in imperial units to the Serial Monitor once a second.

  The circuit:
  - Arduino MKR board
  - Arduino MKR ENV Shield attached

  This example code is in the public domain.
*/

#include <Arduino_MKRENV.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV Shield!");
    while (1);
  }
}

void loop() {
  // Passing in FAHRENHEIT as the unit parameter to ENV.readTemperature(...),
  // PSI to readPressure(...) and FOOTCANDLE to readIlluminance(...)
  // allows you to read the sensor values in imperial units
  float temperature = ENV.readTemperature(FAHRENHEIT);
  float humidity    = ENV.readHumidity();
  float pressure    = ENV.readPressure(PSI);
  float illuminance = ENV.readIlluminance(FOOTCANDLE);
  float uva         = ENV.readUVA();
  float uvb         = ENV.readUVB();
  float uvIndex     = ENV.readUVIndex();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °F");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure    = ");
  Serial.print(pressure);
  Serial.println(" psi");

  Serial.print("Illuminance = ");
  Serial.print(illuminance);
  Serial.println(" fc");

  Serial.print("UVA         = ");
  Serial.println(uva);

  Serial.print("UVB         = ");
  Serial.println(uvb);

  Serial.print("UV Index    = ");
  Serial.println(uvIndex);

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

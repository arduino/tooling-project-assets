/*
  MKR THERM Shield - Read Sensors

  This example reads the temperatures (in Fahrenheit and kelvins) measured by the thermocouple
  connected to the MKR THERM Shield and prints them to the Serial Monitor
  once a second.

  The circuit:
  - Arduino MKR board
  - Arduino MKR THERM Shield attached
  - A type K thermocouple temperature sensor connected to the shield

  This example code is in the public domain.
*/

#include <Arduino_MKRTHERM.h>

void setup() {

  Serial.begin(9600);

  while (!Serial)
    ;

  if (!THERM.begin()) {
    Serial.println("Failed to initialize MKR THERM Shield!");
    while (1)
      ;
  }
}

void loop() {

  Serial.print("Reference temperature ");
  Serial.print(THERM.readReferenceTemperature());
  Serial.println(" °C");

  Serial.print("Temperature in Fahrenheit ");
  Serial.print(THERM.readTemperature(FAHRENHEIT));
  Serial.println(" °F");

  Serial.print("Temperature in kelvin ");
  Serial.print(THERM.readTemperature(KELVIN));
  Serial.println(" K");

  Serial.println();

  delay(1000);
}

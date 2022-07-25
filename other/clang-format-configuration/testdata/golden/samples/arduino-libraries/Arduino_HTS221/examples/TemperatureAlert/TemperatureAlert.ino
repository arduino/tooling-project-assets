/*
  HTS221 - Temperature Alert
  This example reads data from the on-board HTS221 sensor of the
  Nano 33 BLE Sense. If the temperature increases above a certain limit, it turns the buzzer on.
  The circuit:
  - Arduino Nano 33 BLE Sense
  - Active buzzer module connected to pin 9 and GND

  written by K.Abhijeet
  This example code is in the public domain
*/

#include <Arduino_HTS221.h>

float tempLimit = 37;  // set your temperature limit in °C

void setup() {
  Serial.begin(9600);
  while (!Serial);

  pinMode(9, OUTPUT);

  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
}

void loop() {

  float temperature = HTS.readTemperature();  // read the sensor value

  Serial.print("Temperature = ");  // print the sensor value
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > tempLimit)
  {
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
  }
  else
  {
    delay(2000); // wait a while before displaying the next reading If the temperature is below the limit
  }
}

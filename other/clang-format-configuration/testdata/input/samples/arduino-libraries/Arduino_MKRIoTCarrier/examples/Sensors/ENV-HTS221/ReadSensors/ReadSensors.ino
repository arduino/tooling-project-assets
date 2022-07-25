/*
  HTS221 - Read Sensors
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
  // read all the sensor values
  float temperature = carrier.Env.readTemperature();
  float humidity    = carrier.Env.readHumidity();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

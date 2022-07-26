/*
  HTS221 - Read Sensors Imperial

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
  // Passing in FAHRENHEIT as the unit parameter to ENV.readTemperature(...),
  // allows you to read the sensor values in imperial units
  float temperature = carrier.Env.readTemperature(FAHRENHEIT);
  float humidity    = carrier.Env.readHumidity();

  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °F");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  // print an empty line
  Serial.println();

  // wait 1 second to print again
  delay(1000);
}

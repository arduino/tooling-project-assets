/*
* _3.3_light_sensor
* 
* The board changes the light intensity of an LED depending on the readings from a light sensor.
*
* (c) 2013-2016 Arduino LLC.
*/


int ledPin=9;
int lightSensorPin=A1;

void setup() {
  //nothing here
}

void loop() {
  int lightSensorValue=analogRead(lightSensorPin);
  int ledValue=map(lightSensorValue,0,1023,0,255);

  analogWrite(ledPin, ledValue);
  delay(10);
}


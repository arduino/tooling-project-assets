/*
* _3.4_light_sensor
* 
* The light sensor acts as a switch and turns an LED on or off depending on the readings.
* With a potentiometer to set the switch threshold.
*
* (c) 2013-2016 Arduino LLC.
*/

int ledPin=9;
int lightSensorPin=A1;
int potPin=A5;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  int lightSensorValue=analogRead(lightSensorPin);
  int threshold=analogRead(potPin);

  if(lightSensorValue>threshold){
    digitalWrite(ledPin,LOW);
  }
  else{
    digitalWrite(ledPin,HIGH);
  }
  
  delay(10);
}


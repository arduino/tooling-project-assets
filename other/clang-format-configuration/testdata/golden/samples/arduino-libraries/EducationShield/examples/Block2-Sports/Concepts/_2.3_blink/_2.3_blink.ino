/*
* _2.3_blink
* 
* An external LED blinks with a 2 second interval, 
* being turned on for 1 second and then turned off for 1 second.
*       
* The variable ledPin is declared to hold the value 5, the number 
* of the digital pin you are using.
*
* (c) 2013-2016 Arduino LLC.
*/

int ledPin = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}


/*
*  	_3.2_writing_analog
* 
* The board will gradually change the light intensity of an LED, connected to a PWM pin.
*
* (c) 2013-2016 Arduino LLC.
*/

int ledPin = 9;
int fade = 0;

void setup() {
  // nothing here
}

void loop() {
  analogWrite(ledPin, fade);
  delay(10);
  fade = fade + 10;
  if (fade > 255) fade = 0;
}


/*
* _2.2_blink
* 
* An external LED blinks with a 2 second interval, 
* being turned on for 1 second and then turned off for 1 second.
*       
* (c) 2013-2016 Arduino LLC.
*/

void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  delay(1000);
}


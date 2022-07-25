/*
* _2.1_blink
* 
* The on-board LED blinks with a 2 second interval, 
* being turned on for 1 second and then turned off for 1 second.
*       
* (c) 2013-2016 Arduino LLC.
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}


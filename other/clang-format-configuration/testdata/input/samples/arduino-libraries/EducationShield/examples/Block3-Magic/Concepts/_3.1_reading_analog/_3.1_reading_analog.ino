/*
* _3.1_reading_analog
* 
* The board uses a potentiometer to control the blinking speed of the on-board LED.
*
* (c) 2013-2016 Arduino LLC.
*/

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int val = analogRead(A5);
  
  digitalWrite(ledPin, HIGH);
  delay(val);
  digitalWrite(ledPin, LOW);
  delay(val);
}


/*
* _2.7_digital_input
* 
* The board will turn the on-board LED on or off
*
* (c) 2013-2016 Arduino LLC.
*/

int inputPin = 5;
int ledPin = 13;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(inputPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
}


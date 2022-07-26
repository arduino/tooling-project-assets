/*
*  _4.3_input_controlled_servo
* 
* The board will use a potentiometer to control the position of a standard servo.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <Servo.h>

Servo myservo;
int potPin = A5;
int val;

void setup() {
  myservo.attach(6);
}

void loop() {
  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 179);
  
  myservo.write(val);
  delay(15);
}


/*
* _4.4_two_servos
* 
* The board will control two servos, moving one at a time to make sure that it can provide enough current.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <Servo.h>

Servo myservo1, myservo2;

void setup() {
  myservo1.attach(6);
  myservo2.attach(9);
}

void loop() {
  myservo2.detach();
  myservo1.attach(6);
  myservo1.write(70);
  delay(1000);
  myservo1.write(120);
  delay(1000);

  myservo1.detach();
  myservo2.attach(9);
  myservo2.write(70);
  delay(1000);
  myservo2.write(120);
  delay(1000);
}


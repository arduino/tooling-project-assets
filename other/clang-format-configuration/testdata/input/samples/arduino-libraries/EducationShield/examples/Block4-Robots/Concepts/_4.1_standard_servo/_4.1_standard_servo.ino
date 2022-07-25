/*
* _4.1_standard_servo
* 
* The board will control the servo to repeatedly move its arm between 0 and 180 degrees.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(6);
}

void loop() {
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
}


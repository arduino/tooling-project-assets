/*
* _4.2_continuous_servo
* 
* The board will control the continuous rotation servo by writing a speed to it instead of a position.
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


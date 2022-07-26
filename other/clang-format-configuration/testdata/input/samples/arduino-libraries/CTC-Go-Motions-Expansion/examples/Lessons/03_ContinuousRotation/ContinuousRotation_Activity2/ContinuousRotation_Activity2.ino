/*
  CTC GO! MOTION 
  LESSON 03 - Continuous Rotation

  This sketch is written to accompany activity 2 of Lesson 3
*/

#include <Servo.h>

Servo servo_Cont;

int potPin = A0;

int potValue = 0;
int vel = 0;

void setup()
{
  servo_Cont.attach(9);
  Serial.begin(9600);
}

void loop()
{
  potValue = analogRead(potPin);
  vel = map(potValue,0,1023,0,180);
  
  servo_Cont.write(vel);
  delay(15);
  Serial.print("Shaft spee: ");
  Serial.println(vel);
}

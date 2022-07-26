/*
  CTC GO! MOTION 
  LESSON 03 - Continuous Rotation

  This sketch is written to accompany activity 1 of Lesson 3
*/

#include <Servo.h>

Servo servo_Cont;

int pos = 0;

void setup()
{
  servo_Cont.attach(9);
  Serial.begin(9600);
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 1)
  {
    servo_Cont.write(pos);
    Serial.print("Position value: ");
    Serial.println(pos);
    delay(0);
  }
  for (pos = 180; pos >= 0; pos -= 1)
  {
    servo_Cont.write(pos);
    Serial.print("Position value: ");
    Serial.println(pos);
    delay(0);
  }
}

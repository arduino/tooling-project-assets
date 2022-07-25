/*
  CTC GO! MOTION 
  LESSON 01 - Making Things Move 

  This sketch is written to accompany activity 1 of Lesson 1
*/

#include <Servo.h>

Servo servo_Standard;

int pos = 0;

void setup() 
{
  servo_Standard.attach(9);

  Serial.begin(9600);
}

void loop()
{
    for (pos = 0; pos <= 180; pos += 1)
    {
      servo_Standard.write(pos);
      Serial.print("Shaft position: ");
      Serial.println(pos);
      delay(50);
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {
      servo_Standard.write(pos);
      Serial.print("Shaft position: ");
      Serial.println(pos);
      delay(50);
    }
}

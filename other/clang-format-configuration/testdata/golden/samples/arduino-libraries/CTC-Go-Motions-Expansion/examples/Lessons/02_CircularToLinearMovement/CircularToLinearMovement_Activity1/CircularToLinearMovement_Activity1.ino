/*
  CTC GO! MOTION 
  LESSON 02 - Circular To Linear Movement 

  This sketch is written to accompany activity 1 of Lesson 2
*/

#include <Servo.h>

Servo servo_Standard;

int potPin = A0;

int pos = 0;
int potValue = 0;

int max_pos = 180;
int min_pos = 0;

void setup()
{
  servo_Standard.attach(6);

  Serial.begin(9600);
}

void loop()
{
  potValue = analogRead(potPin);

  pos = map(potValue, 0, 1023, min_pos, max_pos);

  servo_Standard.write(pos);
  Serial.print("Shaft position: ");
  Serial.println(pos);
  delay(15);
}

/*
  CTC GO! MOTION 
  LESSON 01 - Making Things Move 

  This sketch is written to accompany activity 2 of Lesson 1
*/


#include <Servo.h>

Servo servo_Standard;

int potPin = A0;

int potValue = 0;
int pos = 0;

void setup()
{
  servo_Standard.attach(9);

  Serial.begin(9600);
}

void loop()
{
  potValue = analogRead(potPin);
  pos = map(potValue,0,1023,0,180);
  
  servo_Standard.write(pos);
  delay(15);
  Serial.print("Shaft position: ");
  Serial.println(pos);
}

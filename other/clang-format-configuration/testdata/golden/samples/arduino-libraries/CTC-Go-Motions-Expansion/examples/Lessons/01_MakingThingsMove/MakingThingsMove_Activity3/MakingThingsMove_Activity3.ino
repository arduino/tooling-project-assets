/*
  CTC GO! MOTION 
  LESSON 01 - Making Things Move 

  This sketch is written to accompany activity 3 of Lesson 1
*/

#include <Servo.h>

Servo servo_Standard;

int USsensor = A0;

int USvalue = 0;
int distance = 0;
int triggerDistance = 500;

void setup()
{
  servo_Standard.attach(9);

  Serial.begin(9600);
}

void loop()
{
  USvalue = analogRead(USsensor);
  distance = USvalue * 3;
  distance = map(distance, 0, 1023, 0, 3000);

  Serial.print("Distance to the object (mm): ");
  Serial.println(distance);

  if (distance <= triggerDistance)
  {
    servo_Standard.write(90);
    delay(5000);
    Serial.print("Door opened");
  }
  else
  {
    servo_Standard.write(0);
    delay(15);
    Serial.print("Door closed");
  }
}

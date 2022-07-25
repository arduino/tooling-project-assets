/*
  CTC GO! MOTION 
  LESSON 03 - Continuous Rotation

  This sketch is written to accompany activity 3 of Lesson 3
*/

#include <Servo.h>

Servo servo_Cont;

int USsensor = A0;

int USvalue = 0;
int distance = 0;
int speed = 0;

void setup()
{
  servo_Cont.attach(9);
  Serial.begin(9600);
}

void loop()
{
  USvalue = analogRead(USsensor);
  distance = map(USvalue, 0, 1023, 0, 3000);

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 150)
  {
    servo_Cont.write(135);
    Serial.print("Object too close to the sensor");
  }
  else if (distance >= 150 && distance <= 200)
  {
    servo_Cont.write(90);
    Serial.print("Object in the targeted position");
  }
  else if (distance > 200 && distance <= 350)
  {
    servo_Cont.write(80);
    Serial.print("Third speed control range");
  }
  else if (distance > 350 && distance <= 500)
  {
    servo_Cont.write(50);
    Serial.print("Second speed control range");
  }

  else
  {
    servo_Cont.write(0);
    Serial.print("Full speed range");
  }
  
  delay(250);
}

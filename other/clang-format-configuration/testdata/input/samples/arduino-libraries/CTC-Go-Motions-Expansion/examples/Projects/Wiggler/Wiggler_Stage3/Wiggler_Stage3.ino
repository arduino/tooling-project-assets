/*
  CTC GO! MOTION
  PROJECT - Wiggler

  This sketch is written to accompany Stage 3 of the Wiggler project
*/

#include <Servo.h>

Servo servo_drive;
Servo servo_steer;

int lightSensor_1 = A0;
int lightSensor_2 = A1;

int lightValue_1 = 0;
int lightValue_2 = 0;

void setup() 
{
  servo_steer.attach(6);
  servo_drive.attach(9);
  Serial.begin(9600);
}

void loop()
{
  lightValue_1 = analogRead(lightSensor_1);
  lightValue_2 = analogRead(lightSensor_2);

  Serial.print("First Light Value: ");
  Serial.println(lightValue_1);
  Serial.print("Second Light Value: ");
  Serial.println(lightValue_2);


  servo_drive.write(120);
  servo_steer.write(90);
  delay(15);

  if (______ >= 900) 
  {
    ______.write(60);
    ______.write(30);
    delay(3000);
  }

  if (______ >= 900) 
  {
    ______.write(60);
    ______.write(150);
    delay(3000);
  }

}

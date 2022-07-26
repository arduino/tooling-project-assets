/*
  CTC GO! MOTION 
  LESSON 04 - Gears and Pulleys

  This sketch is written to accompany activity 1 of Lesson 4
*/

#include <Servo.h>

Servo waterServo;

int button1 = 2;
int button2 = 3;

int waterLevel = 0;
int b1_state = 0;
int b2_state = 0;

void setup()
{
  waterServo.attach(9);

  Serial.begin(9600);
}

void loop()
{
  b1_state = digitalRead(button1);
  b2_state = digitalRead(button2);

  if (b1_state == 1 && b2_state == 1)
  {
    waterLevel = 100;
  }
  else if (b1_state == 1 && b2_state == 0)
  {
    waterLevel = 60;
  }
  else if (b1_state == 0 && b2_state == 1)
  {
    waterLevel = 30;
  }
  else
  {
    waterLevel = 0;
  }

  switch (waterLevel)
  {
    case 100:
      waterServo.write(180);
      Serial.println("Water level 100%");
      break;

    case 60:
      waterServo.write(110);
      Serial.println("Water level 60%");
      break;

    case 30:
      waterServo.write(100);
      Serial.println("Water level 30%");
      break;

    default:
      waterServo.write(90);
      Serial.println("Water level 0%");
      break;
  }
}

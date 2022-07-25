
/*
  CTC GO! MOTION 
  LESSON 02 - Circular To Linear Movement 

  This sketch is written to accompany activity 2 of Lesson 2
*/

#include <Servo.h>

Servo servo_Standard;

int photo = A0;
int piezo = 3;

bool open = true;
bool closed = false;

int light = 0;
int trigger = 400;
int open_pos = 30;
int closed_pos = 125;
int closed_tone = 250;
int open_tone = 1500;

void setup()
{
  servo_Standard.attach(9);
  pinMode(piezo, OUTPUT);
}

void loop()
{
  light = analogRead(A0);

  if (light <= trigger)
  {
    servo_Standard.write(closed_pos);
    delay(400);
    sounds(closed);
  }
  else
  {
    servo_Standard.write(open_pos);
    delay(400);
    sounds(open);
  }
}


void sounds(bool state) {
  static bool prev_state = open;

  if (state != prev_state)
  {
    if (state == true)
    {
      for (int i = 0; i < 2; i++)
      {
        tone(piezo, open_tone);
        delay(50);
        noTone(piezo);
        delay(50);
      }
    }
    else
    {
      for (int i = 0; i < 2; i++)
      {
        tone(piezo, closed_tone);
        delay(50);
        noTone(piezo);
        delay(50);
      }
    }
  }
  else
  {
    noTone(piezo);
  }
  prev_state = state;
}


/*
  CTC GO! CORE MODULE 
  LESSON 08 - Analog Outputs

  This sketch is written to accompany Activity 1 in Lesson 08 of the CTC GO! core module
*/

int pot = A0;
int LED = 3;

// to save the potentiometer position
int val = 0;

// to change the LED bright
int PWM = 0;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  val = analogRead(pot);

  //re-ranging val values
  PWM = map (val, 0, 1023, 0, 255);
  analogWrite(LED, PWM); 
}

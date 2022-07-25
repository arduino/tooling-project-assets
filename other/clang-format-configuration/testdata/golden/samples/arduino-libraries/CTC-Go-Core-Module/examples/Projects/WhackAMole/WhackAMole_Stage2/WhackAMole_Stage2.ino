/*
  CTC GO! CORE MODULE 
  PROJECT 1 - WHACK A MOLE

  This sketch is written to accompany Stage 2 in Whack-a-mole of the CTC GO! core module
*/

int loseLED = 13;
int winLED = 12;
int yellowLED_1 = 11;
int yellowLED_2 = 10;
int yellowLED_3 = 9;
int button_1 = 5;
int button_2 = 6;
int button_3 = 7;

void setup()
{
  pinMode(loseLED, OUTPUT);
  pinMode(winLED, OUTPUT);
  pinMode(yellowLED_1, OUTPUT);
  pinMode(yellowLED_2, OUTPUT);
  pinMode(yellowLED_3, OUTPUT);

  pinMode(button_1, _____);
  pinMode(button_2, _____);
  pinMode(button_3, _____);
}

void loop()
{
  /*
    digitalWrite(loseLED, HIGH);
    digitalWrite(winLED, HIGH);
    digitalWrite(yellowLED_1, HIGH);
    digitalWrite(yellowLED_2, HIGH);
    digitalWrite(yellowLED_3, HIGH);
    delay(1000);
    digitalWrite(loseLED, LOW);
    digitalWrite(winLED, LOW);
    digitalWrite(yellowLED_1, LOW);
    digitalWrite(yellowLED_2, LOW);
    digitalWrite(yellowLED_3, LOW);
    delay(1000);
  */

  if (digitalRead(button_1) == _____)
  {
    digitalWrite(yellowLED_1, _____);
  }
  else if (digitalRead(button_2) == _____)
  {
    digitalWrite(yellowLED_2, _____);
  }
  else if (digitalRead(button_3) == _____)
  {
    digitalWrite(yellowLED_3, _____);
  }
  else  
  {
    digitalWrite(loseLED, LOW);
    digitalWrite(winLED, LOW);
    digitalWrite(yellowLED_1, LOW);
    digitalWrite(yellowLED_2, LOW);
    digitalWrite(yellowLED_3, LOW);
  }
}

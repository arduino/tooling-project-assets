/*
  CTC GO! - CORE MODULE 
  PROJECT 1 - Finger Race

  This sketch is written to accompany Stage 3 in Finger Race of the CTC GO! Core Module
*/

int greenLED_P1 = 13;
int greenLED_P2 =  9;

int button_P1 = 6;
int button_P2 = 7;

int blueLED_P1 =  12;
int blueLED_P2 =  10;

int gameState = 0;

void setup()
{
  pinMode(greenLED_P1, OUTPUT);
  pinMode(blueLED_P1, _____);
  pinMode(blueLED_P2, _____);
  pinMode(greenLED_P2, OUTPUT);

  pinMode(button_P1, INPUT);
  pinMode(button_P2, INPUT);
}

void loop()
{

  if (gameState == _____)
  {
    digitalWrite(greenLED_P1, _____);
    digitalWrite(blueLED_P1, _____);
    digitalWrite(blueLED_P2, _____);
    digitalWrite(greenLED_P2, _____);
    delay(200);
    digitalWrite(greenLED_P1, _____);
    digitalWrite(blueLED_P1, _____);
    digitalWrite(blueLED_P2, _____);
    digitalWrite(greenLED_P2, _____);
    delay(200);
  }
  else if (gameState == 1)
  {

  }
  else if (gameState == 2)
  {

  }

  if ( digitalRead(button_P1) == HIGH)
  {
    gameState = _____;
    digitalWrite(greenLED_P1, HIGH);
  }
  else
  {
    digitalWrite(greenLED_P1, LOW);
  }

  if ( digitalRead(button_P2) == HIGH)
  {
    gameState = _____;
    digitalWrite(greenLED_P2, HIGH);
  }
  else
  {
    digitalWrite(greenLED_P2, LOW);
  }
}

/*
  CTC GO! - CORE MODULE 
  PROJECT 1 - Finger Race

  This sketch is written to accompany Stage 4 in Finger Race of the CTC GO! Core Module
*/

int greenLED_P1 = 13;
int blueLED_P1 =  12;

int blueLED_P2 =  10;
int greenLED_P2 =  9;

int button_P1 = 6;
int button_P2 = 7;

int gameState = 0;

int player_1 = 0;
int player_2 = 0;

void setup()
{
  pinMode(greenLED_P1, OUTPUT);
  pinMode(blueLED_P1, OUTPUT);
  pinMode(blueLED_P2, OUTPUT);
  pinMode(greenLED_P2, OUTPUT);

  pinMode(button_P1, INPUT);
  pinMode(button_P2, INPUT);
}

void loop()
{
  
  if (gameState == 0)
  {
    digitalWrite(greenLED_P1, HIGH);
    digitalWrite(blueLED_P1, HIGH);
    digitalWrite(blueLED_P2, HIGH);
    digitalWrite(greenLED_P2, HIGH);
    delay(200);
    digitalWrite(greenLED_P1, LOW);
    digitalWrite(blueLED_P1, LOW);
    digitalWrite(blueLED_P2, LOW);
    digitalWrite(greenLED_P2, LOW);
    delay(200);
  }
  
  else if(gameState == 1)
  {
  
  }
 
  else if (gameState == 2)
  {
    if (_____ )
    {
      digitalWrite(blueLED_P1, _____);
      digitalWrite(blueLED_P2, _____);
    }
    else if (_____)
    {
      digitalWrite(blueLED_P1, _____);
      digitalWrite(blueLED_P2, _____);
    }
    else
    {
      digitalWrite(blueLED_P1, _____);
      digitalWrite(blueLED_P2, _____);
    }
    if (_____)
    {
      digitalWrite(greenLED_P1, _____);
      digitalWrite(blueLED_P1, _____);
      digitalWrite(blueLED_P2, _____);
      digitalWrite(greenLED_P2, _____);

      delay(_____);
      gameState = _____;
      player_1 = _____;
      player_2 = _____;
    }
    if (_____)
    {
      digitalWrite(greenLED_P1, _____);
      digitalWrite(blueLED_P1, _____);
      digitalWrite(blueLED_P2, _____);
      digitalWrite(greenLED_P2, _____);

      delay(_____);
      gameState = _____;
      player_1 = _____;
      player_2 = _____;
    }
  }
 

  if ( digitalRead(button_P1) == HIGH)
  {
    gameState = 2;
    digitalWrite(greenLED_P1, HIGH);
    player_1 = _____;
   }

  else
  {
    digitalWrite(greenLED_P1, LOW);
  }

  if ( digitalRead(button_P2) == HIGH)
  {
    gameState = 2;
    digitalWrite(greenLED_P2, HIGH);
    player_2 = _____;
  }
  else
  {
    digitalWrite(greenLED_P2, LOW);
  }
}

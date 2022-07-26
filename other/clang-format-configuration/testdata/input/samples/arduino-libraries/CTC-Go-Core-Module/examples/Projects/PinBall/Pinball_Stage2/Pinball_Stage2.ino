/*
  CTC GO! CORE MODULE 
  PROJECT 1 - Pinball

  This sketch is written to accompany Stage 2 in Pinball of the CTC GO! core module
*/

int blueLED_1 = 11;
int blueLED_2 = 12;
int redLED = 13;
int greenLED = 9;

int button_1 = 7; 
int button_2 = 6;

void setup()
{
  pinMode (blueLED_1, OUTPUT);
  pinMode (blueLED_2, OUTPUT);
  pinMode (redLED, OUTPUT);
  pinMode (greenLED, OUTPUT);
  
  pinMode (button_1, _____);
  pinMode (button_2, _____);
}

void loop() {
 
  /*
  digitalWrite(blueLED_1, HIGH);
  digitalWrite(blueLED_2,HIGH);
  digitalWrite(redLED,HIGH);
  digitalWrite(greenLED,HIGH);
  delay(1000);
  digitalWrite(blueLED_1, LOW);
  digitalWrite(blueLED_2,LOW);
  digitalWrite(redLED,LOW);
  digitalWrite(greenLED,LOW);
  delay(1000);
  */

  if ( digitalRead(button_1) == _____)
  {
   digitalWrite(greenLED, _____);
   delay(_____);
  }

  if ( digitalRead(_____) == _____ )
  {
   digitalWrite(blueLED_1, _____);
   delay(_____);
  }

   digitalWrite(blueLED_1, _____);
   digitalWrite(greenLED, _____);
   
}

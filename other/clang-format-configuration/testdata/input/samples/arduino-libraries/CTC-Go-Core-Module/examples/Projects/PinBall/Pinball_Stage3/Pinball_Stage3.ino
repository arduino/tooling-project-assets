/*
  CTC GO! CORE MODULE 
  PROJECT 1 - Pinball

  This sketch is written to accompany Stage 3 in Pinball of the CTC GO! core module
*/

int blueLED_1 = 11;
int blueLED_2 = 12;
int redLED = 13;
int greenLED = 9;
int button_1 = 7;
int button_2 = 6;

int losing = 0;
int winning  = 0; 

void setup()
{
  pinMode (blueLED_1, OUTPUT);
  pinMode (blueLED_2, OUTPUT);
  pinMode (redLED, OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode (button_1, INPUT);
  pinMode (button_2, INPUT);
}

void loop() {

if ( digitalRead(button_1) == HIGH ) 
  {
   digitalWrite(greenLED, HIGH);
   winning = _____;
   delay(_____);
  }

  if ( digitalRead(button_2) == HIGH ) 
  {
   digitalWrite(blueLED_1, HIGH);
   losing = _____;
   delay(_____);
  }

   digitalWrite(blueLED_1, LOW);
   digitalWrite(greenLED, LOW);

  if(losing == _____ && winning == _____)
  {
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
  }

  
}

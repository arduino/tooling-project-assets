/*
  CTC GO! CORE MODULE 
  PROJECT 1 - REACT

  This sketch is written to accompany Stage 2 in REACT  of the CTC GO! core module
*/

int blueLED_P1 = 10;
int redLED = 11;
int greenLED = 12;
int blueLED_P2 = 13;
int button_P1 = 2;
int button_P2 = 3;

void setup() {

  pinMode (blueLED_P1, OUTPUT);
  pinMode (blueLED_P2, OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode (redLED, OUTPUT);

  pinMode (button_P1, _____);
  pinMode (button_P2, _____);

}

void loop() 
{
  /*
    //STEP 1; check if the LEDs are working
    digitalWrite(blueLED_P1, HIGH);
    digitalWrite(blueLED_P2, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, HIGH);
    delay(100);
    digitalWrite(blueLED_P1, LOW);
    digitalWrite(blueLED_P2, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    delay(100);
  */

  if (digitalRead(button_P1) == _____)
  {
    digitalWrite(blueLED_P1, _____);
    delay(100);
    digitalWrite(blueLED_P1, LOW);
    delay(100);
  }

  if (digitalRead(button_P2) == _____)
  {
    digitalWrite(blueLED_P2, _____);
    delay(100);
    digitalWrite(blueLED_P2, LOW);
    delay(100);
  }
}

/*
  CTC GO! CORE MODULE 
  PROJECT 1 - REACT

  This sketch is written to accompany Stage 5 in REACT  of the CTC GO! core module
*/

int blueLED_P1 = 10;
int redLED = 11;
int greenLED = 12;
int blueLED_P2 = 13;

int button_P1 = 2;
int button_P2 = 3;

int game = 0;

int level = 300;
int gameSpeed = 0;
int win_P1 = 0;
int win_P2 = 0;

void setup() {

  pinMode (blueLED_P1, OUTPUT);
  pinMode (blueLED_P2, OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode (redLED, OUTPUT);

  pinMode (button_P1, INPUT);
  pinMode (button_P2, INPUT);

}

void loop() {
  
   if (game == 0)
   {
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
    
    if (digitalRead(button_P1)== HIGH || digitalRead(button_P2) == HIGH )
     {
      game += 1;
      digitalWrite(blueLED_P1, HIGH);
      digitalWrite(blueLED_P2, HIGH);  
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, HIGH);
      delay(3000);    
      digitalWrite(blueLED_P1, LOW);
      digitalWrite(blueLED_P2, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      delay(1000);
      }
   } 

  if (game == 1)
  {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    
    delay(level);

    if (digitalRead(button_P1) == HIGH) 
     {
         digitalWrite(blueLED_P1, HIGH);
         delay(100);
         digitalWrite(blueLED_P1, LOW);
         delay(100);
         digitalWrite(blueLED_P1, HIGH);
         delay(100);
         digitalWrite(blueLED_P1, LOW);
         delay(100);
         win_P1 += _____;
     }
    
    if (digitalRead(button_P2) == HIGH)
    {
       digitalWrite(blueLED_P2, HIGH);
       delay(100);
       digitalWrite(blueLED_P2, LOW);
       delay(100);
       digitalWrite(blueLED_P2, HIGH);
       delay(100);
       digitalWrite(blueLED_P2, LOW);
       delay(100);
       win_P2 += _____;
    }

    digitalWrite (greenLED, LOW);
    digitalWrite(redLED, HIGH);
    
  if (win_P1 == 5) 
  {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P1, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P1, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P1, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P1, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P1, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P1, _____);
    delay(2000);
    win_P1 = 0;
    win_P2 = 0;
    game = 0;
  }

  //STEP 5; Code to show the victory of player 2  
  if (win_P2 == _____) 
  {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P2, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P2, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P2, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P2, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P2, _____);
    delay(200);
    digitalWrite(greenLED, _____);
    digitalWrite(blueLED_P2, _____);
    delay(2000);
    win_P1 = 0;
    win_P2 = 0;
    game = 0;
  }

    gameSpeed = random(1000, 5000);
    delay(gameSpeed);

  }


  
}

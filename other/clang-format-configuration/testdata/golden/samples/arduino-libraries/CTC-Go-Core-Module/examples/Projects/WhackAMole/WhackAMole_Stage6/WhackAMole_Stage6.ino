/*
  CTC GO! CORE MODULE 
  PROJECT 1 - WHACK A MOLE

  This sketch is written to accompany Stage 6 in Whack-a-mole of the CTC GO! core module
*/

int loseLED = 13;
int winLED = 12;
int yellowLED_1 = 11;
int yellowLED_2 = 10;
int yellowLED_3 = 9;
int button_1 = 5;
int button_2 = 6;
int button_3 = 7;

int startLevel = 500;    
int gameStarted = 0;     
int blinkLED = 0;      
int level = 0;

void setup()
{
  pinMode(loseLED, OUTPUT);
  pinMode(winLED, OUTPUT);
  pinMode(yellowLED_1, OUTPUT);
  pinMode(yellowLED_2, OUTPUT);
  pinMode(yellowLED_3, OUTPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT); 
}

void loop()
{
  if (gameStarted == 0)
  {
    digitalWrite(loseLED, HIGH);
    digitalWrite(winLED, HIGH); 
    digitalWrite(yellowLED_1, HIGH);
    digitalWrite(yellowLED_2, HIGH);
    digitalWrite(yellowLED_3, HIGH);
    delay(startLevel);
    digitalWrite(loseLED, LOW);
    digitalWrite(winLED, LOW);
    digitalWrite(yellowLED_1, LOW);
    digitalWrite(yellowLED_2, LOW);
    digitalWrite(yellowLED_3, LOW);
    delay(startLevel);

  if (digitalRead(button_1) == HIGH || digitalRead(button_2) == HIGH || digitalRead(button_3) == HIGH )
  {
    digitalWrite(loseLED, HIGH);
    digitalWrite(winLED, HIGH);

    gameStarted = 1;
    delay(2000);
    digitalWrite(loseLED, LOW);
    digitalWrite(winLED, LOW);
  }
  

  }else if (gameStarted == 1)
   {
    
      blinkLED = random (1, 4);

    if (blinkLED == 1)
     {
       digitalWrite(yellowLED_1, HIGH);
       delay(startLevel - level);
      
        if (digitalRead(button_2) == _____ || digitalRead(button_3) == _____ )
        {
        digitalWrite(loseLED, HIGH);
        delay(2000);
        gameStarted = _____; 
        }
        
        else if (digitalRead(button_1) == _____)
        {
        digitalWrite(winLED, HIGH);
        delay(_____);
        level = level + 5;
        }
     }
      
    if (blinkLED == 2)
     {
      digitalWrite(yellowLED_2, HIGH);
      delay(startLevel - _____);
      
        
        if (digitalRead(button_1) == _____ || digitalRead(button_3) == _____ )
        {
        digitalWrite(loseLED, HIGH);
        delay(2000);
        gameStarted = _____; 
        }
      
        else if (digitalRead(button_2) == _____)
        {
        digitalWrite(winLED, HIGH);
        delay(_____);
        level = level + 5;
        }
     }

     
    if (blinkLED == 3)
     {
      digitalWrite(yellowLED_3, HIGH);
      delay(startLevel - _____);    
     
        if (digitalRead(button_1) == _____ || digitalRead(button_2) == _____ )
        {
        digitalWrite(loseLED, HIGH);
        delay(2000);
        gameStarted = _____; 
        }
     
        else if (digitalRead(button_3) == _____)
        {
        digitalWrite(winLED, HIGH);
        delay(_____);
        level = level + 5;
        }
     }
  }
  if (level >= startLevel)
  {
    level = startLevel;
  }
    digitalWrite(loseLED, LOW);
    digitalWrite(winLED, LOW);
    digitalWrite(yellowLED_1, LOW);
    digitalWrite(yellowLED_2, LOW);
    digitalWrite(yellowLED_3, LOW);
    delay(startLevel - _____);
}

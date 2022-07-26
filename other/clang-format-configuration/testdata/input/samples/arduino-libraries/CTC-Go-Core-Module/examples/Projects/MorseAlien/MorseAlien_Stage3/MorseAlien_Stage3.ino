/*
  CTC GO! CORE MODULE 
  PROJECT 2 - MORSE ALIEN

  This sketch is written to accompany Stage 3 in MORSE ALIEN  of the CTC GO! core module
*/

int distanceSensor = A0;
int blueLED = 13;
int breakButton = 10;
int recordButton = 12;
int playButton = 11;
int piezo = 8;

int prevBreakButtonState = LOW;
int prevRecordButtonState = LOW;
int prevPlayButtonState = LOW;

int mySymbols[50];
int symbolIndex = 0;
int symbolLength = 300;
int currentSymbol = 0;
int sequencePlayed = false;

int DASH = 2;
int DOT = 1;
int freq_DASH = 1500 ;
int freq_DOT = 1000 ;

void setup()
{
   pinMode(blueLED,OUTPUT);
   pinMode(breakButton,INPUT);
   pinMode(recordButton,INPUT);
   pinMode(playButton,INPUT);
   pinMode(piezo, OUTPUT);

   Serial.begin(9600);
}

void loop()
{    
   int distanceSensorValue = analogRead(distanceSensor);
   int actualDistanceMM = map(distanceSensorValue,0,1023,0,3000);

   if (distanceSensorValue < 200)
   {
     digitalWrite(blueLED,HIGH);
     currentSymbol = _____;
   }
   else
   {
     digitalWrite(blueLED,LOW);
     currentSymbol = _____;
   }
   
   if (digitalRead(recordButton) == HIGH) 
   { 
     if (prevRecordButtonState == LOW) 
    {  
      Serial.print("ADDING SYMBOL");
      Serial.print(_____);
      Serial.print(" ");
      Serial.println(_____);
      digitalWrite(blueLED, LOW);
      delay(symbolLength);

      if (currentSymbol == _____) 
      {
         digitalWrite(_____, _____);
         tone(_____, freq_DOT);
         delay(symbolLength);
         digitalWrite(_____, _____);
      }
      else if (currentSymbol == DASH) 
      {
         digitalWrite(_____, _____);
         tone(piezo, _____ );
         delay(symbolLength * 3);
         digitalWrite(_____, _____);
       }
    }
    prevRecordButtonState = HIGH;  

    /*
      Add the symbol to the array
    */
    if (sequencePlayed == true) 
    {
      sequencePlayed = _____;
      symbolIndex = _____;
    }
    mySymbols[ _____ ] = _____;
    symbolIndex = _____;    
   }
   else
   {
    prevRecordButtonState = LOW;    
   }

   if (digitalRead(breakButton) == HIGH)
   {    
     if (prevBreakButtonState == LOW) 
     {
      Serial.println("ADDING BREAK");
      tone(piezo, 1000);
     }
     prevBreakButtonState = HIGH;  
   }
   else
   {
    prevBreakButtonState = LOW;  
   }

   if (digitalRead(playButton) == HIGH)
   {    
     if (prevPlayButtonState == LOW) 
      {
        Serial.println("START PLAYING SYMBOLS");
        tone(piezo, 1000);
      }
      prevPlayButtonState = HIGH; 
   } 
   else
   {
    prevPlayButtonState = LOW;  
   }
}

/*
  CTC GO! CORE MODULE 
  PROJECT 2 - MORSE ALIEN

  This sketch is written to accompany Stage 5 in MORSE ALIEN  of the CTC GO! core module
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
int BREAK = 0;

int freq_DASH = 1500 ;
int freq_DOT = 1000 ;
int freq_BREAK = 500 ; 

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
     currentSymbol = DASH;
   }
   else
   {
     digitalWrite(blueLED,LOW);
     currentSymbol = DOT;
   }
   
   if (digitalRead(recordButton) == HIGH) 
   { 
     if (prevRecordButtonState == LOW) 
    {  
      Serial.print("ADDING SYMBOL ");
      Serial.print(symbolIndex);
      Serial.print(" ");
      Serial.println(currentSymbol);

      digitalWrite(blueLED, LOW);
      delay(symbolLength);
      
      if (currentSymbol == DOT) 
      {
         digitalWrite(blueLED, HIGH);
         tone(piezo, freq_DOT);
         delay(symbolLength);
         digitalWrite(blueLED, LOW);
      }
      else if (currentSymbol == DASH) 
      {
         digitalWrite(blueLED, HIGH);
         tone(piezo, freq_DASH );
         delay(symbolLength * 3);
         digitalWrite(blueLED, LOW);
       }
    }
    prevRecordButtonState = HIGH;  

    if (sequencePlayed == true) 
    {
      sequencePlayed = false;
      symbolIndex = 0;
    }
    mySymbols[symbolIndex] = currentSymbol;
    symbolIndex = symbolIndex + 1;    
   }
   else
   {
    prevRecordButtonState = LOW;    
   }

   if (digitalRead(breakButton) == HIGH)
   {    
     if (prevBreakButtonState == LOW) 
     {
       Serial.print("ADDING BREAK");
       currentSymbol = BREAK;
       Serial.print(symbolIndex);
       Serial.println(currentSymbol);
       tone(piezo, freq_BREAK);
       delay(symbolLength * 3);
      /*
        Add the symbol to the array
      */
      //If the sequence played already, start recording from scratch
      if (sequencePlayed == true)
      {
        symbolIndex = 0;
      }
      mySymbols[symbolIndex] = currentSymbol;
      symbolIndex = symbolIndex + 1;
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
         sequencePlayed = true;
         for (int i = 0; i < symbolIndex; i++)
         {
           digitalWrite(blueLED, LOW);
           delay(symbolLength);
           
           if (mySymbols[i] == _____)
           {
           digitalWrite(_____, _____);
           tone(piezo, _____ );
           delay(_____);
           digitalWrite(_____, _____);
           }
           else if (_____ == DASH)
           {
           digitalWrite(_____, _____);
           tone(_____, _____);
           delay(_____);
           digitalWrite(_____, _____);
           }
           else if (mySymbols[i] == _____)
           {
           digitalWrite(_____, _____);
           delay(_____);
           }
        } 
      prevPlayButtonState = HIGH; 
    }
   }  
   else
   {
    prevPlayButtonState = LOW;  
   }
}

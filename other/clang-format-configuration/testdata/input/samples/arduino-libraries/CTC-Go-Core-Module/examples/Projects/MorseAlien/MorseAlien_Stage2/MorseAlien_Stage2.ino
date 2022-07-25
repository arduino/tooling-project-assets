/*
  CTC GO! CORE MODULE 
  PROJECT 2 - MORSE ALIEN

  This sketch is written to accompany Stage 2 in MORSE ALIEN  of the CTC GO! core module
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

void setup()
{
   pinMode(blueLED,OUTPUT);
   pinMode(breakButton,_____);
   pinMode(recordButton,_____);
   pinMode(playButton,_____);
   pinMode(piezo, _____);

   Serial.begin(9600);
}

void loop()
{    
   int distanceSensorValue = analogRead(distanceSensor);
   int actualDistanceMM = map(distanceSensorValue,0,1023,0,3000);

   if (distanceSensorValue < 200)
   {
     digitalWrite(blueLED,HIGH);
   }
   else
   {
     digitalWrite(blueLED,LOW);
   }
   
   if (digitalRead(_____) == _____) 
   { 
    if (prevRecordButtonState == _____) 
    {
      Serial.println("_____");
      tone(_____, 1000);
    }
    prevRecordButtonState = _____;  
   }
   else
   {
    prevRecordButtonState = _____;    
   }

   if (_____ == _____)
   {    
    if (prevBreakButtonState == _____) 
    {
      Serial.println(_____);
      tone(_____, _____);
    }
    prevBreakButtonState = _____;  
   } 
   else
   {
    prevBreakButtonState = _____;  
   }

   if (_____ == _____)
   {    
    if (prevPlayButtonState == _____) 
    {
      Serial.println(_____);
      tone(_____, _____);
    }
    _____ = _____;  
   } 
   else
   {
    _____ = _____;  
   }

}

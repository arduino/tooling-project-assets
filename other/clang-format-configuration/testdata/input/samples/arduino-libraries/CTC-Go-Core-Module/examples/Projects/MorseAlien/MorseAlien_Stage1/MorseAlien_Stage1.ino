/*
  CTC GO! CORE MODULE 
  PROJECT 2 - MORSE ALIEN

  This sketch is written to accompany Stage 1 in MORSE ALIEN  of the CTC GO! core module
*/

int distanceSensor = A0;
int blueLED = 13;

void setup()
{
   pinMode(_____,_____);
   Serial.begin(9600);
}

void loop()
{    
   
   int distanceSensorValue = _____(distanceSensor);

   int actualDistanceMM = map(_____,0,1023,0,3000);

   Serial.print(_____);
   Serial.print(",");
   Serial.println(_____);
   
   if (_____<200)
   {
     digitalWrite(_____,HIGH);
   }
   _____
   {
     digitalWrite(_____,LOW);
   }
}

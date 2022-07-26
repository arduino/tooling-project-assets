/*
  CTC GO! CORE MODULE 
  PROJECT 2 - CRAZY DJ

  This sketch is written to accompany Stage 1 in CRAZY DJ  of the CTC GO! core module
*/

//STEP 1; Variables for blue LED & light sensor
int lightSensor = A0;
int ledPin = 10;

int lightValue = 0;
int LEDvalue = 0;

void setup()
{ 
  _____(ledPin, _____);
  Serial.begin(9600);
}

void loop() 
{
   lightValue = _____(lightSensor);
   LEDvalue = map(lightValue, _____, _____, _____, _____);
   analogWrite(ledPin, LEDvalue);
   
   Serial.print("Light value: ");
   Serial.println(lightValue);
   delay(100);
}

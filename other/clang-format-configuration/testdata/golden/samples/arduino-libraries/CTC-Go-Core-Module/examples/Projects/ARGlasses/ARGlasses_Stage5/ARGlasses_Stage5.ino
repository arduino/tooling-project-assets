/*
  CTC GO! CORE MODULE 
  PROJECT 2 - AR GLASSES

  This sketch is written to accompany Stage 5 in AR GLASSES  of the CTC GO! core module
*/

int piezo = 11;
int yellowLED = 13;
int redLED = 12;
int distanceSensor = A0 ;
int freq_1 = 500;
int distanceSensorValue = 0;
int actualDistanceMM = 0;
int actualDelay = 0;
int distance = 250;

void setup()
{
  pinMode(piezo, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  distanceSensorValue = analogRead(distanceSensor);
  actualDistanceMM = map(distanceSensorValue, 0, 1023, 0, 3000);
  Serial.print("Distance read: ");
  Serial.println(distanceSensorValue);
  Serial.print("Distance converted: ");
  Serial.println(actualDistanceMM);
  
  actualDelay = map(actualDistanceMM,0,3000,0,1000);
 
  if (actualDistanceMM < _____)
  {
    digitalWrite(redLED, _____);
    _____ (_____, freq_1);
    delay(100);
    digitalWrite(redLED, _____);
    delay(100);
  }
  else if (actualDistanceMM > _____)
  {
    digitalWrite(yellowLED, _____);
    tone(piezo, freq_1);
    delay(actualDelay);
    digitalWrite(yellowLED, _____);
    noTone(piezo);
    delay(actualDelay);
  }
}

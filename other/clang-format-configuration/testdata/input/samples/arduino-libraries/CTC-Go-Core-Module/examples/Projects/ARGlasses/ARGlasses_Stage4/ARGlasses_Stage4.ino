/*
  CTC GO! CORE MODULE 
  PROJECT 2 - AR GLASSES

  This sketch is written to accompany Stage 4 in AR GLASSES  of the CTC GO! core module
*/

int piezo = 11;
int yellowLED = 13;
int distanceSensor = A0 ;

int freq_1 = 500;
int distanceSensorValue = 0;
int actualDistanceMM = 0;
int actualDelay = 0;

void setup()
{
  pinMode(piezo, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  distanceSensorValue = analogRead(distanceSensor);

  actualDistanceMM = map(distanceSensorValue,0,1023,0,3000);

  Serial.print("Distance read: ");
  Serial.println(distanceSensorValue);
  Serial.print("Distance converted: ");
  Serial.println(actualDistanceMM);

  actualDelay = map(actualDistanceMM,_____,_____,_____,_____);

  digitalWrite(yellowLED,HIGH);
  tone(piezo,freq_1);
  delay(_____);
  digitalWrite(yellowLED,LOW);
  noTone(piezo);
  delay(_____);
}

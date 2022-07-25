/*
  CTC GO! CORE MODULE 
  PROJECT 2 - AR GLASSES

  This sketch is written to accompany Stage 3 in AR GLASSES  of the CTC GO! core module
*/

int piezo = 11;
int yellowLED = 13;

int distanceSensor = A0 ;

int freq_1 = 500;
int distanceSensorValue = 0;
int actualDistanceMM = 0;

void setup()
{
  pinMode(piezo, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  distanceSensorValue = analogRead(distanceSensor);
  actualDistanceMM = map(distanceSensorValue, 0, 1023, _____, _____);

  Serial.print("Distance read: ");
  Serial.println(_____);
  Serial.print("Distance converted: ");
  Serial.println(_____);

  /*
    digitalWrite(yellowLED,HIGH);
    tone(piezo,freq_1);
    delay(100);
    digitalWrite(yellowLED,LOW);
    noTone(piezo,freq_1);
    delay(100);
  */

    delay(_____);
}

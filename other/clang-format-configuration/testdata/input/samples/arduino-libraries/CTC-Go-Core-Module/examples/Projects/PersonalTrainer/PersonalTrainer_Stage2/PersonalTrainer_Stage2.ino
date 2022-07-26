/*
  CTC GO! CORE MODULE 
  PROJECT 2 - PERSONAL TRAINER

  This sketch is written to accompany Stage 2 in PERSONAL TRAINER  of the CTC GO! core module
*/

int ledCounter_1 = 2;
int ledCounter_2 = 3;
int ledCounter_3 = 4;
int distanceSensor = A0;

int distanceSensorValue;
int currentDistanceMM = 0;
int lastDistance = 0;

void setup(){
    pinMode(ledCounter_1, OUTPUT);
    pinMode(ledCounter_2, OUTPUT);
    pinMode(ledCounter_3, OUTPUT);

    Serial.begin(_____);
}

void loop()
{

    digitalWrite(ledCounter_1,HIGH);
    digitalWrite(ledCounter_2, LOW);
    digitalWrite(ledCounter_3, LOW);
    delay(100);
    digitalWrite(ledCounter_1, LOW);
    digitalWrite(ledCounter_2, HIGH);
    digitalWrite(ledCounter_3, LOW);
    delay(100);
    digitalWrite(ledCounter_1, LOW);
    digitalWrite(ledCounter_2, LOW);
    digitalWrite(ledCounter_3, HIGH);
    delay(100);

    distanceSensorValue = analogRead(_____);
    currentDistanceMM = map(_____,_____,_____,0,3000);
    Serial.println(_____);

    lastDistance = currentDistanceMM;
   
}

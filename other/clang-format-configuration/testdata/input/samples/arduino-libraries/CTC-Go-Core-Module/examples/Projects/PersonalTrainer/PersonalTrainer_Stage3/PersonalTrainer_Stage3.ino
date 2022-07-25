/*
  CTC GO! CORE MODULE 
  PROJECT 2 - PERSONAL TRAINER

  This sketch is written to accompany Stage 3 in PERSONAL TRAINER  of the CTC GO! core module
*/


int ledCounter_1 = 2;
int ledCounter_2 = 3;
int ledCounter_3 = 4;
int distanceSensor = A0;
int incrementButton = 8;

int distanceSensorValue;
int currentDistanceMM = 0;
int lastDistance = 0;

int incrementButtonState = LOW;
int lastIncrementButtonState = LOW;
int stepCounter = 30;

void setup(){
    
    pinMode(ledCounter_1, OUTPUT);
    pinMode(ledCounter_2, OUTPUT);
    pinMode(ledCounter_3, OUTPUT);
    pinMode(incrementButton, INPUT);
    Serial.begin(9600);
    
}

void loop(){
  
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
    
    distanceSensorValue = analogRead(distanceSensor);
    currentDistanceMM = map(distanceSensorValue,0,1023,0,3000);
    //Serial.println(currentDistanceMM);

    incrementButtonState = digitalRead(_____);
    
    if (_____ == HIGH && lastIncrementButtonState == _____)
    {
        if (_____)
        {        
            Serial.println("increase the stepCounter by 10");
            stepCounter += _____;
        }else
        {
            stepCounter = _____;
        }
        Serial.print("stepCounter is ");
        Serial.println(stepCounter);
    }
    lastIncrementButtonState = incrementButtonState;
  
    lastDistance = currentDistanceMM;
}

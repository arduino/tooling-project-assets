/*
  CTC GO! CORE MODULE 
  PROJECT 2 - PERSONAL TRAINER

  This sketch is written to accompany Stage 5 in PERSONAL TRAINER  of the CTC GO! core module
*/


int ledCounter_1 = 2;
int ledCounter_2 = 3;
int ledCounter_3 = 4;
int distanceSensor = A0;
int incrementButton = 8;
int piezo = 6;

int currentDistanceMM = 0;
int distanceSensorValue;
int lastDistance = 0;

int incrementButtonState = LOW;
int lastIncrementButtonState = LOW;
int stepCounter = 30;

int freq_1 = 1000;
int freq_2 = 1500;
int freq_3 = 2000;

void setup(){

    pinMode(ledCounter_1, OUTPUT);
    pinMode(ledCounter_2, OUTPUT);
    pinMode(ledCounter_3, OUTPUT);
    pinMode(incrementButton, INPUT);    
    pinMode(piezo, OUTPUT);  

    Serial.begin(9600);
  
}

void loop(){
  
    distanceSensorValue = analogRead(distanceSensor);
    currentDistanceMM = map(distanceSensorValue,0,1023,0,3000);
    
    incrementButtonState = digitalRead(incrementButton);
    if (incrementButtonState == HIGH && lastIncrementButtonState == LOW){
        Serial.println("increase the stepCounter by 10");
        if (stepCounter < 30){
            stepCounter = stepCounter + 10;
            tone(piezo, freq_2);
            delay(100);
            noTone(piezo);
        }else{
            stepCounter = 10;
            tone(piezo,freq_1);
            delay(100);
            noTone(piezo);
            delay(100);
            tone(piezo,freq_1);
            delay(100);
            noTone(piezo);
        }
        Serial.print("stepCounter is ");
        Serial.println(stepCounter);
    }
    lastIncrementButtonState = incrementButtonState;
    
    if (lastDistance > 200 && currentDistanceMM < 200){
        Serial.println("decrease the stepCounter with one");
        stepCounter = stepCounter - 1;
        Serial.print("stepCounter is ");
        Serial.println(stepCounter);
        digitalWrite(ledCounter_1, LOW);
        digitalWrite(ledCounter_2, LOW);
        digitalWrite(ledCounter_3, LOW);
        tone(piezo,freq_2);
        delay(100);
        noTone(piezo);
        delay(100);
    }

    digitalWrite(ledCounter_1, LOW);
    digitalWrite(ledCounter_2, LOW);
    digitalWrite(ledCounter_3, LOW);

    if (stepCounter <= 0)
    {
        Serial.println("Woopwoop, you succeeded");
        tone(piezo,_____);
        delay(100);
        noTone(_____);
        delay(100);
        tone(piezo,_____);
        delay(200);
        noTone(_____);
        digitalWrite(_____, _____);
        digitalWrite(_____, _____);
        digitalWrite(_____, _____);
    }
    else
    {
        if (stepCounter > 0){
            digitalWrite(ledCounter_1, HIGH);
        }
        if (stepCounter > 10){
            digitalWrite(ledCounter_2, HIGH);
        }
        if (stepCounter > 20){
            digitalWrite(ledCounter_3, HIGH);
        }
    }
      lastDistance = currentDistanceMM;
}

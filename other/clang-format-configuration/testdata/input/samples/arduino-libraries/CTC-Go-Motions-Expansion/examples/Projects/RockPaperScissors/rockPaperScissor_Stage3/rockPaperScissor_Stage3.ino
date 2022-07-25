/*
  CTC GO! MOTION 
  PROJECT - ROCK PAPER SCISSOR

  This sketch is written to accompany Stage 3 of the ROCK PAPER SCISSOR project
*/

#include <Servo.h>

Servo servo_main;
Servo servo_wheel;

int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int piezo = 11;
int USsensor = A0;

int USvalue = 0;
float distance = 0;
int check = 0;
int randomNumber;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  servo_main.______(6);
  servo_wheel.______(9);
  
  servo_main.______(0);
  delay(10);

  Serial.begin(9600);
}

void loop()
{

  USvalue = analogRead(USsensor);
  distance = USvalue * 3;
  
  servo_wheel.______(80);
  delay(10);

  if (distance < 400) {
    check++;
    delay(400); 
    Serial.println(check);
  }

  if (check == 0) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }

  else if (check == 1) {
    digitalWrite(redLED, HIGH);
  }

  else if (check == 2) {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }

  else if (check == 3) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    tone(piezo, 500);
    delay(100);
    noTone(piezo);
    randomNumber = ______(1, 4); 
    delay(10);
    Serial.println(randomNumber);
    delay(100);
    check = 0;
    
    switch(____________)
    {
    case 1:
      servo_main.______(0);
      delay(1000);
      servo_wheel.______(93);
      delay(2000);
      servo_main.______(0);
      delay(2000);
    break;
    
    case 2:
      servo_main.______(80);
      delay(1000);
      servo_wheel.______(93);
      delay(2000);
      servo_main.______(0);
      delay(2000);
    break;
    
    case 3:
      servo_main.______(160);
      delay(1000);
      servo_wheel.______(93);
      delay(2000);
      servo_main.______(0);
      delay(2000);
    break;
    }
    
    ____________ = 0;
  }  
  
delay(250);
}
/*
  CTC GO! MOTION 
  PROJECT - ROCK PAPER SCISSOR

  This sketch is written to accompany Stage 5 of the ROCK PAPER SCISSOR project
*/

#include <Servo.h>

Servo servo_main;
Servo servo_wheel;

int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int piezo = 8;
int USsensor = A0;

int rock = 0;
int paper = 80;
int scissor = 160;

int USvalue = 0;
float distance = 0;
int check = 0;
int randomNumber;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  servo_main.attach(6);
  servo_wheel.attach(9);
  
  servo_main.write(0);
  delay(10);

  Serial.begin(9600);
}

void loop() {
  USvalue = analogRead(USsensor);
  distance = USvalue * 3;

  servo_wheel.write(80);
  delay(10);
  
  
  if (distance < 400) {
    check++;
    delay(400); 
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

  else if (check == 3)
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    tone(piezo, 500);
    delay(100);
    noTone(piezo);
    randomNumber = random(1, 4);
    Serial.println(randomNumber);
    delay(100);
    check = 0;

    switch(randomNumber)
    {
      case 1:
        ____________(rock);
      break;
    
      case 2:
        ____________(paper);
      break;
    
      case 3:
        ____________(scissor);
      break;
    }
    
    randomNumber = 0;
  }

  delay(250);
}

void ____________(int object)
{
      servo_main.write(______);
      delay(1000);
      
      servo_wheel.write(95);
      delay(2000);
      
      servo_main.write(0);
      digitalWrite(greenLED, LOW);
      delay(2000);
     
}
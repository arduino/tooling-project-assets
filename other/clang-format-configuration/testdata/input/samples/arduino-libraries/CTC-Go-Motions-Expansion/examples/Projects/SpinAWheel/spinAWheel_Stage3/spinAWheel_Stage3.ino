/*
  CTC GO! MOTION 
  PROJECT - Spin-A-Wheel

  This sketch is written to accompany Stage 3 of the Spin-a-Wheel project
*/

#include <Servo.h>

Servo servo_wheel;
Servo servo_pointer;

int button_1 = 2;
int button_2 = 3;

int yellowLED = 4;
int blueLED = 5;
int piezo = 8;

int buttonState_1;
int buttonState_2;

void setup()
{  
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  ______(yellowLED, ______);
  ______(blueLED, ______);
  ______(piezo, ______);

  servo_pointer.attach(6);
  servo_wheel.attach(9);

  Serial.begin(9600);
}


void loop()
{
  buttonState_1 = digitalRead(button_1);
  buttonState_2 = digitalRead(button_2);

  if(buttonState_1 == HIGH) {
    Serial.println("Button 1 pressed");
    servo_pointer.write(30);
    delay(10);
    servo_wheel.write(30); 
    ______(blueLED, HIGH);
    ______(yellowLED, LOW);
    tone(______, ______);
    delay(1000);
    noTone(______);

  }

  if(buttonState_2 == HIGH) {
    Serial.println("Button 2 pressed");
    servo_pointer.write(70);
    delay(10);
    servo_wheel.write(93);
    ______(blueLED, ______);
    ______(yellowLED, ______);
    tone(______, ______);
    delay(1000);
    noTone(______);
  }

  delay(100);
}









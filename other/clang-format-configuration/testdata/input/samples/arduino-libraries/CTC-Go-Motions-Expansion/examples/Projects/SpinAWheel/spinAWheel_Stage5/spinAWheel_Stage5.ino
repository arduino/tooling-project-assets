/*
  CTC GO! MOTION 
  PROJECT - SPIN-A-WHEEL

  This sketch is written to accompany Stage 5 of the SPIN-A-WHEEL project
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

int counter;

void setup() {
  
pinMode(button_1, INPUT);
pinMode(button_2, INPUT);

pinMode(yellowLED, OUTPUT);
pinMode(blueLED, OUTPUT);

servo_pointer.attach(6);
servo_wheel.attach(9);

Serial.begin(9600);

}

void loop() {

  buttonState_1 = digitalRead(button_1);
  buttonState_2 = digitalRead(button_2);

  if(buttonState_1 == HIGH)
  {
    Serial.println("Button 1 pressed");
    servo_pointer.write(30);
    delay(10);
    servo_wheel.write(30);
    delay(1000);
  } 

  if(buttonState_2 == HIGH) 
  {
    Serial.println("Button 2 pressed");
    servo_pointer.write(70);
    delay(10);
    servo_wheel.write(93);
    delay(1000);
    ____________();
  }

}

void ____________() {
  
  ______++;
  
  if(counter <= 2)
  {
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, LOW);
  }

  else if(counter == 3) 
  {
    ______();
    counter++;
    digitalWrite(blueLED, HIGH);
    digitalWrite(yellowLED, LOW);
  }

  else if(counter >= 4 && counter <= 6)
  {
    digitalWrite(blueLED, HIGH);
    digitalWrite(yellowLED, LOW);
  }

  else if(counter == 7) 
  {
    ______();
    ______ = 0;
    digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, HIGH);
  }

  delay(100);
}

void ______() {
    tone(______, 500);
    delay(300);
    ______(______);
    delay(300);
    
    tone(______, 1200);
    delay(500);
    ______(______);
    delay(300);
    
    tone(______, 200);
    delay(700);
    ______(______);
    delay(300);
}
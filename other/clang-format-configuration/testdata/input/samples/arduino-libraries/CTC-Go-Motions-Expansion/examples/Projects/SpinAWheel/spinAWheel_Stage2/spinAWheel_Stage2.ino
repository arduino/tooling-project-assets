/*
  CTC GO! MOTION 
  PROJECT - Spin-A-Wheel

  This sketch is written to accompany Stage 2 of the Spin-a-Wheel project
*/

#include <Servo.h>

______ servo_wheel;
______ servo_pointer;

int button_1 = 2;
int button_2 = 3;

int buttonState_1;
int buttonState_2;

void setup() {
  
pinMode(button_1, INPUT);
pinMode(button_2, INPUT);

servo_pointer.______(6);
servo_wheel.______(9);

Serial.begin(9600);

}

void loop() {

buttonState_1 = digitalRead(button_1);
buttonState_2 = digitalRead(button_2);

if(buttonState_1 == HIGH) {
  Serial.println("Button 1 pressed");
  servo_pointer.______(30);
  delay(10);
  servo_wheel.______(30);
  delay(1000);
}

if(buttonState_2 == HIGH) {
  Serial.println("Button 2 pressed");
  ______.______(70);
  delay(10);
  ______.______(93);
  delay(1000);
}

delay(100);
}
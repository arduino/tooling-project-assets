/*
  CTC GO! CORE MODULE 
  PROJECT 2 - CRAZY DJ

  This sketch is written to accompany Stage 2 in CRAZY DJ  of the CTC GO! core module
*/


int lightSensor = A0;
int ledPin = 10;
int piezo = 9;

int lightValue = 0;
int LEDvalue = 0;
int soundValue = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(_____, _____);
  Serial.begin(9600);
}

void loop()
{
  lightValue = analogRead(lightSensor);
  LEDvalue = map(lightValue, 0, 1023, 0, 255);
  analogWrite(ledPin, LEDvalue);

  soundValue = map(lightValue, _____, _____, _____, _____);
  _____(piezo, _____);
  delay(_____);
  _____(piezo);
  delay(_____);

  Serial.print("Light value: ");
  Serial.print(lightValue);
  Serial.print("    Sound frequence: ");
  Serial.println(soundValue);
  delay(100);
}

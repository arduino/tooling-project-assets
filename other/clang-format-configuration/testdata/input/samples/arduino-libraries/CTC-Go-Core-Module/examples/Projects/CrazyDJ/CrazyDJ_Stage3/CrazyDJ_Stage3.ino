/*
  CTC GO! CORE MODULE 
  PROJECT 2 - CRAZY DJ

  This sketch is written to accompany Stage 3 in CRAZY DJ  of the CTC GO! core module
*/

int lightSensor = A0;
int on_pot = A1;
int off_pot = A2;
int ledPin = 10;
int piezo = 9;

int lightValue = 0;
int LEDvalue = 0;
int soundValue = 0;
int onTime = 0;
int offTime = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  lightValue = analogRead(lightSensor);
  LEDvalue = map(lightValue, 0, 1023, 0, 255);
  analogWrite(ledPin, LEDvalue);

  onTime = _____;
  offTime = _____;

  soundValue = map(lightValue, 0, 1023, 31, 4000);

  tone(piezo, soundValue);
  delay(_____);
  noTone(piezo);
  delay(_____);

  Serial.print("Light value: ");
  Serial.print(lightValue);
  Serial.print("    Sound frequence: ");
  Serial.println(soundValue);
  Serial.print("Time ON: ");
  Serial.print(_____);
  Serial.print("   Time OFF: ");
  Serial.println(_____);

  
}

/*
* Basketball
* 
* Score a goal!
* 
* In this game, players will try to bounce a ping pong ball 
* into a cup. Make five points to win. The score is tracked 
* using a LightSensor.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>
#include "pitches.h"
/*
An array of pin numbers to which LEDs are attached
the defaults are 2 to 6 but you can choose any of the digital pins
*/
int ledPins[] = {2, 3, 4, 5, 6};
int pinCount = 5;
VUMeter vuMeter;

Melody piezo = Melody(8); // the piezo connected to digital pin 8
LightSensor sensor = LightSensor(A1); //the LightSensor connected to analog pin 1

int score = 0;

void setup(){
  //if your are using other pins than 2 to 6 you need to configure that here
  vuMeter.config(pinCount, ledPins);
  vuMeter.begin(); //does the same as pinMode, LEDs are outputs

  sensor.config(800, 600); //first run the LightSensorTest example to see what values you need to put here
}

void loop(){
  //if the LightSensor is covered the score increases with 1
  //and a sound is played
    sensor.pressed();
    score++;
    vuMeter.fill(score); //Turn on as many LEDs as the score

    int melody[] = { NOTE_GS4, NOTE_C5};
    int noteDurations[] = { 8, 8};
    int numberOfNotes = 2;
    piezo.play(numberOfNotes, melody, noteDurations, 1);

    delay(50);

  if(score>=pinCount) startOver(); //If the score equals the amount of LEDs you start over
}


void startOver(){
  score=0; //reset the score

  int melody[] = { NOTE_C5, NOTE_G4,NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5};
  int noteDurations[] = { 4, 8, 8, 4,4,4,4,4 };
  int numberOfNotes = 8;
  piezo.play(numberOfNotes, melody, noteDurations, 1);

  vuMeter.blinkAll(50,10);

}


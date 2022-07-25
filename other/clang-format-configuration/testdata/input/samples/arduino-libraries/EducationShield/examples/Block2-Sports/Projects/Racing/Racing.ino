/*
* Racing
* 
*  Run with your fingers as fast as you can.
* 
* In this game, the player must tap two sensors repeatedly 
* in order to run laps. One LED will light up per lap. 
* When all laps are completed, LEDs will blink in victory. 
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

/*
  An array of pin numbers to which LEDs are attached
  the defaults are 2 to 6 but you can choose any of the digital pins
  just remember to leave digital pin 2,3 and 4 for the capacitive switches
*/
int ledPins[] = {8, 9, 10, 11, 13};
int pinCount = 5;
//This variable will let us keep track of which LED to turn on
int LED = 0;
VUMeter scoreBoard;

//Configure the capacitive sensors
int capacitiveSensorThreshold=400;
CapacitiveSwitch leftFoot=CapacitiveSwitch(2,3);
CapacitiveSwitch rightFoot=CapacitiveSwitch(2,4);

int score;

void setup(){
  //initializing the game, set up all the components and variables
  score=0;

  //Connect scoreboard
  scoreBoard.config(pinCount,ledPins);
  scoreBoard.begin();

  //initialize left and right "foot"
  leftFoot.config(capacitiveSensorThreshold);
  rightFoot.config(capacitiveSensorThreshold);
}

void loop(){
  //Wait for the left foot to be pressed
   leftFoot.pressed();
   scoreBoard.on(LED);
  
  //Wait for the right foot to be pressed
  rightFoot.pressed();
  scoreBoard.off(LED);
  
  score=score+1; //After both feet are pressed, add one point
  
  //Every 20 points light up a LED
  LED =score/20;
  scoreBoard.fill(LED);
  
 //When you get 100 points, you win
  if(score>100){
    //if you win, blink all LEDs for celebration
    //See vuMeter in reference list to make your own blink animation
    scoreBoard.blinkAll(50,5);
    //and reset the game
    score=0;
  }
}

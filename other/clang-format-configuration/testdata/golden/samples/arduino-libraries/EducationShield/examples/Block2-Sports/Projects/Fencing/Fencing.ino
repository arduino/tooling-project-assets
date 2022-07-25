/*
* Fencing
* 
*   Test your reaction time against an opponent!
* 
* In this game, two players will hold tilt switch swords. 
* When the green LED randomly lights up, the first person 
* to swing their sword wins. 
*
* (c) 2013-2016 Arduino LLC.
*/


#include <EducationShield.h>

//Position of the LEDs in VU-meter is represented
//by their names here. So we can use names to find LEDs later
#define YELLOW_LED_1 0
#define GREEN_LED 1
#define RED_LED 2
#define YELLOW_LED_2 3

//An array stores which pins the VU-meter is connected
int ledPins[]={2,3,4,5};
//How many pins are used by VU-meter
int pinCount=4;
VUMeter lights;

TiltSwitch player_1 = TiltSwitch(6);
TiltSwitch player_2 = TiltSwitch(9);

void setup(){
  lights.config(pinCount,ledPins);

  //Initializing components
  lights.begin();
  player_1.begin();
  player_2.begin();

  //We need this for generating random numbers later
  randomSeed(analogRead(0));
}
void loop(){
 lights.clear();

 //Red LED means both of you should hold the tilt switch sword up right
 lights.on(RED_LED);

 //Wait for a random period of time, between 3 seconds
 //And 6 seconds. Get ready!
 delay(random(3000,6000));

 lights.off(RED_LED);
 //When the green LED turns on, game starts
 lights.on(GREEN_LED);

 //Swing your swords as fast as you can, the faster one 
 //will be returned by getWinner()
 int winner=getWinner();

 //The yellow LED on the side of the winner will light up
 if(winner==1){
   lights.on(YELLOW_LED_1);
 }else{
   lights.on(YELLOW_LED_2);
 }
 delay(5000);
}

//The function below waits for either of the tilter
//switch to be swung. The first one to swing
//will be returned by its number
int getWinner(){
  do{
    if(player_1.pressed(1)){
      return 1;
    }else if(player_2.pressed(1)){
      return 2;
    }
  }while(true);
}

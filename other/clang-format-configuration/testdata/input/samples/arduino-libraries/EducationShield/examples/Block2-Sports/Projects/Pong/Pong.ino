/*
* Pong
* 
* Play a simplified version of the classic arcade game, Pong!
* 
* In this game, a “pong” will move across five LEDs (VU-meter) 
* and bounce back and forth as players press the button. 
* Players must press the button at the right time in order to 
* return the pong. 
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>
/*
  An array of pin numbers to which LEDs are attached
  the defaults are 2 to 6 but you can choose any of the digital 
  pins. Just remember to leave digital pin 9 and 6 for the buttons.
*/
int ledPins[] = {2, 3, 4, 5, 7};
int pinCount = 5;
VUMeter vuMeter;

Button button1 = Button(9); //the button connected to digital pin 9
Button button2 = Button(6); //the button connected to digital pin 6

int ledTime = 100; //determines how fast the LEDs will switch
int pressTime = 200; //determines how long time a player has to press the button
int buttonNotPressed = 0; //this keeps track of who missed pressing the button

void setup(){
  //if you are using other pins than 2 to 6 you need to configure that here
  vuMeter.config(pinCount, ledPins);

  vuMeter.begin(); //does the same as pinMode, LEDs are outputs
  button1.begin(); //does the same as pinMode, buttons are inputs
  button2.begin(); //does the same as pinMode, buttons are inputs

  vuMeter.scrollLeft(ledTime, 1); //The game starts by scrolling the LEDs to the left
}

void loop(){
  /*
  if button1 is pressed within the press time, the game will continue
  by scrolling the LEDs to the right
  else if button1 is not pressed, the program will jump to gameOver()
  */
  if(button1.released(pressTime)){
    vuMeter.scrollRight(ledTime, 1);
  }
  else{
    buttonNotPressed = 1; //Keep track of where we are in the game
    gameOver();
  }

  /*
  if button2 is pressed within the press time, the game will continue
  by scrolling the LEDs to the left
  else if button2 is not pressed, the program will jump to gameOver()
  */
  if(button2.released(pressTime)){
    vuMeter.scrollLeft(ledTime, 1);
  }
  else{
    buttonNotPressed = 2; //Keep track of where we are in the game
    gameOver();
  }
}

/*
  When a player doesn't press the right button within the right
  time it is game over. Inside the function gameOver() you can 
  decide how the LEDs should blink. 
  Use vuMeter.blink(LED,delayTime,numberOfBlinks) to make one specific LED blink
  Use vuMeter.blinkAll(delayTime,numberOfBlinks) to make all LEDs blink
*/
void gameOver(){
  vuMeter.blinkAll(100,10);

  if(buttonNotPressed==1) vuMeter.scrollRight(ledTime, 1); //if button1 was not pressed, scroll LEDs to the right to start over
  else if(buttonNotPressed==2) vuMeter.scrollLeft(ledTime, 1); //if button2 was not pressed, scroll LEDs to the left to start over
}

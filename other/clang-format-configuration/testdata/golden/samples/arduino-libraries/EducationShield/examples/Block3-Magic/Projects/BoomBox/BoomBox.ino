/*
* BoomBox
* 
* This is your first step towards these kinds of skills:
* http://www.youtube.com/watch?v=FcJCxe1VSLA&noredirect=1
* The boom box is a small sample player you can use to make music, 
* or just random sound. It comes with three prerecorded samples 
* but we probably don’t have the same creative cleverness when it
* comes to recording as you do so you should definitely record your 
* own samples too! 
* 
*  (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declare a button group with 3 buttons. The
//sound player secretly takes pin 3, 4 and 11,
//so don't use them.
ButtonGroup bg;
int buttons[]={5,6,7};

//There're 3 buttons in the button group.
int buttonsCount=3;

//Declare the sound player
Player player=Player();

void setup(){
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  // Initialize the sound player. Open the Serial Monitor to see
  //the sound files found on your micro SD card
  player.begin();

  //Initialize the button group.
  bg.begin(buttonsCount,buttons);
}

void loop(){
  //Wait for one of the buttons to be pressed.
  //According to which button is pressed, it
  //returns either 0, 1 or 2
  int pressedButton=bg.pressed();

  //Play a different sound according to the
  //button pressed.
  switch(pressedButton){
    case 0:
      Serial.println("sound 0");
      player.play("0.wav");
      break;
    case 1:
      Serial.println("sound 1");
      player.play("1.wav");
      break;
    case 2:
      Serial.println("sound 2");
      player.play("2.wav");
      break;
  }

}


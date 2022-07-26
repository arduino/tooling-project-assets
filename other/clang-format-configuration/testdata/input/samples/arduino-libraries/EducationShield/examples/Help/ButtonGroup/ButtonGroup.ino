/*  
*  ButtonGroup
* ButtonGroup is used for making a few buttons work together.
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declaring the button group
ButtonGroup bg;

//Declaring the pins to which the buttons are connected
int buttons[]={4,5,6};

void setup(){
  Serial.begin(9600);

  while(!Serial);
  
  //initialize the button group. The first parameter is
  //number of buttons, the second is the array containing
  //pins used by these buttons.
  bg.begin(3,buttons);
}
void loop(){
  Serial.println("Please press a button");
  //pressed(timeout)
  //  timeout:milliseconds within which one button should
  //          be pressed. If pressed within time, the function
  //          returns number of the button within initial list.
  //          Otherwise -1. If not used, it waits until being
  //          pressed.
  //
  //Wait until one button is pressed.
  Serial.println(bg.pressed());
  delay(10);
}

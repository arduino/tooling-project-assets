/*  
* Button
* A button is a digital input. This means that it can have two 
* states, either HIGH (5 V in Uno, 3 V in 101) or LOW (0 V). When 
* you connect a button to your control board you can read these 
* states as 1 or 0. 
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declare the button component.
//6 is the pin number. If it's a button module, use 6 or 9.
//HIGH can be ignored mostly, which means when the button is
//pressed, what state it is in.
Button me=Button(6,HIGH);

void setup(){
  Serial.begin(9600);

  while(!Serial);

  //Initialize the component. Must be called.
  me.begin();
}
void loop(){
  Serial.println("Please press...");
  //pressed(timeout)
  //  timeout: milliseconds within which the button should
  //    be pressed. If pressed within time, the function
  //    returns 1, otherwise 0. If not used, it waits
  //    until being pressed.
  //
  //Wait until the button is pressed.
  Serial.println(me.pressed());


  Serial.println("Please release...");
  //released(timeout)
  //  timeout: same as in pressed(timeout).
  //
  //Wait until the button is released.
  Serial.println(me.released());

  Serial.println("Press a few times...");
  //beenPressed()
  //
  //Check if the button has been pressed without blocking the
  //sketch execution. Useful when press detection is not part
  //of the main program logic.
  long timer=millis();
  int counter=0;
  while(millis()-timer<3000){
    if(me.isPressed()){
      counter++;
    }
  }
  Serial.println(counter);
}

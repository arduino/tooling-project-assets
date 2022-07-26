/*  TiltSwitch
*
*  Tilt Switch is a component that detects if it’s right side up
*  or tilted.
*
*  (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declare the tilt switch. A tilt switch module can be
//connected to D6 or D9 (We use D9 here).
TiltSwitch me=TiltSwitch(9);

void setup(){
  Serial.begin(9600);

  while(!Serial);
  
  //Initialize the component. Must be called.
  me.begin();
}
void loop(){
  Serial.println("Please tilt...");

  //pressed(timeout)
  //	timeout: milliseconds within which the tilt switch should
  //		be tilted. If tilted within time, the function
  //		returns 1, otherwise 0. If not used, it waits
  //		until being pressed.
  //
  //Wait until the tilt switch is tilted.
  Serial.println(me.pressed());

}

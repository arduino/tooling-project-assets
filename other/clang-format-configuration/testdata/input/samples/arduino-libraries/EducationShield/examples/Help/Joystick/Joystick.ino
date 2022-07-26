/*	Joystick
*       The joystick is one component but uses two analog sensors and 
*       gives you two values. One x value and one y value. The value 
*       for each direction is zero if it’s in the middle, -1 on one side 
*       and 1 on the other side. 
*
*       (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//The joystick uses two analog pins. One for X and one for Y.
Joystick me=Joystick(A1,A0);

void setup(){
  //Start serial communication to be able to print values to the Serial Monitor
  Serial.begin(9600);
}
void loop(){
  Serial.print("X: ");
  Serial.print(me.getX()); //Get the X value and print it.
  Serial.print("  Y: ");
  Serial.println(me.getY()); //Get the Y value and print it.
  delay(200);
}

/*	ContinuousServo
*
*	Continuous servo looks the same as a standard servo, but it's
*	capable of rotating continuously like a normal motor. You can not
*	control which angle it's pointing to, but you can specify how
*	fast it spins, and which direction it spins.
*
*       To control two servos as wheels on a vehicle please see the 
*       example Wheels in the Help folder.
*
*       (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

Servo me;

void setup(){
  //Servo is initialized, 
  //in this example connected to digital pin 9
  me.attach(9);
}

void loop(){
  //write(speed):
  //	speed: the speed in which you want to rotate
  //	the servo. It is ranged between 0 and 180.
  //    180 is fastest speed in one direction and 0 
  //    fastest speed in the opposite direction. 
  //    90 should make it stand still. This exact 
  //    value is slightly different for each servo.
  //
  //Make the servo rotate in speed 120.
  me.write(120);

}

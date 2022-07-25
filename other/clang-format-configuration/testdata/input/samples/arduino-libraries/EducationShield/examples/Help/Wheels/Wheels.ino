/*
* Wheels
*
* If you ever want to use two continuous rotation servos as a pair
* of wheels we've made it easy for you. 
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Wheels(left, right)
//  Declares the wheels.
//  left: the digital pin where you connect the left wheel
//  right: the digital pin where you connect the right wheel
Wheels wheels=Wheels(6, 9);

void setup(){
  //Initialize the servo wheels
  wheels.begin();
}

void loop(){
  //Makes the wheel spin forward
  wheels.goForward();
  delay(2000);
  
  //Makes the wheels spin backwards
  wheels.goBackwards();
  delay(2000);
  
  //Makes the wheels spin in opposite direction so that
  //the vehicle will spin left
  wheels.turnLeft();
  delay(2000);
  
  //Makes the wheels spin in opposite direction so that
  //the vehicle will spin right
  wheels.turnRight();
  delay(2000);
  
  //Makes the wheels stop
  wheels.standStill();
  delay(2000);
}

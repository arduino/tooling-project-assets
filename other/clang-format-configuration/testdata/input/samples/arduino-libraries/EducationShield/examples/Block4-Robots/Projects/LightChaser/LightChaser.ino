/*
* LightChaser
*
* This little vehicle is on an impossible, never ending 
* mission to catch the light. You can make it follow you 
* by pointing a flashlight at it. (The one on your mobile 
* phone eg.) It will always turn towards the light. 
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declare the two wheels of robot, left wheel to D6 and
// right wheel to D9
Wheels wheels=Wheels(6, 9);

//Declare the two LightSensor
LightSensor sensorLeft=LightSensor(A0);
LightSensor sensorRight=LightSensor(A2);

void setup(){
  //initialize the LightSensor
  sensorLeft.config(600,800);
  sensorRight.config(600,800);

  //initialize the servo motors
  wheels.begin();
}
void loop(){
  if(sensorLeft.getState()){
	//Left LightSensor detects strong light, the vehicle turns left
    wheels.turnLeft();
  }else if(sensorRight.getState()){
	//Right LightSensor detects strong light, the vehicle turns right
    wheels.turnRight();
  }else{
	//No strong light detected, the vehicle goes straight
    wheels.goForward();
  }
}

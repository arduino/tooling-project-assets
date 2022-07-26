/*
* CrawlingRobot
* 
* This small robot can crawl. It’s all it can do, and it isn’t 
* very good at it. But it is super cute and great fun. 
*
*  (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

Servo front, back;

void setup(){
  //servos are initialized
  front.attach(6);
  back.attach(9);
}

void loop(){
  //Make the robot crawl by setting the servos to opposite angles.
  //90 is the middle angle
  
  //First step of each pair of legs
  front.write(110);   
  delay(200);
  back.write(70);
  delay(200);

  //Second step of each pair of legs
  front.write(70);
  delay(200);
  back.write(110);
  delay(200);
}

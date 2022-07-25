/*
* CameraRobot
* 
* Spy on your cat with this robot camera. Mount the camera robot and
* control it with a small joystick. You can run everything from the
* computer and when you see your cat doing something suspicious, 
* take a picture! 
* 
* You need to run the processing sketch included in the sketch folder
* to be able to take photos with a webcam connected to your computer.
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//The joystick uses two analog pins. Here pin A0 and A1
Joystick joystick = Joystick(A1,A0);//Joystick(XanalogPin, YanalogPin)

Servo pan, tilt;

int panAngle = 90; //Pan angle starts in the middle position
int tiltAngle = 90; //Tilt angle starts in the middle position

int panJoystick = 0;
int tiltJoystick = 0;

void setup(){
  //servos are initialized
  pan.attach(6);
  tilt.attach(9);
}
void loop(){
  panJoystick = joystick.getX(); //Get X value from joystick
  tiltJoystick = joystick.getY(); //Get Y value from joystick

  //If the joysticks X value isn't 0 we will pan
  if(panJoystick!=0){
    //If the X value from the joystick equals 1 and
    //panAngle is less than 180 degrees, increase panAngle with 1
    if(panJoystick==1 && panAngle<180) panAngle++;
    //If the X value from the joystick equals -1 and
    //panAngle is more than 0 degrees, decrease panAngle with 1
    else if(panJoystick==-1 && panAngle>0) panAngle--;
  }
  //If the joysYicks Y value is 0 we will tilt
  if(tiltJoystick!=0){
    //If the Y value from the joystick equals 1 and
    //tiltAngle is less than 180 degrees, increase tiltAngle with 1
    if(tiltJoystick==1 && tiltAngle<180) tiltAngle++;
    //If the Y value from the joystick equals -1 and
    //tiltAngle is more than 0 degrees, decrease tiltAngle with 1
    else if(tiltJoystick==-1 && tiltAngle>0) tiltAngle--;
  }
  pan.write(panAngle); //Set position of the pan servo
  tilt.write(tiltAngle); //Set position of the tilt servo
  delay(5);
}

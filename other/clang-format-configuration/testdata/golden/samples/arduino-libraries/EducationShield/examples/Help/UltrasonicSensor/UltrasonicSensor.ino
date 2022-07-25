/*
* Ultrasonic Sensor
* An ultrasonic sensor is used to detect the distance to the 
* closest object in front of the sensor. It uses ultrasound, 
* sound with a frequency higher than humans can hear. As you 
* probably know, sound can reflect from surfaces creating an 
* echo. This echo is what the sensor uses to estimate the 
* distance. The sensor sends out a burst of ultrasound and 
* then waits for the echo. By knowing the speed of sound and 
* the time between the burst and the detection we can  
* calculate the distance. The shorter time it takes to detect 
* the echo, the closer the object is. 
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declare the ultrasonic sensor with the trigger pin connected to
// digital pin 11, and the echo pin to digital pin 12.
UltrasonicSensor us = UltrasonicSensor(11, 12);

void setup(){  
  //Initialize the serial communication
  Serial.begin(9600); 
}

void loop(){
  //Get the distance in cm
  int distance = us.getDistance();
  
  //Print out the distance to the Serial Monitor
  Serial.println(distance);
  delay(100);
}

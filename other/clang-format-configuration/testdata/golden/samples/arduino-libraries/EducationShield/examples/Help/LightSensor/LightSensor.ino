/*
* LightSensor
*
* LightSensor is a sensor that reads the intensity of light. 
* It gives analog reading. When connected with analog 
* pins, its value ranges from 0 to 1023 depending on the amount 
* of light shining on it. 
*
* The EducationShield library includes some features for 
* using the LightSensor as a button, or get values directly. See 
* the example LightSensorTest for more information about how to 
* configure it correctly. 
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Phototransistor component is connected to analog 1.
LightSensor sensor = LightSensor(A1);

void setup(){

  Serial.begin(9600);

  //LDR needs to be configured with baseValue
  //and threshold. See LightSensorTest sketch for
  //details.
  sensor.config(700,900);
}

void loop(){
  Serial.println("Please press...");

  //pressed(timeout)
  //	timeout: milliseconds within which the
  //		phototransistor should be cover-uncovered. If
  //		cover-uncovered within time, the
  //		function returns 1, otherwise 0. If
  //		not used, it waits until being
  //		cover-uncovered.
  //
  //Wait until the phototransistor gets cover-uncovered.
  Serial.println(sensor.pressed());

  Serial.println("Please release...");

  //released(timeout)
  //	timeout: same as in pressed(timeout).
  //
  //Wait until the phototransistor gets uncover-covered.
  Serial.println(sensor.released());


  while(true){
  //getState()
  //	returns whether the sensor readings has
  //	passed the threshold. Returns true if the
  //	threshold has been passed, false if not.
  //	Unlike pressed or released, this function
  //	does not stop the whole program.
  //
  //Continuously output whether the sensor has
  //passed threshold.
	Serial.println(sensor.getState());
	delay(30);
  }

}

/* 
* Piezo Knock Sensor
* Piezo can play music, as well as be used as knock sensor.
*
* Connect the red pin of the piezo to a 1M ohm resistor, 
* and the resistor to an analog pin (A5 in this example), 
* the other pin to GND. Connect a 3.3 V Zener diode in 
* parallel to the piezo and resistor circuit, with its 
* anode to GND, cathode to A5.
*       
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Remember: Piezo as speaker is connected to digital pin
//while piezo as knock sensor is connected to analog pin.
PiezoKnockSensor sensor=PiezoKnockSensor(A0);

void setup(){
  Serial.begin(9600);

  while(!Serial);
  
  //define the threshold and debounce time of the knock
  //sensor. Threshold defines how hard you need to knock,
  //debounce time prevents the sensor from returning several
  //hits from one knock, but also limits how rapid you can knock.
  sensor.config(120,80);

}
void loop(){
  Serial.println("Please knock...");

  //knocked(timeout)
  //	timeout: milliseconds within which the sensor should
  //		be knocked. If knocked within time, the function
  //		returns 1, otherwise 0. If not used, it waits
  //		until being knocked.
  //
  //Wait until the button is knocked.
  Serial.println(sensor.knocked());
}

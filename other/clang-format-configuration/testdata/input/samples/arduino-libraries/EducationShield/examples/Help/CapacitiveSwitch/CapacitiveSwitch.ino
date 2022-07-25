/*	CapacitiveSwitch
*
*	CapacitiveSwitch can be constructed in various ways.
*	Typically a 1 million ohm resistor between sender pin
*	and receiver pin(we use 2 as sender, 3 as receiver
*	here), and conductive material connected to the receive
*	pin.
*
*	When you touch the conductive material with your hand, or
*	other objects (should be conductive), the sensor will
*	get a different reading.
*
*	The library includes some features for using the
*	capacitive sensor as a button, or getting values directly.
*
*       (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//The sensor is connected between 2 and 3 by default
CapacitiveSwitch me=CapacitiveSwitch(2,3);

void setup(){
  Serial.begin(9600);

  while(!Serial);

  //Config the sensor, set threshold for the sensor used as
  //button. If sensor reading passes it, it's counted as
  //being pressed/released
  me.config(400);
}
void loop(){
  Serial.println("Please press...");
  //pressed(timeout)
  //	timeout: milliseconds within which the sensor should
  //		be pressed. If pressed within time, the function
  //		returns 1, otherwise 0. If not used, it waits
  //		until being pressed.
  //
  //Wait until the capacitive sensor is pressed.
  Serial.println(me.pressed());

  delay(1000);

  Serial.println("Please release...");
  //released(timeout)
  //	timeout: same as in pressed(timeout).
  //
  //Wait until the capacitive sensor is released.
  Serial.println(me.released());

  do{
	//getValue(minimum)
	//	minimum: minimum value that needs to be returned. If
	//		the sensor reading is smaller than minimum, it'll
	//		return 0.
	//
	//Print values bigger than 20. Print 0 otherwise.
	Serial.println(me.getValue(20));
  }while(true);
}

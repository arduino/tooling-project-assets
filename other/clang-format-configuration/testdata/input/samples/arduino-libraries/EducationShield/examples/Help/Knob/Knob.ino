/*  
* Knob
*
* The Knob class is used for working with potentiometers. It provides
* functionalities to divide the raw value into a set amount of levels,
* which is helpful when a set of options are picked by the level of 
* the knob.
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

Knob pot=Knob(A5);//a knob is connected to A5

void setup(){
  Serial.begin(9600);

  //setLevels(levels)
  //  levels: the amount of levels needed. So the possible output of the 
  //  knob will be between 0 and levels
  //
  //Initializing the knob with total number of levels
  pot.setLevels(10);
  
}

void loop(){
  //getValue()
  //
  //Return the current reading of the knob. Same as analogRead()  
  int a = pot.getValue();

  //getLevel()
  //
  //Return the current level. It ranges between 0 and the max levels, as 
  //pre-configured by Knob.setLevels().
  int b = pot.getLevel();
  
  Serial.print("Analog: ");
  Serial.print(a);
  Serial.print("  Level: ");
  Serial.println(b);
  
  delay(100);

}

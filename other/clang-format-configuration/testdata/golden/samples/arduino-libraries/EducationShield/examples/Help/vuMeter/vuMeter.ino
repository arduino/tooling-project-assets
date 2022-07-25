/*	
* VU-Meter
*  VU-Meter is a few LEDs grouped together into a line.
* 
* This library has some features that makes it easy to control 
* several LEDs. Functions to use are:
* 
*     clear() - turns all LEDs off.
*     on(LEDindex) - turns one LED on
*     off(LEDindex) - turns one LED off
*     scrollRight(speed, startIndex) - one LED lights up at a time from left to right
*     scrollLeft(speed, startIndex) - one LED lights up at a time from right to left
*     blink(LEDindex,speed, times) - one LED blinks
*     blinkAll(speed, times) - all LEDs blink
*     fillFrom(startIndex, stopIndex) - turns LEDs from startIndex to stopIndex on
*     fill(numberOfLEDs) - turns LEDs on from first to numberOfLEDs 
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//Declare the VUMeter
VUMeter me;

//The pins used by the VUMeter, default to 2-5 and 7. Can be
//customized as you wish, but do change the pinCount if the
//number of LEDs are changed.
int pins[]={2,3,4,5,7};

//How many pins are used. Should reflect the pins array above.
int pinCount=5;

void setup(){
  //Configure the VU meter using parameters defined previously.
  me.config(pinCount,pins);

  //initialize the component. Must be called.
  me.begin();

}
void loop(){
  //fill(number)
  //  number: how many LEDs from first pin shall be turned on
  //
  //Fill 5 LEDs
  me.fill(5);
  delay(3000);

  //clear()
  //
  //turn all the LEDs off
  me.clear();
  delay(1000);

  //on(index)
  //  index: which LED being turned on
  //
  //Turn the 3rd LED on
  me.on(2);
  delay(1000);

  //off(index)
  //  index: which LED being turned off
  //
  //Turn the 3rd LED off
  me.off(2);
  delay(1000);

  //scrollRight(speed, startIndex)
  //  speed: milliseconds before the next LED turns on
  //  startIndex: from which LED to the left it starts
  //     scrolling. If not specified, it's 1.
  //
  //One LED lights up at a time, scrolling from left to right
  me.scrollRight(700);

  //scrollLeft(speed, startIndex)
  //  speed: milliseconds before the next LED turns on
  //  startIndex: from which LED TO THE RIGHT it starts
  //     scrolling. If not specified, it's 1.
  //
  //And then scroll back from the 2nd on the right
  me.scrollLeft(700,1);

  //blink(index, speed, times)
  //  index: which LED should blink
  //  speed: milliseconds, of which the LED lights on and off
  //  times: how many times the LED blinks. Defaults to 1
  //
  //the 3rd LED will be blinking 10 times, each time
  //with 100 milliseconds on and 100 milliseconds off
  me.blink(2,100,10);

  //blinkAll(speed, times)
  //  speed: milliseconds, of which all LEDs light on and off
  //  times: how many times the LED blinks. Defaults to 1
  //
  //All LEDs will be blinking 10 times
  me.blinkAll(100,10);

  //fillFrom(leftIndex,rightIndex)
  //  leftIndex: start filling from which LED
  //  rightIndex: end filling to which LED
  //
  //The 2nd to 4th LED will light up
  me.fillFrom(1,3);
  delay(2000);

}

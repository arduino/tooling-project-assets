/*  
* Drawdio
*
* Draw audio with drawdio. You might think that this pen is magic,
* and it might just be. Drawdio turns (almost) everything that is
* conductive into an instrument. You can either make music by
* drawing a picture or by touching the tip of it to different
* conductive things around you. 
* 
* (c) 2013-2016 Arduino LLC.
* Inspiration from Jay Siver's DRAWDIO
* http://web.media.mit.edu/~silver/drawdio/
*
*/

#include <EducationShield.h>
#include "pitches.h"

//Capacitive switch connected between 2 and 3
CapacitiveSwitch me=CapacitiveSwitch(2,3);

//A piezo speaker connected to digital pin 8
Melody speaker=Melody(8);

//The range of capacitive sensor values to be
//mapped to music tones. See example
//"Help/CapacitiveSwitchTest" for how to get
//the values
int lowerThreshold=80;
int upperThreshold=900;

//Define the lowest and highest tone. Defined
//in pitches.h
int toneLow=NOTE_C3;
int toneHigh=NOTE_B6;

void setup(){
  //Nothing to do here. Magic?
}
void loop(){
  //Get value of the sensor. If it's smaller
  //than the threshold, it'll be 0
  int value=me.getValue(lowerThreshold);

  //map the sensor value to tones. The map()
  //function maps values smaller than lower
  //threshold to the lowest desired value. If
  //you want to keep drawdio quiet when you're
  //not playing, you have to deal with 0 separately
  int pitch;
  if(value>0){
    pitch=map(value,lowerThreshold,upperThreshold,toneLow,toneHigh);
  }else{
    pitch=0;
  }

  //Play the tone to the speaker.
  speaker.playTone(pitch,10);
}

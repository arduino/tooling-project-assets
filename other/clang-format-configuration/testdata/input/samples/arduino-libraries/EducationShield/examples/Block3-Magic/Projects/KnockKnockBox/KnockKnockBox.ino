/*
* KnockKnockBox
* 
* Knock on this coffin to awake the dead. Don’t worry, 
* the skeleton won’t get out and come after you but it 
* will reply from inside.
* 
* Ok, we know that you know that there isn’t a real 
* skeleton there. It's really a piezo used as a knock 
* sensor. After you've made this project you might 
* think of a handy way to use this sensor in other ways. 
* Check out this secret knock detecting lock for some 
* inspiration: http://www.youtube.com/watch?v=zE5PGeh2K9k 
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

//The number of knocks that can be recorded
#define MAX_KNOCKS 30

PiezoKnockSensor sensor=PiezoKnockSensor(A0);
int speaker = 8;

//An array for remembering the knock pattern
long timer[MAX_KNOCKS];

//If it has started recording
boolean started;

//Used for calculating if you have finished the pattern
long timeoutBase;

//If you stop knocking for the period of timeout, it'll
//stop recording
long timeout=2000;

//Keep track of the number of knocks you've knocked
int currentKnock;

void setup(){
  //define the threshold and debounce time of the knock
  //sensor. Threshold defines how hard you need to knock,
  //debounce time prevents the sensor from detecting
  //false knocks, but also limits how rapid you can knock.
  sensor.config(100,80);

  //initializing the values
  started=false;
  timeoutBase=0;
  currentKnock=0;
  clearArray();
}

void loop(){
  //Knock sensor waits for a short time if a knock is detected
  //and then move on.
  if(sensor.knocked(20)){
    //If it's the first knock in the round, start recording
    if(!started){
      started=true;
    }

    long currentTime=millis();
    //Reset timeout
    timeoutBase=currentTime;
    //Save the amount of milliseconds that have 
    //passed since the last knock
    timer[currentKnock]=currentTime;
    currentKnock++;
  }
  if(started){
    //If recording has started and you stop
    //knocking for the time of "timeout", it'll
    //stop recording and play it back to you.
    if(millis()-timeoutBase>timeout){
      playback();
      //reset the parameters, so a new round begins
      started=false;
      clearArray();
      currentKnock=0;
    }
  }
}
void clearArray(){
  //clean up values in the timer array
  for(int i=0;i<MAX_KNOCKS;i++){
    timer[i]=0;
  }
}
void playback(){
  //Play the knock pattern back to you through the
  //speaker piezo
  for(int i=0;timer[i]!=0;i++){
    //Make a beep sound with tone 200 for 30 milliseconds
    tone(speaker, 200, 30);
    if(timer[i+1]){
      //Wait the same amount of milliseconds that was detected
      //between the knocks
      delay(timer[i+1]-timer[i]);
    }
  }
}

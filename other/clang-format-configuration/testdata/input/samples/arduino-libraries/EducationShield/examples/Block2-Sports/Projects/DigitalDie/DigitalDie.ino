/*
* DigitalDie
* 
*   Use this digital die next time you play a board game. 
*
* You "throw" the die by shaking a tilt sensor. The LEDs 
* will show different numbers, waiting a longer and longer 
* time for each number, until it finally stops. Don't be 
* too fast to cheer believing it stopped on your desired 
* number or you might get disappointed ...
*
* (c) 2013-2016 Arduino LLC.
*/
 
#include <EducationShield.h>

//declare the pins used for LEDs, 9 LEDs in total
int pinCount=9;
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 11, 13};

/*
declare the tilt switch, it's connected to TinkerKit 
port 9
*/
TiltSwitch ts=TiltSwitch(9);

/*
  Define the patterns of die values. Each pattern is
  an array of 9 integers, indicating the on/off state
  of each LED.
  And because there're 6 possible patterns, we need a 
  2-dimensional array to define all the data. It's a 
  big array of 6 elements, each element is an array of
  9 integers.
*/
int die[6][9]={
  //1
  {
  0,0,0,
  0,1,0,
  0,0,0 
  },
  
  //2
  {
  1,0,0,
  0,0,0,
  0,0,1 
  },
  
  //3
  {
  1,0,0,
  0,1,0,
  0,0,1 
  },
  
  //4
  {
  1,0,1,
  0,0,0,
  1,0,1 
  },
  
  //5
  {
  1,0,1,
  0,1,0,
  1,0,1 
  },
  
  //6
  {
  1,1,1,
  0,0,0,
  1,1,1 
  }
};

/*
  wait time between the die rolls to a different face.
  Notice it's using float type here? Read on!
*/
float waitTime=1;

void setup(){
  //Configure each pin as an output. 
  for(int i=0;i<pinCount;i++){
    pinMode(ledPins[i],OUTPUT);
  }
  
  //initialize the tilt switch.
  ts.begin();
  
  //generate the random seed. We use the value from
  //A0, since it's not connected to anything, it should
  //generate some random noises. Perfect for our purpose
  randomSeed(analogRead(A0));
}
void loop(){
  //Reset the wait time
  waitTime=2;
  
  /*
    Imagine when you throw a die, it'll bounce around, 
    showing a few values before laying still. 
  
    Let's keep generating new values until it's stable
    (when time between new values become long enough)
  */
  while(waitTime<1000){
    /*
      Generate a random die value.
      The die value can be 1 to 6, in the array it's
      die[0] to die[5]. random(0,6) generate a value
      between 0 to 6, that would be 0 to 5 in effect.
    */
    int value;
    value=random(0,6);
    
    //Display the die value
    displayDie(value);
    
    /*
      See why waitTime has to be float? If it's an integer,
      multiplying it by 1.3 will make it lose everything behind
      the decimal mark. We use 2 as the starting value, 
      2*1.3 should be 2.6, losing the fractional parts means
      it'll be 2 in the end, so 2*1.3=2!
    */
    waitTime=waitTime*1.3;    
    delay(waitTime);
  }
  
  /*
    Now the die is stable, wait until the tilt switch is 
    activated again. ts.pressed() stops the whole program 
    until it's activated.
  */
  ts.pressed();
}

void displayDie(int num){
  //Show the die value by turning on/off the right LEDs
  for(int i=0;i<pinCount;i++){
    digitalWrite(ledPins[i],die[num][i]);
  }
}

/*
* POV (Persistence of Vision)
* 
* With POV, persistence of vision, you can take eg a bike wheel
* and make it into a display with just a few LEDs. Check out 
* this video to see what we mean: 
* http://www.youtube.com/watch?v=-TvGvVWS3IE
* 
* In this project you will make one of these displays yourself. 
* Wave it with long strokes or even hold it while running to 
* display a text, a statement or a picture. The effect is most 
* visible in a dark place so if you’re running, make sure not 
* to run in to a tree or a friend. 
* 
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>
/*
An array of pin numbers to which LEDs are attached
the defaults are 2 to 6 but you can choose any of the digital pins
*/
int ledPins[] = {2, 3, 4, 5, 6};
int pinCount = 5;
VUMeter vuMeter;

int rowCount = 0; // Stores the number of rows
int rowLength = 22; // Width of the message, copy this number to the message array
int delayTime = 9; // Time it takes to show a row in milliseconds

// The message where 0 is LOW and 1 is HIGH
boolean message[5][22]={
  // H H H H   O O O O   L L L L   A A A A
  {0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,0},
  {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0},
  {0,1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0}

};

void setup(){
  // If your are using other pins than 2 to 6 you need to configure that here
  vuMeter.config(pinCount, ledPins);

  vuMeter.begin(); //does the same as pinMode, LEDs are outputs
}

void loop(){
 // If the whole array has been drawn
  if(rowCount == rowLength) {
    rowCount = 0; // Reset the rowCount
  } else {
    // Shows the message
    for (int i = 0; i < pinCount; i++) {
      // Checks if the array says HIGH
      if (message[i][rowCount] == 1) {
        vuMeter.on(i);
      } else {
        vuMeter.off(i);
      }
    }
    rowCount++;
  }

  delay(delayTime);// This is the delay per row

}

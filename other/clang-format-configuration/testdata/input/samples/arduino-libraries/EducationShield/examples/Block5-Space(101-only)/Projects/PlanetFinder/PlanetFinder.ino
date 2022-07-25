/*
*  PlanetFinder
* 
* The universe is big, really big, so if you are ever going to be able to find any planets then you'll
* need a tool track them down for you.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>


IMU imu; // the IMU

bool blinkState = false; // state of the LED
const int ledPin = 13;      // activity LED pin
const int piezoPin = 8; //piezo
const int redPin = 6; // the red LED
int piezoState = LOW;             // piezoState used to set the piezo

bool newGame = true;
int x = 0;
int y = 0;
const int errorMargin=10;

unsigned long previousMillis = 0;   // last time the click played, in ms


// notes in the melody:
int melody[] = {
  196,  196, 262
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4
};


void setup() {
  Serial.begin(9600); // initialize Serial communication


  imu.begin();


  // configure Arduino LED for activity indicator
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn on LED to show that the board has executed

  pinMode(piezoPin, OUTPUT); // sets piezo
  pinMode(redPin, OUTPUT); // sets red LED
  randomSeed(analogRead(0)); // initializes the pseudo-random number generator

}

void loop() {

  // start the IMU read
  imu.run();

  // get the pitch and roll result from the filter
  int pitch = imu.getPitch();
  int roll = imu.getRoll();


  // new round the game
  if (newGame) {

    //pick goal
    x = random(-180, 180);
    y = random(-90, 90);
    newGame = false;
  }


  // print the roll/pitch and the target roll/pitch needed for debugging only
  Serial.print("roll:");
  Serial.print(roll);
  Serial.print("\t");
  Serial.print("pitch:");
  Serial.print(pitch);
  Serial.print("\t");

  Serial.print("Target roll:");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("Target pitch:");
  Serial.println(y);


  // calculate how close the gyro is to the goal values

  //Computes the value of the IMU reads and the goal target
  int absoluteRollDiff = abs(roll - x);
  int absolutePitchDiff = abs(pitch - y);
  int closeTogoal = absoluteRollDiff + absolutePitchDiff;



  // click in shorter intervals the closer the gyro read is to the goal
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= closeTogoal ) {
    // save the last time you clicked the piezo
    previousMillis = currentMillis;

    // if the piezo is off turn it on and vice-versa:
    if (piezoState == LOW) {
      piezoState = HIGH;
    } else {
      piezoState = LOW;
    }

    digitalWrite(piezoPin, piezoState);
    digitalWrite(redPin, piezoState);
  }

  // if the gyro value is at the goal
  if (closeTogoal <= errorMargin) {

    Serial.print("Win");


    // play the win tune
    for (int thisNote = 0; thisNote < 3; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(piezoPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(piezoPin);

    }
    // a new goal and new game round is needed
    newGame = true;
  }


  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(ledPin, blinkState);

}

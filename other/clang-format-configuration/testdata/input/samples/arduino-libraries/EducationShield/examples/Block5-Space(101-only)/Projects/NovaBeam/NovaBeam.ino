/*
* NovaBeam
* 
* Ever wondered what it might be like to swing a laser beam? Then this project is for you! See
* yourself play with the Nova Beam on screen, and listen to the awesome sounds it makes.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

IMU imu; // the IMU
Button toggleButton(10);

int piezoPin = 8; //piezo

bool toggleState = false;

const int ledPin = 13;      // activity LED pin
boolean blinkState = false; // state of the LED

//smoothing function
const int numReadings = 50;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading

//int total2,average2;

void setup() {
  Serial.begin(9600); // initialize Serial communication

  imu.begin();
  toggleButton.begin();

  //smoothing function
  // initialize all the readings to 0:
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }


  // configure Arduino LED for activity indicator
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn on LED to show that the board has executed

}

void loop() {
  // start the IMU read
  imu.run();

  // read raw accel measurements from the IMU device
  int ay = imu.getAccelerometerY();

  // map the raw value to be on a smaller scale
  ay = map(ay, -36044 , 36043 , -360, 360);

  // read from the sensor:
  readings[readIndex] = ay;
  // advance to the next position in the array:
  readIndex = readIndex + 1;
  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // get the total of last 10 readings
  int total=0;
  for(int i=0;i<numReadings;i++){
    total+=readings[i];
  }
  // calculate the average:
  int average = total / numReadings;

  // map the average to a scale for the frequency for the piezo
  int frequency = map(abs(average), 0, 360, 200, 700);


  if(toggleButton.isPressed()){
    //toggle the button each time its pressed
    toggleState = !toggleState;
  }

  if (toggleState) {
    //play sound based on the average reading for the ay value
    tone(piezoPin, frequency);
  } else {
    //turn off the sound
    noTone(piezoPin);
  }

  // get the gyro result from the filter and convert them into INT
  int pitch = imu.getPitch();
  int roll = imu.getRoll();

  // when Serial is open, check for a 's' from Procssing
  if (Serial.available() > 0) {
    int val = Serial.read();
    if (val == 's') { // if incoming serial is "s"

      // print the roll,pitch and toggleState to the Procssing
      Serial.print(average); 
      Serial.print(",");
      Serial.print(pitch);  
      Serial.print(",");
      Serial.print(toggleState);  
      Serial.print(",");
      Serial.println("");

    }
  }


  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(ledPin, blinkState);
  delay(30);

}



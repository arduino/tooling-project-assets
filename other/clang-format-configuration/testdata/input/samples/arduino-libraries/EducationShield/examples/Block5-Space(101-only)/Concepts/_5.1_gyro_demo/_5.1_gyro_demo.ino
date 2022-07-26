/*
* _5.1_gyro_demo
* 
* The Piezo will play sound based on how fast you tilt the board in the X and Y axes.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>


IMU imu; // the IMU

const int piezoPin = 8; //piezo

const int ledPin = 13;      // activity LED pin
boolean blinkState = false; // state of the LED


void setup() {
  // configure Arduino LED for activity indicator
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn on LED to show that the board has executed


  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open


  imu.begin();
 



  // blink the LED again to show that the calibration is done
  blinkState = !blinkState;
  digitalWrite(ledPin, blinkState);

  pinMode(piezoPin, OUTPUT);
}

void loop() {
  // start the IMU read
  imu.run();

  // read raw gyro measurements from the IMU device
  int gx = imu.getGyroX();
  int gy = imu.getGyroY();

  // map the raw value to be on a smaller scale
  gx = map(gx, -36044 , 36043 , -360, 360);
  gy = map(gy, -36044 , 36043 , -360, 360);


  // print the measurements
  Serial.print(gx);
  Serial.print("\t");
  Serial.println(gy);



  //Computes the absolute value of the IMU read
  gx = abs(gx);
  gy = abs(gy);



  // add together the 2 values and use them for setting the frequency for the speaker to play
  int frequency = gx  + gy;
  frequency = frequency / 2;
  frequency = map(frequency, 0, 360, 0, 1000);

  // only play a sound if the frequency is not too low or the IMU is still
  if (frequency > 50) {
    tone(piezoPin, frequency);
  } else {
    noTone(piezoPin);// stop the sound
  }

  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(ledPin, blinkState);
  delay(30);
}



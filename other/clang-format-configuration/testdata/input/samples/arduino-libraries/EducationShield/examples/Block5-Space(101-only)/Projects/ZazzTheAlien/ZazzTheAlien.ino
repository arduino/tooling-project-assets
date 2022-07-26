/*
*  ZazzTheAlien
* 
* It is a lot of responsibility, but now you will have to take care of the alien baby. This particular
* alien baby communicates with Bluetooth. You need to make sure it has proper exercises, gets
* enough food and sleep.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

BLEuart ble=BLEuart(TYPE_TAMAGOTCHI);
IMU imu;

//const int lightPin = A0; //phototransistor
LightSensor sleepSensor(A1);

Button foodButton(9);

int exerciseLv, foodLv, sleepLv; // the saved stats that will go down over time

long sleepTimer;
long updateTimer; 

void setup() {
  Serial.begin(9600);

  // Curie IMU setup
  imu.begin();
  imu.detectShock();
  imu.attachCallback(shockCallback);

  // set advertised local name
  ble.setName("Zazz");
  ble.begin();

  foodButton.begin();

  sleepSensor.config(1000,200);

  //Set initial values for the three states
  exerciseLv = 100;
  foodLv = 100;
  sleepLv = 100;
  
  updateTimer = millis();
  sleepTimer = millis();
}

void loop() {

  updateStatus(); // used to update the stats values

  // if a central is connected to peripheral:
  if(ble.searchCentral()){
    Serial.println("Connected to central ");
    // while the central is still connected to peripheral:
    while(ble.connected()){
      updateStatus();// used to update the stats values
      Serial.println("Sending data");
      ble.addValue(exerciseLv);
      ble.addValue(foodLv);
      ble.addValue(sleepLv);    
      ble.send();
    }
    // when the central disconnects, print it out:
    Serial.println(F("Disconnected from central "));

  }

}

void updateStatus() {
  // if the light level is low, add 1 to the sleepLv
  if(sleepSensor.getState() && millis()-sleepTimer>200){
    sleepLv++;
    sleepTimer=millis();
  }

  //Fill the food stat when the button is being pressed
  if(foodButton.isPressed()){
    foodLv+=5;
  }

  // every 3 sec update and lower the 3 stats in different rates
  if (millis() - updateTimer >= 3000) {
    exerciseLv = exerciseLv - 1;
    foodLv = foodLv - 2;
    sleepLv = sleepLv - 3;

    updateTimer = millis();
  }

  //Constrain the values so they don't exceed 100 or go below 0
  exerciseLv=constrain(exerciseLv,0,100);
  foodLv=constrain(foodLv,0,100);
  sleepLv=constrain(sleepLv,0,100);
}

// this is called when the IMU detects a shock in any direction
static void shockCallback(void) {
  //add 1 to the exerciseLv
  exerciseLv++;
}

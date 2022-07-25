/*
*  ShipNavigator
* 
* To find your way around space safely, your ship will need a navigator. Follow your ship’s AI
* instructions to navigate your ship without crashing it into anything.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

Player player = Player(); // for playing sounds
IMU imu; // the IMU


const int ledPin = 13;      // activity LED pin
boolean blinkState = false; // state of the LED

bool up, down, left, right; //used for checking if the board has been moved in any direction
int moveTask = 1; //used for picking what direction should be done
bool newMove = false; // used for checking if a newMove is needed

long lastTimer; //used for saving millis()

void setup() {

  // configure Arduino LED for activity indicator
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn on led to show that the board has executed


  Serial.begin(9600); // initialize Serial communication


  imu.begin();


  //Initialize the sound player
  player.begin();

  randomSeed(analogRead(0));// initializes the pseudo-random number generator


}

void loop() {
  // read raw rollro measurements from device
  imu.run();
  // get the pitch and roll result from the filter
  int pitch = imu.getPitch();
  int roll = imu.getRoll();

  Serial.print("roll:");
  Serial.print(pitch);
  Serial.print("\t");
  Serial.print("pitch:");
  Serial.println(roll);

  // short pause before the next round start
  if (!newMove) {
    Serial.println("New round");

    delay(1000);

  }




  // check if the board has been tilted in any direction and set the direction bools accordingly
  if (pitch < -45) {
    up = true;
    down = false;
    left = false;
    right = false;
  } else if (pitch > 45) {
    up = false;
    down = true;
    left = false;
    right = false;
  } else if (roll  < -45) {
    up = false;
    down = false;
    left = true;
    right = false;
  } else if (roll > 45) {
    up = false;
    down = false;
    left = false;
    right = true;
  } else {
    up = false;
    down = false;
    left = false;
    right = false;
  }


  // if a new move is needed, generate random direction and play the sound for that direction
  if (!newMove) {
    // picks a random number from 1 to 4
    moveTask = random(1, 5);

    //Playsound
    if (moveTask == 1) {
      Serial.println("move up");
      player.play("up.wav");

    } else if  (moveTask == 2) {
      Serial.println("move down");
      player.play("down.wav");

    } else if (moveTask == 3) {
      Serial.println("move left");
      player.play("left.wav");

    } else if (moveTask == 4) {
      Serial.println("move right");
      player.play("right.wav");

    }

    newMove = true; // a new move is created
    lastTimer = millis(); // reset the 3 sec timer

  }

  // check if the random direction and the direction the board moved in is the same
  if (up && moveTask == 1) {
    Serial.println("up");
    newMove = false;
  }
  if (down && moveTask == 2) {
    Serial.println("down");
    newMove = false;
  }
  if (left && moveTask == 3) {
    Serial.println("left");
    newMove = false;
  }
  if (right && moveTask == 4) {
    Serial.println("right");
    newMove = false;
  }


  // if the right move is not done before the 3 sec timer, reset the newMove bool and the timer to start a new round
  if (millis() - lastTimer >= 3000) {

    if (newMove) {
      Serial.println("To slow");
      //Play the sound for being too slow
      player.play("slow.wav");
      newMove = false;
    }

    lastTimer = millis();

  }





  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(ledPin, blinkState);

  delay(250);
}

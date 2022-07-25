/*
*  SpaceRover
* 
* Getting around on alien planets can be difficult. 
* You are going to need a rover to investigate these new alien worlds. 
* Now you will be able to control the rover to explore alien planets.
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

BLEuart ble = BLEuart(TYPE_LOGOROBOT);

Wheels wheels = Wheels(6, 9);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ble.setName("Rover");
  ble.begin();
  
 wheels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ble.searchCentral()) {
    Serial.println("Connected to central ");
    while (ble.connected()) {
      if (ble.dataReceived()) {
        ble.fetchData();

        Serial.print("Received number of commands: ");
        Serial.println(ble.getReceivedLength());

        for (int i = 0; i < ble.getReceivedLength(); i++) {
          unsigned char n = ble.receivedString()[i];

          Serial.print(n);

          logoMove(n);
        }
        Serial.println();
      }
    }
    Serial.println(F("Disconnected from central "));

  }
}

void logoMove(unsigned char direction) {
  switch (direction) {
    case 1:	//forward
      wheels.goForward();
      delay(750);
      break;
    case 2:	//backwards
      wheels.goBackwards();
      delay(750);
      break;
    case 3:	//left
      wheels.turnLeft();
      delay(250);
      break;
    case 4:	//right
      wheels.turnRight();
      delay(250);
      break;
  }
  wheels.standStill();
  delay(300);
}



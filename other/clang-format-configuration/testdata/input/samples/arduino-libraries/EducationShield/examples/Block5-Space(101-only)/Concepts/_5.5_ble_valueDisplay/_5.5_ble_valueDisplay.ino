/*
* _5.5_ble_valueDisplay
* 
* The 101 board monitors the status of a button connected to digital pin 9,
* a press counter, and a light sensor connected to pin A0. 
* The 3 values are sent through the BLE in such sequence, 
* and the app reads the values in the same sequence. 
*
* (c) 2013-2016 Arduino LLC.
*/


#include <EducationShield.h>

BLEuart ble=BLEuart();

Button button(9);

int count;

void setup() {
  Serial.begin(9600);

  // Curie BLE setup
  // set advertised local name
  ble.setName("valDisp");
  ble.begin();

  button.begin();

  count=0;
}

void loop() {
  // if a central is connected to peripheral:
  if(ble.searchCentral()){
    Serial.println("Connected to central ");
    // while the central is still connected to peripheral:
    while(ble.connected()){
      //Get readings from sensors 
      int buttonValue=button.getState();
      int lightValue=analogRead(A1);

      //Value Display can only pass numbers smaller than 255
      lightValue=map(lightValue,0,1023,0,255);

      //Check if the button is being pressed, and update the
      //counter accordingly
      if(button.isPressed()){
        count++;
      }


      //Note the sequence of data being sent, the phone app displays 
      //the values in the same sequence.
      ble.addValue(buttonValue);
      ble.addValue(count);
      ble.addValue(lightValue);    
      ble.send();
        
    }
    // when the central disconnects, print it out:
    Serial.println(F("Disconnected from central "));

  }

}



/*
* _5.4_ble_demo
* 
* The board will now store a message that is sent to it and send it back to anyone connecting to it
*
* (c) 2013-2016 Arduino LLC.
*/

#include <EducationShield.h>

BLEuart ble=BLEuart(TYPE_MESSENGER);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ble.setName("Message");
  ble.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ble.searchCentral()){
    Serial.println("Connected to central ");
    while(ble.connected()){

      //When receiving data from mobile app, write it 
      //back to the sender
      if(ble.dataReceived()){
        ble.fetchData();
        Serial.println(ble.receivedString());
        char data[20];
        int length=ble.getReceivedLength();
        for(int i=0;i<length;i++){
          data[i]=ble.receivedString()[i];
        }
        ble.sendString(data,length);
      }

    }
    Serial.println(F("Disconnected from central "));

  }
}

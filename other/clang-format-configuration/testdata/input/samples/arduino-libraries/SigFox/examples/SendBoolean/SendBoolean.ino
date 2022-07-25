/*
  SigFox Send Boolean tutorial

  This sketch demonstrates how to send a simple binary data ( 0 or 1 ) using a MKR Fox 1200.
  If the application only needs to send one bit of information the transmission time
  (and thus power consumption) will be much lower than sending a full 12 bytes packet.

  This example code is in the public domain.
*/

#include <SigFox.h>

// We want to send a Boolean value to signal a binary event
// like open/close or on/off

bool value_to_send = true;

#define DEBUG 1

void setup() {

  if (DEBUG){
    Serial.begin(9600);
    while (!Serial) {};
  }

  // Initialize the Sigfox module
  if (!SigFox.begin()) {
    if (DEBUG){
      Serial.println("Sigfox module unavailable !");
    }
    return;
  }

  // If we want to to debug the application, print the device ID to easily find it in the backend
  if (DEBUG){
    SigFox.debug();
    Serial.println("ID  = " + SigFox.ID());
  }

  delay(100);

  // Compose a message as usual; the single bit transmission will be performed transparently
  // if the data we want to send is suitable
  SigFox.beginPacket();
  SigFox.write(value_to_send);
  int ret = SigFox.endPacket();

  if (DEBUG){
    Serial.print("Status : ");
    Serial.println(ret);
  }
}

void loop(){}

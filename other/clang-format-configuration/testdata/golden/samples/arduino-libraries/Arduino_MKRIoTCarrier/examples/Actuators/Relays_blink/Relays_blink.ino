#include <Arduino_MKRIoTCarrier.h>

MKRIoTCarrier carrier;

void setup() {

  Serial.begin(9600);
  Serial.println("Init");
  carrier.noCase();
  carrier.begin();
}

void loop() {
  //Switch to NO
  carrier.Relay1.open();
  carrier.Relay2.open();
  Serial.println("Both Relays switched to NO");
  delay(2500);


  //Switch to NC
  carrier.Relay1.close();
  carrier.Relay2.close();
  Serial.println("Both Relays switched to NC");

  //Get status
  Serial.print("Relay 1 is: ");
  Serial.println(carrier.Relay1.getStatus());
  delay(2500);
}
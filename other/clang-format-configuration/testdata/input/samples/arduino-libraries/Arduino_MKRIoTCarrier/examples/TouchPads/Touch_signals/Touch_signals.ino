// Touch Buttons test

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

int msr[5];

void setup() {
  // put your setup code here, to run once:
  //carrier.noCase();     //No need to use it, default false
  Serial.begin(9600);
  carrier.begin();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++) {
    msr[i] = analogRead(i);
    Serial.print(i);
    Serial.print(" - ");
    Serial.print(msr[i]);
    Serial.print("\t");
  }
  Serial.println();
  
}

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier; //Constructor of the carrier maybe we can include it on the library itself

//Be sure that the Pins are the same as your wiring
int moisture = A5;
int moist;
int pir = A6;
bool trigger = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  carrier.noCase();
  carrier.begin();
  pinMode(moisture,INPUT);
  pinMode(pir,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Save readings
  moist = analogRead(moisture);
  trigger = digitalRead(pir);
  Serial.println("Reading grove inputs A5 and A6");
  Serial.print("Moist: ");
  Serial.print(moist);
  Serial.print("\t Move state: ");
  Serial.println(digitalRead(pir));
  Serial.println();
  //delay(00);

}

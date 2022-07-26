/*
* _3.7_receiving_serial
* 
* The board turns the on-board LED on or off by sending an ‘H’ or ‘L’ to the control board from the Serial Monitor
*
* (c) 2013-2016 Arduino LLC.
*/

int ledPin=13;
int incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
void loop() {
  if(Serial.available()>0){
    incomingByte=Serial.read();
    
    if(incomingByte=='H'){
      digitalWrite(ledPin, HIGH);
    }
    if(incomingByte=='L'){
      digitalWrite(ledPin,LOW);
    }
    
  }
}


/*
* _3.5_sending_serial
* 
* The board will send a text message from the board to the computer and Serial Monitor
*
* (c) 2013-2016 Arduino LLC.
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello World");
  delay(1000);
}


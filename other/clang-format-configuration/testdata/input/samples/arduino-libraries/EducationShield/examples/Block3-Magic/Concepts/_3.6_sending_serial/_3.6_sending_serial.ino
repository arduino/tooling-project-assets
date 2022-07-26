/*
* _3.6_sending_serial
* 
* The board will read the analog value from a light sensor and print that value to the Serial Monitor.
*
* (c) 2013-2016 Arduino LLC.
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A1);
  
  Serial.println(sensorValue);
  delay(100);
}


/*  Serialportsend
*
* connect a potentiometer to your board and you will check its value by using Processing
*
*       (c) 2013-2016 Arduino LLC.
*/

void setup() {

Serial.begin(9600);

}

void loop() {
// send to port
 Serial.write(analogRead(A5)/4);
 delay(1);

}

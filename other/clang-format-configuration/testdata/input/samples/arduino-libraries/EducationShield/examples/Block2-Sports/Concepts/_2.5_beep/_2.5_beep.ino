/*
* _2.5_beep
* 
* The piezo makes clicks with a 1 millisecond interval.
*
* (c) 2013-2016 Arduino LLC.
*/
int speakerPin = 8;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  digitalWrite(speakerPin, HIGH);
  delay(1);
  digitalWrite(speakerPin, LOW);
  delay(1);
}


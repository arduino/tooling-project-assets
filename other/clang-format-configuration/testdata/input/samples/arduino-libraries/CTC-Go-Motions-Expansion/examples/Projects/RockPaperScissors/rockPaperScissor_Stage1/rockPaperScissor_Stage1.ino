/*
  CTC GO! MOTION 
  PROJECT - ROCK PAPER SCISSOR

  This sketch is written to accompany Stage 1 of the ROCK PAPER SCISSOR project
*/

int piezo = 8;
int USsensor = A0;

int USvalue = 0;
float distance = 0;


void setup() {
______(piezo, ______);
Serial.begin(9600);
}

void loop() {
  USvalue = ______(______);
  distance = ______ * 3;
  
  Serial.print("Distance to object: ");
  Serial.println(______);
  
    if (______ < 400) {
    tone(______, 500);
    delay(100);
    noTone(______);
    }

delay(250);
}
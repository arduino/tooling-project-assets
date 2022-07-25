/*
  CTC GO! MOTION 
  PROJECT - ROCK PAPER SCISSOR

  This sketch is written to accompany Stage 2 of the ROCK PAPER SCISSOR project
*/

int redLED = 2;
int yellowLED = 3;
int greenLED = 4;
int piezo = 8;
int USsensor = A0;

int USvalue = 0;
float distance = 0;
int check = 0;

void setup() {
  pinMode(piezo, OUTPUT);
  
  ______(redLED, ______);
  ______(yellowLED, ______);
  ______(greenLED, ______);

  Serial.begin(9600);
}

void loop() {
  USvalue = analogRead(USsensor);
  distance = USvalue * 3;
  
  if (distance < 400) {
    /*tone(piezo, 500);
    delay(100);
    noTone(piezo);*/
    
    ______++;
    delay(400); 
    Serial.println(______);
  }

  if (check == 0) {
    ____________(redLED, ______);
    ____________(yellowLED, ______);
    ____________(greenLED, ______);
  }

  else if (check == 1) {
    ______(redLED, ______);
  }

  else if (check == 2) {
    ____________(yellowLED, ______);
    ____________(redLED, ______);
  }

  else if (check == 3) {
    ____________(greenLED, ______);
    ____________(yellowLED, ______);
    tone(piezo, 500);
    delay(100);
    noTone(piezo);
    ______ = 0; 
  }
}
  
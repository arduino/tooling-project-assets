/*
  CTC GO! CORE MODULE 
  LESSON 03 - Let's Start Programming 

  This sketch is written to accompany Activity 3 in Lesson 03 of the CTC GO! core module

*/

// initialising the pins.
int redLED = 13;
int yellowLED = 12;

void setup() 
{
  // Setting up the pins as OUTPUTS.
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() 
{
  // Blink the LEDs. 
  digitalWrite(redLED, HIGH); 
  digitalWrite(yellowLED, HIGH); 
  delay(1000);                   
  digitalWrite(redLED, LOW);     
  digitalWrite(yellowLED, LOW);
  delay(1000);                   
} 

/*
  CTC GO! CORE MODULE 
  LESSON 03 - Let's Start Programming 

  This sketch is written to accompany Activity 1 in Lesson 03 of the CTC GO! core module

*/

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second                  
} 

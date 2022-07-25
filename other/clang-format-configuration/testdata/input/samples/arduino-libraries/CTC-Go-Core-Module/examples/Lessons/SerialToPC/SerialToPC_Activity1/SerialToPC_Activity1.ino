/*
  CTC GO! CORE MODULE 
  LESSON 05 - Showing messages on PC

  This sketch is written to accompany Activity 1 in Lesson 05 of the CTC GO! core module
*/

void setup() 
{
  // initialize digital serial communication at 9600baud.
  Serial.begin(9600);
}

void loop() 
{
  //Printing a sentnce every second
  Serial.println("Hello World!!");
  delay(1000);
}

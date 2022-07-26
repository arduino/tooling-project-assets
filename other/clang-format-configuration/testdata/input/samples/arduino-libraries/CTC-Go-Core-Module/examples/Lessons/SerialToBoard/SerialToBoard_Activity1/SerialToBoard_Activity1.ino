
/*
  CTC GO! CORE MODULE 
  LESSON 06 - Sending Data to the Board

  This sketch is written to accompany Activity 1 in Lesson 06 of the CTC GO! core module
*/

int incomingNum = 0;   
char incomingChar;

void setup()
{
  Serial.begin(9600);     
}

void loop()
{
  // if there are characters available, read and print them 
  if (Serial.available() > 0) 
  {
    incomingNum = Serial.read();
    incomingChar = incomingNum;

    Serial.println("Character Code");
    Serial.print(incomingChar);
    Serial.print(" ");
    Serial.println(incomingNum);
  }
}

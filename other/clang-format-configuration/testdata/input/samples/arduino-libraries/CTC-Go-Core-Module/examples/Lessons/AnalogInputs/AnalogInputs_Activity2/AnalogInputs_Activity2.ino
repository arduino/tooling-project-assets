/*
  CTC GO! CORE MODULE 
  LESSON 07 - Analog Inputs

  This sketch is written to accompany Activity 2 in Lesson 07 of the CTC GO! core module
*/


int lightSensor = A0;  
int LED = 13;          
int val = 0;           
int trigger = 250;    

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //savethe read on a variable and print it
  val = analogRead(lightSensor);
  Serial.print("Value read: ");
  Serial.println(val);

  if (val < trigger)    
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW); 
  }
  delay(500);
}

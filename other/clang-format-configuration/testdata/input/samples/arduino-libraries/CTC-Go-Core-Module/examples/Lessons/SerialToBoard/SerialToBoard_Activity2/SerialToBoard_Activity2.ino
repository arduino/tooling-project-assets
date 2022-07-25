/*
  CTC GO! CORE MODULE 
  LESSON 06 - Sending Data to the Board

  This sketch is written to accompany Activity 2 in Lesson 06 of the CTC GO! core module
*/

char incomingWord[10];  
int counter = 0;        
int i = 0;              

// initialising the pins.
int redLED = 13;        
int greenLED = 12;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // send data only when you receive data:
  if (Serial.available() > 0)
  {
    incomingWord[i] = Serial.read();

    if (incomingWord[i] == 'a')
    {
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
      counter += 1;
    }
    else if (incomingWord[i] == 'e')
    {
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
      counter += 1;
    }
    else if (incomingWord[i] == 'i')
    {
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
      counter += 1;
    }
    else if (incomingWord[i] == 'o')
    {
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
      counter += 1;
    }
    else if (incomingWord[i] == 'u')
    {
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
      counter += 1;
    }
    else
    {
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
    }

    i += 1; 
  }
  else
  {
    Serial.print("The word introduced is: ");
    for (int i = 0; i < 10; i++)
    {
      Serial.print(incomingWord[i]);
    }
    Serial.println("");
    Serial.print("It has: ");
    Serial.print (counter);
    Serial.println(" Vowels");
    delay(5000);
    counter = 0;
    i = 0;
    for (int i = 0; i < 10; i++)
    {
      incomingWord[i] = 0;
    }
  }
}


/*
  CTC GO! CORE MODULE 
  LESSON 07 - Analog Inputs

  This sketch is written to accompany Activity 3 in Lesson 07 of the CTC GO! core module
*/

  int USsensor = A0;
  int greenLED = 9; 
  int yellowLED = 11;
  int redLED = 13;   
  
  float distance = 0; 
  int value = 0;
  
  
  void setup()
  {
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
  
    Serial.begin(9600);
  }
  
  void loop()
  {
    // reading, calculating and printing the distance
    value = analogRead(USsensor);
    distance = value * 3;
    Serial.print("Dinstance to the object (mm): ");
    Serial.println(distance);
    delay(250);
  
    // visualizing the distance with the LEDs
    if (distance < 200)
    {
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
    }
    else if (distance < 400)
    {
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
    }
    else if (distance < 600)
    {
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
    }
    else
    {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
    }
  }

/*
  CTC GO! CORE MODULE 
  LESSON 05 - Showing messages on PC

  This sketch is written to accompany Activity 2 in Lesson 05 of the CTC GO! core module
*/

  // initialising the pins and other variables.
  int button = 2;
  int button_state = 0;
  int counter = 0;
  
  void setup()
  {
    Serial.begin(9600);
    // Setting up the pins as OUTPUTS.
    pinMode(button, INPUT);
  }
  
  void loop()
  {
    button_state = digitalRead(button);
    
    //increase the value of counter one unit when button is pressed
    if (button_state == HIGH)
    {
      counter += 1;                   
      delay(500);
      Serial.print("counter value = "); 
      Serial.println(counter);

      //Reset counter when it reaches 100
      if (counter == 100)   
      {
        counter = 0;
      }
    }
  }

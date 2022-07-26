
/*
  CTC GO! CORE MODULE 
  LESSON 08 - Analog Outputs

  This sketch is written to accompany Activity 2 in Lesson 08 of the CTC GO! core module
*/
 
  //pin connections
  int buttonA = 13;
  int buttonB = 12;
  int piezo = 8;
  
  // notes frequency
  int A_note = 262;
  int B_note = 493;
  
  // to save the button states
  int buttAvalue = 0;
  int buttBvalue = 0;
  
  void setup()
  {
    pinMode(buttonA, INPUT);
    pinMode(buttonB, INPUT);
    pinMode(piezo, OUTPUT);
  }
  
  void loop()
  {
    //reading the buttons states
    buttAvalue = digitalRead(buttonA);
    buttBvalue = digitalRead(buttonB);

    // play a note, based on the button pressed 
    if (buttAvalue == HIGH)
    {
      tone (piezo, A_note); 
    }
    else if (buttBvalue == HIGH)
    {
      tone (piezo, B_note); 
    }
    else
    {
      noTone(piezo); 
    }
  }


  

/*
  CTC GO! CORE MODULE 
  LESSON 04 - Digital Inputs & Outputs

  This sketch is written to accompany Activity 1 in Lesson 04 of the CTC GO! core module
*/

// Initialising the pins and other variables.

int button_pin = 2;
int button_state = 0; 

void setup() 
{
  // Setting up the pins as OUTPUTS & INPUTS.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button_pin,INPUT);
}

void loop() 
{
  // Saving the button state in a variable
  button_state = digitalRead(button_pin);
  digitalWrite(LED_BUILTIN, button_state);   
}

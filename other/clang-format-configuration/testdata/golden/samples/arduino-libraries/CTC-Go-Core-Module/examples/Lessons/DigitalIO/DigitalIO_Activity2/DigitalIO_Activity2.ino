/*
  CTC GO! CORE MODULE 
  LESSON 04 - Digital Inputs & Outputs

  This sketch is written to accompany Activity 2 in Lesson 04 of the CTC GO! core module
*/

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
  button_state = digitalRead(button_pin);

  // if the button is presed, blink the LEDS
  if (button_state == HIGH)       
  {
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(1000);                       
    digitalWrite(LED_BUILTIN, LOW);    
    delay(1000);                       
  }
  else                         
  {
    digitalWrite(LED_BUILTIN, LOW);  
  }
}

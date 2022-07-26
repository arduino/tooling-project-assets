/*
  CTC GO! CORE MODULE 
  PROJECT 2 - AR GLASSES

  This sketch is written to accompany Stage 2 in AR GLASSES  of the CTC GO! core module
*/

int piezo = 11;
int yellowLED = 13;

int distanceSensor = A0 ;

int freq_1 = 500;
int distanceSensorValue = 0;

void setup() 
{
  pinMode(piezo,OUTPUT);
  pinMode(yellowLED,OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  
  distanceSensorValue = _____(distanceSensor);
  _____("Distance read: ");
  Serial.println(_____);

  /*
  //STEP 1; Blink the LED and Activate the Piezo 
  digitalWrite(yellowLED,HIGH);
  tone(piezo,freq_1);
  delay(100);
  digitalWrite(yellowLED,LOW);
  noTone(piezo);
  delay(100);
  */
}

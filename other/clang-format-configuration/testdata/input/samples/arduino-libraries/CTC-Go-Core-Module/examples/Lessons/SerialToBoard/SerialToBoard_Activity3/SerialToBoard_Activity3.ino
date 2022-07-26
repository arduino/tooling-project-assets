/*
  CTC GO! CORE MODULE 
  LESSON 06 - Sending Data to the Board

  This sketch is written to accompany Activity 3 in Lesson 06 of the CTC GO! core module
*/

// choosing the word to guess
char selectedWord[] = {"HelloWorld"};          
char guessingWord[sizeof(selectedWord)];  
char incoming = 0;

int counter = 0;      
int mistakes = 0;     
int success = 0;        
int chances = 3;   

void setup()
{
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
  // to show the length of the word has to be guessed
  for (int i = 0; i < sizeof(selectedWord) - 1; i++)
  {
    guessingWord[i] = '_';
  }
  Serial.print("The Word you are looking for is: ");
  Serial.println(guessingWord);
}

void loop()
{

  if (Serial.available() > 0)
  {
    incoming = Serial.read();
    // checking if it is a success or mistake
    for (int i = 0; i < sizeof(selectedWord); i++)
    {
      if (incoming == selectedWord[i])
      {
        guessingWord[i] = incoming;
        success += 1;
      }
      else
      {
        counter = counter + 1;
      }
    }

    if (counter == sizeof(selectedWord))
    {
      mistakes += 1;
      Serial.println("Wrong letter!! Try again...");
    }
  }

  // printing the state of the guess word
  if (mistakes < chances)
  {
    Serial.print("The Word you are looking for is:  ");
    for (int i = 0; i < sizeof(selectedWord); i++)
    {
      Serial.print(guessingWord[i]);
    }
    Serial.print("      Mistakes: ");
    Serial.println(mistakes);
    counter = 0;
    delay(1000);
  }

  // finishing the game
  else if (mistakes == chances)
  {
    Serial.println();
    Serial.println("Game Over");
    mistakes = 5;
  }
  
  // end of the game
  else
  {}

  // winning
  if (success == sizeof(selectedWord) - 1)
  {
    Serial.println();
    Serial.print("WINEER!!");
    success = 0;
    mistakes = 5;
  }
}

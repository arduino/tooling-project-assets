/*
* Sequencer
* 
* Play beats and change the sequence in real time. Basically 
* all you need to become a hiphop artist. That, and rapping 
* skills. But that's another course. 
*  
* (c) 2013-2016 Arduino LLC.
*/
#include <EducationShield.h>

//Declare the sound player
Player player=Player();

//There're 4 slots for 4 sequences. We use 4 analog pins
//to read them.
int analog_pins[]={3,2,1,0};
int pin_count=4;
int analog_values[4];

//Template for the music file names.
char filename[]="seq0.wav";

void setup(){
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  //The system automatically calibrates itself
  calibrate();
  
  // Initialize the sound player. Open the Serial Monitor to see
  //the sound files found on your micro SD card
  player.begin();

}
void loop(){
  //Loop through 4 pins and play the right sequence accordingly
  for(int i=0;i<pin_count;i++){
    int slot_value=analogRead(analog_pins[i]);
    int sequence=getSeq(slot_value);
    
    //Get the right file name by sequence
    filename[3]='0'+sequence;
    Serial.println(filename);
    //Play the file
    player.play(filename);
  }

  //End of one loop
  Serial.println("=======");
}

void calibrate(){
  delay(1000);
  Serial.println("Begin Calibration");
  for(int i=0;i<4;i++){
    Serial.print("calibrating slot ");
    Serial.println(i);
    int val=0;
    do{
      val=analogRead(analog_pins[i]);
      Serial.println(i);
    }while(val>1010);
    analog_values[i]=val;
  }
  for(int i=0;i<4;i++){
    for(int j=i;j<4;j++){
      if(analog_values[i]>analog_values[j]){
        int temp=analog_values[i];
        analog_values[i]=analog_values[j];
        analog_values[j]=temp;
      }
    }
  }
  Serial.println("Done Calibration");
}

int getSeq(int analogVal){
  for(int i=0;i<4;i++){
    if(analogVal>analog_values[i]-50 && analogVal<analog_values[i]+50){
      return i+1;
    }
  }

  return 0;

/*
  if(analogVal>200 && analogVal<300){  //220 Ohm
   return 1; 
  }else if(analogVal>360 && analogVal<460){  //470 Ohm
   return 2;
  }else if(analogVal>480 && analogVal<580){  //680 Ohm
   return 3;
  }else if(analogVal>600 && analogVal<700){  //1k2 Ohm
   return 4;
  }else{  //No resistor
   return 0; 
  }
*/
  //If you're using Arduino 101, the same resistors give
  //different analog read values. Use the following code 
  //instead. 
  /*
  if(analogVal>200 && analogVal<300){  //220 Ohm
   return 1; 
  }else if(analogVal>400 && analogVal<500){  //470 Ohm
   return 2;
  }else if(analogVal>600 && analogVal<700){  //680 Ohm
   return 3;
  }else if(analogVal>800 && analogVal<900){  //1k2 Ohm
   return 4;
  }else{  //No resistor
   return 0; 
  }*/
}
#include <ArduinoMotorCarrier.h>
#define INTERRUPT_PIN 6

//Variable to store the battery voltage
int batteryVoltage;

void setup() 
{
  //Serial port initialization
  Serial.begin(115200);
  while (!Serial);

  //Establishing the communication with the Motor Carrier
  if (controller.begin()) 
    {
      Serial.print("MKR Motor Carrier connected, firmware version ");
      Serial.println(controller.getFWVersion());
    } 
  else 
    {
      Serial.println("Couldn't connect! Is the red LED blinking? You may need to update the firmware with FWUpdater sketch");
      while (1);
    }

  // Reboot the motor controller; brings every value back to default
  Serial.println("reboot");
  controller.reboot();
  delay(500);

  //Take the battery status
  float batteryVoltage = (float)battery.getConverted();
  Serial.print("Battery voltage: ");
  Serial.print(batteryVoltage);
  Serial.print("V, Raw ");
  Serial.println(battery.getRaw());
}


void loop() {

  //Take the battery status
  float batteryVoltage = (float)battery.getConverted();

  //Reset to the default values if the battery level is lower than 11 V
  if (batteryVoltage < 11) 
  {
    Serial.println(" ");
    Serial.println("WARNING: LOW BATTERY");
    Serial.println("ALL SYSTEMS DOWN");
    while (batteryVoltage < 11) {
      batteryVoltage = (float)battery.getConverted();
    }
  }
  else
  {
    //Servo sweep from 0 position to 180
    for (int i=0; i<180; i+=5)
    {
      //Choose which of the servo connectors you want to use: servo1(default), servo2, servo3 or servo4
      servo1.setAngle(i);
      Serial.print("Servo position");
      Serial.println(i);
      delay(50);
    }
    
    delay(200);
    
    //Servo sweep from 180 position to 0
    for (int i=180; i>0; i-=5)
    {
      //Choose which of the servo connectors you want to use: servo1(default), servo2, servo3 or servo4
      servo1.setAngle(i);
      Serial.print("Servo position");
      Serial.println(i);
      delay(50);
    }
  }

  //Keep active the communication between MKR board & MKR Motor Carrier
  //Ping the SAMD11
  controller.ping();
  //wait
  delay(50);
}

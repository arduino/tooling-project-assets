#include <ArduinoMotorCarrier.h>
#define INTERRUPT_PIN 6

//Variable to store the battery voltage
static int batteryVoltage;

//Variable to change the motor speed and direction
static int duty = 0;

void setup() 
{
  //Serial port initialization
  Serial.begin(115200);
  while (!Serial);

  //Establishing the communication with the Motor Carrier
  if (controller.begin()) 
    {
      Serial.print("MKR Motor Connected connected, firmware version ");
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
    M1.setDuty(0);
    M2.setDuty(0);
    M3.setDuty(0);
    M4.setDuty(0);
    while (batteryVoltage < 11) 
    {
      batteryVoltage = (float)battery.getConverted();
    }
  }
  else
  {
    //Motor test
    for (duty=-100; duty<100; duty+=5)
    {
      Serial.print("Motor Duty: ");
      Serial.println(duty);
      M1.setDuty(duty);
      M2.setDuty(duty);
      M3.setDuty(duty);
      M4.setDuty(duty);
      delay(50);
    }
    for (duty=100; duty>-100; duty-=5)
    {
      Serial.print("Motor Duty: ");
      Serial.println(duty);
      M1.setDuty(duty);
      M2.setDuty(duty);
      M3.setDuty(duty);
      M4.setDuty(duty);
      delay(50);
    }
    
  //Keep active the communication between MKR board & MKR Motor Carrier
  //Ping the SAMD11
  controller.ping();
  //wait
  delay(50);
  }
}

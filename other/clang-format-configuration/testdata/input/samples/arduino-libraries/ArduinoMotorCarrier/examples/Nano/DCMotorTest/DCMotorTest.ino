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
  //while (!Serial);

  //Establishing the communication with the Motor Carrier
  if (controller.begin())
  {
    Serial.print("Motor Carrier connected, firmware version ");
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

  int dutyInit = 0; // at 50 it works as expected, at 60 shift sides and is too small duty to move, at 70 is very big duty.
  M1.setDuty(dutyInit);
  M2.setDuty(dutyInit);
  M3.setDuty(dutyInit);
  M4.setDuty(dutyInit);
  Serial.print("Duty init: ");
  Serial.println(dutyInit);
  //  int duty2 = dutyInit * 16777215 / 100;
  //  Serial.print("Conversion formula: ");
  //  Serial.println(duty2);
  //while (1); //WHILE 1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! REMOVE!!!!
}


void loop() {

  //Take the battery status
  //float batteryVoltage = (float)battery.getConverted();

  //Reset to the default values if the battery level is lower than 11 V
  //  if (batteryVoltage < 11)
  //  {
  //    Serial.println(" ");
  //    Serial.println("WARNING: LOW BATTERY");
  //    Serial.println("ALL SYSTEMS DOWN");
  //    M1.setDuty(0);
  //    M2.setDuty(0);
  //    M3.setDuty(0);
  //    M4.setDuty(0);
  //    while (batteryVoltage < 11)
  //    {
  //      batteryVoltage = (float)battery.getConverted();
  //    }
  //  }
  //  else
  //  {

  //Motor test
  for (duty = -100; duty < 100; duty += 1)
  {
    Serial.print("Motor Duty: ");
    Serial.println(duty);
    M1.setDuty(duty);
    M2.setDuty(duty);
    M3.setDuty(duty);
    M4.setDuty(duty);
    delay(10);
  }
  for (duty = 100; duty > -100; duty -= 1)
  {
    Serial.print("Motor Duty: ");
    Serial.println(duty);
    M1.setDuty(duty);
    M2.setDuty(duty);
    M3.setDuty(duty);
    M4.setDuty(duty);
    delay(10);
  }

  //Keep active the communication between Nano & Motor Carrier
  //Ping the SAMD11
  controller.ping();
  //wait
  delay(50);
}

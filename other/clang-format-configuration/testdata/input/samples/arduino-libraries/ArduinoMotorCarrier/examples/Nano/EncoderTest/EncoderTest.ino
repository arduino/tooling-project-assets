#include <ArduinoMotorCarrier.h>
#define INTERRUPT_PIN 6

//Variable to store the battery voltage
static int batteryVoltage;

//Variable to change the motor speed and direction
static int duty = 0;

void setup()
{
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

  //Serial port initialization
  Serial.begin(115200);
  while (!Serial);

  // Reboot the motor controller; brings every value back to default
  Serial.println("reboot");
  controller.reboot();
  delay(500);

  // Reset the encoder internal counter to zero (can be set to any initial value)
  Serial.println("reset counters");
  encoder1.resetCounter(0);
  encoder2.resetCounter(0);

  M1.setDuty(30);
  M2.setDuty(30);
  M3.setDuty(30);
  M4.setDuty(30);
}


void loop() {

  //Chose the encoder to use:encoder1(default) or encoder2
  Serial.print("Encoder1 Pos [counts]: ");
  Serial.print(encoder1.getRawCount());
  Serial.print(" Encoder1 vel [counts/sec]: ");
  Serial.println(encoder1.getCountPerSecond());
  Serial.print("Encoder2 Pos [counts]: ");
  Serial.print(encoder2.getRawCount());
  Serial.print(" Encoder2 vel [counts/sec]: ");
  Serial.println(encoder2.getCountPerSecond());
  Serial.println("");

  //Keep active the communication between Nano & Motor Carrier
  //Ping the SAMD11
  controller.ping();
  //wait
  delay(50);
}

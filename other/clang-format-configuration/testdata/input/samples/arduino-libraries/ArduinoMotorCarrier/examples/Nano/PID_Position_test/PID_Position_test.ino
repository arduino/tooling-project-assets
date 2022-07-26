#include <MKRMotorCarrier_PID_test.h>
//#include <MKRMotorCarrier.h>
#define INTERRUPT_PIN 6

//Variable to store the battery voltage
static int batteryVoltage;

//Variable to change the motor speed and direction
static int duty = 0;

int target;

void setup()
{
  //Serial port initialization
  Serial.begin(115200);
  while (!Serial);

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

  //Take the battery status
  float batteryVoltage = (float)battery.getConverted();
  Serial.print("Battery voltage: ");
  Serial.print(batteryVoltage);
  Serial.print("V, Raw ");
  Serial.println(battery.getRaw());

  int dutyInit = 0; // at 50 it works as expected, at 60 shift sides and is too small duty to move, at 70 is very big duty.
  M1.setDuty(dutyInit);
  M2.setDuty(dutyInit);
  M3.setDuty(dutyInit);
  M4.setDuty(dutyInit);
  Serial.print("Duty: ");
  Serial.println(dutyInit);

  /************* PID 1 ***********************/

//  pid1.setControlMode(CL_POSITION);
//
//  //pid1.resetGains();
//  //pid1.setLimits(-100,100);
//  pid1.setGains(0.01f, 0.017f, 0.0f); //Proportional(change) Integral(change) Derivative
//  Serial.print("P Gain: ");
//  Serial.println((float)pid1.getPgain());
//  Serial.print("I Gain: ");
//  Serial.println((float)pid1.getIgain());
//  Serial.print("D Gain: ");
//  Serial.println((float)pid1.getDgain(), 7);
//  Serial.println("");
//
//  encoder1.resetCounter(0);
//  Serial.print("encoder1: ");
//  Serial.println(encoder1.getRawCount());
//  target = 1000;
//  pid1.setSetpoint(TARGET_POSITION, target);

  /************* PID 2 ***********************/

  pid2.setControlMode(CL_POSITION);

  //pid1.resetGains();
  //pid1.setLimits(-100,100);
  pid2.setGains(0.1f, 0.0f, 0.0f); //Proportional(change) Integral(change) Derivative
  Serial.print("P Gain: ");
  Serial.println((float)pid2.getPgain());
  Serial.print("I Gain: ");
  Serial.println((float)pid2.getIgain());
  Serial.print("D Gain: ");
  Serial.println((float)pid2.getDgain(), 7);
  Serial.println("");

  encoder2.resetCounter(0);
  Serial.print("encoder2: ");
  Serial.println(encoder2.getRawCount());
  target = 1000;
  pid2.setSetpoint(TARGET_POSITION, target);

}

void loop() {

  /************* PID 1 ***********************/

//  Serial.print("encoder1: ");
//  Serial.print(encoder1.getRawCount());
//  Serial.print(" target: ");
//  Serial.println(target);
//  if (encoder1.getRawCount() == target) {
//    target += 1000;
//    Serial.print("Target reached: Setting new target..");
//    pid1.setSetpoint(TARGET_POSITION, target);
//    //delay(5000);
//  }

  /************* PID 2 ***********************/

  Serial.print("encoder2: ");
  Serial.print(encoder2.getRawCount());
  Serial.print(" target: ");
  Serial.println(target);
  if (encoder2.getRawCount() == target) {
    target += 1000;
    Serial.print("Target reached: Setting new target..");
    pid2.setSetpoint(TARGET_POSITION, target);
    //delay(5000);
  }

  //---------------------------------------
  controller.ping();
  //wait
  delay(50);
}

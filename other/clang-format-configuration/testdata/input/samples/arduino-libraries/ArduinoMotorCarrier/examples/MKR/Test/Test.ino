/*
  MKR Motor Carrier Test sketch
  This sketch demonstrates some APIs exposed by the ArduinoMotorCarrier library.
  For the complete list, visit the reference page on https://www.arduino.cc/en/Reference/MKRMotorCarrier
  This example code is in the public domain.
*/

#include "ArduinoMotorCarrier.h"

void setup() {

  Serial.begin(115200);
  while (!Serial);

  // Start communication with the Motor Carrier
  if (controller.begin()) {
    Serial.print("MKR Motor Carrier connected, firmware version ");
    Serial.println(controller.getFWVersion());
  } else {
    Serial.println("Couldn't connect! Is the red LED blinking? You may need to update the firmware with FWUpdater sketch");
    while (1);
  }

  // Reboot the motor controller; brings every value back to default
  controller.reboot();

  Serial.println(controller.getFreeRam());

  // Reset the encoder internal counter to zero (can be set to any initial value)
  encoder1.resetCounter(0);

  // Start DC Motor 1 (labeled M1) with 90% of maximum speed, clockwise
  M1.setDuty(90);

  // Read the encoder connected to Motor1 until it reaches 36000 counts
  int motor1Pos = 0;
  while (motor1Pos < 36000) {
    motor1Pos = encoder1.getRawCount();
    // Remember to call ping() here and there!
    // If you forget to do so the controller will think that the user sketch is not running and will freeze.
    // You can wait up to 3 seconds between pings before the reset kicks in
    controller.ping();
  }

  // Switch motor control from DIRECT to PID-driven.
  // This way, you can program the motor to reach a certain position or velocity without any further intervention.
  // The PID can be carefully tuned if a particular profile is needed.
  pid1.setControlMode(CL_POSITION);
  pid1.setGains(25, 0, 3);
  pid1.setMaxAcceleration(4000);
  pid1.setSetpoint(TARGET_POSITION, 5000);
}

void loop() {
  // Simply print the actual position while the PID is running, pinging the controller every loop()
  Serial.println(encoder1.getRawCount());
  controller.ping();
  delay(100);
}

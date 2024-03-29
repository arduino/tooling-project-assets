/*
  Battery Charge Example

  This example shows how to configure and enable charge mode on Arduino MKR boards

  Circuit:
  - Arduino MKR board
  - 750 mAh LiPo battery

  created 21 Aug 2019
  by Riccardo Rizzo

  This sample code is part of the public domain.
*/

#include <Arduino_PMIC.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  if (!PMIC.begin()) {
    Serial.println("Failed to initialize PMIC!");
    while (1)
      ;
  }

  // Set the input current limit to 2 A and the overload input voltage to 3.88 V
  if (!PMIC.setInputCurrentLimit(2.0)) {
    Serial.println("Error in set input current limit");
  }

  if (!PMIC.setInputVoltageLimit(3.88)) {
    Serial.println("Error in set input voltage limit");
  }

  // set the minimum voltage used to feeding the module embed on Board
  if (!PMIC.setMinimumSystemVoltage(3.5)) {
    Serial.println("Error in set minimum system volage");
  }

  // Set the desired charge voltage to 4.11 V
  if (!PMIC.setChargeVoltage(4.2)) {
    Serial.println("Error in set charge volage");
  }

  // Set the charge current to 375 mA
  // the charge current should be defined as maximum at (C for hour)/2h
  // to avoid battery explosion (for example for a 750 mAh battery set to 0.375 A)
  if (!PMIC.setChargeCurrent(0.375)) {
    Serial.println("Error in set charge current");
  }
  Serial.println("Initialization done!");
}

void loop() {
  // Enable the Charger
  if (!PMIC.enableCharge()) {
    Serial.println("Error enabling Charge mode");
  }
  // canRunOnBattery() returns true if the battery voltage is < the minimum
  // systems voltage
  if (PMIC.canRunOnBattery()) {
    // loop until charge is done
    while (PMIC.chargeStatus() != CHARGE_TERMINATION_DONE) {
      delay(1000);
    }
    // Disable the charger and loop forever
    Serial.println("Disable Charge mode");
    if (!PMIC.disableCharge()) {
      Serial.println("Error disabling Charge mode");
    }
    while (1)
      ;
    // if you really want to detach the battery call
    // PMIC.disableBATFET();
    //isbatteryconnected = false;
  }
  delay(100);
}

#include "Arduino_PMIC.h"
#include "PF1550/PF1550_Register.h"

#define Serial Serial1

uint8_t regVal;

void setup() {
  Serial.begin(115200);
  while(!Serial);

  PMIC.begin();

  PMIC.debug(Serial);

}


void loop() {
  PMIC.writePMICreg(Register::CHARGER_CHG_EOC_CNFG, 0x41);
  regVal = PMIC.readPMICreg(Register::CHARGER_CHG_EOC_CNFG);

  Serial.print("CHARGER_CHG_SNS register value: ");
  Serial.println(regVal,HEX);
  
  regVal = PMIC.readPMICreg(Register::CHARGER_VBUS_SNS);

  Serial.print("CHARGER_VBUS_SNS register value: ");
  Serial.println(regVal,HEX);
  
  regVal = PMIC.readPMICreg(Register::CHARGER_CHG_INT_OK);

  Serial.print("CHARGER_CHG_INT_OK register value: ");
  Serial.println(regVal,HEX);
  Serial.println();
  Serial.println();

  delay(5000);
  
}

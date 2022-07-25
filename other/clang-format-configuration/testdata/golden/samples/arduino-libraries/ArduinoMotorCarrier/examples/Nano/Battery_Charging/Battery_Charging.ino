
#include <ArduinoMotorCarrier.h>

//Variable to store the battery voltage
float batteryVoltage;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  //while (!Serial);

  if (controller.begin())
  {
    Serial.print("Nano Motor Shield connected, firmware version ");
    Serial.println(controller.getFWVersion());
  }
  else
  {
    Serial.println("Couldn't connect! Is the red led blinking? You may need to update the firmware with FWUpdater sketch");
    while (1);
  }
}

// the loop function runs over and over again forever
void loop() {

  batteryVoltage = battery.getRaw()/236.0;
  Serial.print("Battery voltage: ");
  Serial.print(batteryVoltage,3);
  //Serial.println("V");
  Serial.print("V, Raw ");
  Serial.println(battery.getRaw());
  delay(5000); //wait for a few seconds
  
}

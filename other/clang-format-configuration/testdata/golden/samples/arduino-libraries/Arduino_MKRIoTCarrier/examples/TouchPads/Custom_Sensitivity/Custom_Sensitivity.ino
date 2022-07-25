#include "Arduino_MKRIoTCarrier.h"
MKRIoTCarrier carrier;

// When calling carrier.noCase() (default) it's set to 100 (closer)
// When calling carrier.case() it's set to 4  (further)
// But if you use Buttons.updateConfig(value) It will not set the above values

unsigned int threshold = 98;
unsigned int threshold_btn_0 = 95;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);

  carrier.begin();
  //carrier.noCase();
  //Now we can set our custom touch threshold
  // First we update all the buttons with the new threshold
  // Then we overwrite individually one of them (they can be all set individually too)
  carrier.Buttons.updateConfig(threshold);
  carrier.Buttons.updateConfig(threshold_btn_0, TOUCH0);
}

void loop() {
  // put your main code here, to run repeatedly:
  carrier.Buttons.update();
  
  // Verify your thresholds
  if (carrier.Buttons.getTouch(TOUCH0)) {
    Serial.println("touching 0");
  }
  
  if (carrier.Buttons.getTouch(TOUCH1)) {
    Serial.println("touching 1");
  }
  
  if (carrier.Buttons.getTouch(TOUCH2)) {
    Serial.println("touching 2");
  }
  
  if (carrier.Buttons.getTouch(TOUCH3)) {
    Serial.println("touching 3");
  }
  
  if (carrier.Buttons.getTouch(TOUCH4)) {
    Serial.println("touching 4");
  }
}

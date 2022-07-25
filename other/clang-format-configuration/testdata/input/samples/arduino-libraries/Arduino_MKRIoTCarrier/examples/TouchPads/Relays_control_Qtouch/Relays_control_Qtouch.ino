/*
  Set the relays with touch pads
*/
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

//False means Normally closed
bool newRelay1 = false;
bool newRelay2 = false;

//uint32_t myColor = carrier.leds.Color(green, red, blue)
uint32_t c_orange = carrier.leds.Color(15, 40, 0);
uint32_t c_green = carrier.leds.Color(40, 0, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  carrier.noCase();
  carrier.begin();

  carrier.leds.setPixelColor(0, c_green);
  carrier.leds.setPixelColor(4, c_green);
  carrier.leds.setPixelColor(2, c_green);
  carrier.leds.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  carrier.Buttons.update();

  /*  Qtouch events
      ButtonX.

      onTouchDown()
      onTouchUp()
      onTouchChange()
      getTouch()

  */

  //Side pads set the new status for each relay
  //The LED changes to Green its going to be NC (Normally Closed) or Orange to NO (Normally Open)
  //Then the middle pad its going to upload the relay status, to confirm both new status

  if (carrier.Buttons.onTouchDown(TOUCH0)) {
    newRelay2 = !newRelay2;
    if (newRelay2) {
      carrier.leds.setPixelColor(0, c_orange);
    } else {
      carrier.leds.setPixelColor(0, c_green);
    }
    carrier.leds.show();

  }
  if (carrier.Buttons.onTouchDown(TOUCH3)) {
    newRelay1 = !newRelay1;
    if (newRelay1) {
      carrier.leds.setPixelColor(4, c_orange);
    } else {
      carrier.leds.setPixelColor(4, c_green);
    }
    carrier.leds.show();
  }

  if (carrier.Buttons.onTouchDown(TOUCH1)) {
    carrier.leds.setPixelColor(2, c_orange);
    carrier.leds.show();

    //Set the relays
    //Relay 1
    if (newRelay1) {
      carrier.Relay1.open();
    } else {
      carrier.Relay1.close();
    }
    //Relay 1
    if (newRelay2) {
      carrier.Relay2.open();
    } else {
      carrier.Relay2.close();
    }

    delay(250);
    carrier.leds.setPixelColor(2, 0);
    carrier.leds.show();
    delay(250);
    carrier.leds.setPixelColor(2, c_green);
    carrier.leds.show();
  }

  delay(20);

}

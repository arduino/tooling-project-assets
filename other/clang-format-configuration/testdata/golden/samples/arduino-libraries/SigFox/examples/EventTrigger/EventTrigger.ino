/*
  SigFox Event Trigger tutorial

  This sketch demonstrates the usage of a MKR Fox 1200
  to build a battery-powered alarm sensor with email notifications

  A couple of sensors (normally open) should be wired between pins 1 and 2 and GND.

  This example code is in the public domain.
*/

#include <SigFox.h>
#include <ArduinoLowPower.h>

// Set debug to false to enable continuous mode
// and disable serial prints
int debug = true;

volatile int alarm_source = 0;

void setup() {

  if (debug == true) {

    // We are using Serial1 instead of Serial because we are going into standby
    // and the USB port could get confused during wakeup. To read the debug prints,
    // connect pins 13-14 (TX-RX) to a 3.3 V USB-to-serial converter

    Serial1.begin(115200);
    while (!Serial1) {}
  }

  if (!SigFox.begin()) {
    //something is really wrong, try rebooting
    reboot();
  }

  //Send module to standby until we need to send a message
  SigFox.end();

  if (debug == true) {
    // Enable debug prints and LED indication if we are testing
    SigFox.debug();
  }

  // attach pin 0 and 1 to a switch and enable the interrupt on voltage falling event
  pinMode(0, INPUT_PULLUP);
  LowPower.attachInterruptWakeup(0, alarmEvent1, FALLING);

  pinMode(1, INPUT_PULLUP);
  LowPower.attachInterruptWakeup(1, alarmEvent2, FALLING);
}

void loop()
{
  // Sleep until an event is recognized
  LowPower.sleep();

  // if we get here it means that an event was received

  SigFox.begin();

  if (debug == true) {
    Serial1.println("Alarm event on sensor " + String(alarm_source));
  }
  delay(100);

  // 3 bytes (ALM) + 8 bytes (ID as String) + 1 byte (source) < 12 bytes
  String to_be_sent = "ALM" + SigFox.ID() +  String(alarm_source);

  SigFox.beginPacket();
  SigFox.print(to_be_sent);
  int ret = SigFox.endPacket();

  // shut down module, back to standby
  SigFox.end();

  if (debug == true) {
    if (ret > 0) {
      Serial1.println("No transmission");
    } else {
      Serial1.println("Transmission ok");
    }

    Serial1.println(SigFox.status(SIGFOX));
    Serial1.println(SigFox.status(ATMEL));

    // Loop forever if we are testing for a single event
    while (1) {};
  }
}

void alarmEvent1() {
  alarm_source = 1;
}

void alarmEvent2() {
  alarm_source = 2;
}

void reboot() {
  NVIC_SystemReset();
  while (1);
}

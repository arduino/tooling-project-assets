/*

 This example tests to see if the modem of the
 MKR GSM 1400 board is working correctly. You do not need
 a SIM card for this example.

 Circuit:
 * MKR GSM 1400 board
 * Antenna

 Created 12 Jun 2012
 by David del Peral
 modified 21 Nov 2012
 by Tom Igoe
*/

// libraries
#include <MKRGSM.h>

// modem verification object
GSMModem modem;

// IMEI variable
String IMEI = "";

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  // start modem test (reset and check response)
  Serial.print("Starting modem test...");
  if (modem.begin()) {
    Serial.println("modem.begin() succeeded");
  } else {
    Serial.println("ERROR, no modem answer.");
  }
}

void loop() {
  // get modem IMEI
  Serial.print("Checking IMEI...");
  IMEI = modem.getIMEI();

  // check IMEI response
  if (IMEI != NULL) {
    // show IMEI in Serial Monitor
    Serial.println("Modem's IMEI: " + IMEI);
    // reset modem to check booting:
    Serial.print("Resetting modem...");
    modem.begin();
    // get and check IMEI one more time
    if (modem.getIMEI() != NULL) {
      Serial.println("Modem is functioning properly");
    } else {
      Serial.println("Error: getIMEI() failed after modem.begin()");
    }
  } else {
    Serial.println("Error: Could not get IMEI");
  }
  // do nothing:
  while (true)
    ;
}

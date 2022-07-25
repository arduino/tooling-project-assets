/*
    Arduino Edge Control - RTC Example

    This sketch shows how to use the RTC (PCF8563T) on the Arduino
    Edge Control and how to configure the RTC's time registers.

    Circuit:
    - Arduino Edge Control
    - CR2032 Battery
    - Optional: Arduino Edge Control LCD + Button brekout

*/

#include "Helpers.h"
#include <Arduino_EdgeControl.h>

void setup()
{
    pinMode(POWER_ON, INPUT);

    Serial.begin(9600);

    for (auto timeout = millis() + 2500l; !Serial && millis() < timeout; delay(250))
        ;

    Serial.println("Hello, Arduino Edge Control!");

    EdgeControl.begin();

    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    Wire.begin();
    delay(500);

    Serial.print("Initializating the Real Time Clock...");
    while (!RealTimeClock.begin()) {
        Serial.println(" failed! Retrying...");
        delay(250);
    }
    Serial.println(" done!");

    // APIs to set date's fields: years, months, days, hours, minutes and seconds
    // The RTC time can be set as epoch, using one of the following two options:
    // - Calendar time: RealTimeClock.setEpoch(years,  months,  days, hours, minutes, seconds);
    // - UTC time: RealTimeClock.setEpoch(date_in_seconds);

    // Set the RTC only when LCD's PowerOn button is pressed.
    // YMMV.
    if (digitalRead(POWER_ON) == LOW) {
        Serial.println("Resetting the RTC to Sketch Build Datetime!");
        auto buildDateTime = getBuildDateTime();
        RealTimeClock.setEpoch(buildDateTime);
        Serial.print("Build ");
    }
}

void loop()
{
    Serial.print("Date: ");
    Serial.println(getRTCDateTime());

    Serial.print("Unix time: ");
    Serial.println(time(NULL));

    delay(1000);
}

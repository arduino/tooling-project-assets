/*
  Arduino Edge Control - RTC Alarm Example

  This sketch shows how to use the RTC (PCF8563T) on the Arduino
  Edge Control and how to configure and use the RTC's alarm.

  Circuit:
   - Arduino Edge Control
   - CR2032 Battery
   - Optional: Arduino Edge Control LCD + Button brekout

*/

#include "Helpers.h"
#include <Arduino_EdgeControl.h>

volatile bool alarmFlag { false };
byte alarmInterval { 1 };

void setup()
{
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

    // Set the RTC only when LCD's PowerOn button is pressed.
    // YMMV.
    if (digitalRead(POWER_ON) == LOW) {
        auto buildDateTime = getBuildDateTime();
        RealTimeClock.setEpoch(buildDateTime);
        Serial.print("Build ");
    }

    Serial.print("Date: ");
    Serial.println(getRTCDateTime());

    // Enables Alarm on the RTC
    RealTimeClock.enableAlarm();

    // Set the minutes at which the alarm should rise
    // Trigger in a minute
    auto minutes = RealTimeClock.getMinutes();
    RealTimeClock.setMinuteAlarm(minutes + alarmInterval);

    // Attach an interrupt to the RTC interrupt pin
    attachInterrupt(
        digitalPinToInterrupt(IRQ_RTC), [] { alarmFlag = true; }, FALLING);

    Serial.println();
}

void loop()
{
    if (alarmFlag) {
        Serial.println("Alarm!");

        auto totalMinutes = RealTimeClock.getMinutes() + alarmInterval;
        
        // Take care of the 60-minute wrapping and...
        auto minutesAlarm = totalMinutes % 60;
        RealTimeClock.setMinuteAlarm(minutesAlarm);

        // don't forget to manage the hour increment.
        if (totalMinutes >= 60)
            RealTimeClock.setHourAlarm(RealTimeClock.getHours() + 1);

        RealTimeClock.clearAlarm();

        // To disable the alarm uncomment the following line:
        // RealTimeClock.disableAlarm();

        alarmFlag = false;
    }

    Serial.println(getRTCTime());
    delay(10000);
}

String getRTCDate()
{
    // APIs to get date fields.
    auto years = RealTimeClock.getYears();
    auto months = RealTimeClock.getMonths();
    auto days = RealTimeClock.getDays();

    char buf[12] {};

    snprintf(buf, 11, "20%02d-%02d-%02d", years, months, days);

    return String(buf);
}

String getRTCTime()
{
    // APIs to get time fields.
    auto hours = RealTimeClock.getHours();
    auto minutes = RealTimeClock.getMinutes();
    auto seconds = RealTimeClock.getSeconds();

    char buf[11] {};

    snprintf(buf, 10, "%02d:%02d:%02d", hours, minutes, seconds);

    return String(buf);
}

String getRTCDateTime()
{
    auto date = getRTCDate();
    auto time = getRTCTime();

    auto dateTime = date + ' ' + time;

    return dateTime;
}

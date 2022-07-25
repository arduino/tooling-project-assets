#pragma once

#include <Arduino.h>
#include <mbed_mktime.h>

#include "DebugMode.h"

rtos::Mutex pwrMutex;

void powerOn()
{
    DebugSerial.print("Powering On");
    auto locked = pwrMutex.trylock();
    if (!locked) {
        DebugSerial.println(": Already Powered On!");
        return;
    }
    DebugSerial.println();

    Power.on(PWR_VBAT);
    Power.on(PWR_3V3);
    Wire.begin();
    delay(500);
    Expander.begin();
    Input.begin();
}

void powerOff()
{
    DebugSerial.print("Powering Off");
    auto owner = rtos::ThisThread::get_id() == pwrMutex.get_owner();
    if (!owner) {
        DebugSerial.println(": Someone still needs power!");
        return;
    }
    DebugSerial.println();

    Input.end();
    Expander.end();
    Wire.end();
    Power.off(PWR_3V3);
    Power.off(PWR_VBAT);
    pwrMutex.unlock();
}

int getAverageInputRead(int pin, const size_t loops)
{
    unsigned int tot { 0 };

    analogReadResolution(ADC_RESOLUTION);

    Input.enable();
    for (auto i = 0u; i < loops; i++)
        tot += Input.analogRead(pin);
    Input.disable();

    return tot / loops;
}

// Convert compile time to system time
time_t buildDateTimeToSystemTime(const String date, const String time, bool local_time = true, int tz = 0)
{
    char s_month[5];
    int year;

    tm t;
    time_t seconds;

    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    sscanf(date.c_str(), "%s %d %d", s_month, &t.tm_mday, &year);
    sscanf(time.c_str(), "%2d %*c %2d %*c %2d", &t.tm_hour, &t.tm_min, &t.tm_sec);

    // Find where is s_month in month_names. Deduce month value.
    t.tm_mon = (strstr(month_names, s_month) - month_names) / 3;
    t.tm_year = year - 1900;
    _rtc_maketime(&t, &seconds, RTC_FULL_LEAP_YEAR_SUPPORT);

    if (!local_time) {
        if (tz > 200) {
            tz = 0x100 - tz; // Handle negative values
            seconds += (3600UL) * tz;
        } else {
            seconds -= (3600UL) * tz;
        }
    }

    return seconds;
}

String getLocaltime()
{
    char buffer[32];
    tm t;
    _rtc_localtime(time(NULL), &t, RTC_FULL_LEAP_YEAR_SUPPORT);
    strftime(buffer, 32, "%Y-%m-%d %k:%M:%S", &t);
    return String(buffer);
}

String getLocaltime(const time_t& build_time)
{
    char buffer[32];
    tm t;
    _rtc_localtime(build_time, &t, RTC_FULL_LEAP_YEAR_SUPPORT);
    strftime(buffer, 32, "%Y-%m-%d %k:%M:%S", &t);
    return String(buffer);
}

/**
 * Set system clock from compile datetime or RTC
 */
void setSystemClock(String buildDate, String buildTime)
{
    // Retrieve clock time from compile date...
    auto buildDateTime = buildDateTimeToSystemTime(buildDate, buildTime, true, 2);
    // ... ore use the one from integrated RTC.
    auto rtcTime = time(NULL);

    // Remember to connect at least the CR2032 battery
    // to keep the RTC running.
    auto actualTime = rtcTime > buildDateTime ? rtcTime : buildDateTime;

    // Set both system time
    set_time(actualTime);

    DebugSerial.print("Compile Date and Time: ");
    DebugSerial.println(getLocaltime(buildDateTime));
    DebugSerial.print("RTC Date and Time:     ");
    DebugSerial.println(getLocaltime(rtcTime));
    DebugSerial.print("System Clock:          ");
    DebugSerial.println(getLocaltime());
}

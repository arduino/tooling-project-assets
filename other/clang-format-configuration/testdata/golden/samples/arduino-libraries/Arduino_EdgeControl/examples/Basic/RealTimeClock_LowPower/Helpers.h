#pragma once

#include <Arduino.h>
#include <Arduino_EdgeControl.h>
#include <mbed_mktime.h>

// Convert build time to UNIX time
time_t getBuildDateTime(bool local_time = true, int tz = 0)
{
    char s_month[5];
    int year;

    tm t;
    time_t seconds;

    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

    sscanf(__DATE__, "%s %d %d", s_month, &t.tm_mday, &year);
    sscanf(__TIME__, "%2d %*c %2d %*c %2d", &t.tm_hour, &t.tm_min, &t.tm_sec);

    // Find where is s_month in month_names. Deduce month value.
    t.tm_mon = (strstr(month_names, s_month) - month_names) / 3 + 1;
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

String getLocaltime(const char* fmt, bool local_time = true, int tz = 0)
{
    char buffer[64];
    time_t tmp_time = time(NULL);
    tm t;

    if (!local_time) {
        if (tz > 200) {
            tz = 0x100 - tz; // Handle negative values
            tmp_time -= (3600UL) * tz;
        } else {
            tmp_time += (3600UL) * tz;
        }
    }

    _rtc_localtime(tmp_time, &t, RTC_FULL_LEAP_YEAR_SUPPORT);
    strftime(buffer, 64, fmt, &t);
    return String(buffer);
}

String getLocaltime(const time_t build_time, const char* fmt, bool local_time = true, int tz = 0)
{
    char buffer[64];
    time_t tmp_time = build_time;
    tm t;

    if (!local_time) {
        if (tz > 200) {
            tz = 0x100 - tz; // Handle negative values
            tmp_time -= (3600UL) * tz;
        } else {
            tmp_time += (3600UL) * tz;
        }
    }

    _rtc_localtime(tmp_time, &t, RTC_FULL_LEAP_YEAR_SUPPORT);
    strftime(buffer, 64, fmt, &t);
    return String(buffer);
}

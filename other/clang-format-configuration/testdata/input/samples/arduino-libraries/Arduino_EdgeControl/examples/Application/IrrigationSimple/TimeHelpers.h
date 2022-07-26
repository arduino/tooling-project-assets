#pragma once

#include <Arduino.h>
#include <mbed_mktime.h>

// Convert compile time to system time
time_t buildDateTimeToSystemTime(const String, const String, bool local_time, int tz);
String getLocaltime();
String getLocaltime(const time_t &build_time);
String getLocaltime(const char *fmt, bool local_time, int);
String getLocaltime(const time_t build_time, const char *fmt, bool local_time, int tz);

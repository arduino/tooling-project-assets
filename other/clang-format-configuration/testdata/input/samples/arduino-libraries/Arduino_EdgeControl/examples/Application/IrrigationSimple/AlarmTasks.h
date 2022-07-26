#pragma once

#include <Arduino.h>
#include <list>
#include <map>

#include <SD.h>
#include <TimeLib.h>
#include <TimeAlarms.h>

#include "CustomTasks.h"

/**
 * Supported alarm types
 */
enum AlarmMethod { 
    METHOD_INVALID,
    ALARM_REPEAT,
    ALARM_ONCE,
    TIMER_REPEAT,
    TIMER_ONCE,
    TRIGGER_ONCE,
};

/**
 * The internal structure for managing tasks
 */
struct AlarmTask {
    AlarmMethod method { METHOD_INVALID };
    OnTick_t handler { nullptr };
    timeDayOfWeek_t day;
    int hour;
    int min;
    int sec;
};

/**
 * An helper map for parsing alarm types from alarmtab lines
 */ 
static std::map<const String, AlarmMethod> alarmMethods {
    {"AR", ALARM_REPEAT},
    {"AO", ALARM_ONCE},
    {"TR", TIMER_REPEAT},
    {"TO", TIMER_ONCE},
    {"RO", TRIGGER_ONCE},
};

/**
 * Parse a task line from the alarmtab.txt file
 */
AlarmTask parseAlarmTask(const String line);

/**
 * Parse the alarmtab.txt file
 */ 
std::list<AlarmTask> parseAlarmTab(File& file);

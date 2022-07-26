#pragma once

#include "SensorsData.h"
#include "TimeHelpers.h"
#include <Arduino_EdgeControl.h>
#include <TimeAlarms.h>
#include <mbed.h>
#include <mbed_mktime.h>

#include <list>
#include <map>

void setSystemClock(String date = __DATE__, String time = __TIME__);
void statusLCD();
void backlightOff(bool powerDown);
uint16_t getAverageInputRead(int pin, size_t loops = 20);
float getAverage05VRead(int pin);
uint8_t getMoisturePerc(int pin);
void displayMsg(const String msg, const unsigned timeout = 5000, const unsigned line = 0, const bool clear = true, const bool off = true);

extern std::list<AlarmID_t> alarmTabIDs;
extern std::list<AlarmID_t> alarmSketchIDs;
extern std::list<DataPoint> dataPoints;

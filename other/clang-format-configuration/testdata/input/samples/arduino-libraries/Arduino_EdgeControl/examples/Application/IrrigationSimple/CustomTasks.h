#pragma once

#include <Arduino.h>
#include <Arduino_EdgeControl.h>
#include <SD.h>
#include <TimeAlarms.h>
#include <TimeLib.h>

#include <list>
#include <map>

#include "Helpers.h"
#include "SensorsData.h"
#include "TimeHelpers.h"

void openLatchingValve();
void closeLatchingValve();
void openSolenoidValve();
void closeSolenoidValve();
void displayClock();
void blinkLed();
void saveData();
void helloWorld();
void hiThere();
void getSensors();

/**
 * Define your task function and add it to the commandMap.
 * The key of the map is the name to be used in the alarmtab file.
 */
static std::map<String, OnTick_t> commandMap {
    { "OpenLatchingValve", openLatchingValve },
    { "CloseLatchingValve", closeLatchingValve },
    { "OpenSolenoidValve", openSolenoidValve },
    { "CloseSolenoidValve", closeSolenoidValve },
    { "DisplayClock", displayClock },
    { "BlinkLed", blinkLed },
    { "SaveData", saveData },
    { "HelloWorld", helloWorld },
    { "HiThere", hiThere },
    { "GetSensors", getSensors },
};
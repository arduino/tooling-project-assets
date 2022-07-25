#pragma once

#include <Arduino_EdgeControl.h>
#include <SD.h>
#include <list>

#include "AlarmTasks.h"

std::list<AlarmTask> loadTasks();
std::list<AlarmID_t> setTasks(std::list<AlarmTask> taskList);
void freeTasks(std::list<AlarmID_t>& alarmIDs);
void loadAndSetTasks(std::list<AlarmID_t>& alarmIDs, bool reload = false);
void printTasks(const std::list<AlarmTask> taskList);


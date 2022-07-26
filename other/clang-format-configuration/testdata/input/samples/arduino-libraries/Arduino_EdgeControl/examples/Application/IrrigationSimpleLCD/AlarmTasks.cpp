#include "AlarmTasks.h"

/**
* Parse a task line from the alarmtab.txt file
*
* Lines must follow the following structure.
*
* The name of the command to execute must match an entry
* in the 'commandMap' map defined in the CustomTasks.h file.
*
* In case of TR, TO and RO alarm types, the day of week, hour
* and minute parameters are ignored.
* In case of RO alarm type, the second parameters must bean UNIX
* specified as UNIX timestamp (seconds since EPOCH).
*
* See the TimeAlarms (https://github.com/PaulStoffregen/TimeAlarms)
* docs for further specs.
* 
* Lines starting with pound symbol (#) are ignored.
*
*
* ┌──────────── alarm type: AR == AlarmRepeat, AO == AlarmOnce,
* |                         TR == TimerRepeat, TO == TimerOnne,
* |                         RO == TriggerOnce
* |  ┌────────── day of week: 0 == None, 1 == Sun, ..., 7 == Sat
* |  |  ┌─────── hour
* |  |  |  ┌──── minute  
* |  |  |  |  ┌─ second
* |  |  |  |  |
* |  |  |  |  |  <command to execute> 
* AR 0 18 45  0  OpenLatchingValve
* AR 0 18 45 30  CloseLatchingValve
* AR 0 18 46  0  OpenLatchingValve
* AR 0 18 46 30  CloseLatchingValve
* TR 0  0  0 20  DisplayClock
* TR 0  0  0 10  BlinkLed
* TO 0  0  0 10  DisplayClockOnce
* RO 0  0  0 1602759860  DisplayClockTrigger
*
*/
AlarmTask parseAlarmTask(const String line)
{
    auto const len { line.length() + 1 };
    char buf[len] { 0 };
    char cmd[32] { 0 };
    char method[3] { 0 };

    AlarmTask task;

    line.toCharArray(buf, len);
    auto n = sscanf(buf, "%s %d %d %d %d %s", method, &task.day, &task.hour, &task.min, &task.sec, cmd);
    if (n != 6)
        return task;

    auto itm = alarmMethods.find(method);
    if (itm != alarmMethods.end())
        task.method = itm->second;

    auto itc = commandMap.find(cmd);
    if (itc != commandMap.end())
        task.handler = itc->second;

    return task;
}

/**
 * Parse the alarmtab.txt file
 */ 
std::list<AlarmTask> parseAlarmTab(File& file)
{
    std::list<AlarmTask> taskList;

    while (file.available()) {
        auto line = file.readStringUntil('\n');
        if ( line.charAt(0) == '#' )
            continue;
        auto task = parseAlarmTask(line);
        if (task.handler != nullptr && task.method != METHOD_INVALID)
            taskList.push_back(task);
    }

    return taskList;
}

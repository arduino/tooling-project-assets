/**
 * Simple irrigation system with Arduino EdgeControl
 * 
 * Circuit:
 * - Arduino EdgeControl
 * - MicroSD card
 * - CR2032 Battery and/or 12V Lead Battery
 * - Button connected to POWER_ON pin on the LCD breakout header
 * 
 * Usage:
 * - Define your callback functions in CustomTasks.{h,cpp}
 * - Map the callback functions to alarmatab command names in
 *   CustomTasks.h::commandMap map.
 * - Add tasks to the alarmtab.txt file and copy it on the SD card;
 *   See alarmtab.txt and AlarmTasks.cpp for documentation.
 */

#include <Arduino_EdgeControl.h>

#include "AlarmTasks.h"
#include "SensorsData.h"
#include "TimeHelpers.h"
#include "TasksHelpers.h"
#include "Helpers.h"

/** UI Management **/
// Button statuses
enum ButtonStatus : byte {
    ZERO_TAP,
    SINGLE_TAP,
    DOUBLE_TAP,
    TRIPLE_TAP,
    LOT_OF_TAPS
};

// ISR: count the button taps
volatile byte taps { 0 };
// ISR: keep elapsed timings
volatile unsigned long previousPress { 0 };
// ISR: Final button status
volatile ButtonStatus buttonStatus { ZERO_TAP };

/**
 * Used to keep track of the running alarms from
 * alarmtab.txt.
 *
 * The loadAndSetTasks() function will fill this
 * with tasks defined in CustomTasks.{h.cpp} and
 * loaded from the alarmtab.txt on the SD.
 *
 */
std::list<AlarmID_t> alarmTabIDs;

/**
 * Used to keep track of the alarms defined in the
 * sketch.
 */
std::list<AlarmID_t> alarmSketchIDs;

/**
 * Used to keep track of the measurements points
 */
std::list<DataPoint> dataPoints;

void setup()
{
    Serial.begin(9600);
    constexpr unsigned long timeout { 2500 };

    // Wait for Serial Monitor for timeout ms
    auto startNow = millis() + timeout;
    while (!Serial && millis() < startNow )
        ;

    delay(1000);

    // Set System and Alarm clock
    // Use compile datetime as proxy clock synch
    // Use a CR2032 battery for persistent RTC.
    setSystemClock();

    // Init board-related objects
    EdgeControl.begin();

    // Enable the 3V3 and 12V power rails.
    // Needed for IO Expander and SD card.
    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    // Init the sensors inputs.
    // If needed, will also take care of enabling the
    // 3V3 and 12V power rails and to initialize the IO Expander.
    Input.begin();

    Latching.begin();
    Latching.channelDirection(LATCHING_OUT_1, POSITIVE);
    Latching.strobe(5000);
    Latching.channelDirection(LATCHING_OUT_1, NEGATIVE);
    Latching.strobe(5000);

    Relay.begin();
    delay(1000);
    Relay.on(RELAY_CH01);
    delay(5000);
    Relay.off(RELAY_CH01);

    // Load alarm tasks list from file on SD.
    // See example alarmtab.txt for example and
    // AlarmTasks.{h, cpp} source files for documentation.
    loadAndSetTasks(alarmTabIDs);

    // Use the a button for housekeeping stuff:
    // Single Tap: Show status
    // Double Tap: Reload alarm tasks from SD
    // Triple Tap: Force saving data to SD
    pinMode(POWER_ON, INPUT);
    attachInterrupt(POWER_ON, buttonPress, RISING);

    auto id = Alarm.timerRepeat(10, getSensors);
    alarmSketchIDs.push_back(id);    
}

void loop()
{
    // Do alarms processing
    Alarm.delay(10);

    // Detect Single Tap, Double Tap, etc.
    // to buttonStatus
    detectTaps();

    switch (buttonStatus) {
    case ZERO_TAP:
        break;
    case SINGLE_TAP:
        Serial.println("Single Tap");
        statusPrint();
        buttonStatus = ZERO_TAP;
        break;
    case DOUBLE_TAP:
        Serial.println("Double Tap");
        loadAndSetTasks(alarmTabIDs, true);
        buttonStatus = ZERO_TAP;
        break;
    case TRIPLE_TAP:
        Serial.println("Triple Tap");
        saveData();
        buttonStatus = ZERO_TAP;
        break;
    default:
        Serial.println("Too Many Taps");
        buttonStatus = ZERO_TAP;
        break;
    }
}

void buttonPress()
{
    const auto now = millis();
    // Poor-man debouncing
    if (now - previousPress > 100)
        taps++;

    previousPress = now;
}

void detectTaps()
{
    // Timeout to validate the button taps counter
    constexpr unsigned int buttonTapsTimeout { 300 };

    // Set the button status and reset the taps counter when button has been
    // pressed at least once and button taps validation timeout has been reached.
    if (taps > 0 && millis() - previousPress >= buttonTapsTimeout) {
        buttonStatus = static_cast<ButtonStatus>(taps);
        taps = 0;
    }
}

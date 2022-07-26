#include "CustomTasks.h"

void openLatchingValve()
{
    Serial.println("Alarm: Opening Latching Valve");

    LCD.home();
    LCD.backlight();
    LCD.print(getLocaltime());
    LCD.setCursor(0, 1);
    LCD.print("Opening Valve   ");

    // Polarize the opening pin of the 3-wires valve
    Latching.channelDirection(LATCHING_OUT_1, POSITIVE);
    Latching.strobe(5000);

    LCD.setCursor(0, 1);
    LCD.print("Valve Open      ");

    // Power off the backlight after 5 seconds
    Alarm.timerOnce(5, [] { backlightOff(false); });
}

void closeLatchingValve()
{
    Serial.println("Alarm: Closing Latching Valve");

    LCD.home();
    LCD.backlight();
    LCD.print(getLocaltime());
    LCD.setCursor(0, 1);
    LCD.print("Closing Valve   ");

    // Polarize the closing pin of the 3-wires valve
    Latching.channelDirection(LATCHING_OUT_1, NEGATIVE);
    Latching.strobe(5000);

    LCD.setCursor(0, 1);
    LCD.print("Valve Closed    ");

    // Power off the backlight after 5 seconds
    // and power off everything else
    Alarm.timerOnce(5, [] { backlightOff(true); });
}

void openSolenoidValve()
{
    Serial.println("Alarm: Opening Solenoid Valve");

    LCD.home();
    LCD.backlight();
    LCD.print(getLocaltime());
    LCD.setCursor(0, 1);
    LCD.print("Opening Valve   ");

    // Open the Solid State Relay on Channel 1
    Relay.on(RELAY_CH01);

    LCD.setCursor(0, 1);
    LCD.print("Valve Open      ");

    // Power off the backlight after 5 seconds
    Alarm.timerOnce(5, [] { backlightOff(false); });
}

void closeSolenoidValve()
{
    Serial.println("Alarm: Closing Solenoid Valve");

    LCD.home();
    LCD.backlight();
    LCD.print(getLocaltime());
    LCD.setCursor(0, 1);
    LCD.print("Closing Valve   ");

    // Close the Solid State Relay on Channel 1
    Relay.off(RELAY_CH01);

    LCD.setCursor(0, 1);
    LCD.print("Valve Closed    ");

    // Power off the backlight after 5 seconds
    // and power off everything else
    Alarm.timerOnce(5, [] { backlightOff(true); });
}

void displayClock()
{
    String date = getLocaltime("%Y-%m-%d", true, 0);
    String time = getLocaltime("%k:%M:%S", true, 0);
    displayMsg(date, 0, 0, true, false);
    displayMsg(time, 5000, 1, false, true);
}

void blinkLed()
{
    Expander.pinMode(EXP_LED1, OUTPUT);
    Expander.digitalWrite(EXP_LED1, LOW);
    delay(10);

    // Power off the on-board LED (active low)
    Expander.pinMode(EXP_LED1, OUTPUT);
    Expander.digitalWrite(EXP_LED1, HIGH);
}

void getSensors()
{
    extern std::list<DataPoint> dataPoints;

    String msg = "Moisture: ";
    Serial.print(msg);

    auto value = getAverageInputRead(INPUT_05V_CH01);
    auto perc = getMoisturePerc(INPUT_05V_CH01);

    DataPoint d{value, perc};

    Serial.println(d);
    dataPoints.push_back(d);

    Alarm.timerOnce(5, [] { backlightOff(true); });
}

void saveData()
{
    String msg = "Saving Data";
    Serial.println(msg);
    LCD.clear();
    LCD.backlight();
    LCD.home();
    LCD.print(msg);
    for (auto rem = 16 - msg.length(); rem > 0; rem--)
        LCD.write(' ');

    LCD.home();
    LCD.setCursor(0, 1);
    auto ret = saveSensorsData();
    if (ret <= 0)
        LCD.print("ERROR:");
    else
        LCD.print("Saved:");

    LCD.print(ret);

    Alarm.timerOnce(5, [] { backlightOff(true); });
}

void helloWorld()
{
    displayMsg("Hello, World!");
}

void hiThere()
{
    displayMsg("Hi, There!");
}
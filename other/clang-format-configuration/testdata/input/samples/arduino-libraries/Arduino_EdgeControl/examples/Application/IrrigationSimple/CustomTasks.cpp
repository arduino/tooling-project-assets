#include "CustomTasks.h"

void openLatchingValve()
{
    Serial.println("Alarm: Opening Latching Valve");

    Serial.print("[");
    Serial.print(getLocaltime());
    Serial.print("] Opening Valve: ");

    // Polarize the opening pin of the 3-wires valve
    Latching.channelDirection(LATCHING_OUT_1, POSITIVE);
    Latching.strobe(5000);

    Serial.println("Valve Open");
}

void closeLatchingValve()
{
    Serial.println("Alarm: Closing Latching Valve");

    Serial.print("[");
    Serial.print(getLocaltime());
    Serial.print("] Closing Valve: ");

    // Polarize the closing pin of the 3-wires valve
    Latching.channelDirection(LATCHING_OUT_1, NEGATIVE);
    Latching.strobe(5000);

    Serial.println("Valve Closed");
}

void openSolenoidValve()
{
    Serial.println("Alarm: Opening Solenoid Valve");

    Serial.print("[");
    Serial.print(getLocaltime());
    Serial.print("] Opening Valve: ");

    // Open the Solid State Relay on Channel 1
    Relay.on(RELAY_CH01);

    Serial.println("Valve Open");
}

void closeSolenoidValve()
{
    Serial.println("Alarm: Closing Solenoid Valve");

    Serial.print("[");
    Serial.print(getLocaltime());
    Serial.print("] Closing Valve: ");

    // Close the Solid State Relay on Channel 1
    Relay.off(RELAY_CH01);

    Serial.println("Valve Closed");
}

void displayClock()
{
    String date = getLocaltime("%Y-%m-%d", true, 0);
    String time = getLocaltime("%k:%M:%S", true, 0);
    Serial.println(date);
    Serial.println(time);
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

    Serial.print("Moisture: ");

    auto value = getAverageInputRead(INPUT_05V_CH01);
    auto perc = getMoisturePerc(INPUT_05V_CH01);

    DataPoint d{value, perc};

    Serial.println(d);
    dataPoints.push_back(d);
}

void saveData()
{
    Serial.println("Saving Data...");

    auto ret = saveSensorsData();
    if (ret <= 0)
        Serial.print("Error: ");
    else
        Serial.print("Saved: ");

    Serial.println(ret);
}

void helloWorld()
{
    Serial.println("Hello, World!");
}

void hiThere()
{
    Serial.println("Hi, There!");
}
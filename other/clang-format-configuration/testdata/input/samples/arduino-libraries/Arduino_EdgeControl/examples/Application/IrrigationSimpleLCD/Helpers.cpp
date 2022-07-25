#include "Helpers.h"

/**
 * Set system and TimeAlarm clock from compile datetime or RTC
 */
void setSystemClock(String buildDate, String buildTime)
{
    // Retrieve clock time from compile date...
    auto buildDateTime = buildDateTimeToSystemTime(buildDate, buildTime, true, 2);
    // ... ore use the one from integrated RTC.
    auto rtcTime = time(NULL);

    // Remember to connect at least the CR2032 battery
    // to keep the RTC running.
    auto actualTime = rtcTime > buildDateTime ? rtcTime : buildDateTime;

    // Set both system time and the alarms one
    set_time(actualTime);
    setTime(actualTime);

    Serial.print("Compile Date and Time: ");
    Serial.println(getLocaltime(buildDateTime));
    Serial.print("RTC Date and Time:     ");
    Serial.println(getLocaltime(rtcTime));
    Serial.print("System Clock:          ");
    Serial.println(getLocaltime());
}

void statusLCD()
{
    // Small helper for waiting without delay()
    auto wait = [](size_t timeout) {
        for (auto go = millis() + timeout; millis() < go; yield())
            ;
    };

    String msg;

    LCD.clear();
    LCD.backlight();

    LCD.home();
    LCD.print("Measures...");

    wait(500);

    LCD.setCursor(16, 0);
    msg = "Moisture [";
    msg += dataPoints.size();
    msg += "]";
    LCD.print(msg);
    LCD.autoscroll();
    LCD.setCursor(16, 1);
    msg = "Latest: ";
    auto d = dataPoints.back();
    msg += d.moistureP;
    msg += "%";

    while (msg.length() < 16)
        msg += ' ';

    LCD.print(msg);
    LCD.noAutoscroll();
    wait(1000);

    LCD.clear();
    LCD.home();
    LCD.print("Loaded Tasks...");

    wait(500);

    LCD.setCursor(16, 0);
    msg = "Custom: ";
    msg += alarmTabIDs.size();
    LCD.print(msg);
    LCD.autoscroll();
    LCD.setCursor(16, 1);
    msg = "Sketch: ";
    msg += alarmSketchIDs.size();

    while (msg.length() < 16)
        msg += ' ';

    LCD.print(msg);
    LCD.noAutoscroll();
    wait(1000);

    // Power off the backlight after 5 seconds
    // and power off everything else
    Alarm.timerOnce(5, [] { backlightOff(true); });
}

void backlightOff(bool powerDown)
{
    LCD.noBacklight();
    if (powerDown)
        LCD.clear();
}

float getAverage05VRead(int pin)
{
    constexpr size_t loops { 10 };
    constexpr float toV { 3.3f / float { (1 << ADC_RESOLUTION) - 1 } };

    // Resistor divider on Input ports
    constexpr float rDiv { 17.4f / (10.0f + 17.4f) };

    int tot { 0 };

    analogReadResolution(ADC_RESOLUTION);

    Input.enable();
    for (auto i = 0u; i < loops; i++)
        tot += Input.analogRead(pin);
    Input.disable();

    const auto avg = static_cast<float>(tot) * toV / static_cast<float>(loops);

    return avg / rDiv;
}

uint16_t getAverageInputRead(int pin, const size_t loops)
{
    unsigned int tot { 0 };

    analogReadResolution(ADC_RESOLUTION);

    Input.enable();
    for (auto i = 0u; i < loops; i++)
        tot += Input.analogRead(pin);
    Input.disable();

    return tot / loops;
}

uint8_t getMoisturePerc(int pin)
{
    // Keep track ok dry/wet values. YMMV.
    static long dryValue { 2160 };
    static long wetValue { 975 };

    auto val = getAverageInputRead(pin);

    // Self-update dry/wet values range.
    if (val > dryValue)
        dryValue = val;
    if (val < wetValue)
        wetValue = val;

    auto perc = map(val, dryValue, wetValue, 0, 100);

    return perc;
}

void displayMsg(const String msg, const unsigned timeout, const unsigned line, const bool clear, const bool off)
{
    if (clear)
        LCD.clear();
        
    LCD.home();
    LCD.backlight();

    if (line == 1)
        LCD.setCursor(0, 1);

    if (msg.length() > 16)
        LCD.autoscroll();

    LCD.print(msg);

    for (auto go = millis() + timeout; millis() < go; yield())
        ;

    LCD.noAutoscroll();

    if (off) {
        LCD.clear();
        LCD.noBacklight();
    }
}

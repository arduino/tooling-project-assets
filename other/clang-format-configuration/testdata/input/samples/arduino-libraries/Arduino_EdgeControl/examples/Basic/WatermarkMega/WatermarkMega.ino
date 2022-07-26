/*
    This sketch is the implementation of the classic Watermark example
    for Arduino Mega ported to the Arduino Edge Control.

    Please, refer to https://www.irrometer.com/200ss.html for further info.

    Another algorithm that can be implemented using the Watermark circuits
    on the Edge Control is the one described at
    https://medium.com/fasal-engineering/a-low-cost-circuit-to-read-from-multiple-watermark-irrometer-200ss-sensors-a4c838da233a

    Requirements:
    - Arduino Edge Control
    - Watermark Sensor
    - External 12V power supply
    
    Circuit:
    - Connect PS 12V and GND to BATT+ and GND pins
    - Connect the two sensor's cables to WATERMARK COMM and INPUT 1 pins
    
*/

#include <Arduino_EdgeControl.h>

constexpr auto adcResolution { 12 };

// You will need a proper temperature value to get correct results
auto refTemperature { 24.5f };

void setup()
{
    Serial.begin(115200);

    // Wait for Serial or start after 2.5s
    for (const auto startNow = millis() + 2500; !Serial && millis() < startNow; delay(250));

    EdgeControl.begin();
    delay(2000);

    Serial.println("Hello, Watermark Mega");

    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    Wire.begin();
    delay(500);

    Serial.print("Waiting for IO Expander Initialization...");
    while (!Expander.begin()) {
        Serial.print(".");
        delay(250);
    }
    Serial.println(" done.");

    Watermark.begin();
    Serial.println("Watermark OK");
}

void loop()
{
    auto wm = getWatermark(WATERMARK_CH01);
    Serial.print("Watermark = ");
    Serial.print(wm);
    Serial.println("kPa");

    delay(1000);
}


int getAverageWatermarkRead(pin_size_t pin)
{
    constexpr size_t count { 20 };
    int sum { 0 };

    Watermark.calibrationMode(OUTPUT);
    Watermark.calibrationWrite(LOW);

    Watermark.commonMode(OUTPUT);

    Watermark.enable();

    for (auto i = 0u; i < count; i++) {
        Watermark.commonWrite(HIGH);
        delay(2);
        sum += Watermark.analogRead(pin);
        Watermark.commonWrite(LOW);
    }

    Watermark.disable();

    return sum / count;
}

float getWatermark(pin_size_t pin)
{
    constexpr unsigned int calibResistor { 7870 };
    constexpr long openResistance { 35000 };
    constexpr long shortResistance { 200 };
    constexpr long shortkPa { 240 };
    constexpr long openkPa { 255 };

    constexpr auto maxValue { 1 << adcResolution };
    constexpr float toV { 3.3f / float { maxValue } };

    float kPa;

    auto val = getAverageWatermarkRead(pin);

    if (val == 0)
        return openkPa;

    auto resistor = calibResistor * float { maxValue - val } / float { val };

    if (resistor > 550.f) {
        if (resistor > 8000.f) {
            kPa = -2.246f - 5.239f * (resistor / 1500.f) * (1.f + .018f * (refTemperature - 24.f)) - .06756f * (resistor / 1500.f) * (resistor / 1500.f) * ((1.f + 0.018f * (refTemperature - 24.f)) * (1.f + 0.018f * (refTemperature - 24.f)));
        } else if (resistor > 1500.f) {
            kPa = (-3.213f * (resistor / 1500.f) - 4.093f) / (1.f - 0.009733f * (resistor / 1500.f) - 0.01205f * (refTemperature));
        } else {
            kPa = ((resistor / 1500.f) * 23.156f - 12.736f) * (1.f + 0.018f * (refTemperature - 24.f));
        }
    } else {
        if (resistor > 300.f)
            kPa = 0.f;
        if (resistor < 300.f && resistor >= shortResistance)
            kPa = shortkPa; // 240 is a fault code for sensor terminal short
    }

    if (resistor >= openResistance) {
        kPa = openkPa; // 255 is a fault code for open circuit or sensor not present
    }

    Serial.print("Watermark average analogRead value: ");
    Serial.print(val);
    Serial.print(" - Calculated Resistor: ");
    Serial.print(resistor);
    Serial.println();

    return abs(kPa);
}

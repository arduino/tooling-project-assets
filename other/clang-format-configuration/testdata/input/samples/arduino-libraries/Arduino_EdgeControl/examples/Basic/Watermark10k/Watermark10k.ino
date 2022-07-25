#include <Arduino_EdgeControl.h>

constexpr unsigned int calibResistor { 7870 };

void setup()
{
    Serial.begin(115200);

    auto startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;

    EdgeControl.begin();
    delay(2000);

    Serial.println("Hello, 10k");

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

    Watermark.calibrationMode(OUTPUT);
    Watermark.calibrationWrite(LOW);

    Watermark.commonMode(OUTPUT);
    Watermark.commonWrite(HIGH);

}

void loop()
{
    auto val = wmkAvgAnalogRead(WATERMARK_CH01);
    Serial.print("Watermark Channel 01");
    Serial.print(" - average analogRead value: ");
    Serial.print(val);
    Serial.print(" -  Calculated Resistor: ");
    Serial.println(calibResistor * (1023 - val) / val);

    delay(1000);
}

int wmkAvgAnalogRead(pin_size_t pin)
{
    constexpr size_t count { 10 };
    unsigned int sum { 0 };

    Watermark.enable();
    for (auto i = 0u; i < count; i ++)
        sum += Watermark.analogRead(pin);
    Watermark.disable();

    return sum / count;
}

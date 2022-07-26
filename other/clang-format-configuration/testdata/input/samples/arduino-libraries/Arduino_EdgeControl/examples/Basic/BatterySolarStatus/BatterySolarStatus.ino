#include <Arduino_EdgeControl.h>

constexpr uint32_t printInterval { 5000 };
uint32_t printNow { 0 };

void setup()
{
    Serial.begin(115200);

    const uint32_t startNow { millis() + 2500 };
    while (!Serial && millis() < startNow)
        ;

    delay(1000);
    Serial.println("Checking Power Supply and Solar Charger status");

    EdgeControl.begin();
    Power.on(PWR_VBAT);
    Power.on(PWR_3V3);

    Wire.begin();
    delay(500);

    Serial.print("I/O Expander initializazion ");
    while (!Expander.begin()) {
        Serial.println("failed.");
        Serial.println("Please, be sure to enable gated 3V3 and 5V power rails");
        Serial.println("via Power.on(PWR_3V3) and Power.on(PWR_VBAT).");
        delay(500);
    }
    Serial.println("succeeded.");

    Expander.pinMode(EXP_FAULT_SOLAR_PANEL, INPUT);
    Expander.pinMode(EXP_FAULT_5V, INPUT);

    printNow = millis();
}

void loop()
{
    if (millis() > printNow) {
        auto vbat = Power.getVBat();
        Serial.print("Battery Voltage: ");
        Serial.println(vbat);

        auto solarStatus = Power.getSolarChargerStatus();
        Serial.print("Solar Panel Charger Status: ");
        Serial.println(solarStatus ? "OK" : "Error");

        auto fiveVoltsStatus = Power.get5VoltStatus();
        Serial.print("5V Power Rail Status: ");
        Serial.println(fiveVoltsStatus ? "OK" : "Error");

        printNow = millis() + printInterval;
    }
}

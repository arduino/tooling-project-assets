// #include <Arduino_EdgeControl.h>
#include "Helpers.h"

void setup()
{
    Serial.begin(115200);
    for (auto startNow = millis() + 2500; !Serial & millis() < startNow; delay(500));

    Serial.println("Starting RTC example");
    // EdgeControl.begin();

    // Init system clock from compilation time or RTC
    setSystemClock(__DATE__, __TIME__);

    // Power.on(PWR_3V3);
}

void loop()
{
    Serial.println(getLocaltime());
    delay(1000);
}

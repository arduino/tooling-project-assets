/*
    Testing strategy: alternatively create a short-time connection between
    WAKEUP 1-6 and any of the +BAT_ext pins (the row above the WAKEUP ones).

    Check IRQChannelMap for advanced C++ implementation.
*/

#include <Arduino_EdgeControl.h>

volatile int irqCounts[6] { };

enum IRQChannelsIndex {
    irqChannel1 = 0,
    irqChannel2,
    irqChannel3,
    irqChannel4,
    irqChannel5,
    irqChannel6
};


void setup()
{
    EdgeControl.begin();
    
    Serial.begin(115200);

    // Wait for Serial Monitor or start after 2.5s
    for (const auto timeout = millis() + 2500; millis() < timeout && !Serial; delay(250));

    // Init IRQ INPUT pins
    for (auto pin = IRQ_CH1; pin <= IRQ_CH6; pin++)
        pinMode(pin, INPUT);

    // Attach callbacks to IRQ pins
    attachInterrupt(digitalPinToInterrupt(IRQ_CH1), []{ irqCounts[irqChannel1]++; }, CHANGE);
    attachInterrupt(digitalPinToInterrupt(IRQ_CH2), []{ irqCounts[irqChannel2]++; }, CHANGE);
    attachInterrupt(digitalPinToInterrupt(IRQ_CH3), []{ irqCounts[irqChannel3]++; }, CHANGE);
    attachInterrupt(digitalPinToInterrupt(IRQ_CH4), []{ irqCounts[irqChannel4]++; }, CHANGE);
    attachInterrupt(digitalPinToInterrupt(IRQ_CH5), []{ irqCounts[irqChannel5]++; }, CHANGE);
    attachInterrupt(digitalPinToInterrupt(IRQ_CH6), []{ irqCounts[irqChannel6]++; }, CHANGE);

}

void loop()
{
    // Check for received IRQ every second.
    Serial.println("--------");
    for (unsigned int i = irqChannel1; i <= irqChannel6; i++) { 
        Serial.print("IRQ Channel: ");
        Serial.print(i + 1);
        Serial.print(" - ");
        Serial.println(irqCounts[i]);
    }
    delay(1000);
}

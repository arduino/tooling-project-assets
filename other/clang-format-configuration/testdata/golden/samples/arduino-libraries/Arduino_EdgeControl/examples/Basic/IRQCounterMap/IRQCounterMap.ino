/*
    Testing strategy: alternatively create a short-time connection between
    WAKEUP 1-6 and any of the +BAT_ext pins (the row above the WAKEUP ones).

    Check IRQChannel for a simpler implementation.
*/

#include <Arduino_EdgeControl.h>

#include <map>

// Use a map to collect IRQ counts
std::map<const pin_size_t, volatile unsigned int> irqCounts {
    { IRQ_CH1, 0 },
    { IRQ_CH2, 0 },
    { IRQ_CH3, 0 },
    { IRQ_CH4, 0 },
    { IRQ_CH5, 0 },
    { IRQ_CH6, 0 }
};

// Map pin numbers to pin names for pretty printing
std::map<pin_size_t, const char*> irqNames {
#define NE(IRQ) { IRQ, #IRQ }
    NE(IRQ_CH1),
    NE(IRQ_CH2),
    NE(IRQ_CH3),
    NE(IRQ_CH4),
    NE(IRQ_CH5),
    NE(IRQ_CH6),
};

void setup()
{
    EdgeControl.begin();

    Serial.begin(115200);

    // Wait for Serial Monitor or start after 2.5s
    for (const auto timeout = millis() + 2500; millis() < timeout && !Serial; delay(250))
        ;

    // Init IRQ pins and attach callbacks
    // NOTE: .first holds the channel pin and .second holds the counter
    for (const auto& irq : irqCounts) {
        // Init pins
        pinMode(irq.first, INPUT);

        // Create a type alias helper
        using IrqCount = std::pair<const pin_size_t, volatile unsigned int>;

        // Define the IRQ callback as lambda function
        // Will receive an entry from the irqCounts map:
        auto isr = [](void* arg) { IrqCount * ic = (IrqCount *)arg; (*ic).second++; };

        // attach the callback passing the current map entry as parameter
        attachInterruptParam(
            digitalPinToInterrupt(irq.first), isr, RISING, (void*)&irq);
    }
}

void loop()
{
    // Print counters every second.
    Serial.println("--------");
    for (const auto& irq : irqCounts) {
        Serial.print("IRQ Channel: ");
        Serial.print(irqNames[irq.first]);
        Serial.print(" - Counts: ");
        Serial.println(irq.second);
    }
    delay(1000);
}

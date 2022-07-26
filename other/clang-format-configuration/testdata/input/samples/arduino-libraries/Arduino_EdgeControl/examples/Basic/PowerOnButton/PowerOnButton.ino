/*
    Test Power On button on LCD breakout board

    Circuit:
    * Arduino Edge Control
    * Arduino Edge Control LCD brekout board
*/

#include <Arduino_EdgeControl.h>

// Keep track of toggle-style press with an ISR
volatile bool buttonPressed { false };
bool ledStatus { false };

void setup()
{
    Serial.begin(9600);

    for (auto timeout = millis() + 2500l; !Serial && millis() < timeout; delay(250))
        ;

    Serial.println("Hello, Arduino Edge Control!");

    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    Wire.begin();

    delay(500);

    Serial.print("IO Expander initializazion ");
    if (!Expander.begin()) {
        Serial.println("failed.");
        Serial.println("Please, be sure to enable gated 3V3 and 5V power rails");
        Serial.println("via Power.on(PWR_3V3) and Power.on(PWR_VBAT).");
    }
    Serial.println("succeeded.");

    Expander.pinMode(EXP_LED1, OUTPUT);

    pinMode(POWER_ON, INPUT);
    // ISR for button press detection
    attachInterrupt(
        digitalPinToInterrupt(POWER_ON), [] { buttonPressed = true; }, FALLING);

}

void loop()
{
    if (buttonPressed == true) {
        buttonPressed = false;
        ledStatus = !ledStatus;
        Serial.print(millis());
        Serial.println(" Pressed");
    }

    Expander.digitalWrite(EXP_LED1, ledStatus == true ? LOW : HIGH);
}

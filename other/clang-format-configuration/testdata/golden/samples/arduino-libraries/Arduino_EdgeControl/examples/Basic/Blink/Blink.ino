/*
    Blink LED1 and external LED via the IO Expander (TCA6424).
    
    Connect an external LED to J1 connector:
    - LED anod to J1-16
    - LED cathod to J1-15 via 1K Ohm resistor

*/

#include <Arduino_EdgeControl.h>

void setup()
{
    Serial.begin(9600);

    auto startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;

    delay(1000);
    Serial.println("Hello, Challenge!");

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
    Expander.pinMode(EXP_LCD_D7, OUTPUT);

}

void loop()
{
    Serial.println("Blink");
    Expander.digitalWrite(EXP_LED1, LOW);
    Expander.digitalWrite(EXP_LCD_D7, HIGH);
    delay(500);
    Expander.digitalWrite(EXP_LED1, HIGH);
    Expander.digitalWrite(EXP_LCD_D7, LOW);
    delay(500);
}

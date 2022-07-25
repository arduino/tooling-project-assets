#include <Arduino_EdgeControl.h>

void setup()
{
    Serial.begin(9600);

    auto startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;

    delay(1000);
    Serial.println("Hello, Challenge!");

    Latching.begin();
}

void loop()
{
    Latching.channelDirection(LATCHING_CMD_1, POSITIVE);
    Latching.strobe(200);
    // Latching.channelDirection(LATCHING_CMD_1, POSITIVE);
    // Latching.latch();
    // delay(200);
    // Latching.release();
    Latching.channelDirection(LATCHING_CMD_1, NEGATIVE);
    Latching.strobe(200);
    // Latching.channelDirection(LATCHING_CMD_1, LOW);
    // Latching.latch();
    // delay(200);
    // Latching.release();
    Latching.channelDirection(LATCHING_OUT_1, POSITIVE);
    Latching.strobe(200);   
    // Latching.digitalWrite(LATCHING_OUT_1, HIGH);
    // Latching.latch();
    // delay(200);
    // Latching.release();
    Latching.channelDirection(LATCHING_OUT_1, NEGATIVE);
    Latching.strobe(200);
    // Latching.digitalWrite(LATCHING_OUT_1, LOW);
    // Latching.latch();
    // delay(200);
    // Latching.release();
    delay(1000);
}
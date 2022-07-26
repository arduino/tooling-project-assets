#include <Arduino_EdgeControl.h>

void setup()
{
    Serial.begin(9600);
    while(!Serial);

    delay(1000);

    Serial.println("3-Wire Valve Demo");

    EdgeControl.begin();
    Latching.begin();

    Serial.println("Starting");
}

void loop()
{
    Serial.println("Closing");
    Latching.channelDirection(LATCHING_OUT_1, POSITIVE);
    Latching.strobe(4500);

    delay(2500);

    Serial.println("Opening");
    Latching.channelDirection(LATCHING_OUT_1, NEGATIVE);
    Latching.strobe(4500);
    delay(2500);
}
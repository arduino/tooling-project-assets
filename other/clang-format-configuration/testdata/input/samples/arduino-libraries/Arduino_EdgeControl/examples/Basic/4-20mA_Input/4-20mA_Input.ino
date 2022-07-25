/*
  Testing strategy:
  - Connect a GND Pin of a 10K potentiometer to +19V reference
  - Connect each 4-20mA IN pin alternatively to signal pin of potentiomer
  - Range the potentiometer
*/

#include <Arduino_EdgeControl.h>

constexpr unsigned int adcResolution { 12 };

constexpr pin_size_t inputChannels [] {
    INPUT_420mA_CH01,
    INPUT_420mA_CH02,
    INPUT_420mA_CH03,
    INPUT_420mA_CH04
};
constexpr size_t inputChannelsLen { sizeof(inputChannels) / sizeof(inputChannels[0]) };
int inputChannelIndex { 0 };

struct Voltages {
    float volt3V3;
    float voltRef;
};

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
    Power.on(PWR_19V);

    Wire.begin();
    Expander.begin();

    Serial.print("Waiting for IO Expander Initialization...");
    while (!Expander) {
        Serial.print(".");
        delay(100);
    }
    Serial.println(" done.");

    Input.begin();
    Input.enable();

    analogReadResolution(adcResolution);
}

void loop()
{
    Serial.print("4-20mA Input Channel ");
    switch (inputChannels[inputChannelIndex]) {
        case INPUT_420mA_CH01: Serial.print("01"); break;
        case INPUT_420mA_CH02: Serial.print("02"); break;
        case INPUT_420mA_CH03: Serial.print("03"); break;
        case INPUT_420mA_CH04: Serial.print("04"); break;
        default: break;
    }
    Serial.print(": ");

    auto [ voltsMuxer, voltsReference ] = getAverageAnalogRead(inputChannels[inputChannelIndex]);

    Serial.print(voltsReference);
    Serial.print(" (");
    Serial.print(voltsMuxer);
    Serial.println(")");
    delay(1000);

    inputChannelIndex = ++inputChannelIndex % inputChannelsLen;
}

Voltages getAverageAnalogRead(int pin)  
{
    constexpr size_t loops { 100 };
    constexpr float toV { 3.3f / float { (1 << adcResolution) - 1 } };
    constexpr float rDiv { 17.4f / ( 10.0f + 17.4f) };

    int tot { 0 };

    for (auto i = 0u; i < loops; i++)
        tot += Input.analogRead(pin);
    const auto avg = static_cast<float>(tot) * toV / static_cast<float>(loops);

    return { avg, avg / rDiv };
}

/*
  Testing strategy: connect each 5V ANALOG-IN input pin alternatively to +5V on the same connector.
*/

#include <Arduino_EdgeControl.h>

constexpr unsigned int adcResolution { 12 };

constexpr pin_size_t inputChannels [] {
    INPUT_05V_CH01,
    INPUT_05V_CH02,
    INPUT_05V_CH03,
    INPUT_05V_CH04,
    INPUT_05V_CH05,
    INPUT_05V_CH06,
    INPUT_05V_CH07,
    INPUT_05V_CH08
};
constexpr size_t inputChannelsLen { sizeof(inputChannels) / sizeof(inputChannels[0]) };
int inputChannelIndex { 0 };

struct Voltages {
    float volt3V3;
    float volt5V;
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
    Serial.print("0-5V Input Channel ");
    switch (inputChannels[inputChannelIndex]) {
        case INPUT_05V_CH01: Serial.print("01"); break;
        case INPUT_05V_CH02: Serial.print("02"); break;
        case INPUT_05V_CH03: Serial.print("03"); break;
        case INPUT_05V_CH04: Serial.print("04"); break;
        case INPUT_05V_CH05: Serial.print("05"); break;
        case INPUT_05V_CH06: Serial.print("06"); break;
        case INPUT_05V_CH07: Serial.print("07"); break;
        case INPUT_05V_CH08: Serial.print("08"); break;
        default: break;
    }
    Serial.print(": ");

    auto [ voltsMuxer, voltsInput ] = getAverageAnalogRead(inputChannels[inputChannelIndex]);

    Serial.print(voltsInput);
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

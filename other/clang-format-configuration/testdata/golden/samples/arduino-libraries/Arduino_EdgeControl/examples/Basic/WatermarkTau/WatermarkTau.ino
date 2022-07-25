#include <Arduino.h>
#include <mbed.h>

#include <Arduino_EdgeControl.h>
#include <RunningMedian.h>

constexpr unsigned int adcResolution { 12 };

mbed::LowPowerTimeout TimerM;

uint8_t watermarkChannel { 1 };

constexpr float tauRatio { 0.63f };
constexpr float tauRatioSamples { tauRatio * float { (1 << adcResolution) - 1 } };
constexpr unsigned long sensorDischargeDelay { 2 };

constexpr unsigned int measuresCount { 20 };
RunningMedian measures { measuresCount };

constexpr unsigned int calibsCount { 10 };
RunningMedian calibs { calibsCount };

void setup()
{
    Serial.begin(9600);

    auto startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;
    delay(2000);

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

    Watermark.begin();

    analogReadResolution(adcResolution);
}

void loop()
{
    static bool highPrec { false };
    Watermark.setHighPrecision(highPrec);
    highPrec = !highPrec;

    // Init commands and reset devices
    Watermark.calibrationMode(OUTPUT);
    Watermark.calibrationWrite(LOW);
    Watermark.commonMode(OUTPUT);
    Watermark.commonWrite(LOW);

    Watermark.fastDischarge(sensorDischargeDelay);

    // Calibration cycle:
    // disable Watermark demuxer
    Watermark.disable();

    Watermark.commonMode(INPUT);
    Watermark.calibrationMode(OUTPUT);
    for (auto i = 0u; i < measuresCount; i++) {
        Watermark.calibrationWrite(HIGH);

        auto start = micros();
        while (Watermark.analogRead(watermarkChannel) < tauRatioSamples)
            ;
        auto stop = micros();

        Watermark.calibrationWrite(LOW);

        Watermark.fastDischarge(sensorDischargeDelay);

        calibs.add(stop - start);
    }

    Serial.print("CALIBS   - Precision: ");
    Serial.print(highPrec ? "High" : "Low ");
    Serial.print(" - Median: ");
    Serial.print(calibs.getMedian());
    Serial.print(" - Average: ");
    Serial.print(calibs.getAverage());
    Serial.print(" - Lowest: ");
    Serial.print(calibs.getLowest());
    Serial.print(" - Highest: ");
    Serial.print(calibs.getHighest());
    Serial.println();

    calibs.clear();

    Watermark.fastDischarge(sensorDischargeDelay);

    // Measures cycle:
    // enable Watermark demuxer
    Watermark.enable();

    Watermark.commonMode(OUTPUT);
    Watermark.calibrationMode(INPUT);
    for (auto i = 0u; i < measuresCount; i++) {
        Watermark.commonWrite(HIGH);

        auto start = micros();
        while (Watermark.analogRead(watermarkChannel) < tauRatioSamples)
            ;
        auto stop = micros();

        Watermark.commonWrite(LOW);

        Watermark.fastDischarge(sensorDischargeDelay);

        measures.add(stop - start);
    }

    Serial.print("MEASURES - Precision: ");
    Serial.print(highPrec ? "High" : "Low ");
    Serial.print(" - Median: ");
    Serial.print(measures.getMedian());
    Serial.print(" - Average: ");
    Serial.print(measures.getAverage());
    Serial.print(" - Lowest: ");
    Serial.print(measures.getLowest());
    Serial.print(" - Highest: ");
    Serial.print(measures.getHighest());
    Serial.println();

    measures.clear();

    Serial.println();

    delay(1000);
}

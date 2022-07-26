/*
    Arduino Edge Control - RTC Low Power Example

    This sketch shows how to use the RTC (PCF8563T) on the Arduino
    Edge Control and how to configure and use the RTC on Low Power mode.

    Circuit:
    - Arduino Edge Control
    - CR2032 Battery
    - Optional: Arduino Edge Control LCD + Button brekout
    
*/

#include "Helpers.h"
#include <Arduino_EdgeControl.h>
#include <USB/PluggableUSBSerial.h>

void setup()
{
    Serial.begin(9600);

    for (auto timeout = millis() + 2500l; !Serial && millis() < timeout; delay(250))
        ;

    Serial.println("Hello, Arduino Edge Control!");

    EdgeControl.begin();

    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    Wire.begin();
    delay(500);

    Serial.print("Initializating the Real Time Clock...");
    while (!RealTimeClock.begin()) {
        Serial.println(" failed! Retrying...");
        delay(250);
    }
    Serial.println(" done!");

    // Set the RTC only when LCD's PowerOn button is pressed.
    // YMMV.
    if (digitalRead(POWER_ON) == LOW) {
        auto buildDateTime = getBuildDateTime();
        RealTimeClock.setEpoch(buildDateTime);
        Serial.print("Build ");
    }

    Serial.print("Date: ");
    Serial.println(getRTCDateTime());

    delay(5000);

    Wire.end();
    Serial.end();
    Serial1.end();

    Power.off(PWR_3V3);
    Power.off(PWR_VBAT);

    mbed::mbed_file_handle(STDIN_FILENO)->enable_input(false);
    PluggableUSBD().deinit();
}

void loop()
{
    delay(10000);
}

void powerDown()
{
    pinMode(I2C_SDA, INPUT_PULLDOWN);
    pinMode(I2C_SCL, INPUT_PULLDOWN);
    pinMode(I2C_SDA1, INPUT_PULLDOWN);
    pinMode(I2C_SCL1, INPUT_PULLDOWN);

    pinMode(VBAT_PROBE, INPUT_PULLDOWN);

    pinMode(CMD_TRIAC_1, INPUT_PULLDOWN);
    pinMode(CMD_TRIAC_2, INPUT_PULLDOWN);
    pinMode(CMD_TRIAC_3, INPUT_PULLDOWN);
    pinMode(CMD_TRIAC_4, INPUT_PULLDOWN);

    pinMode(SENSOR_COMMON, INPUT_PULLDOWN);
    pinMode(SENSOR_CALIB, INPUT_PULLDOWN);
    pinMode(SENSOR_INPUT_ADC, INPUT_PULLDOWN);
    pinMode(SENSOR_CAPTURE_A, INPUT_PULLDOWN);
    pinMode(SENSOR_CAPTURE, INPUT_PULLDOWN);

    pinMode(PULSE_DIRECTION, INPUT_PULLDOWN);
    pinMode(PULSE_STROBE, INPUT_PULLDOWN);

    pinMode(SD_CS, INPUT_PULLDOWN);

    pinMode(QSPIDCS, INPUT_PULLDOWN);
    pinMode(GPIOCLK, INPUT_PULLDOWN);
    pinMode(QSPID0, INPUT_PULLDOWN);
    pinMode(QSPID1, INPUT_PULLDOWN);
    pinMode(QSPID2, INPUT_PULLDOWN);
    pinMode(QSPID3, INPUT_PULLDOWN);

    pinMode(IRQ_CH1, INPUT_PULLDOWN);
    pinMode(IRQ_CH2, INPUT_PULLDOWN);
    pinMode(IRQ_CH3, INPUT_PULLDOWN);
    pinMode(IRQ_CH4, INPUT_PULLDOWN);
    pinMode(IRQ_CH5, INPUT_PULLDOWN);
    pinMode(IRQ_CH6, INPUT_PULLDOWN);
}

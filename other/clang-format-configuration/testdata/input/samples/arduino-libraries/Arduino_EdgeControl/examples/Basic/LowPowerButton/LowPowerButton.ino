/*
*   Show usage of POWER_ON pin (J1-2).
*
*   Board goes to low power mode as soon as started.
*   Pressing a momentary button connected to POWER_ON pin
*   will wake up the board for 5 seconds.
*
*   Requirements:
*   - Connect a momentary button between POWER_ON (J1-2) and GND (J1-9)
*   - Connect the PC/Mac to USB and open the Arduino Serial Monitor
*     or any serial communication application.
*
*/

#include <Arduino_EdgeControl.h>
#include <USB/PluggableUSBDevice.h>

constexpr unsigned long printInterval { 250 };
unsigned long printNow { 0 };
constexpr unsigned long wakeUpInterval { printInterval * 20 };
unsigned long sleepNow { 0 };
volatile bool sleeping { true };
volatile bool poweredOn { false };

void wakeUp()
{
    sleeping = false;
    poweredOn = true;
}

void setup()
{
    EdgeControl.begin();
    Power.on(PWR_3V3);

    Serial.begin(9600);

    auto startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;

    delay(1000);
    Serial.println("Testing Low Power");
    Serial.println("and Power On Button.");

    pinMode(POWER_ON, INPUT);
    attachInterrupt(digitalPinToInterrupt(POWER_ON), wakeUp, FALLING);

    sleepNow = millis();
    printNow = millis() + printInterval;

    powerDown();

}

void loop()
{
    if (poweredOn) {
        poweredOn = false;

        powerOn();

        delay(1000); // Wait for Serial Monitor/Serial Communication Application
        Serial.println("");
        Serial.println("Woke Up!");
        sleepNow = millis() + wakeUpInterval;
    }

    if (millis() > sleepNow && !sleeping) {
        // Going to sleep
        powerDown();
        sleeping = true;
    }

    if (sleeping)
        delay(10000); // delay() puts the board in low power mode.
    else    
        if (millis() > printNow) {
            Serial.print('.');
            printNow = millis() + printInterval;
        }
}

void powerOn()
{
    // Enable Gated 3V3 to devices and peripherals
    Power.on(PWR_3V3);

    // Enable Gated 12V and 5V to output pins, devices and peripherals
    Power.on(PWR_VBAT);

    // Enable Gated 12V and 5V to output pins, devices and peripherals
    Power.on(PWR_19V);

    // Attach USB
    PluggableUSBD().begin();

    // Enable stdin
    mbed::mbed_file_handle(STDIN_FILENO)->enable_input(true);    

    // Open Serial and wait for connection
    Serial.begin(9600);
    while(!Serial);    
}

void powerDown()
{
    Serial.println();
    Serial.println("Powering down");

    // Disable Gated 3V3
    Power.off(PWR_3V3);

    // Disable Gated 12V and 5V
    Power.off(PWR_VBAT);

    // Disable Gated 19V
    Power.off(PWR_19V);

    // Close Serial
    Serial.end();
    Serial1.end();
    // Disable stdin 
    mbed::mbed_file_handle(STDIN_FILENO)->enable_input(false);
    // Detach USB
    PluggableUSBD().deinit();
    // Put pins in threestate
    powerDownPins();
}

void powerDownPins()
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

    pinMode(IRQ_CH1, INPUT);
    pinMode(IRQ_CH2, INPUT);
    pinMode(IRQ_CH3, INPUT);
    pinMode(IRQ_CH4, INPUT);
    pinMode(IRQ_CH5, INPUT);
    pinMode(IRQ_CH6, INPUT);
}

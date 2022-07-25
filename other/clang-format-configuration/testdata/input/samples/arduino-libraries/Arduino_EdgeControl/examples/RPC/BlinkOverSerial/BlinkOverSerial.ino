/*
    This sketch shows how to use an MKR board connected to one of the
    two available slots. The Edge Control and the MKR board will communicate
    over UART connection.

    Circuit:
    - Arduino Edge Control
    - Any Arduino MKR Board connected to MKR Slot 2
    - External 12V Power Supply

    To get the example working, please, load the extras/BlinkFromSerial
    sketch on the MKR board.


*/

#include <Arduino_EdgeControl.h>

bool led { false };

void setup()
{
    EdgeControl.begin();
    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    // Power on the MKR on slot 2
    Power.on(PWR_MKR2);

    // Wait for MKR to power on
    delay(5000);

    // Open the serial communication with the MKR board on slot 2...
    SerialMKR2.begin(115200);

    // ... and ait for the serial communication from the MKR board
    while (!SerialMKR2) {
        delay(500);
    }
}

void loop()
{
    SerialMKR2.write(led);
    led = !led;
    delay(1000);
}

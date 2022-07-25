// Remote Control - As The Controller Device
//
// This script configures your Arduino to remotely control another Arduino.
//
// This script is designed to pair with "arduino_to_arduino_communication_as_the_remote_device.ino"
// example sketch included with this library.

#include <Arduino_EdgeControl.h>
#include <openmvrpc.h>

openmv::rpc_scratch_buffer<256> scratch_buffer; // All RPC objects share this buffer.

#define RPC_OVER_SERIAL 1

#if defined(RPC_OVER_SERIAL)
openmv::rpc_hardware_serial1_uart_master rpc(115200);
#else
openmv::rpc_i2c1_master rpc(0x12, 10000);
#endif

void setup()
{
    EdgeControl.begin();
    
    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    Power.on(PWR_MKR2);
    delay(5000); // Wait for MKR2 to power-on

    Serial.begin(115200);
    rpc.begin();
}

//////////////////////////////////////////////////////////////
// Call Back Handlers
//////////////////////////////////////////////////////////////

// This example shows reading a Digital I/O pin remotely.
//
void digital_read_example()
{
    uint8_t state;
    if (rpc.call_no_args("digital_read", &state, sizeof(state))) {
        Serial.print(F("Remote Digital I/O State: "));
        Serial.println(state);
    }
}

// This example shows reading an Analog I/O pin remotely.
//
void analog_read_example()
{
    uint16_t state;
    if (rpc.call_no_args(F("analog_read"), &state, sizeof(state))) {
        Serial.print(F("Remote Analog I/O State: "));
        Serial.println(state);
    }
}

// This example shows writing a Digital I/O pin remotely.
//
void digital_write_example()
{
    static uint8_t state = 0;

    auto ret = rpc.call("digital_write", &state, sizeof(state), nullptr, 0, false);
    if (!ret) {
        Serial.println("DigitalWrite Call Failed!");
        return;
    }
    state = !state; // flip state for next time
}

// This example shows writing an Analog I/O pin remotely.
//
void analog_write_example()
{
    static uint8_t state = 0;

    auto ret = rpc.call("analog_write", &state, sizeof(state), nullptr, 0, false);
    if (!ret) {
        Serial.println("AnalogWrite Call Failed!");
        return;
    }
      
    state = state + 1; // counts from 0 to 255 then rolls over
}

void serial_print_example()
{
    String str = "Hello World @";
    str += millis();

    char buffer[str.length() + 1] {};
    str.toCharArray(buffer, sizeof(buffer));

    rpc.call("serial_print", buffer, sizeof(buffer));
}

void loop()
{
    digital_read_example();
    analog_read_example();
    digital_write_example();
    analog_write_example();
    serial_print_example();
}

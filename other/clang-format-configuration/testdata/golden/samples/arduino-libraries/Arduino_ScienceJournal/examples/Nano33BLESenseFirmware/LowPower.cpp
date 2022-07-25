#include "Arduino.h"
#include "mbed.h"
#include "ArduinoBLE.h"
#include "LowPower.h"

#include "nrf_power.h"
#include "nrf_uarte.h"
#include "nrf_uart.h"

void lowPower()
{
    // Disable UARTE0 which is initially enabled by the bootloader
    nrf_uarte_task_trigger(NRF_UARTE0, NRF_UARTE_TASK_STOPRX); 
    while (!nrf_uarte_event_check(NRF_UARTE0, NRF_UARTE_EVENT_RXTO)) ; 
    NRF_UARTE0->ENABLE = 0; 
    NRF_UART0->ENABLE = 0; 

    // Enable DCDC
    nrf_power_dcdcen_set(true);

    // Turn off LED_BUILTIN
    digitalWrite(LED_BUILTIN, LOW);
}

void lowPowerWait(unsigned long time)
{
    rtos::ThisThread::sleep_for(time); 
}

void lowPowerBleWait(unsigned long time)
{
    unsigned long timeRef = millis();
    while (millis() - timeRef < time) {
      BLE.poll(time - (millis() - timeRef));
    }
}

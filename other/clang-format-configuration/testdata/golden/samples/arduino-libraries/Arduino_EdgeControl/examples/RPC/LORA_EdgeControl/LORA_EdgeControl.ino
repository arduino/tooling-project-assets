// LoRa example for the Edge control.
//
// This script configures your Arduino Edge control to receive Lora messages from another Arduino.
// Requirements:
//   1 Edge Control board
//   2 MKR1300/1310 boards (sender and receiver)
//
// Connect one of the MKR1300 to the MKR2 socket in the EdgeControl board
// This script is designed to pair with "LORA_receiver-EC.ino". Also 
// you will need a LoRa transmitter. We have used the LoRa Sender example from the other
// MKR1300.
// 
// The sketch make use of the OpenMV RPC library for communicating between the EdgeControl
// and the MKR1300 via UART
//
//  Created 20 April. 2021
//  by e.lopez


#include <Arduino_EdgeControl.h>
#include <openmvrpc.h>

openmv::rpc_scratch_buffer<256> scratch_buffer; // All RPC objects share this buffer.
openmv::rpc_hardware_serial1_uart_master rpc(115200);

//LoRa message received interrupt pin
const byte interruptPin = PIN_WIRE_SCL1;

bool message_received = false;
uint16_t msg_count {0};


//////////////////////////////////////////////////////////////
// Call Back Handlers
//////////////////////////////////////////////////////////////

void rpc_retrieve_LoRa_data()
{
  rpc.begin();
  void *message;
  size_t result_data_len;

  if (rpc.call_no_copy_no_args(F("retrieve_msg"), &message, &result_data_len) ) {

    char buff[result_data_len + 1];
    memset(buff, 0, result_data_len + 1);
    // Copy what we received into our data type container.
    memcpy(buff, message, result_data_len);
    // Use it now.
    Serial.print(F(": "));
    Serial.println(buff);
 
    //print on LCD
    //LCD.setCursor(0, 0);
    //LCD.print("LoRa MSG:");
    //LCD.setCursor(0, 1);
    //LCD.print(buff);
    
  } else {
    Serial.print(F("Error:rpc_retrieve_LoRa_data() failed! "));
  }
  rpc.end();
}

//*******************
//SETUP
//*******************
void setup()
{
  //LoRa data available interrupt
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), LoRa_ISR, FALLING);

  EdgeControl.begin();

  Power.on(PWR_3V3);
  Power.on(PWR_VBAT);

  Power.on(PWR_MKR2);
  delay(5000); // Wait for MKR2 to power-on'

  Serial.begin(115200);
  while (!Serial);

  //  //LCD init
  //  LCD.begin(16, 2);   // set up the LCD's number of columns and rows:
  //  LCD.home();         // go home
  //  LCD.backlight();    // turn on Backlight
  //  LCD.print("EDGE:"); // Print a message to the LCD.

  String serialNumber = EdgeControl.serialNumber();
  Serial.print("Serial Number: ");
  Serial.println(serialNumber);
}

//*******************
//LOOP
//*******************
void loop()
{
  if (message_received) {    
    Serial.print("Message ");
    Serial.print(++msg_count);
    rpc_retrieve_LoRa_data();
    message_received = false;
  }
}

void LoRa_ISR() {
  message_received = true;  
}

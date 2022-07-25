/*
  STANDALONE FIRMWARE UPDATE FOR Arduino Motor Carrier

  To generate a new firmware, compile D11-Firmware with target MKRMotorShield, 4KB bootloader, LTO enabled, pinmap complete
  and execute

  echo -n "const " > fw.h && xxd -i D11-Firmware.ino.bin >> fw.h
*/

#include "Wire.h"
#include "ArduinoMotorCarrier.h"

#ifdef ARDUINO_SAMD_NANO_33_IOT
#include "fw_nano.h"
#else
#include "fw_mkr.h"
#endif

#define I2C_ADDRESS 0x09

void setDataRunning(int cmd, uint8_t target, int data) {
  Wire.beginTransmission(0x66);
  Wire.write((uint8_t)cmd);
  Wire.write((uint8_t)target);
  Wire.write(data);
  Wire.endTransmission();
}


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.setClock(1000000);

  Serial.begin(115200);
  while (!Serial);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);

  int prev_address = -1;

  Wire.beginTransmission(0x66);
  Wire.write((uint8_t)GET_VERSION);
  Wire.write((uint8_t)0);
  Wire.endTransmission();

  Wire.requestFrom(0x66, 5);
  Wire.read();

  String version = "";

  while (Wire.available()) {
    version += (char)Wire.read();
  }

  if (version.c_str()[0] == '0') {
    Serial.println("Reset D11");
    setDataRunning(RESET, 0, 0);
    delay(10);
  } else {
    // TODO: on NanoMotorCarrier we have the change to forcefully reset the D11; do it now if it is unresponsive

  }

  // reset running D11
  Serial.println("Erase flash");

  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write('r');
  Wire.endTransmission();

  delay(500);

  Serial.println("Starting flash");

  int address = 0;
  while (address < (D11_Firmware_ino_bin_len + 0x1000)) {
    int retry = 0;
    do {
      Wire.requestFrom(I2C_ADDRESS, 4);
      uint8_t buf[4];
      int k = 0;
      while (Wire.available()) {
        buf[k++] = Wire.read();
      }
      address = *(uint32_t*)buf;
      delay(10);
    } while (prev_address == address && retry++ < 5);
    prev_address = address;
    Serial.println(address);

    uint8_t crc = 0;
    for (int j = 0; j < 64; j++) {
      crc ^= D11_Firmware_ino_bin[address - 0x1000 + j];
    }

    Serial.println(crc, HEX);

    Wire.beginTransmission(I2C_ADDRESS);
    Wire.write('w');
    Wire.write(crc);
    Wire.write(&D11_Firmware_ino_bin[address - 0x1000], 64);
    Wire.endTransmission();
  }

  Serial.println("Booting FW");
  Wire.beginTransmission(I2C_ADDRESS);
  Wire.write('x');
  Wire.endTransmission();

  delay(1000);

  Wire.beginTransmission(0x66);
  Wire.write((uint8_t)GET_VERSION);
  Wire.write((uint32_t)0);
  Wire.endTransmission();

  Wire.requestFrom(0x66, 5);
  Wire.read();

  Serial.print("New version: ");
  while (Wire.available()) {
    Serial.print((char)Wire.read());
  }
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}

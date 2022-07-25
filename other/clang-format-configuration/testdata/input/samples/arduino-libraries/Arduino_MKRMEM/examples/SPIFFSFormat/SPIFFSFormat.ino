/* SPIFFSFormat.ino
 * 
 * This sketch erases the complete flash and formats it for
 * usage with the SPIFFS (SPI Flash File System).
 * 
 * Alexander Entinger
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_MKRMEM.h>

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);

  unsigned long const start = millis();
  for(unsigned long now = millis(); !Serial && ((now - start) < 5000); now = millis()) { };
  
  flash.begin();

  Serial.println("Erasing chip ...");
  flash.eraseChip();

  Serial.println("Mounting ...");
  int res = filesystem.mount();
  if(res != SPIFFS_OK && res != SPIFFS_ERR_NOT_A_FS) {
    Serial.println("mount() failed with error code "); Serial.println(res); return;
  }

  Serial.println("Unmounting ...");
  filesystem.unmount();

  Serial.println("Formatting ...");
  res = filesystem.format();
  if(res != SPIFFS_OK) {
    Serial.println("format() failed with error code "); Serial.println(res); return;
  }

  Serial.println("Mounting ...");
  res = filesystem.mount();
  if(res != SPIFFS_OK) {
    Serial.println("mount() failed with error code "); Serial.println(res); return;
  }

  Serial.println("Checking ...");
  res = filesystem.check();
  if(res != SPIFFS_OK) {
    Serial.println("check() failed with error code "); Serial.println(res); return;
  }

  Serial.println("Retrieving filesystem info ...");
  unsigned int bytes_total = 0,
               bytes_used  = 0;
  res = filesystem.info(bytes_total, bytes_used);
  if(res != SPIFFS_OK) {
    Serial.println("check() failed with error code "); Serial.println(res); return;
  } else {
    char msg[64] = {0};
    snprintf(msg, sizeof(msg), "SPIFFS Info:\nBytes Total: %d\nBytes Used:  %d", bytes_total, bytes_used);
    Serial.println(msg);
  }

  Serial.println("Unmounting ...");
  filesystem.unmount();
}

void loop()
{ 

}

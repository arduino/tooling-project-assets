/* RawFlashAccess.ino
 * 
 * This sketch demonstrates the raw API of the W25Q16DV class
 * which allows for low level flash memory control.
 * 
 * Alexander Entinger
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_MKRMEM.h>

#undef max
#undef min
#include <array>
#include <algorithm>

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);

  unsigned long const start = millis();
  for(unsigned long now = millis(); !Serial && ((now - start) < 5000); now = millis()) { };
  
  flash.begin();
  
  W25Q16DV_Id const id = flash.readId();

  char msg[32] = {0};
  snprintf(msg, sizeof(msg), "ID: %02X %02X %02X", id.manufacturer_id, id.memory_type, id.capacity);
  Serial.println(msg);


  std::array<uint8_t, 256> data_write = {0},
                           data_read  = {0};

  /**************************************************************************************
   * CHIP ERASE
   **************************************************************************************/
  
  Serial.println("Erasing chip");
  
  flash.eraseChip();
  
  flash.read(0x000100, data_read.data(), data_read.size());
  
  if(std::all_of(data_read.begin(), data_read.end(), [](uint8_t const elem) { return (elem == 0xFF); })) {
    Serial.println("Comparison OK");
  } else {
    Serial.println("Comparison FAIL");
  }
  printArray("RD: ", data_read);

  /**************************************************************************************
   * PAGE PROGRAM
   **************************************************************************************/

  Serial.println("Programming page");

  /* Initialize data */
  std::transform(data_write.begin(), data_write.end(), data_write.begin(),
                [](uint8_t const elem)
                {
                  static uint8_t i = 0;
                  return i++;
                });

  flash.programPage(0x000100, data_write.data(), data_write.size());
  flash.read       (0x000100, data_read.data(),  data_read.size());

  printArray("WR: ", data_write);
  printArray("RD: ", data_read);

  if(std::equal(data_write.begin(), data_write.end(), data_read.begin())) {
    Serial.println("Comparison OK");
  } else {
    Serial.println("Comparison FAIL");
  }

  /**************************************************************************************
   * SECTOR ERASE
   **************************************************************************************/

  Serial.println("Sector erase");
  
  /* Erase the whole first sector (4 kB) */
  flash.eraseSector(0x000000);

  /* Set the comparison buffer to 0xFF since we now need to compare if every value is 0xFF */
  std::fill(data_write.begin(), data_write.end(), 0xFF);

  /* Read the data */
  flash.read(0x000100, data_read.data(), data_read.size());
  printArray("RD: ", data_read);

  /* Compare the two data buffers */
  if(std::all_of(data_read.begin(), data_read.end(), [](uint8_t const elem) { return (elem == 0xFF); })) {
    Serial.println("Comparison OK");
  } else {
    Serial.println("Comparison FAIL");
  }
}

void loop()
{ 

}

/**************************************************************************************
 * HELPER
 **************************************************************************************/

void printArray(char const * desc, std::array<uint8_t, 256> arr)
{
  Serial.print(desc);
  
  std::for_each(arr.begin(), arr.end(),
                [](uint8_t const elem)
                {
                  Serial.print(elem, HEX);
                  Serial.print(" ");
                });
  
  Serial.println();
}

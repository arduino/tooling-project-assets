/* SPIFFSUsage.ino
 * 
 * This sketch demonstrates various file operations utilizing
 * the Arduino MKR MEM Shield port for the SPIFFS.
 * 
 * Alexander Entinger
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Arduino_MKRMEM.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

/* A pangram is a sentence using every letter of a given alphabet at least once. */
static char const PANGRAM[] = "The quick brown fox jumps over the lazy dog.";

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup() {
  Serial.begin(9600);

  unsigned long const start = millis();
  for(unsigned long now = millis(); !Serial && ((now - start) < 5000); now = millis()) { };
  
  flash.begin();

  Serial.println("Mounting ...");
  if(SPIFFS_OK != filesystem.mount()) {
    Serial.println("mount() failed with error code "); Serial.println(filesystem.err()); return;
  }


  Serial.println("Checking ...");
  if(SPIFFS_OK != filesystem.check()) {
    Serial.println("check() failed with error code "); Serial.println(filesystem.err()); return;
  }

  Serial.print("Checking for file ... ");
  File fnf = filesystem.open("404.txt", READ_ONLY);
  if (!fnf) {
    Serial.println(" 404.txt does not exist.");
  }

  Serial.print("Checking for file ... ");
  File fox = filesystem.open("fox.txt", READ_ONLY);
  if (fox) {
    Serial.println(" fox.txt exists. It will be overwritten.");
  }

  Serial.println("Writing ...");
  /* Create file if it doesn't exist (SPIFFS_CREAT) and open in 
   * write only mode (SPIFFS_WRONLY). If the file does exist
   * delete the existing content (SPIFFS_TRUNC).
   */
  File file = filesystem.open("fox.txt", CREATE | READ_WRITE| TRUNCATE);

  int const bytes_to_write = strlen(PANGRAM);
  int const bytes_written = file.write((void *)PANGRAM, bytes_to_write);
  
  if(bytes_written != bytes_to_write) {
    Serial.println("write() failed with error code "); Serial.println(filesystem.err()); return;
  } else {
    Serial.print(bytes_written);
    Serial.println(" bytes written");
  }


  Serial.println("Retrieving filesystem info ...");
  unsigned int bytes_total = 0,
               bytes_used = 0;
  if(SPIFFS_OK != filesystem.info(bytes_total, bytes_used)) {
    Serial.println("check() failed with error code "); Serial.println(filesystem.err()); return;
  } else {
    char msg[64] = {0};
    snprintf(msg, sizeof(msg), "SPIFFS Info:\nBytes Total: %d\nBytes Used:  %d", bytes_total, bytes_used);
    Serial.println(msg);
  }


  Serial.println("Reading ...");
  file.lseek(0, START); /* Rewind file pointer to the start */

  char buf[64] = {0};
  int const bytes_read = file.read(buf, sizeof(buf));
  buf[bytes_read] = '\0';
  
  file.close();
  Serial.print("["); Serial.print(bytes_read); Serial.print("] ");
  Serial.println(buf);


  Serial.println("Unmounting ...");
  filesystem.unmount();
}

void loop() {

}

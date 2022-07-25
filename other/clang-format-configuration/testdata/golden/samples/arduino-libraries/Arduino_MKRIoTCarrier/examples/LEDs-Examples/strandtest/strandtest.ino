#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

#define NUMPIXELS 5

void setup() {
  carrier.noCase();
  carrier.begin();
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head  = 0, tail = -4; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000;      // 'On' color (starts red)

void loop() {

  carrier.leds.setPixelColor(head, color); // 'On' pixel at head
  carrier.leds.setPixelColor(tail, 0);     // 'Off' pixel at tail
  carrier.leds.show();                     // Refresh strip
  delay(20);                        // Pause 20 milliseconds (~50 FPS)


  if (++head >= NUMPIXELS) {        // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if ((color >>= 8) == 0)         //  Next color (R->G->B) ... past blue now?
      color = 0xFF0000;             //   Yes, reset to red
  }
  if (++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index
}

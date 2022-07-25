/*
  MKR RGB - Scroll Text

  This example demonstrates how to display and scroll text
  on the MKR RGB shield. It continuously scrolls the
  current millis() value on the display.

  The circuit:
  - Arduino MKR board
  - Arduino MKR RGB shield attached

  This example code is in the public domain.
*/

#include <ArduinoGraphics.h> // Arduino_MKRRGB depends on ArduinoGraphics
#include <Arduino_MKRRGB.h>

void setup() {
  // initialize the display
  MATRIX.begin();

  // set the brightness, supported values are 0 - 255
  MATRIX.brightness(10);

  // configure the text scroll speed
  MATRIX.textScrollSpeed(125);

  // display some short text without scrolling
  MATRIX.beginText(0, 0, 127, 0, 0); // X, Y, then R, G, B
  MATRIX.print("Hi");
  MATRIX.endText();

  delay(2000);
}

void loop() {
  MATRIX.beginText(MATRIX.width() - 1, 0); // use the same color as before, start text at the right edge
  MATRIX.print("millis=");
  MATRIX.println(millis());
  MATRIX.endText(SCROLL_LEFT); // SCROLL_LEFT parameter here to configure scrolling left
}

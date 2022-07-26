/*
  MKR RGB - Simple Draw

  This example demonstrates how to draw on the
  MKR RGB shield.

  The circuit:
  - Arduino MKR board
  - Arduino MKR RGB shield attached

  This example code is in the public domain.
*/

#include <ArduinoGraphics.h>  // Arduino_MKRRGB depends on ArduinoGraphics
#include <Arduino_MKRRGB.h>

void setup() {
  // initialize the display
  MATRIX.begin();

  // set the brightness, supported values are 0 - 255
  MATRIX.brightness(10);
}

void loop() {
  // set one pixel RED
  MATRIX.beginDraw();
  MATRIX.set(0, 0, 255, 0, 0);  // X, Y, and R, G, B
  MATRIX.endDraw();

  delay(1000);

  // clear the display
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.endDraw();

  delay(1000);

  // set one pixel GREEN, using the stroke and point methods
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.stroke(0, 255, 0);
  MATRIX.point(1, 1);
  MATRIX.endDraw();

  delay(1000);

  // set draw a BLUE line
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.stroke(0, 0, 255);
  MATRIX.line(0, 0, MATRIX.width() - 1, MATRIX.height() - 1);
  MATRIX.endDraw();

  delay(1000);

  // outline a CYAN rectangle
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.stroke(0, 255, 255);
  MATRIX.rect(0, 0, MATRIX.width(), MATRIX.height());
  MATRIX.endDraw();

  delay(1000);

  // fill a YELLOW rectangle
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.noStroke();
  MATRIX.fill(255, 255, 0);
  MATRIX.rect(0, 0, MATRIX.width(), MATRIX.height());
  MATRIX.endDraw();

  delay(1000);

  // fill and stroke a rectangle
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.stroke(255, 0, 255);
  MATRIX.fill(0, 255, 0);
  MATRIX.rect(0, 0, MATRIX.width(), MATRIX.height());
  MATRIX.endDraw();

  delay(1000);

  // stroke a small text
  MATRIX.beginDraw();
  MATRIX.clear();
  MATRIX.stroke(255, 255, 255);
  MATRIX.text("abc", 0, 1);
  MATRIX.endDraw();

  delay(1000);

  // clear the display
  MATRIX.beginDraw();
  MATRIX.noFill();
  MATRIX.noStroke();
  MATRIX.clear();
  MATRIX.endDraw();

  delay(1000);
}

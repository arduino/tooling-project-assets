/**************************************************************************
  This example orignillay from Adafruit ST7735 library, just converted for the carrier usage
 **************************************************************************/

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

float p = 3.1415926;

void setup(void) {
  
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
  carrier.noCase();
  carrier.begin();

  uint16_t time = millis();
  carrier.display.fillScreen(ST77XX_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  // large block of text
  carrier.display.fillScreen(ST77XX_BLACK);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
  delay(1000);

  // tft print function!
  tftPrintTest();
  delay(4000);

  // a single pixel
  carrier.display.drawPixel(carrier.display.width() / 2, carrier.display.height() / 2, ST77XX_GREEN);
  delay(500);

  // line draw test
  testlines(ST77XX_YELLOW);
  delay(500);

  // optimized lines
  testfastlines(ST77XX_RED, ST77XX_BLUE);
  delay(500);

  testdrawrects(ST77XX_GREEN);
  delay(500);

  testfillrects(ST77XX_YELLOW, ST77XX_MAGENTA);
  delay(500);

  carrier.display.fillScreen(ST77XX_BLACK);
  testfillcircles(10, ST77XX_BLUE);
  testdrawcircles(10, ST77XX_WHITE);
  delay(500);

  testroundrects();
  delay(500);

  testtriangles();
  delay(500);

  mediabuttons();
  delay(500);

  Serial.println("done");
  delay(1000);
}

void loop() {
  carrier.display.invertDisplay(true);
  delay(500);
  carrier.display.invertDisplay(false);
  delay(500);
}

void testlines(uint16_t color) {
  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < carrier.display.width(); x += 6) {
    carrier.display.drawLine(0, 0, x, carrier.display.height() - 1, color);
    delay(0);
  }
  for (int16_t y = 0; y < carrier.display.height(); y += 6) {
    carrier.display.drawLine(0, 0, carrier.display.width() - 1, y, color);
    delay(0);
  }

  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < carrier.display.width(); x += 6) {
    carrier.display.drawLine(carrier.display.width() - 1, 0, x, carrier.display.height() - 1, color);
    delay(0);
  }
  for (int16_t y = 0; y < carrier.display.height(); y += 6) {
    carrier.display.drawLine(carrier.display.width() - 1, 0, 0, y, color);
    delay(0);
  }

  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < carrier.display.width(); x += 6) {
    carrier.display.drawLine(0, carrier.display.height() - 1, x, 0, color);
    delay(0);
  }
  for (int16_t y = 0; y < carrier.display.height(); y += 6) {
    carrier.display.drawLine(0, carrier.display.height() - 1, carrier.display.width() - 1, y, color);
    delay(0);
  }

  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < carrier.display.width(); x += 6) {
    carrier.display.drawLine(carrier.display.width() - 1, carrier.display.height() - 1, x, 0, color);
    delay(0);
  }
  for (int16_t y = 0; y < carrier.display.height(); y += 6) {
    carrier.display.drawLine(carrier.display.width() - 1, carrier.display.height() - 1, 0, y, color);
    delay(0);
  }
}

void testdrawtext(char *text, uint16_t color) {
  carrier.display.setCursor(0, 0);
  carrier.display.setTextColor(color);
  carrier.display.setTextWrap(true);
  carrier.display.print(text);
}

void testfastlines(uint16_t color1, uint16_t color2) {
  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t y = 0; y < carrier.display.height(); y += 5) {
    carrier.display.drawFastHLine(0, y, carrier.display.width(), color1);
  }
  for (int16_t x = 0; x < carrier.display.width(); x += 5) {
    carrier.display.drawFastVLine(x, 0, carrier.display.height(), color2);
  }
}

void testdrawrects(uint16_t color) {
  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t x = 0; x < carrier.display.width(); x += 6) {
    carrier.display.drawRect(carrier.display.width() / 2 - x / 2, carrier.display.height() / 2 - x / 2 , x, x, color);
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  carrier.display.fillScreen(ST77XX_BLACK);
  for (int16_t x = carrier.display.width() - 1; x > 6; x -= 6) {
    carrier.display.fillRect(carrier.display.width() / 2 - x / 2, carrier.display.height() / 2 - x / 2 , x, x, color1);
    carrier.display.drawRect(carrier.display.width() / 2 - x / 2, carrier.display.height() / 2 - x / 2 , x, x, color2);
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = radius; x < carrier.display.width(); x += radius * 2) {
    for (int16_t y = radius; y < carrier.display.height(); y += radius * 2) {
      carrier.display.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x = 0; x < carrier.display.width() + radius; x += radius * 2) {
    for (int16_t y = 0; y < carrier.display.height() + radius; y += radius * 2) {
      carrier.display.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  carrier.display.fillScreen(ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = carrier.display.width() / 2;
  int x = carrier.display.height() - 1;
  int y = 0;
  int z = carrier.display.width();
  for (t = 0 ; t <= 15; t++) {
    carrier.display.drawTriangle(w, y, y, x, z, x, color);
    x -= 4;
    y += 4;
    z -= 4;
    color += 100;
  }
}

void testroundrects() {
  carrier.display.fillScreen(ST77XX_BLACK);
  uint16_t color = 100;
  int i;
  int t;
  for (t = 0 ; t <= 4; t += 1) {
    int x = 0;
    int y = 0;
    int w = carrier.display.width() - 2;
    int h = carrier.display.height() - 2;
    for (i = 0 ; i <= 16; i += 1) {
      carrier.display.drawRoundRect(x, y, w, h, 5, color);
      x += 2;
      y += 3;
      w -= 4;
      h -= 6;
      color += 1100;
    }
    color += 100;
  }
}

void tftPrintTest() {
  carrier.display.setTextWrap(false);
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setCursor(0, 30);
  carrier.display.setTextColor(ST77XX_RED);
  carrier.display.setTextSize(1);
  carrier.display.println("Hello World!");
  carrier.display.setTextColor(ST77XX_YELLOW);
  carrier.display.setTextSize(2);
  carrier.display.println("Hello World!");
  carrier.display.setTextColor(ST77XX_GREEN);
  carrier.display.setTextSize(3);
  carrier.display.println("Hello World!");
  carrier.display.setTextColor(ST77XX_BLUE);
  carrier.display.setTextSize(4);
  carrier.display.print(1234.567);
  delay(1500);
  carrier.display.setCursor(0, 0);
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.setTextSize(0);
  carrier.display.println("Hello World!");
  carrier.display.setTextSize(1);
  carrier.display.setTextColor(ST77XX_GREEN);
  carrier.display.print(p, 6);
  carrier.display.println(" Want pi?");
  carrier.display.println(" ");
  carrier.display.print(8675309, HEX); // print 8,675,309 out in HEX!
  carrier.display.println(" Print HEX!");
  carrier.display.println(" ");
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.println("Sketch has been");
  carrier.display.println("running for: ");
  carrier.display.setTextColor(ST77XX_MAGENTA);
  carrier.display.print(millis() / 1000);
  carrier.display.setTextColor(ST77XX_WHITE);
  carrier.display.print(" seconds.");
}

void mediabuttons() {
  // play
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.fillRoundRect(25, 10, 78, 60, 8, ST77XX_WHITE);
  carrier.display.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_RED);
  delay(500);
  // pause
  carrier.display.fillRoundRect(25, 90, 78, 60, 8, ST77XX_WHITE);
  carrier.display.fillRoundRect(39, 98, 20, 45, 5, ST77XX_GREEN);
  carrier.display.fillRoundRect(69, 98, 20, 45, 5, ST77XX_GREEN);
  delay(500);
  // play color
  carrier.display.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_BLUE);
  delay(50);
  // pause color
  carrier.display.fillRoundRect(39, 98, 20, 45, 5, ST77XX_RED);
  carrier.display.fillRoundRect(69, 98, 20, 45, 5, ST77XX_RED);
  // play color
  carrier.display.fillTriangle(42, 20, 42, 60, 90, 40, ST77XX_GREEN);
}

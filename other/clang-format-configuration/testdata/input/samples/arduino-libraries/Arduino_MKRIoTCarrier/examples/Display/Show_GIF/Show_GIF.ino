// Base sketch from Fil Connesso, https://www.youtube.com/watch?v=qNVWZY3WbhU
// Using AnimatedGIF from @bitbank2
// Thanks!!

#include <AnimatedGIF.h>
#include <Arduino_MKRIoTCarrier.h>

#include "Adafruit_GFX.h"

#include "gifs.h"

MKRIoTCarrier carrier;

// AnimatedGIF library needed, https://github.com/bitbank2/AnimatedGIF
AnimatedGIF gif;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  carrier.noCase();

  carrier.begin();
  carrier.display.setRotation(4);
  carrier.display.fillScreen(ST77XX_BLACK);

  gif.begin(LITTLE_ENDIAN_PIXELS);

  carrier.leds.fill(0xFFFFFF, 0, 5);

}

void loop() {
  int c = 0;
  if (gif.open((uint8_t *)LOGO_Arduino, sizeof(LOGO_Arduino), GIFDraw))
  {

    while (gif.playFrame(false, NULL))
    {
      carrier.leds.setBrightness(c );
      c++;
      carrier.leds.show();
    }
    c = 0;
    carrier.leds.setBrightness(0);
    carrier.leds.show();
    gif.close();
  }
  delay(1500);
}

void GIFDraw(GIFDRAW *pDraw)
{
  uint8_t *s;
  uint16_t *d, *usPalette, usTemp[320];
  int x, y, dWidth, vardX, vardY, varY;
  int DX = carrier.display.width();
  int DY = carrier.display.height();

  dWidth = pDraw->iWidth;
  vardX = pDraw->iX;
  vardY = pDraw->iY;
  varY = pDraw->y;

  if (dWidth +  vardX > dWidth)
    dWidth = DX - pDraw->iX;
  usPalette = pDraw->pPalette;
  y = varY + vardY;
  if (y >= DY || vardX >= DX || dWidth < 1)
    return;
  s = pDraw->pPixels;
  if (pDraw->ucDisposalMethod == 2)
  {
    for (x = 0; x < dWidth; x++)
    {
      if (s[x] == pDraw->ucTransparent)
        s[x] = pDraw->ucBackground;
    }
    pDraw->ucHasTransparency = 0;
  }
  if (pDraw->ucHasTransparency)
  {
    uint8_t *pEnd, c, ucTransparent = pDraw->ucTransparent;
    int x, iCount;
    pEnd = s + dWidth;
    x = 10; //offset
    y += 10;
    iCount = 0;
    while (x < dWidth)
    {
      c = ucTransparent - 1;
      d = usTemp;
      while (c != ucTransparent && s < pEnd)
      {
        c = *s++;
        if (c == ucTransparent)
        {
          s--;
        }
        else
        {
          *d++ = usPalette[c];
          iCount++;
        }
      }
      if (iCount)
      {
        carrier.display.startWrite();
        carrier.display.setAddrWindow(pDraw->iX + x, y, iCount, 1);
        carrier.display.writePixels(usTemp, iCount, true, false);
        carrier.display.endWrite();
        x += iCount;
        iCount = 0;
      }
      c = ucTransparent;
      while (c == ucTransparent && s < pEnd)
      {
        c = *s++;
        if (c == ucTransparent)
          iCount++;
        else
          s--;
      }
      if (iCount)
      {
        x += iCount;
        iCount = 0;
      }
    }
  }
  else
  {
    s = pDraw->pPixels;
    for (x = 0; x < dWidth; x++)
      usTemp[x] = usPalette[*s++];
    carrier.display.startWrite();
    carrier.display.setAddrWindow(pDraw->iX + 50, y, dWidth, 1);
    carrier.display.writePixels(usTemp, dWidth, true, false);
    carrier.display.endWrite();
  }
}

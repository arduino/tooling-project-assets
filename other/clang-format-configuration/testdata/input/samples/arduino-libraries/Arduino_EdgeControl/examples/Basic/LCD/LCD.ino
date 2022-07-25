/*
 LCD Display (HD44780) via LiquidCrystal for TCA6224A 

  The circuit:
 * Arduino Edge Control
 * Arduino Edge Control LCD brekout board

*/

#include <Arduino_EdgeControl.h>
#include <Wire.h>

byte smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
};

byte armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
};

byte frownie[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001
};

void setup()
{
    EdgeControl.begin();
    
    Serial.begin(9600);

    auto startNow = millis() + 2500;
    while (!Serial && millis() < startNow)
        ;

    delay(1000);
    Serial.println("Testing LCD for Arduino Edge Control");

    Power.on(PWR_3V3);
    Power.on(PWR_VBAT);

    Wire.begin();

    delay(500);

    Serial.print("IO Expander initializazion ");
    if (!Expander.begin()) {
        Serial.println("failed.");
        Serial.println("Please, be sure to enable gated 3V3 and 5V power rails");
        Serial.println("via Power.on(PWR_3V3) and Power.on(PWR_VBAT).");
    }
    Serial.println("succeeded.");

    // set up the LCD's number of columns and rows:
    LCD.begin(16, 2);

    LCD.createChar(0, smiley); // load character to the LCD
    LCD.createChar(1, armsUp); // load character to the LCD
    LCD.createChar(2, frownie); // load character to the LCD

    // Print a message to the LCD.
    LCD.home(); // go home
    LCD.print("Edge Control");
    LCD.setCursor(15, 0);
    LCD.print(char(1));
}

void loop()
{
    static bool backlight = true;

    if (backlight) {
        LCD.backlight();
        backlight = false;
    } else {
        LCD.noBacklight();
        backlight = true;
    }

    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    LCD.setCursor(0, 1);
    // print the number of seconds since reset:
    LCD.print(millis() / 1000);
    // Do a little animation by writing to the same location
    LCD.setCursor(15, 1);
    LCD.print(char(2));
    delay(200);
    LCD.setCursor(15, 1);
    LCD.print(char(0));
    delay(200);
}

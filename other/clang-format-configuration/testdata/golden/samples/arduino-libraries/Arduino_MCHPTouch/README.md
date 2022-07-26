# MCHPTouch Library for Arduino

[![Check Arduino status](https://github.com/arduino-libraries/Arduino_MCHPTouch/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_MCHPTouch/actions/workflows/check-arduino.yml)
[![Compile Examples status](https://github.com/arduino-libraries/Arduino_MCHPTouch/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_MCHPTouch/actions/workflows/compile-examples.yml)
[![Spell Check status](https://github.com/arduino-libraries/Arduino_MCHPTouch/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino-libraries/Arduino_MCHPTouch/actions/workflows/spell-check.yml)

This library allows you to read touch sensors values from the [Arduino MKR](https://store.arduino.cc/arduino-mkr-wifi-1010) boards and the [Arduino Nano 33 IoT](https://store.arduino.cc/arduino-nano-33-iot). Touch sensing is a hardware capability of the SAMD21 processor.

```c++
#include "Arduino_MCHPTouch.h"

void setup() {
    TOUCH.begin();
}

void loop() {
    TOUCH.poll();
    if (TOUCH.available()) {
        int value = TOUCH.read(0);  // read sensor 0
    }
}
```

See the bundled [examples](examples/) for usage and visit the [Microchip Developer](https://microchipdeveloper.com/touch:start) website to learn more about touch sensing.

## License

This library is a wrapper around the MCHPTouch library by Microchip, which is bundled in binary form in this distribution in agreement with Microchip.

> Microchip Technology Inc., provides the Microchip Touch Library software subject to the license terms contained at the link below.  By using the Microchip Touch Library, you acknowledge and agree to the terms of the license contained at the link below. [Microchip Touch Library License Agreement](Microchip%20Touch%20Library%20License%20Agreement%20-%20Arduino%20082420.pdf)

The Arduino_MCHPTouch wrapper library is distributed under the terms of the MPL-2.0 license.

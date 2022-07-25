# SigFox Library

[![Check Arduino status](https://github.com/arduino-libraries/SigFox/actions/workflows/check-arduino.yml/badge.svg)](https://github.com/arduino-libraries/SigFox/actions/workflows/check-arduino.yml)
[![Compile Examples status](https://github.com/arduino-libraries/SigFox/actions/workflows/compile-examples.yml/badge.svg)](https://github.com/arduino-libraries/SigFox/actions/workflows/compile-examples.yml)
[![Spell Check status](https://github.com/arduino-libraries/SigFox/actions/workflows/spell-check.yml/badge.svg)](https://github.com/arduino-libraries/SigFox/actions/workflows/spell-check.yml)

## Description

This library allows you to use the ATMEL SigFox transceiver (ATAB8520E) on the Arduino MKRFOX1200 board. For additional information on the Arduino MKR Fox 1200 board, see the [Getting Started page](https://www.arduino.cc/en/Guide/MKRFox1200) and the [product page](https://store.arduino.cc/arduino-mkr-fox-1200-1408).

SigFox employs a cellular system that enables remote devices to connect using Ultra-Narrow Band (UNB) technology. It requires little energy, being termed Low-power Wide-area network (LPWAN).

## Installation

![image](https://user-images.githubusercontent.com/36513474/67494578-d9213100-f692-11e9-9cc2-e18e69ae7d3c.png)

### First Method

1. In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries
1. Then the Library Manager will open and you will find a list of libraries that are already installed or ready for installation.
1. Then search for SigFox using the search bar.
1. Click on the text area and then select the specific version and install it.

### Second Method

1. Navigate to the Releases page.
1. Download the latest release.
1. Extract the zip file
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

## Features

- ### Ultra Narrowband

    This library enables remote devices to use UNB. The benefit of using ultra narrowband receiver is that it rejects noise and interference which may enter the receiver, enabling an acceptable signal-to-noise ratio to be achieved with a relatively weak received signal

- ### LPWAN

    SigFox library requires Low Powered Wide Area Network. This technology connects low-bandwidth devices with low rate of bits over long ranges.

- ### Good fit for small applications

    This library is a good fit for any application that needs to send small, infrequent bursts of data. Things like basic alarm systems, location monitoring, and simple metering are all examples of one-way systems that might make sense for this network.

- ### Give back

    SigFox is free for everyone. The licensed document can be copied, redistributed and used in the projects, assignments or anywhere.

- ### Licensed Document

    Library is licensed under GNU lesser General Public License. It's not allowed to make changes in the functions or anything. The user simply has to import the library in the project and can use any of its functions by just calling it.

## Functions

- begin()
- beginPacket()
- write()
- print()
- endPacket()
- parsePacket()
- statusCode()
- AtmVersion()
- SigVersion()
- ID()
- PAC()
- reset()
- internalTemperature()
- debug()
- noDebug()
- end()
- peek()
- available()
- read()

For further functions description visit [SigFox](https://www.arduino.cc/en/Reference/SigFox)

## Example

There are many examples implemented where this library is used. You can find other examples from [Github-SigFox](https://github.com/arduino-libraries/SigFox/tree/master/examples) and [Arduino-Reference](https://www.arduino.cc/en/Reference/SigFox)

- ### Send Boolean

    This sketch demonstrates how to send a simple binary data ( 0 or 1 ) using a MKR Fox 1200. If the application only needs to send one bit of information the transmission time (and thus power consumption) will be much lower than sending a full 12 bytes packet.

``` C++
#include <SigFox.h>

bool value_to_send = true;

#define DEBUG 1

void setup() {

  if (DEBUG){
    Serial.begin(9600);
    while (!Serial) {};
  }

  if (!SigFox.begin()) {
    if (DEBUG){
      Serial.println("Sigfox module unavailable !");
    }
    return;
  }

  if (DEBUG){
    SigFox.debug();
    Serial.println("ID  = " + SigFox.ID());
  }

  delay(100);

  SigFox.beginPacket();
  SigFox.write(value_to_send);
  int ret = SigFox.endPacket();

  if (DEBUG){
    Serial.print("Status : ");
    Serial.println(ret);
  }
}

void loop(){}
```

## Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell others about this library
- Contribute new protocols

Please read [CONTRIBUTING.md](https://github.com/arduino-libraries/SigFox/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Credits

The Library created and maintained by Arduino LLC

Based on previous work by:

- M. Facchin
- N. Lesconnec
- N. Barcucci

## Current stable version

**version:** v1.0.4

## License

This library is licensed under [GNU LGPL](https://www.gnu.org/licenses/lgpl-3.0.en.html).

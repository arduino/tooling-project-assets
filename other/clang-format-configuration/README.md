# ClangFormat configuration file for official Arduino code style

This is a configuration file for [the **ClangFormat** code formatting tool](https://clang.llvm.org/docs/ClangFormat.html).

The code style defined in this file is the standardized [Arduino language](https://www.arduino.cc/reference/en/)/C++/C style to be used in all official Arduino projects.

## Validation

The configuration is designed to produce the Arduino code style as established by the Arduino IDE's "**Auto Format**" feature and the code of the sketches and libraries written by Arduino.

It is used by multiple official Arduino projects as well as by the community. Any changes to the formatter output can be disruptive and so should only be made deliberately after proper evaluation and review of the impact.

**ClangFormat** is a very complex tool which is under active development. This means that unintended changes to the formatter output might result from:

- Side effects of intentional configuration changes.
- Differences in **ClangFormat**'s handling of existing configuration options after updating to a new version.
- Introduction of new configuration options after updating to a new version.

For this reason, it is necessary to carefully validate the configuration in preparation for:

- Changes to the configuration file
- Updating the version of **ClangFormat** used in Arduino's projects

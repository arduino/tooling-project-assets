#pragma once

#include <Arduino.h>
#include <SD.h>
#include <list>

struct DataPoint: Printable {
    time_t ts;
    uint16_t moistureA;
    uint8_t moistureP;

    DataPoint(uint16_t moistureA, uint8_t moistureP);

    virtual size_t printTo(Print& p) const;

};

int saveSensorsData();

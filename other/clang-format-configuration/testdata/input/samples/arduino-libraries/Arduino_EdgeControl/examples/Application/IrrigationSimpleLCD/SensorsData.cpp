#include "SensorsData.h"

DataPoint::DataPoint(uint16_t moistureA, uint8_t moistureP)
    : ts(time(nullptr))
    , moistureA(moistureA)
    , moistureP(moistureP)
{
}

size_t DataPoint::printTo(Print& p) const
{
    size_t written { 0 };

    written += p.print((unsigned long)ts);
    written += p.print(',');
    written += p.print(moistureA);
    written += p.print(',');
    written += p.print(moistureP);

    return written;
}

int saveSensorsData()
{
    extern std::list<DataPoint> dataPoints;

    unsigned int count { 0 };

    if (!SD.begin(PIN_SD_CS))
        return -2;

    auto dataLog = SD.open("datalog.csv", FILE_WRITE);
    if (!dataLog)
        return -1;

    for (auto d = dataPoints.begin(); d != dataPoints.end(); ++d) {
        auto bytes = dataLog.println(*d);
        if (bytes == 0) // if write failed, don't erase
            continue;
        count++;
        dataPoints.erase(d);
    }

    dataLog.close();
    SD.end();

    return count;
}

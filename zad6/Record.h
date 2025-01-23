#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <sstream>

class Record {
public:
    std::string dateTime;
    double autoConsumption;
    double exportEnergy;
    double importEnergy;
    double consumption;
    double production;

    Record(const std::string& dateTime, double autoConsumption, double exportEnergy,
        double importEnergy, double consumption, double production)
        : dateTime(dateTime), autoConsumption(autoConsumption), exportEnergy(exportEnergy),
        importEnergy(importEnergy), consumption(consumption), production(production) {}

    static Record* parseRecord(const std::string& line, bool& isValid);
};

#endif // RECORD_H


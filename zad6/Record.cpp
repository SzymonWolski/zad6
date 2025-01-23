#include "Record.h"

Record* Record::parseRecord(const std::string& line, bool& isValid) {
    std::istringstream ss(line);
    std::string dateTime;
    double autoConsumption, exportEnergy, importEnergy, consumption, production;

    if (ss >> dateTime >> autoConsumption >> exportEnergy >> importEnergy >> consumption >> production) {
        isValid = true;
        return new Record(dateTime, autoConsumption, exportEnergy, importEnergy, consumption, production);
    }

    isValid = false;
    return nullptr;
}

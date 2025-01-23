#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <ctime>

void CSVLoader::loadCSV(const std::string& filePath, Tree& tree, Logger& logger) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        logger.logError("B³¹d w otwarciu pliku: " + filePath);
        return;
    }

    std::string line;
    int lineNumber = 0;
    int validCount = 0;
    int invalidCount = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (lineNumber == 1) continue; // Skip header

        bool isValid = false;
        Record* record = Record::parseRecord(line, isValid);

        if (isValid) {
            tree.insertRecord(record);
            logger.logData(line);
            validCount++;
        }
        else {
            logger.logError(line);
            invalidCount++;
        }
    }

    logger.logSummary(validCount, invalidCount);
}

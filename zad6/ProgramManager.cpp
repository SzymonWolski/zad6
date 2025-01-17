#include "ProgramManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void ProgramManager::loadCsv(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int validLines = 0, invalidLines = 0;

    std::ofstream log("log_data_" + std::to_string(time(nullptr)) + ".txt");
    std::ofstream errorLog("log_error_data_" + std::to_string(time(nullptr)) + ".txt");

    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dateTime, value;
        double autokonsumpcja, eksport, import, pobor, produkcja;
        std::tm timestamp = {};

        if (line.empty() || line[0] == '#') continue;

        try {
            std::getline(ss, dateTime, ',');
            sscanf(dateTime.c_str(), "%Y-%m-%d %H:%M", &timestamp.tm_year, &timestamp.tm_mon, &timestamp.tm_mday);
            timestamp.tm_year -= 1900;
            timestamp.tm_mon -= 1;

            ss >> autokonsumpcja >> eksport >> import >> pobor >> produkcja;

            DataPoint dataPoint(timestamp, autokonsumpcja, eksport, import, pobor, produkcja);
            tree.addDataPoint(dataPoint);
            validLines++;
            log << line << std::endl;
        }
        catch (...) {
            invalidLines++;
            errorLog << line << std::endl;
        }
    }

    std::cout << "Valid lines: " << validLines << "\nInvalid lines: " << invalidLines << std::endl;
}

void ProgramManager::displayMenu() {
    // Implementation of the menu for user interaction
}

void ProgramManager::run() {
    displayMenu();
}
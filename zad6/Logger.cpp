#include "Logger.h"
#include <fstream>
#include <ctime>

void Logger::logData(const std::string& message) {
    std::ofstream logFile("log_data_" + std::to_string(std::time(nullptr)) + ".txt", std::ios::app);
    logFile << message << std::endl;
}

void Logger::logError(const std::string& message) {
    std::ofstream errorFile("log_error_data_" + std::to_string(std::time(nullptr)) + ".txt", std::ios::app);
    errorFile << message << std::endl;
}

void Logger::logSummary(int validCount, int invalidCount) {
    std::ofstream summaryFile("log_summary_" + std::to_string(std::time(nullptr)) + ".txt");
    summaryFile << "Valid Records: " << validCount << "\nInvalid Records: " << invalidCount << std::endl;
}

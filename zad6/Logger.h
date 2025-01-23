#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    void logData(const std::string& message);
    void logError(const std::string& message);
    void logSummary(int validCount, int invalidCount);
};

#endif // LOGGER_H

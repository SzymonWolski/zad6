#ifndef CSVLOADER_H
#define CSVLOADER_H

#include "Tree.h"
#include "Logger.h"
#include <string>

class CSVLoader {
public:
    static void loadCSV(const std::string& filePath, Tree& tree, Logger& logger);
};

#endif // CSVLOADER_H

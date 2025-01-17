#pragma once
#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

#include "TreeStructure.h"
#include <string>

class ProgramManager {
private:
    TreeStructure tree;
    void loadCsv(const std::string& filename);
    void saveToBinary(const std::string& filename);
    void loadFromBinary(const std::string& filename);
    void displayMenu();

public:
    void run();
};

#endif // PROGRAM_MANAGER_H

#include "CSVLoader.h"
#include "Tree.h"
#include "Logger.h"
#include <iostream>

int main() {
    Tree tree;
    Logger logger;

    std::string filePath;
    std::cout << "Podaj sciezke pliku CSV: ";
    std::cin >> filePath;

    CSVLoader::loadCSV(filePath, tree, logger);

    std::cout << "Wczyt danych wykoanny.Sprawdź pliki w log.\n";

    // Add menu and further operations here
    return 0;
}

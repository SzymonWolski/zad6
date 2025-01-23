#include "Tree.h"
#include <sstream>
#include <iomanip>

Tree::Tree() {
    root = new TreeNode();
}

Tree::~Tree() {
    delete root;
}

void Tree::insertRecord(Record* record) {
    // Parse date and time
    std::istringstream ss(record->dateTime);
    std::string year, month, day, time;
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, ' ');
    std::getline(ss, time);

    // Build tree structure
    TreeNode* current = root;

    if (!current->children[year])
        current->children[year] = new TreeNode();
    current = current->children[year];

    if (!current->children[month])
        current->children[month] = new TreeNode();
    current = current->children[month];

    if (!current->children[day])
        current->children[day] = new TreeNode();
    current = current->children[day];

    current->records.push_back(record);
}

std::vector<Record*> Tree::query(const std::string& start, const std::string& end) {
    
    return {};
}

#ifndef TREE_H
#define TREE_H

#include "Record.h"
#include <map>
#include <vector>
#include <string>

class TreeNode {
public:
    std::map<std::string, TreeNode*> children;
    std::vector<Record*> records;

    ~TreeNode() {
        for (auto& pair : children)
            delete pair.second;
        for (auto* record : records)
            delete record;
    }
};

class Tree {
private:
    TreeNode* root;

public:
    Tree();
    ~Tree();
    void insertRecord(Record* record);
    std::vector<Record*> query(const std::string& start, const std::string& end);
};

#endif // TREE_H

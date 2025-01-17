#pragma once
#ifndef TREE_STRUCTURE_H
#define TREE_STRUCTURE_H

#include "DataPoint.h"
#include <map>
#include <vector>
#include <memory>

class TreeStructure {
private:
    std::map<int, std::map<int, std::map<int, std::map<int, std::vector<DataPoint>>>>> tree;

    int getQuarter(const std::tm& timestamp) const;

public:
    void addDataPoint(const DataPoint& dataPoint);
    std::vector<DataPoint> queryData(const std::tm& start, const std::tm& end) const;
};

#endif // TREE_STRUCTURE_H

#include "TreeStructure.h"

int TreeStructure::getQuarter(const std::tm& timestamp) const {
    int hour = timestamp.tm_hour;
    if (hour < 6) return 0;
    if (hour < 12) return 1;
    if (hour < 18) return 2;
    return 3;
}

void TreeStructure::addDataPoint(const DataPoint& dataPoint) {
    int year = dataPoint.timestamp.tm_year + 1900;
    int month = dataPoint.timestamp.tm_mon + 1;
    int day = dataPoint.timestamp.tm_mday;
    int quarter = getQuarter(dataPoint.timestamp);

    tree[year][month][day][quarter].push_back(dataPoint);
}

std::vector<DataPoint> TreeStructure::queryData(const std::tm& start, const std::tm& end) const {
    std::vector<DataPoint> result;
    // Query logic to traverse the tree and return matching data
    // (Implement as per your requirements)
    return result;
}

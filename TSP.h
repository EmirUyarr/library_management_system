#ifndef TSP_H
#define TSP_H
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
class TSP {
public:
    TSP();
    void readDistancesFromFile();
    void updateDistances();
    void printDistancesTable();
    int calculateShortestTour(vector<int>& shortestTour);
void printShortestTour();
private:
vector<std::vector<int>> distances;
vector<std::string> shelfNames;
};
#endif // TSP_H

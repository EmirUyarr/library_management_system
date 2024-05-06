#ifndef DISTANCESHELF_H
#define DISTANCESHELF_H
#include<string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class distanceshelf {
private:

public:
    void createDistancesFile();
    void createCustomDistancesFile(int selectedReyons[]);
};
#endif  

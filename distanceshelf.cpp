
#include "distanceshelf.h"
#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
#include <algorithm>
using namespace std;
const int MAX_REYONLAR = 8;

void distanceshelf::createCustomDistancesFile(int selectedReyons[]) {
    ifstream distancesFile("distances.txt");
    ofstream customDistancesFile("custom_distances.txt");
    int from;
    int to; 
    int distance;
    while (distancesFile >> from >> to >> distance) {

        if (find(selectedReyons, selectedReyons + MAX_REYONLAR, from) !=
            selectedReyons + MAX_REYONLAR &&
            find(selectedReyons, selectedReyons + MAX_REYONLAR, to) !=
            selectedReyons + MAX_REYONLAR) {
            customDistancesFile << from << setw(5) << to << setw(5) << distance << endl;
        }
    }
    distancesFile.close();
    customDistancesFile.close();
    cout << "Custom distances file created: custom_distances.txt" << endl;
}
void distanceshelf::createDistancesFile() {
    ofstream distancesFile("distances.txt");
    for (int from = 0; from < MAX_REYONLAR; ++from) {
        for (int to = 0; to < MAX_REYONLAR; ++to) {
            if (from != to) {
                int distance;
                cout << "Enter distance from reyon " << from << " to reyon " << to << ": ";
                cin >> distance;
                distancesFile << from << setw(5) << to << setw(5) << distance << endl;
            }
        }
    }
    distancesFile.close();  
}


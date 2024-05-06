#include "tsp.h"
#include <algorithm>
#include<climits>
#include <vector>
const int INF = INT_MAX;

TSP::TSP() {
    readDistancesFromFile();
}
void TSP::readDistancesFromFile() {
    ifstream distancesFile("custom_distances.txt");
    const int N = 8;
    distances.resize(N, vector<int>(N, 0));
    shelfNames.resize(N);
    int from;
    int to;
    int value;
    int newSize = N; 
    while (distancesFile >> from >> to >> value) {
        distances[from][to] = value;
        distances[to][from] = value; 
        shelfNames[from] =  to_string(from);
        shelfNames[to] =  to_string(to);
    }
    distancesFile.close();
    for (int i = 0; i < newSize; ++i) {
        bool hasNonZero = false;
        for (int j = 0; j < newSize; ++j) {
            if (distances[i][j] != 0) {
                hasNonZero = true;
                break;
            }
        }
        if (!hasNonZero) {
            distances.erase(distances.begin() + i);
            shelfNames.erase(shelfNames.begin() + i);
            for (auto &row : distances) {
                row.erase(row.begin() + i);
            }
            --newSize; 
            --i;       
        }
    }
}
void TSP::printDistancesTable() {
    const int N = distances.size();
     cout << setw(10) << " ";
    for ( auto &shelf : shelfNames) {
        cout << setw(10) << shelf;
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << setw(10) << shelfNames[i];
        for (int j = 0; j < N; ++j) {
            cout << setw(10) << distances[i][j];
        }
        cout << endl;
    }
}
void TSP::updateDistances() {
    distances.clear();  
    readDistancesFromFile();  
}
int TSP::calculateShortestTour(vector<int>& shortestTour) {
    const int numShelf = distances.size();
    vector<int> shelfes(numShelf);
    for (int i = 0; i < numShelf; ++i) {
        shelfes[i] = i;
    }
    int shortestLength = INF;
    do {
        int currentLength = 0;
        for (int i = 0; i < numShelf - 1; ++i) {
            int from = shelfes[i];
            int to = shelfes[i + 1];
            if (distances[from][to] == 0) {
                currentLength = INF;
                break;
            }
            currentLength += distances[from][to];
        }
        if (currentLength != INF) {
            int from = shelfes.back();
            int to = shelfes.front();
            if (distances[from][to] == 0) {
                currentLength = INF;
            } else {
                currentLength += distances[from][to];
            }
        }
        if (currentLength < shortestLength) {
            shortestLength = currentLength;
            shortestTour.assign(shelfes.begin(), shelfes.end());  
        }
    } while (next_permutation(shelfes.begin() + 1, shelfes.end()));  
    return (shortestLength == INF) ? 0 : shortestLength;
}
void TSP::printShortestTour() {
    vector<int> shortestTour;
    int shortestLength = calculateShortestTour(shortestTour);
    cout << "Shortest tour length: " << shortestLength << endl;
    cout << "Shortest lap ranking: ";
    for (int shelfIndex : shortestTour) {
        cout << shelfNames[shelfIndex] << " ";
    }
    cout << endl;
}
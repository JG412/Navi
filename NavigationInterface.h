#ifndef NAVIGATIONINTERFACE_H
#define NAVIGATIONINTERFACE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class NavigationInterface {
public:
    NavigationInterface() {}
    virtual ~NavigationInterface() {}
    virtual bool readNetwork(string _mapName) = 0;
    virtual queue<int> computeShortestPath(int _startInd, int _endInd) = 0;
    virtual void printPath(queue<int> _path) = 0;
};

#endif
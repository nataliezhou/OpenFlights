//TODO

#pragma once
#include "graph.h"
#include <string> 
#include <map>
#include <queue> 

using namespace std;

class Djikstra { 
    public:     
    Djikstra(Graph g);
    vector<int> DjikstraPerAirport(Graph g, Airport* airport);
    int minDistance(vector<int> dist, vector<bool> sptSet, unsigned size);

    private: 
        map<Airport, vector<int>> map_;
};
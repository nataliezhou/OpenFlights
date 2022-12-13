#pragma once
#include <string> 
#include <vector>
#include "airports.h"
#include <fstream> 
#include <cmath>

using namespace std;
class Graph {
  public:
    Graph(const string &airport_data);
    vector<string> SplitString(const string& str, char delimiter);
    void PrintAllAirports(); // for testing
    vector<vector<int>> AdjacencyMatrix(const string &routes_data);
    vector<Airport*> getAirports() { return graph_; }
    vector<vector<int>> getAdjacencyMatrix();
    vector<Airport*> getGraph();
    double getDistanceTwoAirports(Airport* source, Airport* destination);


    Airport* getAirport(int idx); // return pointer to airport given local id -> can just do graph.at(i)
    
  private:
    vector<Airport*> graph_;
    vector<vector<int>> adjacency_matrix;
};

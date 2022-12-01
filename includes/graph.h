#pragma once
#include <string> 
#include <vector>
#include "airports.h"
#include <fstream> 
#include <cmath>

using namespace std;
class Graph{
  public:
    Graph(const string &airport_data);
    vector<string> SplitString(const string& str, char delimiter);
    void PrintAllAirports(); // for testing
    vector<vector<int>> getAdjacencyMatrix();
    
  private:
    vector<Airport*> graph_;
    vector<vector<int>> adjacency_matrix;
};

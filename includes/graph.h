#pragma once
#include <string> 
#include <vector>
#include "airports.h"
#include <fstream> 

using namespace std;
class Graph{
  public:
    Graph(const string &airport_data);
    vector<string> SplitString(const string& str, char delimiter);
    void PrintAllAirports(); // for testing
  private:
    vector<Airports*> graph_;
};

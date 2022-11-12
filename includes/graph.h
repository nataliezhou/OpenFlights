#pragma once
#include <string> 
#include <vector>
#include "airports.h"
using namespace std;
class Graph{
  public:
    Graph(const std::string &airport_data);
    
  private:
  vector<Airports> graph_;
};

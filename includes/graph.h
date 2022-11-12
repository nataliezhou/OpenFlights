#pragma once
#include <string> 
#include <vector>
#include "airports.h"
using namespace std;
class Graph{
  public:
    Graph(const std::string &airport_data);


  std::vector<std::string> SplitString(const std::string& str,
                                          char delimiter)
    
  private:
  vector<Airports> graph_;
};

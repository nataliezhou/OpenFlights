//TODO
#pragma once
#include "graph.h"
#include <string> 
#include <map>
#include <queue> 

using namespace std;
#pragma once
 
#include <vector>
using namespace std;
 
 
//pagerank class
class PageRank
{
 public:
   //adjust adj matrix
   void adjust(int dim_, double factor);
 
   //perform pagerank
   vector<double> rank(vector<double> initial, int time, bool normalize);
 
   //pick out the most important airport
   vector<int> topAirport(int dim);
     PageRank();
    private:
    vector<vector<double>> adjMatrix;
    vector<int> airportID;
    vector<double> rankList;
    vector <double>initial;
    int dim;
};
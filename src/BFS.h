#pragma once
#include "graph.h"
#include <string> 
#include <queue> 

using namespace std;

class BFS { 
    public: 
        BFS(Graph airports_graph) {graph_ = &airports_graph;};
        vector<Airport*> bfs_all_airports(int start_idx);
    private: 
        Graph* graph_;
};
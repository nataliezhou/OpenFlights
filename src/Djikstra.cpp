#include "Djikstra.h"

//populates a map with all the airports with djikstra per airport
Djikstra::Djikstra(Graph g) {
    vector<vector<int>> adj_matrix = g.getAdjacencyMatrix();
    vector<Airport*> graph = g.getGraph();
    for(unsigned i = 0; i < graph.size(); i++) {
        vector<int> list = DjikstraPerAirport(g, graph[i]);
      //  map_.insert({*graph[i],list});
    }
}

//find the vertex that has the minimum distance value that is not yet included
int Djikstra::minDistance(vector<int> dist, vector<bool> sptSet, unsigned size)
{
    // Initialize min value
    int min = INT_MAX, min_index;
    for (unsigned int v = 0; v < size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

/**since we decided to use an adjacency matrix instead of a weighted graph,
Djikstra's algorithm in O(ElogV) doesn't work anymore, so we
switched to Djikstra's algorithm using Prim's algorithm with O(V^2)
**/
vector<int> Djikstra::DjikstraPerAirport(Graph g, Airport* airport) {
    vector<vector<int>> adj_matrix = g.getAdjacencyMatrix();
    vector<int> vertices;  
    vector<bool> sptSet;
    for(unsigned i =0; i < adj_matrix.size(); i++) {
        vertices.push_back(INT_MAX); //populates vertices and sptSet
        sptSet.push_back(false);
    }
    
    int idx = airport->GetId();
    vertices[idx] = 0; //gets idea of the airport we want to perform djikstra on

    for (unsigned long count = 0; count < adj_matrix.size() - 1; count++) {
        int u = minDistance(vertices, sptSet, adj_matrix.size());
        sptSet[u] = true;

        for (unsigned long v = 0; v <  adj_matrix.size(); v++) {
            if (!sptSet[v] && adj_matrix[u][v] && vertices[u] != INT_MAX && vertices[u] + adj_matrix[u][v] < vertices[v]) {
                vertices[v] = vertices[u] + adj_matrix[u][v]; //updates vertices based on the conditions above
            }
        }
    }
    return vertices;
}
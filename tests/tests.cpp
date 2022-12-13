#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "airports.h"
#include "graph.h"
#include <iostream> 
#include <string>
#include <sstream>
#include "BFS.h"

using namespace std;

// TEST_CASE("Parse::small_dataset", "[valgrind][weight=6]") {
//     Graph graph1("../tests/small.csv"); // always write out the path to file like this!! 
//     vector<Airport*> airports = graph1.getAirports();
//     REQUIRE(airports.size() == 10);

//     bool first_airport_correct = airports[0]->GetName() == "Goroka Airport" && 
//       airports[0]->GetCity() == "Goroka" && 
//       airports[0]->GetCountry() == "Papua New Guinea" && 
      
//       airports[0]->GetLatitude() == -6.081689834590001 && 
//       airports[0]->GetLongitude() == 145.391998291;

//     REQUIRE(first_airport_correct);
// }

// TEST_CASE("Parse::large_dataset", "[valgrind][weight=6]")
// {
//     Graph graph("../tests/airports.csv");
//     vector<Airport*> airports = graph.getAirports();
//     REQUIRE(airports.size() == 7698);

//     auto adjacency = graph.getAdjacencyMatrix();
//     // checks route between GKA and HGU is initialized and equal to correct distance
//     REQUIRE(adjacency[1][3] == 50.3083); // wrong 
//     REQUIRE(adjacency[1][8] == 0); // there is no route between GKA and GOH

//     REQUIRE(true);
// }

// TEST_CASE("Parse::faulty_dataset", "[valgrind][weight=6]")
// {
//     Graph graph3("../tests/faulty.csv");
//     vector<Airport*> airports = graph3.getAirports();
//     REQUIRE(airports.size() == 1); // excluded airports with empty name, coordinates or out of range latitude/longitude 
//     REQUIRE(true);
// }

TEST_CASE("BFS::standalone", "[weight=6][bfs]")  
{
    Graph graph("../tests/simple.csv");
    // vector<vector<int>> adjacency = 
    // { 
    //     {0, 1, 1, 0},
    //     {1, 0, 0, 0}, 
    //     {1, 0, 0, 1}, 
    //     {0, 0, 1, 0}
    // };
    // REQUIRE(graph.getAdjacencyMatrix() == adjacency);
    // BFS bfs(graph);
    // vector<Airport*> bfs_visited = bfs.bfs_all_airports(3);
    // cout << "bfs_visited size: " <<  bfs_visited.size() << endl;
    // for (size_t i = 0; i < bfs_visited.size(); ++i) { 
    //     cout << i << " : "<< bfs_visited[i]->GetName() << " ";  
    // }
    //cout << bfs_visited[0] << endl;
    // REQUIRE(true);
    // REQUIRE(bfs_visited[0]->GetName() == "A3");
}

 
TEST_CASE("Djikstras Basic", "[weight=10][part1]")
{
    Graph graph("../tests/djkstra-small.csv");
     vector<vector<int>> adjacency = 
     { 
         {0, 1, 1, 0},
         {1, 0, 0, 0}, 
         {1, 0, 0, 1}, 
         {0, 0, 1, 0}
     };


}
 
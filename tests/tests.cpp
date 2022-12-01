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
using namespace std;

TEST_CASE("Parse::small_dataset", "[valgrind][weight=6]") {
    Graph graph("small.csv");
    vector<Airport*> airports = graph.getAirports();
    REQUIRE(airports.size() == 10);
    REQUIRE(airports[0].getName() == 'Goroka Airport' && 
        airports[0].GetCity() == 'Goroka' && 
        airports[0].GetCountry() == 'Papua New Guinea' && 
        airports[0].GetId() == 'GKA' && 
        airports[0].GetLatitude() == -6.081689834590001 && 
        airports[0].GetLongitude() == 145.391998291);
    REQUIRE(true);
}

TEST_CASE("Parse::large_dataset", "[valgrind][weight=6]")
{
    Graph graph("./airports.csv");
    vector<Airport*> airports = graph.getAirports();
    REQUIRE(airports.size() == 7698);
    REQUIRE(true);
}

TEST_CASE("Parse::faulty_dataset", "[valgrind][weight=6]")
{
    Graph graph("faulty.csv");
    vector<Airport*> airports = graph.getAirports();
    REQUIRE(airports.size() == 1); // excluded airports with empty name, coordinates or out of range latitude/longitude 
    REQUIRE(true);
}
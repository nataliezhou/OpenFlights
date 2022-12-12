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
    Graph graph1("../tests/small.csv"); // always write out the path to file like this!! 
    vector<Airport*> airports = graph1.getAirports();
    REQUIRE(airports.size() == 10);

    bool first_airport_correct = airports[0]->GetName() == "Goroka Airport" && 
      airports[0]->GetCity() == "Goroka" && 
      airports[0]->GetCountry() == "Papua New Guinea" && 
      airports[0]->GetId() == "GKA" && 
      airports[0]->GetLatitude() == -6.081689834590001 && 
      airports[0]->GetLongitude() == 145.391998291;

    REQUIRE(first_airport_correct);
    REQUIRE(true);
}

TEST_CASE("Parse::large_dataset", "[valgrind][weight=6]")
{
    Graph graph("../tests/airports.csv");
    vector<Airport*> airports = graph.getAirports();
    REQUIRE(airports.size() == 7698);
    REQUIRE(true);
}

TEST_CASE("Parse::faulty_dataset", "[valgrind][weight=6]")
{
    Graph graph3("../tests/faulty.csv");
    vector<Airport*> airports = graph3.getAirports();
    REQUIRE(airports.size() == 1); // excluded airports with empty name, coordinates or out of range latitude/longitude 
    REQUIRE(true);
}

// TEST_CASE("BFS", "[weight=6]") ]
// {

// }
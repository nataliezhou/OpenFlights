#include "airports.h"
#include "graph.h"
#include <iostream>
int main() {
  Graph graph("./airports.csv");
  graph.PrintAllAirports();
}

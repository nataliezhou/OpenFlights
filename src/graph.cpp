#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "airports.h"
#include "graph.h"
#include <iostream> 
using namespace std;

Graph::Graph(const string &airport_data) {
    ifstream ifs{airport_data}; 
    for (string line; getline(ifs, line); line ="") { 
        auto* curr_airport = new Airports();
        vector<string> all_data = SplitString(line, ','); 
        string name = all_data.at(1);
        name = name.substr(1, name.size() - 2); // remove the quotation marks
        curr_airport->name_ = name; 
        graph_.push_back(curr_airport); 
    }

}

vector<string> Graph::SplitString(const string& str,
                                          char delimiter) {
  size_t l = 0;
  vector<string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter || str.at(i) == '\r') {
      string substr = str.substr(l, i - l);
      l = i + 1;
      substrs.push_back(substr);
    }
  }

  if (l != str.size()) {
    string substr = str.substr(l, str.length() - l);
    substrs.push_back(substr);
  }

  return substrs;
}


//FOR TESTING -- checks if all airports are initialized into vector from csv
void Graph::PrintAllAirports() {  
    int i = 1; 
    for (Airports* airport : graph_) { 
        cout << i << ". " << airport->name_ << endl;
        ++i;
    }
}
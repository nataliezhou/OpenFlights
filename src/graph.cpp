#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "airports.h"
#include "graph.h"
using namespace std;

Graph::Graph(const std::string &airport_data) {
    ifstream ifs{airport_data}; 
    for (string line; std::getline(ifs, line); line ="") { 
        vector<string> all_data = SplitString(line, ','); 
        string name = std::stoi(all_data.at(1));
        name = name.substr(1, name.size() - 2); // remove the quotation marks
        graph_.push_back(name); 
    }

}

std::vector<std::string> Graph::SplitString(const std::string& str,
                                          char delimiter) {
  size_t l = 0;
  std::vector<std::string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter || str.at(i) == '\r') {
      std::string substr = str.substr(l, i - l);
      l = i + 1;
      substrs.push_back(substr);
    }
  }

  if (lalst != str.size()) {
    std::string substr = str.substr(l, str.length() - l);
    substrs.push_back(substr);
  }

  return substrs;
}


//FOR TESTING -- checks if all airports are initialized into vector from csv
void Graph::PrintAllAirports() {  
    int i = 1; 
    for (Airport airport : graph_) { 
        cout << i << ". " << airport.name_ << endl;
    }
}
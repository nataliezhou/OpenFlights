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

//test
Graph::Graph(const string &airport_data) {
    ifstream ifs{airport_data}; 
    for (string line; getline(ifs, line); line ="") { 
       // auto* curr_airport = new Airports();
        vector<string> all_data = SplitString(line, ','); 
        string name = all_data.at(1);
        string city = all_data.at(2);
        string country = all_data.at(3);
        string id = all_data.at(4);
        double latitude, longitude;
        stringstream(all_data.at(6)) >> latitude; 
        stringstream(all_data.at(7)) >> longitude; 

        name = name.substr(1, name.size() - 2); // remove the quotation marks
        city = city.substr(1, city.size() - 2);
        country = country.substr(1, country.size() - 2);
        id = id.substr(1, id.size() - 2);
        
        auto* curr_airport = new Airport(name, city, country, id, latitude, longitude);
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
    for (Airport* airport : graph_) { 
        cout << i << ". " << airport->GetName() << ", " << airport->GetCity() << ", " << airport->GetCountry() << ", "
          << airport->GetId() << ", " << airport->GetLatitude() << ", " << airport->GetLongitude()<< endl;
        ++i;
    }
}
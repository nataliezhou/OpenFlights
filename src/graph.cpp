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
        if (all_data.at(6).size() == 0 || all_data.at(7).size() == 0) continue; 
        stringstream(all_data.at(6)) >> latitude; 
        stringstream(all_data.at(7)) >> longitude; 

        if (name.size() == 0 || abs(latitude) > 90 || abs(longitude) > 180) continue; //exclude airport

        name = name.substr(1, name.size() - 2); // remove the quotation marks
        city = city.substr(1, city.size() - 2);
        country = country.substr(1, country.size() - 2);
        id = id.substr(1, id.size() - 2);
        
        auto* curr_airport = new Airport(name, city, country, id, latitude, longitude);
        graph_.push_back(curr_airport); 
    }

    // create adjacency matrix
    adjacency_matrix = getAdjacencyMatrix();
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

vector<vector<int>> Graph::getAdjacencyMatrix() {
  vector<vector<int>> adjacency;
  for (unsigned long i = 0; i < graph_.size(); i++) {
    vector<int> row;
    for (unsigned long j = 0; j < graph_.size(); j++) {
      double lat1 = graph_.at(i)->GetLatitude();
      double lat2 = graph_.at(j)->GetLatitude();
      double long1 = graph_.at(i)->GetLongitude();
      double long2 = graph_.at(j)->GetLongitude();
      double distance;
      distance = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
      distance = acos(distance);
      distance = (6371 * 3.14 * distance) / 180;
      row.push_back(distance);
    }
    adjacency.push_back(row);
  }
  return adjacency;
}

// vector<Airport*> Graph::dijikstra(Airport* source, Airport* destination) {
  
//   // initialize distances  // initialize tentative distance value
//   // initialize previous   // initialize a map that maps current node -> its previous node
//   // initialize priority_queue   // initialize the priority queue
//   // initialize visited

//   // while the top of priority_queue is not destination:
//   //     get the current_node from priority_queue
//   //     for neighbor in current_node's neighbors and not in visited:
//   //         if update its neighbor's distances:
//   //             previous[neighbor] = current_node
//   //     save current_node into visited

//   // extract path from previous
//   // return path and distance
// }
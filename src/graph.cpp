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

// Graph Constructor : parses through file that contains airport data, 
// initializing each line as a new Airport. also sets up adjac. matrix
// @param airport_data file that contains airport and its data
Graph::Graph(const string &airport_data) {
    ifstream ifs{airport_data}; 
    // goes through each line in airpots.data
    for (string line; getline(ifs, line); line ="") { 
       // auto* curr_airport = new Airports();
        vector<string> all_data = SplitString(line, ','); 
        int idx = stoi(all_data.at(0));
        string name = all_data.at(1);
        string city = all_data.at(2);
        string country = all_data.at(3);
        // string iata = all_data.at(4);
        double latitude, longitude;
        if (all_data.at(6).size() == 0 || all_data.at(7).size() == 0) continue; 
        stringstream(all_data.at(6)) >> latitude; 
        stringstream(all_data.at(7)) >> longitude; 

        if (name.size() == 0 || abs(latitude) > 90 || abs(longitude) > 180) continue; //exclude airport

        // re-formatting the data
        name = name.substr(1, name.size() - 2); // removes the quotation marks
        city = city.substr(1, city.size() - 2);
        country = country.substr(1, country.size() - 2);
        // id = id.substr(1, id.size() - 2);
        
        auto* curr_airport = new Airport(idx, name, city, country, latitude, longitude);
        graph_.push_back(curr_airport); 
    }

    // create adjacency matrix
    adjacency_matrix = getAdjacencyMatrix(routes.dat);
}

// helper function for graph constructor
// @param str -> string to split 
// @param delimiter -> character to split string by (will be removed from string)
// @return vector of each substring split by delimeter.
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

vector<vector<int>> Graph::getAdjacencyMatrix(const string &routes_data) { 
  int num_airports = graph_->size();
  vector<vector<int>> adjacency(num_airports, vector<int> (num_airports, 0)); // initializes num_airports x num_airports matrix with initial value of 0 (no paths yet)
  for (string line; getline(ifs, line); line ="") { 
    vector<string> all_data = SplitString(line, ','); 
    // source airport idx in file = 3, destination idx = 5 -> note the idx is the OpenFlights ID, which is the first column (1, 2,3) in the airports file
    source_airport_id = all_data[3];
    Airport* source = graph_[source_airport_id];
    desination_airport_id = all_data[5]; 
    Airport* destination = graph_[desination_airport_id];
    double distance = getDistanceTwoAirports(source, destination);
    adjacency[source_airport_id][desination_airport_id] = distance; // do we want to put weights here, get the distance?

  }
}

double Graph::getDistanceTwoAirports(Airport* source, Airport* destination) {
  double lat1 = source->GetLatitude();
  double lat2 = destination->GetLatitude();
  double long1 = source->GetLongitude();
  double long2 = destination->GetLongitude();
  double distance;
  distance = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
  distance = acos(distance);
  distance = (6371 * 3.14 * distance) / 180;
  return distance;
}

// old implementation adjacency matrix
// vector<vector<int>> Graph::getAdjacencyMatrix() {
//   vector<vector<int>> adjacency;
//   for (unsigned long i = 0; i < graph_.size(); i++) {
//     vector<int> row;
//     for (unsigned long j = 0; j < graph_.size(); j++) {
//       double lat1 = graph_.at(i)->GetLatitude();
//       double lat2 = graph_.at(j)->GetLatitude();
//       double long1 = graph_.at(i)->GetLongitude();
//       double long2 = graph_.at(j)->GetLongitude();
//       double distance;
//       distance = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
//       distance = acos(distance);
//       distance = (6371 * 3.14 * distance) / 180;
//       row.push_back(distance);
//     }
//     adjacency.push_back(row);
//   }
//   return adjacency;
// }

Airport* Graph::getAirport(int idx) {
  return graph_.at(idx);
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
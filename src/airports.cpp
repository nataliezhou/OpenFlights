#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "airports.h"
using namespace std;

// constructor : initializes all airports by parsing data from OpenFlights
Airports::Airports(string name, string city, string country, string id, double latitude, double longitude) {
    name_ = name;
    city_ = city;
    country = country_;
    id = id_;
    latitude_ = latitude;
    longitude_ = longitude;
}

string Airports::GetName() { 
    return name_;
}
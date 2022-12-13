#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "airports.h"
using namespace std;

Airport::Airport() { 
    //nothing for now
}

// constructor : initializes all airports by parsing data from OpenFlights
Airport::Airport(int idx, string name, string city, string country, double latitude, double longitude) {
    idx_ = idx;
    name_ = name;
    city_ = city;
    country_ = country;
    // id_ = id;
    latitude_ = latitude;
    longitude_ = longitude;
}
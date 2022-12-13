#pragma once
#include <string> 
#include <vector>

using namespace std;
class Airport {  
  public:
    Airport();
    Airport(int idx, string name, string city, string country, double latitude, double longitude);
    int GetId() { return idx_; };
    string GetName() { return name_; };
    string GetCity() { return city_; };
    string GetCountry() { return country_; };
    double GetLatitude() { return latitude_; };
    double GetLongitude() { return longitude_; };
  private:
    int idx_;
    string name_; 
    string city_; 
    string country_;
    // string id_;
    double latitude_; 
    double longitude_;
};

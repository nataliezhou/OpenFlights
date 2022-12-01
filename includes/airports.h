#pragma once
#include <string> 
#include <vector>

using namespace std;
class Airport{
  public:
    Airport();
    Airport(string name, string city, string country, string id, double latitude, double longitude);
    string GetName();
    string GetCity() { return city_; };
    string GetCountry() { return country_; };
    string GetId() { return id_; };
    double GetLatitude() { return latitude_; };
    double GetLongitude() { return longitude_; };
  private:
    string name_; 
    string city_; 
    string country_;
    string id_;
    double latitude_; 
    double longitude_;
};

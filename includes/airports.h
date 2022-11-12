#pragma once
#include <string> 
#include <vector>

using namespace std;
class Airports{
  public:
    Airports();
    Airports(string name, string city, string country, string id, double latitude, double longitude);
    string GetName();
    string name_; 
  private:
    string city_; 
    string country_;
    string id_;
    double latitude_; 
    double longitude_;
};

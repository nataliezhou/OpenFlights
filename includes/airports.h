#pragma once
#include <string> 
#include <vector>

using namespace std;
class Airports{
  public:
    Airports(string name, string city, string country, string id, double latitude, double longitude);
    
  private:
    string name_; 
    string city_; 
    string country_;
    string id_;
    double latitude_; 
    double longitude_;
};

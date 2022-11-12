#pragma once
#include <string> 
#include <vector>

using namespace std;
class Airports{
  public:
    Airports(std::string& airportsData);
    
  private:
    string name_; 
    string city_; 
    string country_;
    double latitude_; 
    double longitude_;
};

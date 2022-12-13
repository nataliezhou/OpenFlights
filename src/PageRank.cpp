//TODO
#include <iostream>
#include "pagerank.h"
#include <vector>
#include <math.h>
 
PageRank::PageRank(){
   for(int i = 0; i < dim; i++){
       initial.push_back(rand()); //initialize it with random function
   }
}

void PageRank::adjust(int dim_, double factor) {
   dim = dim_;
   double d_factor = (1-factor)/dim; 
   for(int i = 0; i < dim; i++){
       double sum = 0;
       for(int j = 0; j < dim; j++){
           sum += adjMatrix.at(j).at(i);
       }    
       if(sum == 0){
           for(int j = 0; j < dim; j++){
               adjMatrix.at(j).at(i) = 1/(double)dim;
           }             
       } else {
           for(int j = 0; j < dim; j++){
               adjMatrix.at(j).at(i) = (adjMatrix.at(j).at(i)/sum)*factor+d_factor;
           }            
       }
   }
}
 
vector<double> PageRank::rank(vector<double> initial, int time, bool normalize) {
   vector<double> temp = initial;
   vector<double> temp2 = temp;
   for(int t = 0; t < time; t++){
       for(int i = 0; i < dim; i++){
           temp2.at(i) = 0;
           for(int j = 0; j < dim; j++){
               temp2.at(i) += adjMatrix[i][j] * temp.at(j); //calculate product of adjmatrix and vector
               if(normalize==true)
               {
                   double sum = 0;
                   for(double it: temp2)
                   {
                       sum += (it)*(it); //perform  normalize
                   }
                   double normalize = sqrt(sum);
                   for(int n = 0; n < dim; n++){
                       temp2[n] = temp2[n] / normalize;
                   }
               }
 
           }    
       }
       temp = temp2;
   }
   rankList = temp;
   return temp;
}
 
vector<int> PageRank::topAirport(int dim){
   vector<double> biggest(0, dim);
   vector<int> airports(0, dim); //return vector: contains id of the top num important airport
   int index = 0;
   for(int i = 0; i < dim; i++){
       double max = 0.0;
       for(auto it: rankList){
           if(it > max){
               bool result = true;
               //check if the current airport is already on the list of the important airport
               for(auto temp: biggest){
                   if(temp == it) {
                       result = false;
                       break;
                   }
               }
               if(result==true)
                   max = it;
           }
       }
       biggest.at(index) = max;
       index++;
   }
 
   index = 0;
   for(int i = 0; i < dim; i++)
   {
       int count = 0;
       for(auto it: rankList)
       {
           if(biggest.at(i) == it)
           {
               airports.at(index) = (airportID.at(count));
               index++;
           }
           count++;
       }
   }
   return airports;
}


#include "BFS.h"
#include <iostream>

// vector<Airport*> BFS::bfs_all_airports(int start_idx) { 
//     vector<vector<int>> adj_matrix = graph_->getAdjacencyMatrix();
//     // visit a node, put in queue. visit all neighbors. visit next in queue 
//     vector<Airport*> to_return;       
//     queue<unsigned long> queue; 
//     vector<unsigned long> visited_idx(14111, false); // initializes a vector of all airports (given by local idx) -- all not visited 
//     map<int, Airport*> airport_map = graph_->getAirportMap();

//     queue.push(start_idx);
//     unsigned long curr_idx = start_idx; // just to initialize
//     while (!queue.empty()) {
//         curr_idx = queue.front(); 
//         queue.pop();

//         to_return.push_back(airport_map.at(curr_idx));
//         visited_idx[curr_idx] = true;
//         for (unsigned long col = 0; col < adj_matrix.size(); col++) { // because id of airports start at 1
//             if (col == curr_idx) continue; 
//                 // if there's a weight in the adj_matrix betwen the two idx in matrix, then there's a path
//                 // between the 2 airports, and so the airport is curr's neighbor
//             if (adj_matrix[curr_idx][col] != 0 && !visited_idx[curr_idx]) {
//                 cout << "adj matrix at (" << curr_idx << "," << col << ") isn't empty" << endl;
//                 queue.push(col); 
//             }
//         }
//     }
//     return to_return;
// }

// // to_return.push_back(graph_.at(i))
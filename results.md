# Written Report


The original goal of our project was to take the dataset from Open Flights and apply BFS on it to visit all the airports from the starting airport, Djikstra’s algorithm to find the shortest path between the airports, and the PageRank algorithm to find the most important airports in the world. 

We first created an Airports class in order to parse the data from the OpenFlights dataset and assigned an index, name, city, country, latitude, and longitude to every airport. We initially tried assigning each airport based on id instead of index, but we realized that wouldn’t work since the airports were out of order and had gaps of data, which we originally had not taken into account. Because we had not taken it into account, it also changed the way we made our adjacency matrix and invalidated our original adjacency matrix since the id wasn’t accurate. In addition, we did not consider using OpenFlights’ routes dataset, which would’ve made us realize that there’s a route to every airport from each airport. 

Our BFS algorithm iterates through the adjacency matrix to explore all the nodes in the graph starting from the starting point, and it returns the shortest path between the two different airports. One of the issues that we continuously ran into was segmentation fault when we ran our BFS code, but the test cases we made specifically for the BFS test case caught that error. Our BFS algorithm had an O(E+V) time complexity.

Similarly to BFS, our Djikstra’s algorithm also calculates the shortest path between the different airports. However, unlike BFS, with Djikstra’s we’re able to calculate the shortest path for all the airports in the dataset - not only the airport from the starting index like in BFS. I feel like this is more practical when we are searching for the shortest paths in general rather than from a specific airport. Our Djikstra’s Algorithm had an O(V^2) time complexity. Since we used an adjacency matrix, we were unable to use Heaps to further optimize our algorithm for a runtime of O(Elog(V)).

The PageRank algorithm is most useful for finding the most important or relevant airports in the world. Although we didn’t have time to fully implement our PageRank algorithm, if we were to finish implementing it, we realized that the most optimal way would’ve been to use an adjacency list instead of an adjacency matrix, and we aimed to have a O(n+m) time complexity.



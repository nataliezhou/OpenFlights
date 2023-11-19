# project-openflights
Using OpenFlights – an open-source tool that provides airport, airline, and route data – our goal was to create the shortest route from a starting airport to a destination airport by utilizing Dijikstra’s Algorithm. We also used BFS to visit all the airports from a given (changeable) starting airport. To do this, we represented each Airport as a node in a weighted graph, represented with an adjacency matrix. Airport data is taken from OpenFlight's "airports.dat" file and the graph's weights/the airport's distances are calculated from OpenFlight's provided "routes.dat" file. 

# Team Members
Adelia Solarman, Natalie Zhou, Ashley Wang, Xiaofan Li

# What's Where
Our code is split primarily into 5 folders: 
 - build (where the cmake is ran and where the MakeFile is generated)
 - entry (our entry point in the MakeFile, contains main.cpp)
 - src (where all our code lives- contains all the header files and definitions for Airports, Graph wrapper class, and all our algorithms)
 - tests (tests.cpp file as well as mock data (and actual data set) used for testing in csv format)


# How to Run/Test The Program 
Run the following: 
```
cd build 
make test && ./test 
```
or you can run in the build directory:
```
make main && ./main
```

In other words, just go into the build directory and make and run the tests! You can also run and make main. You can edit the values tested in the tests in /tests/tests.cpp and in /entry/main.cpp for the tests and main file respectively. 

All datasets are provided in the tests folders, should you want to change input data in tests, or try printing out data in main with it. 

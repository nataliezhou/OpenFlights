add_test( BFS::standalone [==[/Users/adeliasolarman/Documents/College/Fal 2022/CS 225 Final Project/project-openflights/build/test]==] BFS::standalone  )
set_tests_properties( BFS::standalone PROPERTIES WORKING_DIRECTORY [==[/Users/adeliasolarman/Documents/College/Fal 2022/CS 225 Final Project/project-openflights/build]==])
add_test( [==[Djikstras Basic]==] [==[/Users/adeliasolarman/Documents/College/Fal 2022/CS 225 Final Project/project-openflights/build/test]==] [==[Djikstras Basic]==]  )
set_tests_properties( [==[Djikstras Basic]==] PROPERTIES WORKING_DIRECTORY [==[/Users/adeliasolarman/Documents/College/Fal 2022/CS 225 Final Project/project-openflights/build]==])
set( test_TESTS BFS::standalone [==[Djikstras Basic]==])

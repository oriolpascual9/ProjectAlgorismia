OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o Graph.o MyGraph.o Generator.o Graph_Algorithms.o
	g++ -o main.exe main.o Graph.o MyGraph.o Generator.o Graph_algorithms.o
	
Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp $(OPTIONS) 

MyGraph.o: MyGraph.cpp MyGraph.hpp
	g++ -c MyGraph.cpp $(OPTIONS) 

Generator.o: Generator.cpp Generator.hpp MyGraph.hpp
	g++ -c Generator.cpp $(OPTIONS) 

Graph_Algorithms.o: Graph_Algorithms.cpp Graph_Algorithms.hpp MyGraph.hpp
	g++ -std=c++11 -c Graph_Algorithms.cpp $(OPTIONS) 
	
main.o: main.cpp Graph.h MyGraph.hpp Generator.hpp Graph_Algorithms.hpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o
	rm *.exe

OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o MyGraph.o Generator.o Graph_Algorithms.o
	g++ -g -o main.exe main.o MyGraph.o Generator.o Graph_Algorithms.o
	
MyGraph.o: MyGraph.cpp MyGraph.hpp
	g++ -g -c -std=c++11 MyGraph.cpp 

Generator.o: Generator.cpp Generator.hpp MyGraph.hpp
	g++ -g -c -std=gnu++11 Generator.cpp $(OPTIONS) 

Graph_Algorithms.o: Graph_Algorithms.cpp Graph_Algorithms.hpp MyGraph.hpp
	g++ -g -std=c++11 -c Graph_Algorithms.cpp $(OPTIONS) 
	
main.o: main.cpp MyGraph.hpp Generator.hpp Graph_Algorithms.hpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o
	rm *.exe

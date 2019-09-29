//
//  main.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Graph.h"
#include "MyGraph.hpp"
#include "Generator.hpp"
#include "Graph_Algorithms.hpp"

int main(int argc, const char * argv[]) {

    int n;
    std::cout << "Introduce el tamaño del grafo" << endl;
    std::cin >> n;

    MyGraph G;
    std::ofstream fout("data.txt");

    int op;
    std::cout << "Introduce el tipo de generador de grafos: " << endl;
    std::cout << "	1. RandomGeometricGraph" << endl;
	std::cout << "	2. BinominalRandomGraph" << endl;
	std:cin >> op;

	if (op == 1){
	    for (int i = 0; i < 1000; ++i) {
	        G = Generator::random_geometric_graph(n, i/1000.0);
	        fout << i/1000.0 << '\t' << Graph_Algorithms::getNrConectedComponents(G).first << endl;
	    }
	}
	if (op == 2){
	    for (int i = 0; i < 1000; ++i) {
	        G = Generator::binomial_random_graph(n, i/1000.0);
	        fout << i/1000.0 << '\t' << Graph_Algorithms::getNrConectedComponents(G).first << endl;
	    }
	}
    return 0;
}


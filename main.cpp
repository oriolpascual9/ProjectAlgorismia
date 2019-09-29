//
//  main.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include "Graph.h"
#include "MyGraph.hpp"
#include "Generator.hpp"
#include "Graph_Algorithms.hpp"

int main(int argc, const char * argv[]) {

    if (argc != 3) {
        std::cout << "Usage: ./main.exe RGG/BRG nr" << std::endl;
        return 1;
    }
    string Gr = argv[1];
    int n = stoi(argv[2]);
        
    MyGraph G;
    std::ofstream fout("data.txt");

    if (Gr == "RGG") {
        for (int i = 0; i < 1000; ++i) {
            G = Generator::random_geometric_graph(n, i/1000.0);
            fout << i/1000.0 << '\t' << Graph_Algorithms::getNrConectedComponents(G).first << endl;
        }
    }
    if (Gr == "BRG") {
        for (int i = 0; i < 1000; ++i) {
            G = Generator::binomial_random_graph(n, i/1000.0);
            fout << i/1000.0 << '\t' << Graph_Algorithms::getNrConectedComponents(G).first << endl;
        }
    }

    return 0;
}

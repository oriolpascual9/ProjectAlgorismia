//
//  main.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "MyGraph.hpp"
#include "Generator.hpp"
#include "Graph_Algorithms.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    if (argc < 3) {
        cout << "Usage: ./main.exe RGG/BRG nr" << std::endl;
        return 1;
    }
    string Gr = argv[1];
    int n = stoi(argv[2]);
    double f = 1.0;
    if (argc == 4) f = stof(argv[3]);
        
    MyGraph G;
    ofstream fout("data.txt");

    if (Gr == "RGG") {
        for (int i = 0; i < 1000; ++i) {
            G = Generator::random_geometric_graph(n, f*i/1000.0);
            fout << f*i/1000.0 << '\t' << Graph_Algorithms::getNrConectedComponents(G).first << endl;
        }
    }
    if (Gr == "BRG") {
        for (int i = 0; i < 1000; ++i) {
            G = Generator::binomial_random_graph(n, f*i/1000.0);
            fout << f*i/1000.0 << '\t' << Graph_Algorithms::getNrConectedComponents(G).first << endl;
        }
    }

    return 0;
}

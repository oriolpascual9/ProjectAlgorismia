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
        cout << "Usage: ./main.exe RGG/BRG/BA CC/CG/Conexo/Acyclic nr" << std::endl;
        return 1;
    }
    string Gr = argv[1];
    string prop = argv[2];
    int n = stoi(argv[3]);
    double f = 1.0;
    double time = 0;
    if (argc == 4) f = stof(argv[3]);
        
    MyGraph G;
    ofstream fout("data.txt");
    if (prop == "CC"){
        if (Gr == "RGG") {
            int sum = 0;
            int nmax, nmin = 0;
            for (int i = 0; i < 1000; ++i) {
                for (int j = 0; j < 100; ++j) {
                    G = Generator::random_geometric_graph(n, f*i/1000.0);
                    int n = Graph_Algorithms::getNrConectedComponents(G,time).first;
                    if (nmin > n) nmin = n;
                    if (nmax < n) nmax = n;
                    sum += n;
                }
                fout << f*i/1000.0 << '\t' << (int)(sum-nmax-nmin)/98 << endl;
            }
        }
        if (Gr == "BRG") {
            int sum = 0;
            int nmax, nmin = 0;
            for (int i = 0; i < 1000; ++i) {
                for (int j = 0; j < 100; ++j) {
                    G = Generator::binomial_random_graph(n, f*i/1000.0);
                    int n = Graph_Algorithms::getNrConectedComponents(G,time).first;
                    if (nmin > n) nmin = n;
                    if (nmax < n) nmax = n;
                    sum += n;
                }
                fout << f*i/1000.0 << '\t' << (int)(sum-nmax-nmin)/98 << endl;
            }
        }
    }
    else if (prop == "Conexo"){
        if (Gr == "RGG") {
            for (int i = 0; i < 1000; ++i) {
                int x = 0;
                int y = 0;
                for (int j = 0; j < 100; ++j){
                    G = Generator::random_geometric_graph(n, f*i/1000.0);
                    if (Graph_Algorithms::getNrConectedComponents(G,time).first == 1) ++x;
                    else ++y;
                }
                fout << f*i/1000.0 << '\t' << (double) x/(x+y) << endl;
            }
        }
        if (Gr == "BRG") {
            for (int i = 0; i < 1000; ++i) {
                int x = 0;
                int y = 0;
                for (int j = 0; j < 100; ++j){
                    G = Generator::binomial_random_graph(n, f*i/1000.0);
                    if (Graph_Algorithms::getNrConectedComponents(G,time).first == 1) ++x;
                    else ++y;
                }
                fout << f*i/1000.0 << '\t' << (double) x/(x+y) << endl;
            }
        }
    }
    else if (prop == "CG"){
        if (Gr == "RGG") {
            int sum = 0;
            int nmax, nmin = 0;
            for (int i = 0; i < 1000; ++i) {
                for (int j = 0; j < 100; ++j) {
                    G = Generator::random_geometric_graph(n, f*i/1000.0);
                    int n = Graph_Algorithms::getNrConectedComponents(G,time).second;
                    if (nmin > n) nmin = n;
                    if (nmax < n) nmax = n;
                    sum += n;
                }
                fout << f*i/1000.0 << '\t' << (int)(sum-nmax-nmin)/98 << endl;
            }
        }
        if (Gr == "BRG") {
            int sum = 0;
            int nmax, nmin = 0;
            for (int i = 0; i < 1000; ++i) {
                for (int j = 0; j < 100; ++j) {
                    G = Generator::binomial_random_graph(n, f*i/1000.0);
                    int n = Graph_Algorithms::getNrConectedComponents(G,time).second;
                    if (nmin > n) nmin = n;
                    if (nmax < n) nmax = n;
                    sum += n;
                }
                fout << f*i/1000.0 << '\t' << (int)(sum-nmax-nmin)/98 << endl;
            }
        }
    }
    return 0;
}

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

const int INF = 0x7FFFFFFF;

int main(int argc, const char * argv[]) {

    if (argc < 4) {
        cout << "\nUsage: ./main.exe Propriedad_a_estudiar Tipo_de_grafo Numero_de_vertices_del_grafo\n"
                "Propriedad:\n"
                "    CC       - Numero de Componentes Conexas\n"
                "    CG       - Dimension Componente Gigante\n"
                "    Conexo   - Conexidad del Grafo\n"
                "    Aciclico - Propredad de ser Aciclico\n"
                "Tipo de grafo:\n"
                "    RGG      - Random Geometric Graph\n"
                "    BRG      - Binomial Random Graph\n"
                "    BAG      - Barabási–Albert Grpah\n\n";
        return 1;
    }
    string propriedad = argv[1];
    string tipo_grafo = argv[2];
    int n = stoi(argv[3]);
    double f = 1.0;
    double time = 0;
    if (argc == 5) f = stof(argv[3]);
        
    MyGraph G;
    ofstream fout("data.txt");
    if (propriedad == "CC") {
        for (int i = 0; i < 1000; ++i) {
            int sum = 0;
            int nmax = -INF, nmin = 0;
            for (int j = 0; j < 100; ++j) {
                if (tipo_grafo == "RGG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else if (tipo_grafo == "BRG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else G = Generator::barabasi_graph(10, 9); // TODO: Change it
                
                int n = Graph_Algorithms::getNrConectedComponents(G,time).first;
                if (nmin > n) nmin = n;
                if (nmax < n) nmax = n;
                sum += n;
            }
            fout << f*i/1000.0 << '\t' << int((sum-nmax-nmin)/98.0) << endl;
        }
    }
    if (propriedad == "Conexo") {
        for (int i = 0; i < 1000; ++i) {
            int x = 0;
            int y = 0;
            for (int j = 0; j < 100; ++j){
                if (tipo_grafo == "RGG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else if (tipo_grafo == "BRG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else G = Generator::barabasi_graph(10, 9); // TODO: Change it
                
                if (Graph_Algorithms::isConnex(G)) ++x;
                else ++y;
            }
            fout << f*i/1000.0 << '\t' << (double)x/(x+y) << endl;
        }
    }
    if (propriedad == "CG") {
        for (int i = 0; i < 1000; ++i) {
            int sum = 0;
            int nmax = -INF, nmin = 0;
            for (int j = 0; j < 100; ++j) {
                if (tipo_grafo == "RGG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else if (tipo_grafo == "BRG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else G = Generator::barabasi_graph(n, n-1); // TODO: Change it
                
                int n = Graph_Algorithms::getNrConectedComponents(G,time).second;
                if (nmin > n) nmin = n;
                if (nmax < n) nmax = n;
                sum += n;
            }
            fout << f*i/1000.0 << '\t' << (int)(sum-nmax-nmin)/98 << endl;
        }
    }
    if (propriedad == "CH") {
        for (int i = 0; i < 1000; ++i) {
            int x = 0;
            int y = 0;
            for (int j = 0; j < 100; ++j){
                if (tipo_grafo == "RGG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else if (tipo_grafo == "BRG") G = Generator::random_geometric_graph(n, f*i/1000.0);
                else G = Generator::barabasi_graph(10, 9); // TODO: Change it
                
                if (Graph_Algorithms::isHamiltonian(G)) ++x;
                else ++y;
            }
            fout << f*i/1000.0 << '\t' << (double)x/(x+y) << endl;
        }
    }
    return 0;
}

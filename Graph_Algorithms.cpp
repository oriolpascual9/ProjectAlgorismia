//
//  Graph_Algorithms.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include "Graph_Algorithms.hpp"

Graph_Algorithms::Graph_Algorithms() : elapsed_secs(0){}

int Graph_Algorithms::dfs(const MyGraph& G, int v, VB& visited) {
    int nc = 1;
    visited[v] = true;
    for (auto i : G.adj[v]) {
        if (not visited[i]) nc += dfs(G, i, visited);
    }
    return nc;
}

std::pair<int,int> Graph_Algorithms::getNrConectedComponents(const MyGraph& G, double& timing) {
    unsigned t0 = clock();
    int nr = 0, nc = 0, nmax = 0;
    VB visited(G.nr_vertexs, false);
    for (int i = 0; i < G.nr_vertexs; ++i) {
        if (not visited[i]) {
            ++nr;
            nc = dfs(G, i, visited);
        }
        nmax = (nc>nmax)?nc:nmax;
    }
    unsigned t1 = clock();
    timing = double(t1 - t0) / CLOCKS_PER_SEC;
    return std::make_pair(nr,nmax) ;
}

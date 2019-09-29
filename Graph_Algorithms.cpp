//
//  Graph_Algorithms.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include "Graph_Algorithms.hpp"

int Graph_Algorithms::dfs(const MyGraph& G, int v, VB& visited) {
    int nc = 1;
    visited[v] = true;
    for (auto i : G.adj[v]) {
        if (not visited[i]) nc += dfs(G, i, visited);
    }
    return nc;
}

std::pair<int,int> Graph_Algorithms::getNrConectedComponents(const MyGraph& G) {
    int nr = 0, nc = 0, nmax = 0;
    VB visited(G.nr_vertexs, false);
    for (int i = 0; i < G.nr_vertexs; ++i) {
        if (not visited[i]) {
            ++nr;
            nc = dfs(G, i, visited);
        }
        nmax = (nc>nmax)?nc:nmax;
    }
    return std::make_pair(nr,nmax) ;
}

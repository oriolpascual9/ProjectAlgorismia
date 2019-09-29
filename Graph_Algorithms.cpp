//
//  Graph_Algorithms.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include "Graph_Algorithms.hpp"

void Graph_Algorithms::dfs(const MyGraph& G, int v, VB& visited) {
    visited[v] = true;
    for (auto i : G.adj[v]) {
        if (not visited[i]) dfs(G, i, visited);
    }
}

int Graph_Algorithms::getNrConectedComponents(const MyGraph& G) {
    int nr = 0;
    VB visited(G.nr_vertexs, false);
    for (int i = 0; i < G.nr_vertexs; ++i) {
        if (not visited[i]) {
            ++nr;
            dfs(G, i, visited);
        }
    }
    return nr;
}


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

bool Graph_Algorithms::isAcyclic(const MyGraph& G){
    MyGraph graph = G;
    int n = graph.getVertexs(); 
    double timing = 0.0;
    if (n == 0) return true;
    else if (noLeafs(graph)) return false;
    else{
        for (int i = 0; i < n; ++i){
            std::list<int> leaf = graph.getAdjacencies(i);
            if (leaf.size() == 1) {
                int adj = leaf.front();
                graph.removeAdj(i,adj);
                return isAcyclic(graph);
            }
        }
    }
}

bool Graph_Algorithms::noLeafs(const MyGraph& G){
    MyGraph graph = G; 
    for (int i = 0; i < graph.getVertexs(); ++i)
        if (graph.getAdjacencies(i).size() == 1) return false;
    return true;
}

//
//  Graph_Algorithms.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//
#include <algorithm>
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
    unsigned long t0 = clock();
    int nr = 0, nc = 0, nmax = 0;
    VB visited(G.adj.size(), false);
    for (int i = 0; i < G.adj.size(); ++i) {
        if (not visited[i]) {
            ++nr;
            nc = dfs(G, i, visited);
        }
        nmax = (nc>nmax)?nc:nmax;
    }
    unsigned long t1 = clock();
    timing = double(t1 - t0) / CLOCKS_PER_SEC;
    return std::make_pair(nr,nmax);
}

bool Graph_Algorithms::isConnex(const MyGraph& G) {
    VB visited(G.adj.size(), false);
    dfs(G, 0, visited);
    for (int i = 0; i < G.adj.size(); ++i)
        if (!visited[i]) return false;
    return true;
}

bool Graph_Algorithms::isAcyclic(const MyGraph& G){
    MyGraph graph = G;
    int n = graph.getVertexs();
    double timing = 0.0;
    if (noEdges(graph)) return true;
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
        return false; // Control may reach end of non-void function ??? Cal comprovar
    }
}

bool Graph_Algorithms::noEdges(const MyGraph& G){
    MyGraph graph = G; 
    for (int i = 0; i < graph.getVertexs(); ++i)
        if (graph.getAdjacencies(i).size() != 0) return false;
    return true;
}

bool Graph_Algorithms::noLeafs(const MyGraph& G){
    MyGraph graph = G; 
    for (int i = 0; i < graph.getVertexs(); ++i)
        if (graph.getAdjacencies(i).size() == 1) return false;
    return true;
}

bool Graph_Algorithms::isHamiltonian(const MyGraph &G) {
    int n = (int)G.adj.size();
    std::vector< std::vector<bool> > adj(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (auto j : G.adj[i])
            adj[i][j] = adj[j][i] = true;
    }
    std::vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i;
    do {
        bool valid = true;
        for(int i = 0; i < v.size()-1 && valid; i++)
            if(!adj[v[i]][v[i+1]]) valid = false;
        if(valid) return true;
    } while(next_permutation(v.begin(), v.end()));

    return false;
}

bool Graph_Algorithms::isHamiltonianFaster(const MyGraph &G) {
    int n = (int)G.adj.size();
    std::vector< std::vector<bool> > adj(n, std::vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (auto j : G.adj[i])
            adj[i][j] = adj[j][i] = true;
    }
    std::vector< std::vector<bool> > dp(n, std::vector<bool>((1<<n), false));
    for (int i = 0; i < n; ++i) dp[i][(1<<i)] = true;
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++)
            if(i & (1<<j)){
                for(int k = 0; k < n; k++)
                    if(i & (1<<k) && adj[k][j] && k!=j && dp[k][i^(1<<j)]) {
                        dp[j][i]=true;
                        break;
                    }
            }
    }
    for(int i = 0; i < n; i++)
        if(dp[i][(1<<n)-1]) return true;
    return false;
}

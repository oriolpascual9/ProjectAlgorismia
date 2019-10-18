//
//  MyGraph.cpp
//  algorismia
//
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include "MyGraph.hpp"

MyGraph::MyGraph() : nr_vertexs(0) {}

MyGraph::MyGraph(int n) {
    nr_vertexs = n;
    adj = std::vector< std::list<int> > (n, std::list<int>());
}

void MyGraph::list_edges() {
    for (int i = 0; i < this->adj.size(); ++i) {
        for (auto j : this->adj[i])
            if (i+1 > j+1) std::cout << i+1 << ',' << j+1 << ',';
    }
    std::cout << std::endl;
}

int MyGraph::getVertexs() {
	return nr_vertexs;
}

std::list<int> MyGraph::getAdjacencies(int vertex){
	return adj[vertex];
}

void MyGraph::removeAdj(int v1, int v2){
	adj[v1].remove(v2);
	adj[v2].remove(v1);
}
//
//  main.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "MyGraph.hpp"
#include "Generator.hpp"
#include "Graph_Algorithms.hpp"

int main() {
    
    MyGraph* G = Generator::random_geometric_graph(10, 0.2);
    
    for (int i = 0; i < G->nr_vertexs; ++i) {
        for (auto j : G->adj[i]) std::cout << i << ' ' << j << std::endl;
    }
    
    std::cout << "Nr CC : " << Graph_Algorithms::getNrConectedComponents(*G) << std::endl;
    
    return 0;
}

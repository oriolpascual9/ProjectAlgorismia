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

int main(int argc, const char * argv[]) {
    
    MyGraph G = Generator::random_geometric_graph(10, 0.2);
    
//    G.list_edges();
    
    std::cout << "Nr CC : " << Graph_Algorithms::getNrConectedComponents(G) << std::endl;
    
    
    MyGraph G1 = Generator::binomial_random_graph(10, 0.3);
    
//     G1.list_edges();
    
    std::cout << "Nr CC : " << Graph_Algorithms::getNrConectedComponents(G1) << std::endl;
    
    return 0;
}

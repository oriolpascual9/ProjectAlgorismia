//
//  Graph_Algorithms.hpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#ifndef Graph_Algorithms_hpp
#define Graph_Algorithms_hpp

#include <stdio.h>
#include "MyGraph.hpp"

typedef std::vector<bool> VB;

class Graph_Algorithms {
    
    static void dfs(const MyGraph& G, int v, VB& visited);
    
public:
    
    static int getNrConectedComponents(const MyGraph& G);
    
    
    
};

#endif /* Graph_Algorithms_hpp */

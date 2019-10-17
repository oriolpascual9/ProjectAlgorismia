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
#include <ctime>
#include "MyGraph.hpp"

typedef std::vector<bool> VB;

class Graph_Algorithms {

	double elapsed_secs;
    static int dfs(const MyGraph& G, int v, VB& visited);

public:
	Graph_Algorithms();
    static std::pair<int,int> getNrConectedComponents(const MyGraph& G, double& timing);

};

#endif /* Graph_Algorithms_hpp */

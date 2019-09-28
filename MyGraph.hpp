//
//  MyGraph.hpp
//  algorismia
//
//  Copyright © 2019 Grup 2. All rights reserved.
//

#ifndef MyGraph_hpp
#define MyGraph_hpp

#include <stdio.h>
#include <vector>
#include <list>

class MyGraph {
    
public:
    std::vector< std::list<int> > adj;
    
    int nr_vertexs;
    
    MyGraph();
    
    MyGraph(int n) {
        nr_vertexs = n;
        adj = std::vector< std::list<int> > (n, std::list<int>());
    }
};


#endif /* MyGraph_hpp */

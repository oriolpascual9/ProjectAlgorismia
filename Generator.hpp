//
//  Generator.hpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#ifndef Generator_hpp
#define Generator_hpp

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <random>
#include "MyGraph.hpp"

typedef std::pair<double, double> Point;

class Generator {
    
    static double euclidean_distance(Point x, Point y);
    
    static std::vector<Point> get_uni_dist_points(int n);
    
public:
    
    static MyGraph random_geometric_graph(int n, double r);
    
    static MyGraph binomial_random_graph(int n, double p);
    
};

#endif /* Generator_hpp */

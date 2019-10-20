//
//  Generator.cpp
//  RandomGeometricGraph
//
//  Created by Grup 2.
//  Copyright © 2019 Grup 2. All rights reserved.
//

#include "Generator.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>

double Generator::euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.first - b.first, 2.0) + (pow(a.second - b.second, 2.0)));
}

std::vector<Point> Generator::get_uni_dist_points(int n) {
    std::vector<Point> v(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        double x = dis(gen);
        double y = dis(gen);
        v[i] = std::make_pair(x, y);
    }
    return v;
}

MyGraph Generator::random_geometric_graph(int n, double r) {

    std::vector<Point> v = get_uni_dist_points(n);

    MyGraph G(n);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if (euclidean_distance(v[i], v[j]) < r) {
                G.adj[i].push_back(j);
                G.adj[j].push_back(i);
            }
        }
    }
    return G;
}

MyGraph Generator::binomial_random_graph(int n, double p) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    MyGraph G(n);
    for (int i = 0; i < G.adj.size(); ++i) {
        for (int j = i+1; j < G.adj.size(); ++j) {
            if (dis(gen) < p) {
                G.adj[i].push_back(j);
                G.adj[j].push_back(i);
            }
        }
    }
    return G;
}

MyGraph Generator::barabasi_graph(int n, int m) {
    pid_t pid = fork();

    if (pid == -1) std::cout << "Error Fork\n";
    if (pid == 0) {
//        std::cout << "Hijo \n";
        execlp("python3", "python3", "barabasi.py", std::to_string(n).c_str(), std::to_string(m).c_str(), NULL);
    }
    else {
//        std::cout << "padre\n";
        waitpid(-1,NULL,0);
        std::ifstream fin("graph.txt");
        int n;
        fin >> n;
        MyGraph G(n);
        int x, y;
        while (fin >> x >> y) {
            G.adj[x].push_back(y);
            G.adj[y].push_back(x);
        }
        return G;
    }
	return MyGraph();
}

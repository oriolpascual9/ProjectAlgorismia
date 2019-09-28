/**
 * @file    Graph.cpp
 * @brief   Implementació de la classe Graph.
 */

#include "Graph.h"

Graph::Graph(int maxId) {
    this->maxId = maxId;
    maxIdActiu = -1;
    minIdActiu = -1;
    nV = 0;
    nA = 0;
    nodeLG n;
    n.x = 0;
    n.y = 0;
    n.actiu = false;
    n.adjacencies = set<int>();
    nodes = vector<nodeLG>(maxId + 1, n);
}

Graph Graph::generateActivatedGraph(int nV) {
    Graph lG(nV - 1);
    lG.maxIdActiu = nV - 1;
    lG.minIdActiu = 0;
    lG.nV = nV;
    nodeLG n;
    n.actiu = true;
    n.adjacencies = set<int>();
    lG.nodes = vector<nodeLG>(nV, n);
    return lG;
}
/*
Graph Graph::generateERGraph(int nV, int M) {
    Graph lG = generateActivatedGraph(nV);
    for (int i = 0; i < M; ++i) {
        int id1 = rand() % nV;
        int id2 = rand() % nV;
        if (id1 != id2 and not lG.adjacent(id1, id2))
            lG.addAresta(id1, id2);
        else
            --i;
    }
    return lG;
}

Graph Graph::generateRGGraph(int nV, float R){
	Graph lG = generateActivatedGraph(nV);
	for (int i = 0; i < nV; i++){
		float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
		float y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
		lG.setCoord(i,x,y);
	}	
	for (int i = 0; i < nV; i++){
		for (int j = 0; j < nV; j++){
			if (j!=i){
				if (lG.distance(i,j) < R and not lG.adjacent(i,j))
					lG.addAresta(i, j);
			}
		}
	}
}

float Graph::distance(int id1, int id2){
    pair<float,float> coords1 = getCoords(id1);
    pair<float,float> coords2 = getCoords(id2);
    if (coords1.first == -1 and coords1.second == -1 or coords2.first == -1 and coords2.second == -1) return 100;
    else {
        float x = coords1.first - coords2.first; //calculating number to square in next step
        float y = coords1.second - coords2.second;
        float dist;

        dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
        dist = sqrt(dist);                  

        return dist;
    }
}
*/

void Graph::setCoord(int id, float x, float y){
	nodes[id].x = x;
	nodes[id].y = y;
}

void Graph::addVertex(int id) {
    if (id > maxId)
        cout << "La id " << id << " és més alta que maxId." << endl;
    else if (isActive(id))
        cout << "Ya existeix un vertex amb la id " << id << '.' << endl;
    else {
        if (maxIdActiu == -1) {
            maxIdActiu = id;
            minIdActiu = id;
        }
        else {
            if (id > maxIdActiu)
                maxIdActiu = id;
            else if (id < minIdActiu)
                minIdActiu = id;
        }
        ++nV;
        nodes[id].actiu = true;
    }
}

void Graph::removeVertex(int id) {
    if (not isActive(id))
        cout << "No existeix un vertex amb la id " << id << '.' << endl;
    else {
        if (maxIdActiu == id and minIdActiu == id) {
            maxIdActiu = -1;
            minIdActiu = -1;
        }
        else if (maxIdActiu == id) {
            bool found = false;
            for (int i = maxIdActiu - 1; i >= minIdActiu and not found; --i)
                if (nodes[i].actiu) {
                    maxIdActiu = i;
                    found = true;
                }
        }
        else if (minIdActiu == id) {
            bool found = false;
            for (int i = minIdActiu + 1; i <= maxIdActiu and not found; ++i)
                if (nodes[i].actiu) {
                    minIdActiu = i;
                    found = true;
                }
        }
        for (set<int>::iterator it = nodes[id].adjacencies.begin(); it != nodes[id].adjacencies.end(); ++it)
        {
            nodes[*it].adjacencies.erase(id);
        }
        --nV;
        nA -= nodes[id].adjacencies.size();
        nodes[id].adjacencies.clear();
        nodes[id].actiu = false;
    }
}



void Graph::addAresta(int id1, int id2) {
    if (not isActive(id1))
        cout << "No existeix un vertex amb la id " << id1 << '.' << endl;
    else if (not isActive(id2))
        cout << "No existeix un vertex amb la id " << id2 << '.' << endl;
    else if (adjacent(id1, id2))
        cout << "Els vertexs " << id1 << " i " << id2 << " ja són adjacents." << endl;
    else if (id1 == id2)
        cout << "S'ha donat dos cops la mateixa id." << endl;
    else {
        ++nA;
        nodes[id1].adjacencies.insert(id2);
        nodes[id2].adjacencies.insert(id1);
    }
}

void Graph::removeAresta(int id1, int id2) {
    if (not isActive(id1))
        cout << "No existeix un vertex amb la id " << id1 << '.' << endl;
    else if (not isActive(id2))
        cout << "No existeix un vertex amb la id " << id2 << '.' << endl;
    else if (not adjacent(id1, id2))
        cout << "Els vertexs " << id1 << " i " << id2 << "no són adjacents." << endl;
    else {
        --nA;
        nodes[id1].adjacencies.erase(id2);
        nodes[id2].adjacencies.erase(id1);
    }
}

void Graph::activate(int id) {
    if (id > maxId) {
        cout << "La id " << id << " és més alta que maxId." << endl;
    }
    else nodes[id].actiu = true;
}


void Graph::desactivate(int id) {
    if (id > maxId) {
        cout << "La id " << id << " és més alta que maxId." << endl;
    }
    else nodes[id].actiu = false;
}

int Graph::getIdDisponible() {
    for (int i = 0; i <= maxId; ++i)
        if (not isActive(i))
            return i;
    ++maxId;
    nodeLG n;
    n.actiu = false;
    n.adjacencies = set<int>();
    nodes.push_back(n);
    return maxId;
}

int Graph::getNVertexs() { return nV; }


set<int> Graph::getVertexs() {
    set<int> vs = set<int>();
    for (int i = minIdActiu; i <= maxIdActiu; ++i)
        if (isActive(i))
            vs.insert(i);
    return vs;
}

int Graph::getNArestes() { return nA; }


set<pair<int, int> > Graph::getArestes() {
    set<pair<int, int> > arestes = set<pair<int, int> >();
    set<int> vs = getVertexs();
    vector<bool> visited(maxId + 1, false);
    for (set<int>::iterator it1 = vs.begin(); it1 != vs.end(); ++it1) {
        visited[*it1] = true;
        set<int> adjs = getAdjacencies(*it1);
        for (set<int>::iterator it2 = adjs.begin(); it2 != adjs.end(); ++it2)
            if (not visited[*it2]) {
                pair<int, int> aresta;
                aresta.first = *it1;
                aresta.second = *it2;
                arestes.insert(aresta);
            }
    }
    return arestes;
}

int Graph::getMaxId() { return maxId; }


bool Graph::isActive(int id) {
    if (id > maxId) {
        cout << "La id " << id << " és més alta que maxId." << endl;
        return false;
    }
    return nodes[id].actiu;
}

set<int> Graph::getAdjacencies(int id) {
    if (not isActive(id)) {
        cout << "No existeix un vertex amb la id " << id << '.' << endl;
        return set<int>();
    }
    return nodes[id].adjacencies;
}

bool Graph::adjacent(int id1, int id2) {
    if (not isActive(id1)) {
        cout << "No existeix un vertex amb la id " << id1 << '.' << endl;
        return false;
    }
    else if (not isActive(id2)) {
        cout << "No existeix un vertex amb la id " << id2 << '.' << endl;
        return false;
    }
    if (nodes[id1].adjacencies.size() < nodes[id2].adjacencies.size())
        return nodes[id1].adjacencies.find(id2) != nodes[id1].adjacencies.end();
    else
        return nodes[id2].adjacencies.find(id1) != nodes[id2].adjacencies.end();
}

pair<float,float> Graph::getCoords(int id){
    pair<float,float> coords = pair<float,float>(-1.0,-1.0);
    if (isActive(id)){
        coords.first = nodes[id].x;
        coords.second = nodes[id].y;
    }
    return coords;
}

/**
 * @file    Graph.h
 * @brief   Especificació de la classe Graph.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

/**Conté la informació d'un possible node del graph.*/
struct nodeLG {
    /**Indica si el ListGraph té el node amb la id igual a la posició del vector nodes on es troba el node.*/
    bool actiu;
    /**ids dels nodes adjacents al node.*/
    set<int> adjacencies;
};

class Graph {

private:
    int maxId;
    /**id més alta assignable als nodes del Graph.*/
    int maxIdActiu;
    /**id més baixa entre les dels nodes del Graph.*/
    int minIdActiu;
    /**Número de vèrtexs que té el Graph.*/
    int nV;
    /**Número d'arestes que té el Graph.*/
    int nA;
    /**vector que conté els nodes del Graph.*/
    vector<nodeLG> nodes;

    /**
     * Genera un Graph amb n vertexs (tots activats) i cap aresta.
     * @param n Nombre de vèrtexs del Graph.
     * @return  Graph amb n vertexs (tots activats) i cap aresta.
     */
    static Graph generateActivatedGraph(int nV);

public:

    /**Constructores*/

    /**
     * Crea un Graph buit.
     * @param maxId Máxima id assignable a un vèrtex del ListGraph.
     */
    Graph(int maxId);

    /**
     * Crea un Graph aleatori donat un nombre de vèrtexs seguint el model Erdős-Rényi.
     * @param nV    Nombre de vèrtexs que tindrà el Graph.
     * @param M     Nombre d'arestes del Graph resultant.
     * @return      Graph aleatori amb nV vèrtexs generat segons el model Erdős-Rényi.
     */
    static Graph generateERGraph(int nV, int M);

	/**
	 * Crea un Graph aleatori donat un nombre de vèrtexs seguint el model Random Geometric
	 * R pertany (0,(nV*nV/2)
	 * @param nV	Nombre de vèrtexs que tindrà el Graph
	 * @param R		Distància màxima perquè hi hagi aresta entre dos vèrtexs
	 * @return 		Graph aleatori amb nV vèrtexs generat segons Random Geomtric Graph
	 */
    static Graph generateRGGraph(int nV, int R);
    /**MODIFICADORES*/

    /**
     * Afegeix un vèrtex amb la id donada al graph si no existeix cap que ya la tingui.
     * @param id    id que es vol assignar al vèrtex.
     */
    void addVertex(int id);

    /**
     * Elimina un vèrtex amb la id donada al graph si existeix.
     * @param id    id qdel vèrtex que es vol eliminar.
     */
    void removeVertex(int id);

    /**
     * Afegeix una aresta entre els vèrtexs amb les ids donades si aquests existeixen i no existeix ya una entre ells.
     * @param id1   id d'un dels nodes de l'aresta.
     * @param id2   id d'un dels nodes de l'aresta.
     */
    void addAresta(int id1, int id2);

    /**
     * Elimina una aresta entre els vèrtexs amb les ids donades si aquests existeixen i existex una aresta entre ells.
     * @param id1   id d'un dels nodes de l'aresta.
     * @param id2   id d'un dels nodes de l'aresta.
     */
    void removeAresta(int id1, int id2);

    /**
     * Activa el vertex amb la id indicada
     * @param id    id del vertex a activar
     */
    void activate(int id);

    /**
     * Desactiva el vertex amb la id indicada
     * @param id    id del vertex a desactivar
     */
    void desactivate(int id);

    /**CONSULTORES*/

    /**
     * Retorna una id disponible per assignar a un vèrtex.
     * @return  id disponible per assignar a un vèrtex.
    */
    int getIdDisponible();


    /**
     * Indica quants vèrtexs té el ListGraph.
     * @return  Número de vèrtexs que té el ListGraph.
     */
    int getNVertexs();

    /**
     * Retorna totes les ids dels vertexs del ListGraph.
     * @return  ids dels vertexs del ListGraph.
     */
    set<int> getVertexs();

    /**
     * Indica quantes arestes té el ListGraph.
     * @return  Número d'arestes que té el ListGraph.
     */
    int getNArestes();

    /**
     * Retorna totes les arestes del ListGraph.
     * @return  arestes del ListGraph.
     */
    set<pair<int, int> > getArestes();

    /**
     * Retorna la máxima id assignable a un vèrtex del ListGraph.
     * @return  Máxima id assignable a un vèrtex del ListGraph.
     */
    int getMaxId();

    /**
     * Indica si el ListGraph té un vèrtex amb la id indicada
     * @param id    id del vèrtex que es vol comprovar.
     * @return      true si el ListGraph té el vèrtex, false altrament.
     */
    bool isActive(int id);

    /**
     * Retorna la llista d'adjacencies d'un vèrtex amb la id indicada si aquest existeix.
     * @param id    id del vèrtex del que es vol obtenir la llista d'adjacencies.
     * @return      llista d'adjacencies del vètex amb la id donada.
     */
    set<int> getAdjacencies(int id);

    /**
     * Indica si 2 vèrtexs existents són adjacents.
     * @param id1   id del 1r vèrtex.
     * @param id2   id del 2n vèrtex.
     * @return      true si els vètexs són adjacents, false altrament.
     */
    bool adjacent(int id1, int id2);
};

#endif

#include "Graph.h"
//clase grafo 

Graph::Graph(unsigned int n) {
    // Constructor del grafo con n nodos y una matriz de nxn en false para indicar que no se vio ningun item todavia
    _n = n;
    _matrix = vector<vector<bool>>(n, vector<bool>(n, false));
}
int Graph::getN(){
    // Devuelve la cantidad de nodos del grafo
    return _n;
}

void Graph::addEdge(unsigned int node1, unsigned int node2){
    // Agrega una arista entre node1 y node2
    if (node1==node2){
        // No se permite agregar una arista de un nodo a sí mismo
        throw std::invalid_argument( "can't draw edge between the same node" );
    }
    // Como es un grafo no dirigido, marcamos ambas direcciones como true
    _matrix[node1][node2] = true;
    _matrix[node2][node1] = true;

}

void Graph::removeEdge(unsigned int node1, unsigned int node2){
    // Elimina la arista entre node1 y node2 
    _matrix[node1][node2] = false;
    _matrix[node2][node1] = false;

}

bool Graph::isAdjacent(unsigned int node1, unsigned int node2){
    // Verifica si existe una arista entre node1 y node2 
    return _matrix[node1][node2];
}

void Graph::printGraph(){
    // Imprime la matriz del grafo
    std::cout<<"Number of vertices:\n";
    std::cout<<_n<<"\n";
    for (int i=0; i<_n; i++){
        for (int j=0; j<_n; j++){
            std::cout<<_matrix[i][j];
        }
        std::cout<<"\n";
    }
}


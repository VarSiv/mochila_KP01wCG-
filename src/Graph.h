#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <tuple>
#include <iostream>
using std::tuple;
using std::vector;

class Graph{
//clase grafo
private:
    int _n; // Número de nodos en el grafo

    // Matriz de adyacencia, _matrix[i][j] es true si hay una arista entre i y j, false en caso contrario.
    // Se utiliza bool para ahorrar memoria.
    vector<vector<bool>> _matrix; 

public:
    // Constructor que inicializa el grafo con n nodos sin aristas
    Graph(unsigned int n);
    //unsigned para evitar numeros negativos
    // Devuelve la cantidad de nodos del grafo
    int getN();

    // Agrega una arista entre los nodos node1 y node2
    void addEdge (unsigned int node1, unsigned int node2);
    // Elimina una arista entre los nodos node1 y node2
    void removeEdge(unsigned int node1, unsigned int node2);
    // Devuelve si hay una arista entre node1 y node2,
    bool isAdjacent(unsigned int node1, unsigned int node2);
    // Imprime la cantidad de vértices y la matriz de adyacencia 
    void printGraph();
};


#endif
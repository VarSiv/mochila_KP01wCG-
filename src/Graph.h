#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <tuple>
#include <iostream>
using std::tuple;
using std::vector;

class Graph{

private:
    int _n;
    //bool to save memory
    vector<vector<bool>> _matrix; //nxn matrix with true if there is an edge between (i,j) and false otherwise

public:
    Graph(unsigned int n);
    //unsigned para evitar numeros negativos
    int getN();
    void addEdge (unsigned int node1, unsigned int node2);
    void removeEdge(unsigned int node1, unsigned int node2);
    bool isAdjacent(unsigned int node1, unsigned int node2);
    void printGraph();
};


#endif
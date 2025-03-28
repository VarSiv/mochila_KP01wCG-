#include "Graph.h"


Graph::Graph(unsigned int n) {

    _n = n;
    _matrix = vector<vector<bool>>(n, vector<bool>(n, false));
}
int Graph::getN(){
    return _n;
}

void Graph::addEdge(unsigned int node1, unsigned int node2){
    if (node1==node2){
        throw std::invalid_argument( "can't draw edge between the same node" );
    }

    _matrix[node1][node2] = true;
    _matrix[node2][node1] = true;

}

void Graph::removeEdge(unsigned int node1, unsigned int node2){

    _matrix[node1][node2] = false;
    _matrix[node2][node1] = false;

}

bool Graph::isAdjacent(unsigned int node1, unsigned int node2){
    return _matrix[node1][node2];
}

void Graph::printGraph(){
    std::cout<<"Number of vertices:\n";
    std::cout<<_n<<"\n";
    for (int i=0; i<_n; i++){
        for (int j=0; j<_n; j++){
            std::cout<<_matrix[i][j];
        }
        std::cout<<"\n";
    }
}

int main(){
    Graph g(3);
    g.addEdge(1, 2);
    g.printGraph();

}
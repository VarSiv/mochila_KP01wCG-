#include "KP01withCGInstance.h"

KP01withCGInstance::KP01withCGInstance(unsigned int n, int cap): _num_items(n), _maxCapacity(n), _conflicts(Graph(n)) {
    _weights=vector<int>(n);
    _profits=vector<int>(n);
}
void KP01withCGInstance::setInstance(string filename) {
    _filename = filename;
    ifstream instanceFile;
    instanceFile.open(filename);

    string fileLine;
    if (instanceFile.is_open()){
        std::getline(instanceFile, fileLine);//toma la primera linea, número total de ítems
        _num_items=stoi(fileLine);
        _conflicts=Graph(_num_items);
        std::getline(instanceFile, fileLine);//toma la segunda linea, capacidad de la mochila
        _maxCapacity=stoi(fileLine);
        std::getline(instanceFile, fileLine);//toma la tercera linea 
        _weights= separar_palabras(fileLine);
        std::getline(instanceFile, fileLine);//toma la cuarta linea 
        _profits= separar_palabras(fileLine);
        std::getline(instanceFile, fileLine);//toma la quinta linea 
        int CantConflictos= stoi(fileLine);
        for(int i=0; i<CantConflictos; i++){
            std::getline(instanceFile, fileLine);//toma la sexta linea y las que quedan 
            vector<int> conflcitos= separar_palabras(fileLine);
            _conflicts.addEdge(conflcitos[0], conflcitos[1]);
        }
    }
    instanceFile.close();
}

void KP01withCGInstance::setWeight(int index, int weight) {
    _weights[index]=weight;
}

void KP01withCGInstance::setProfit(int index, int profit) {
    _profits[index]=profit;
}

int KP01withCGInstance::getWeight(int index) const {
    return _weights[index];
}

int KP01withCGInstance::getProfit(int index) const {
    return _profits[index];
}

int KP01withCGInstance::getNumItems() const {
    return _num_items;
}

int KP01withCGInstance::getCapacity() const {
    return _maxCapacity;
}

void KP01withCGInstance::addConflict(int item1, int item2) {
    _conflicts.addEdge(item1, item2);
    
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    _conflicts.removeEdge(item1, item2);
}
int main() {
    KP01withCGInstance instance(0,0);
    instance.setInstance("instances/test_instance.in");
    return 0;
}

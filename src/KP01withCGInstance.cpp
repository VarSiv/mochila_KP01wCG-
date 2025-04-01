#include "KP01withCGInstance.h"

KP01withCGInstance::KP01withCGInstance(): _num_items(0), _maxCapacity(0), _conflicts(Graph(0)){
    _weights=vector<int>(0);
    _profits=vector<int>(0);
}
KP01withCGInstance::KP01withCGInstance(int n, int cap): _num_items(n), _maxCapacity(cap), _conflicts(Graph(n)){
    _weights=vector<int>(n);
    _profits=vector<int>(n);
}
void KP01withCGInstance::setInstance(string filename){
    _conflicts=Graph(0);
    _filename = filename;
    _weights = {};
    _profits = {};

    ifstream instanceFile;
    
    instanceFile.open(filename);

    string fileLine;
    if (instanceFile.is_open()){
        
        std::getline(instanceFile, fileLine);//gets number of items
        _num_items = std::stoi(fileLine);
        _conflicts = Graph(_num_items);

        std::getline(instanceFile, fileLine);//gets max capacity
        _maxCapacity = std::stoi(fileLine);


        string itemWeight;
        std::getline(instanceFile, fileLine); //gets item weight and fills out weight vector
        std::stringstream weightsStream(fileLine);

        while (getline(weightsStream, itemWeight, ' ')){  
            int intWeight = std::stoi(itemWeight);
            _weights.push_back(intWeight);

        }

        string itemProfit;
        std::getline(instanceFile, fileLine); //gets item profit and fills out profit vector
        std::stringstream profitsStream(fileLine);

        while (getline(profitsStream, itemProfit, ' ')){  
            int intProfit = std::stoi(itemProfit);
            _profits.push_back(intProfit);

        }

        std::getline(instanceFile, fileLine); //gets number of conflicts
        int conflictNumber = std::stoi(fileLine);
        
        for (int i=0; i<conflictNumber; i++){ //iterates through every line
            std::getline(instanceFile, fileLine);
            std::stringstream edgeStream(fileLine);

            string vertexNumber;
            getline(edgeStream, vertexNumber, ' ');//divides string by spaces and makes edges
            int v1 = std::stoi(vertexNumber);
            getline(edgeStream, vertexNumber, ' ');
            int v2 = std::stoi(vertexNumber);
            _conflicts.addEdge(v1, v2);


        }

        
    }
}

void KP01withCGInstance::setWeight(int index, int weight){
    _weights[index]=weight;
}

void KP01withCGInstance::setProfit(int index, int profit){
    _profits[index]=profit;
}


int KP01withCGInstance::getWeight(int index) const
{
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

bool KP01withCGInstance::isConflicting(int item1, int item2){
    return _conflicts.isAdjacent(item1, item2);
}

#include "KP01withCGInstance.h"

KP01withCGInstance::KP01withCGInstance(string filename) {
    _filename = filename;
    ifstream instanceFile;
    instanceFile.open(filename);

    string fileLine;
    if (instanceFile.is_open()){
        std::getline(instanceFile, fileLine);
        
    }
    
}

void KP01withCGInstance::setWeight(int index, int weight) {
}

void KP01withCGInstance::setProfit(int index, int profit) {
}

int KP01withCGInstance::getWeight(int index) const {
}

int KP01withCGInstance::getProfit(int index) const {
}

int KP01withCGInstance::getNumItems() const {
    return _num_items;
}

int KP01withCGInstance::getCapacity() const {
}

void KP01withCGInstance::addConflict(int item1, int item2) {
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
}

int main() {
    KP01withCGInstance instance("instances/test_instance.in");
}
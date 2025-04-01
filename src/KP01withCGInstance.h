// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H
#include <string>
#include <vector>
#include "Graph.h"
#include <iostream>
#include <fstream> 
#include <sstream>
using std::ifstream;
using std::string;
using std::vector;


class KP01withCGInstance {
private:
    int _num_items;
    string _filename;
    int _maxCapacity;
    vector<int> _weights;
    vector<int> _profits;
    Graph _conflicts;

    

public:
    KP01withCGInstance();
    KP01withCGInstance(int n, int cap);
    void setInstance(string filename);
    void setWeight(int index, int weight);
    void setProfit(int index, int profit);
    int getWeight(int index) const;
    int getProfit(int index) const;
    int getNumItems() const;
    int getCapacity() const;
    void addConflict(int item1, int item2);
    void removeConflict(int item1, int item2);
    bool isConflicting(int item1, int item2);
   
    

};

#endif // KP01WITHCGINSTANCE_H
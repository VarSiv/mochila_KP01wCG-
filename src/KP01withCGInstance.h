// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H
#include <string>
#include <vector>
#include "Graph.h"
#include <iostream>
#include <fstream> 
using std::ifstream;

using namespace std;

class KP01withCGInstance {
private:
    int _num_items;
    string _filename;
    int _maxCapacity;
    vector<int> _weights;
    vector<int> _profits;
    Graph _conflicts(int);
//Funcion auxiliar 
    vector<int> separar_palabras( const string & texto){
        string palabra = "";												
        vector<int> v;													
        for (int i=0; i<texto.size(); i++){									
            if(texto[i]!=' '){												
                palabra.push_back(texto[i]);								
            }
            else{
                v.push_back(stoi(palabra));										
                palabra="";												
            }
        }
        v.push_back(stoi(palabra));											
        return v;										
    }

    

public:
    KP01withCGInstance(unsigned int n, int cap);
    void setInstance(string filename);
    void setWeight(int index, int weight);
    void setProfit(int index, int profit);
    int getWeight(int index) const;
    int getProfit(int index) const;
    int getNumItems() const;
    int getCapacity() const;
    void addConflict(int item1, int item2);
    void removeConflict(int item1, int item2);
    

};

#endif //KP01WITHCGINSTANCE_H

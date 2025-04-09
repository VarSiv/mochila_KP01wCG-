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
    int _num_items;               // Cantidad de ítems en la instancia
    string _filename;            // Nombre del archivo desde donde se carga la instancia
    int _maxCapacity;
    vector<int> _weights;
    vector<int> _profits;
    Graph _conflicts;

    

public:
    // Constructor por defecto
    KP01withCGInstance();

    // Constructor que inicializa con cantidad de ítems y capacidad
    KP01withCGInstance(int n, int cap);

    // Carga una instancia desde un archivo
    void setInstance(string filename);

    // Pone el peso del ítem en la posición pasada por parametro
    void setWeight(int index, int weight);

    // Pone la ganancia del ítem en la posición pasada por parametro
    void setProfit(int index, int profit);

    // Devuelve el peso del ítem en la posición pasada por parametro
    int getWeight(int index) const;

    // Devuelve el beneficio del ítem en la posición pasada por parametro
    int getProfit(int index) const;

    // Devuelve la cantidad total de ítems
    int getNumItems() const;

    // Devuelve la capacidad máxima de la mochila
    int getCapacity() const;

    // Agrega un conflicto (arista) entre dos ítems
    void addConflict(int item1, int item2);

    // Elimina un conflicto (arista) entre dos ítems
    void removeConflict(int item1, int item2);

    // Devuelve si hay conflicto entre los ítems dados 
    bool isConflicting(int item1, int item2);    

};

#endif // KP01WITHCGINSTANCE_H
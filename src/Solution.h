#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
#include "KP01withCGInstance.h"

using namespace std;

class Solution {
private:
int _num_items;                    // Cantidad total de ítems posibles en la instancia
vector<bool> _items_vector;       // Vector que indica que ítems fueron seleccionados
KP01withCGInstance _mochila;      // Instancia del problema asociada a esta solución 


public:
    // Constructor que inicializa la solución con la cantidad total de ítems
    Solution(int numItems);

    // Asocia una instancia de mochila a esta solución
    void setMochila(KP01withCGInstance mochila);

    // Devuelve la cantidad de ítems en la solución
    int numItems();

    // Agrega un ítem a la solución 
    void addItem(int item);

    // Elimina un ítem de la solución
    void removeItem(int item);

    // Verifica si un ítem está en la solución
    bool contains(int item) const;

    // Devuelve el beneficio total de los ítems seleccionados
    int totalProfit();

    // Devuelve el peso total de los ítems seleccionados
    int totalWeight();

    // Devuelve el vector de ítems seleccionados
    vector<bool> getItemsVector();

    // Verifica si la solución no tiene conflictos entre sus items seleccionados
    bool isValidItems();

    // Imprime la solución
    void printSolution() const;

};
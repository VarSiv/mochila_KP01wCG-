#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
#include "KP01withCGInstance.h"

using namespace std;

class Solution {
private:
    int _num_items;//toda la mochila (intance) [1,2,3,4,5..]
    vector<bool> _items_vector;
    KP01withCGInstance _mochila;


public:
    Solution(int numItems); // Constructor to initialize size
    void addItem(int item);
    void removeItem(int item);
    bool contains(int item) const;
    int totalProfit();
    int totalWeight();
    vector<bool> getItemsVector();
    void printSolution() const;
    // Pueden agregar los metodos que consideren necesarios.
};

#endif // SOLUTION_Hl


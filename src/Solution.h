#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
#include "KP01withCGInstance.h"

using namespace std;

class Solution {
private:
    int _num_items;//toda la mochila (intance) [1,2,3,4,5..]
    vector<int> _items_vector;//solution subconjunto de instance [1,3,4]
    KP01withCGInstance _mochila;

    vector<int> generarVectorCreciente(int i) {
        vector<int> vec;
        for (int j = 1; j <= i; j++) {
            vec.push_back(j);
        }
        return vec;
    }
    


public:
    Solution(int numItems); // Constructor to initialize size
    void addItem(int item);
    void removeItem(int item);
    bool contains(int item) const;
    int totalProfit();
    int totalWeight();
    vector<int> getItemsVector();
    void printSolution() const;
    // Pueden agregar los metodos que consideren necesarios.
};

#endif // SOLUTION_Hl


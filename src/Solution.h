#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>

class Solution {
private:
    // Definir estructura interna.

public:
    Solution(int numItems); // Constructor to initialize size
    void addItem(int item);
    void removeItem(int item);
    bool contains(int item) const;
    void printSolution() const;
    // Pueden agregar los metodos que consideren necesarios.
};

#endif // SOLUTION_H


// DynamicProgrammingKP01.h
#ifndef DYNAMICPROGRAMMINGKP01_H
#define DYNAMICPROGRAMMINGKP01_H
#include <limits>
#include "Solution.h"
#include "KP01withCGInstance.h"

class DynamicProgrammingKP01 {
private:
   // Funcion auxiliar que reconstruye la solución a partir de la tabla de memorizacion
    void obtainSolution(const KP01withCGInstance& mochila, Solution& S, vector<vector<int>>& memo);
public:
    // Constructor 
    DynamicProgrammingKP01();

    // Funcion que resuelve una instancia del problema usando programación dinámica
    Solution solve(const KP01withCGInstance& instance);

    // Función recursiva auxiliar que usa programacion dinamica 
    int solveAux(const KP01withCGInstance& mochila, vector<vector<int>>& m, int k, int capacity);
};

#endif // DYNAMICPROGRAMMINGKP01_H
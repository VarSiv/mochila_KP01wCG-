// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BacktrackingKP01wCG {
private:
    // Función recursiva auxiliar que explora todas las combinaciones posibles de ítems válidos usando backtracking (con podas).
    void solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S);

    // Calcula el máximo beneficio posible a partir de una solución parcial S y a partir del ítem k
    int maxProfit(Solution S, int k);

public:
    // Constructor por defecto
    BacktrackingKP01wCG();
     // Resuelve la instancia utilizando backtracking y devuelve la mejor solución encontrada
    Solution solve(const KP01withCGInstance& instance);
};

#endif // BACKTRACKINGKP01_H
// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BruteForceKP01wCG {
private:

    // Función recursiva auxiliar que explora todas las combinaciones posibles de ítems usando Fuerza Bruta (sin podas)
    void solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S);

public:
    // Constructor por defecto
    BruteForceKP01wCG();
     // Resuelve la instancia utilizando  fuerza bruta y devuelve la mejor solución encontrada después de evaluar todas las combinaciones posibles
    Solution solve(const KP01withCGInstance& instance);
};

#endif // BRUTEFORCEKP01WCG_H
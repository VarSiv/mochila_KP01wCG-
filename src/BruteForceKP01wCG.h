// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BruteForceKP01wCG {
private:

    void solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S);

public:
    BruteForceKP01wCG();
    Solution solve(const KP01withCGInstance& instance);
};

#endif // BRUTEFORCEKP01WCG_H
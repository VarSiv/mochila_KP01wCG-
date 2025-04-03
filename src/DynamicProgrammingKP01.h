// DynamicProgrammingKP01.h
#ifndef DYNAMICPROGRAMMINGKP01_H
#define DYNAMICPROGRAMMINGKP01_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class DynamicProgrammingKP01 {
private:
    void solveAux(const KP01withCGInstance& mochila, Solution& S, vector<vector<pair<int,Solution >>>& m);
public:
    DynamicProgrammingKP01();
    Solution solve(const KP01withCGInstance& instance);
};

#endif // DYNAMICPROGRAMMINGKP01_H
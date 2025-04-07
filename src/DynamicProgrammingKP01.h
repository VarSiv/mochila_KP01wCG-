// DynamicProgrammingKP01.h
#ifndef DYNAMICPROGRAMMINGKP01_H
#define DYNAMICPROGRAMMINGKP01_H
#include <limits>
#include "Solution.h"
#include "KP01withCGInstance.h"

class DynamicProgrammingKP01 {
private:
   
    void obtainSolution(KP01withCGInstance mochila, Solution& S, vector<vector<int>> m);
public:
    DynamicProgrammingKP01();
    Solution solve(const KP01withCGInstance& instance);
    int solveAux( KP01withCGInstance mochila, vector<vector<int>>& m, int k, int capacity);
};

#endif // DYNAMICPROGRAMMINGKP01_H
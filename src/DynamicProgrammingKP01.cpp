// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01() {}

int DynamicProgrammingKP01::solveAux(const KP01withCGInstance& mochila, vector<vector<int>>& memo, int k, int capacity){
    if (k==0 || capacity==0){
        memo[k][capacity] = 0;
        return 0;
    }
    else{
        if (memo[k][capacity]!=-1){
            return memo[k][capacity];
        }
        else{
            int vWithout = solveAux(mochila, memo, k-1, capacity);

            int vWith = -1;
            if (mochila.getWeight(k)<=capacity){
                vWith = mochila.getProfit(k) + solveAux(mochila, memo, k-1, capacity-mochila.getWeight(k));
            }
            memo[k][capacity] = vWithout>vWith ? vWithout : vWith;
            return memo[k][capacity];
        }
    }
}

void DynamicProgrammingKP01::obtainSolution(const KP01withCGInstance& mochila, Solution& S, vector<vector<int>>& memo ){

    S.setMochila(mochila);
    int numItems = mochila.getNumItems();
    int cap = mochila.getCapacity();
    for (int k = numItems; k>0; k--){
        if (memo[k][cap] == memo[k-1][cap]){
            S.removeItem(k);
        }
        else{
            S.addItem(k);
            cap -= mochila.getWeight(k);
        }
    }
}
    
Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    Solution ret(1);
    ret.setMochila(instance);
    int numItems = instance.getNumItems();
    int maxCapacity = instance.getCapacity();

    vector<vector<int>> memo= vector<vector<int>>(numItems+1, vector<int>(maxCapacity+1, -1 ));
    solveAux(instance,memo, numItems, maxCapacity);
    obtainSolution(instance, ret, memo);
    return ret;

}






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
            if (mochila.getWeight(k-1)<=capacity){
                vWith = mochila.getProfit(k-1) + solveAux(mochila, memo, k-1, capacity-mochila.getWeight(k-1));
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
    return ret;

}

/*
int main(){
    KP01withCGInstance instance(0,0);
    instance.setInstance("instances/costo_peso_correlaciona_n30_star.txt");
    DynamicProgrammingKP01 solver_dp;
    int numItems = instance.getNumItems();
    int maxCapacity = instance.getCapacity();
    vector<vector<int>> memo= vector<vector<int>>(numItems+1, vector<int>(maxCapacity+1, -1 ));
    int ret = solver_dp.solveAux(instance, memo, numItems, maxCapacity);
    cout<<ret<<"\n";
}


*/


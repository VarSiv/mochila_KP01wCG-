// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"

BacktrackingKP01wCG::BacktrackingKP01wCG() {}

int BacktrackingKP01wCG::maxProfit(Solution S, int k){
    int n = S.numItems();

    for (int i = k; i<n; i++){
        S.addItem(i);
    }

    return S.totalProfit();
}

void BacktrackingKP01wCG::solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S){
    int n = mochila.getNumItems();
    if(k ==n){
        if(S.totalWeight()<=mochila.getCapacity() && S.totalProfit()> B.totalProfit() && S.isValidItems()){
            B=S;
        }
    } 
    else if(S.isValidItems() && S.totalWeight()<=mochila.getCapacity() && maxProfit(S, k)>B.totalProfit()){
        Solution S2 = S;
        S2.addItem(k);
        solveAux(mochila, k+1, B, S2);
        S2.removeItem(k);
        solveAux(mochila, k+1, B, S2);
    }
}

Solution BacktrackingKP01wCG::solve(const KP01withCGInstance& instance) {
    Solution ret(1);
    ret.setMochila(instance);
    solveAux(instance, 0, ret, ret);

    return ret;
}
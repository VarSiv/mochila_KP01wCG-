// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"

BruteForceKP01wCG::BruteForceKP01wCG() {}

void BruteForceKP01wCG::solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S){
    int n = mochila.getNumItems();
    if(k ==n){
        if(S.totalWeight()<=mochila.getCapacity() && S.totalProfit()> B.totalProfit() && S.isValidItems()){
            B=S;
        }
    } else{
        Solution S2 = S;
        S2.addItem(k);
        solveAux(mochila, k+1, B, S2);
        S2.removeItem(k);
        solveAux(mochila, k+1, B, S2);
    }
}

Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance) {

    Solution ret(1);
    ret.setMochila(instance);
    solveAux(instance, 0, ret, ret);

    return ret;

}



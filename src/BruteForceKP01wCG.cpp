// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"

BruteForceKP01wCG::BruteForceKP01wCG() {}


Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance, int k) {
    Solution b = bestSolution(instance.getNumItems());
    Solution s;
    
    if(k ==instance.getNumItems()){
        if(s.totalWeight()<=instance.getCapacity() && s.totalProfit()> b.totalProfit()){
            b = s;
        }
    } else{
        s.addItem(k);
        s=solve(instance, k+1);
        s.removeItem(k);
        s=solve(instance, k+1);
    }
    return bestSolution;
}
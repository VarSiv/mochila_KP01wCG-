// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"

BacktrackingKP01wCG::BacktrackingKP01wCG() {}


Solution BacktrackingKP01wCG::solve(const KP01withCGInstance& instance, int k) {
    //Solution solution(instance.getNumItems());
    Solution b = bestSolution(instance.getNumItems());
    Solution s;
    
    if(k ==instance.getNumItems()){
        if(s.totalWeight()<=instance.getCapacity() && s.totalProfit()> b.totalProfit()){
            b = s;
        }
    } else if(s.totalWeight()<=instance.getCapacity()&& s.totalProfit()+ sumatoria(k+1, instance)> b.totalProfit()){
        s.addItem(k);
        s=solve(instance, k+1);
        s.removeItem(k);
        s=solve(instance, k+1);
    }
    return bestSolution;
}

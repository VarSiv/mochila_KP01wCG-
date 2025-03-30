// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BacktrackingKP01wCG {
private:
int sumatoria(int k, KP01withCGInstance instance){
    int res=0;
    for(int i=k;i<instance.getNumItems();i++){
        res+=getProfit(instance[i]);
    }
    return res;
}

public:
    BacktrackingKP01wCG();
    Solution solve(const KP01withCGInstance& instance);
};

#endif // BACKTRACKINGKP01_H
// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01() {}

void DynamicProgrammingKP01::solveAux( KP01withCGInstance mochila, Solution& S, vector<vector<int>>& m){
    for(int i=0; i<= mochila.getNumItems(); i++){
        m[i][0]=0;
    }
    for(int c=0; c<= mochila.getCapacity(); c++){
        m[0][c]=0;
    }
    for(int k=1; k<= mochila.getNumItems(); k++){
        for(int c=1; c<= mochila.getCapacity(); c++){
            if(mochila.getWeight(k-1)> c){//solo puedo considerar no agregarlo
                m[k][c]=m[k-1][c];
            }else{
                obtainSolution(mochila, S, m);
                if( m[k-1][c] < mochila.getProfit(k-1) + m[k-1][c-mochila.getWeight(k-1)] && S.isValidItems()){
                    m[k][c]=mochila.getProfit(k-1)+m[k-1][c-mochila.getWeight(k-1)];
                }else{
                    m[k][c]=m[k-1][c];
                }
            }
        }
    }
}


void DynamicProgrammingKP01::obtainSolution(KP01withCGInstance mochila, Solution& S, vector<vector<int>> m){
    int c=m[0].size()-1;
    int k=m.size()-1;
    while(k>0){
        S.addItem(k-1);
        if(c-mochila.getWeight(k-1)>=0 && m[k-1][c] < mochila.getProfit(k-1)+m[k-1][c-mochila.getWeight(k-1)] && S.isValidItems()){
            c=c-mochila.getWeight(k-1);
        }else{
            S.removeItem(k-1);
        }
        k--;
    }
}
    
Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    Solution ret(1);
    ret.setMochila(instance);
    vector<vector<int>> v= vector<vector<int>>(instance.getNumItems()+1, vector<int>(instance.getCapacity()+1, 0 ));
    solveAux(instance, ret, v);
    return ret;
}

int main(){
    KP01withCGInstance instance(0,0);
    instance.setInstance("instances/mochila_chica_n10_no_conflict.txt");
    DynamicProgrammingKP01 BT;
    Solution sol = BT.solve(instance);
    std::cout<<sol.totalProfit()<<"\n";
    sol.printSolution();

}
   






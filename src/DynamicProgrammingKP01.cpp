// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01() {}



void DynamicProgrammingKP01::solveAux(const KP01withCGInstance& mochila, Solution& S, vector<vector<int>>& m){
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

              

                if(m[k-1][c] < mochila.getProfit(k-1)+m[k-1][c-mochila.getWeight(k-1)].first && S2.isValidItems() && S2.totalWeight()<=mochila.getCapacity() ){
                    m[k][c]=S2;
                    m[k][c]=mochila.getProfit(k-1)+m[k-1][c-mochila.getWeight(k-1)].first;


                }else if(m[k-1][c].second.isValidItems() && m[k-1][c].second.totalWeight()<=mochila.getCapacity()){
                    m[k][c]=m[k-1][c];


                }
            }
        }

            
        }
    }



Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    Solution ret(1);
    ret.setMochila(instance);
    vector<vector<pair<int,Solution>>> v= vector<vector<pair<int,Solution>>>(instance.getNumItems()+1, vector<pair<int,Solution>>(instance.getCapacity()+1, {0,ret} ));
    solveAux(instance, ret, v);
    ret=v[instance.getNumItems()][instance.getCapacity()];
    return ret;
}
int main(){
    KP01withCGInstance instance(0,0);
    instance.setInstance("instances/test_instance_2.in");
    DynamicProgrammingKP01 BT;
    Solution sol = BT.solve(instance);
    std::cout<<sol.totalProfit()<<"\n";
    sol.printSolution();
}


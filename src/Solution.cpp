#include "Solution.h"

Solution::Solution(int numItems) {
    _num_items=numItems;
    _items_vector=vector<bool>(numItems, false);
    _mochila= KP01withCGInstance(numItems, 0);

}

void Solution::addItem(int item) {
    _items_vector[item]=true;

}

void Solution::removeItem(int item) {
    _items_vector[item]=false;  
}

bool Solution::contains(int item) const {
    return _items_vector[item];
    
}
int Solution::totalProfit(){
    int res=0;
    for(int i=0;i<_num_items;i++){
        if (_items_vector[i]){
            res+=_mochila.getProfit(i);
        }
        
    }
    return res;

}
int Solution::totalWeight(){
    int res=0;
    for(int i=0;i<_num_items;i++){
        if (_items_vector[i]){
            res+=_mochila.getWeight(i);
        }
    }
    return res;

}
vector<bool> Solution::getItemsVector(){
    return _items_vector;
}

void Solution::printSolution() const {
 for(int i=0; i<_num_items; i++){
    cout<<i<<": "<< _items_vector[i]<<" "<< endl;
 }
}

int main(){
    Solution sol(2);
}
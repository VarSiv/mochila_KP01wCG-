#include "Solution.h"

Solution::Solution(int numItems) {
    
    _num_items=numItems;
    _items_vector=vector<bool>(numItems, false);
    _mochila= KP01withCGInstance(numItems, 0);

}
int Solution::numItems(){
    return _num_items;
}
void Solution::setMochila(KP01withCGInstance mochila){
    _num_items = mochila.getNumItems();
    _items_vector=vector<bool>(_num_items, false);
    _mochila = mochila;
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
bool Solution::isValidItems(){
    for (int i=0; i<_num_items; i++){
        for (int j=0; j<_num_items; j++){
            if (_items_vector[i] && _items_vector[j] && _mochila.isConflicting(i, j)){
                return false;
            }
        }
    }
    return true;
}
void Solution::printSolution() const {
    for(int i=0; i<_num_items; i++){
        cout<<i<<": "<< _items_vector[i]<<" "<< endl;
 }
}
// int main(){
//     KP01withCGInstance instance(0,0);
//     instance.setInstance("instances/test_instance.in");
//     Solution sol(2);
//     sol.setMochila(instance);
//     sol.addItem(2);
//     cout<<sol.totalProfit()<<" "<<sol.totalWeight()<<" "<<sol.isConflictingItems()<<"\n";
//     sol.printSolution();
//     sol.addItem(4);
//     cout<<sol.totalProfit()<<" "<<sol.totalWeight()<<" "<<sol.isConflictingItems()<<"\n";
//     sol.printSolution();
// }
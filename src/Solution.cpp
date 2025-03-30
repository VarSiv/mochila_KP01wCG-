#include "Solution.h"

Solution::Solution(int numItems) {
    _num_items=numItems;
    _items_vector=generarVectorCreciente(numItems);

}

void Solution::addItem(int item) {
    _items_vector.push_back(item);

}

void Solution::removeItem(int item) {
    _items_vector.erase(item);  
}

bool Solution::contains(int item) const {
    for(int i=0; i<_items_vector.size();i++){
        if(item == _items_vector[i]){
            return true;
        }
    }
    return false;
    
}
int Solution::totalProfit(){
    int res=0;
    for(int i=0;i<_num_items;i++){
        res+=getProfit(_items_vector[i]);
    }
    return res;

}
int Solution::totalWeight(){
    int res=0;
    for(int i=0;i<_num_items;i++){
        res+=getWeight(_items_vector[i]);
    }
    return res;

}
vector<int> Solution::getItemsVector(){
    return _item_vector;
}

void Solution::printSolution() const {
 for(int i=0; i<_num_items; i++){
    cout<< _items_vector[i]<< endl;
 }
}


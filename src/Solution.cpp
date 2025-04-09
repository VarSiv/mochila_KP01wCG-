#include "Solution.h"

Solution::Solution(int numItems) {
    // Constructor que inicializa el número de ítems, el vector de selección de items, todos en false ya que todavia 
    // no se tomo ninguna decision sobre ellos, y una mochila vacía
    _num_items=numItems;
    _items_vector=vector<bool>(numItems, false);
    _mochila= KP01withCGInstance(numItems, 0);

}

// Devuelve la cantidad total de ítems 
int Solution::numItems(){
    return _num_items;
}

// Asocia la solución a una instancia de mochila, y reinicia el vector de ítems 
void Solution::setMochila(KP01withCGInstance mochila){
    _num_items = mochila.getNumItems();
    _items_vector=vector<bool>(_num_items, false);
    _mochila = mochila;
}

// Agrega un ítem a la solución
void Solution::addItem(int item) {
    _items_vector[item]=true;

}

// Quita un ítem de la solución
void Solution::removeItem(int item) {
    _items_vector[item]=false;  
}

// Verifica si un ítem está incluido en la solución
bool Solution::contains(int item) const {
    return _items_vector[item];
    
}

// Calcula el beneficio total de la solución sumando los beneficios de los ítems seleccionados
int Solution::totalProfit(){
    int res=0;
    for(int i=0;i<_num_items;i++){
        if (_items_vector[i]){
            res+=_mochila.getProfit(i);
        }
        
    }
    return res;

}

// Calcula el peso total sumando los pesos de los ítems seleccionados
int Solution::totalWeight(){
    int res=0;
    for(int i=0;i<_num_items;i++){
        if (_items_vector[i]){
            res+=_mochila.getWeight(i);
        }
    }
    return res;

}

// Devuelve el vector de ítems seleccionados 
vector<bool> Solution::getItemsVector(){
    return _items_vector;
}

// Verifica si una solucion es valida en cuanto a los conlfictos, es decir, no hay conflictos entre ítems seleccionados
bool Solution::isValidItems(){
    for (int i=0; i<_num_items; i++){
        for (int j=0; j<_num_items; j++){
            if (_items_vector[i] && _items_vector[j] && _mochila.isConflicting(i, j)){ // Si hay conflicto no es valida y devuelve false
                return false;
            }
        }
    }
    return true;
}

// Imprime la solución mostrando cada ítem y si está incluido (1) o no (0)
void Solution::printSolution() const {
    for(int i=0; i<_num_items; i++){
        cout<<i<<": "<< _items_vector[i]<<" "<< endl;
 }
}

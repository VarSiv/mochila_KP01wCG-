// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"

BacktrackingKP01wCG::BacktrackingKP01wCG() {}

// Función auxiliar que calcula el beneficio máxima posible agregando todos los ítems de k en adelante
int BacktrackingKP01wCG::maxProfit(Solution S, int k){
    int n = S.numItems();

    for (int i = k; i<n; i++){
        S.addItem(i); //Agregamos todos los items de k en adelante ya que como no hay beneficios negativos, el beneficio maximo a partir de k implica agregar todos los items
    }

    return S.totalProfit(); //Devolvemos el beneficio maximo
}

void BacktrackingKP01wCG::solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S){
    int n = mochila.getNumItems();

    //Caso base: si ya recorrimos todos los items
    if(k == n){
        //Si el peso total de la posible solucion es menor o igual que la capacidad de la mochila, su beneficio es mayor que el de la mejor solucion encontrada hasta el momento y sus items no tienen conflictos
        if(S.totalWeight()<=mochila.getCapacity() && S.totalProfit()> B.totalProfit() && S.isValidItems()){
            //Se guarda la mejor solucion encontrada hasta el momento
            B=S;
        }
    } 
    // Caso recursivo: si la posible solucion es válida, no tiene conflictos y el beneficio potencial máximo de su sub-arbol es mayor que la mejor hasta ahora
    else if(S.isValidItems() && S.totalWeight()<=mochila.getCapacity() && maxProfit(S, k)>B.totalProfit()){
        Solution S2 = S; //Creamos una copia del estado actual de la solucion
        S2.addItem(k); //Agregamos el item k
        solveAux(mochila, k+1, B, S2); //Llamado recursivo incluyendo al item k
        S2.removeItem(k); //Sacamos k
        solveAux(mochila, k+1, B, S2); //Llamado recursivo sin incluir al item k
    }
}

Solution BacktrackingKP01wCG::solve(const KP01withCGInstance& instance) {
    Solution ret(1);  //Creamos una solucion vacia
    ret.setMochila(instance); // Asociamos la instancia del problema a la solución
    solveAux(instance, 0, ret, ret); // Iniciamos la recursión desde el ítem 0

    return ret;
}
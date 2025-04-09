// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"

BruteForceKP01wCG::BruteForceKP01wCG() {}

void BruteForceKP01wCG::solveAux(const KP01withCGInstance& mochila, int k, Solution& B, Solution S){
    int n = mochila.getNumItems();

    // Caso base: si ya consideramos cada ítem
    if(k == n){
        // Si el peso de la solucion parcial es válido, los ítems no tienen conflicto y el beneficio es mejor que el de la mejor solucion encontrada hasta el momento
        if(S.totalWeight()<=mochila.getCapacity() && S.totalProfit()> B.totalProfit() && S.isValidItems()){
            B=S; //Guardamos la nueva solucion como la mejor hasta el momento
        }
    } else{
        //Caso recursivo
        Solution S2 = S; //Creamos una copia de la solucion actual
        S2.addItem(k); //Agregamos el item k
        solveAux(mochila, k+1, B, S2); //Llamado recursivo incluyendo al item k
        S2.removeItem(k); //Sacamos el item k
        solveAux(mochila, k+1, B, S2); //Llamado recursivo sin incluir al item k
    }
}

Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance) {
    Solution ret(1);  //Creamos una solucion vacia
    ret.setMochila(instance); // Asociamos la instancia del problema a la solución
    solveAux(instance, 0, ret, ret); // Iniciamos la recursión desde el ítem 0

    return ret;

}


 

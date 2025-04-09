// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>



DynamicProgrammingKP01::DynamicProgrammingKP01() {}


// Función auxiliar de Programacion Dinamica que usa el enfoque Top-Down
int DynamicProgrammingKP01::solveAux(const KP01withCGInstance& mochila, vector<vector<int>>& memo, int k, int capacity){
    // Caso base: sin ítems o sin capacidad disponible
    if (k==0 || capacity==0){
        memo[k][capacity] = 0; //Si no tengo items o capacidad no voy a poder agregar nunca un item por lo que el beneficio va a ser 0
        return 0;
    }
    else{
        // Si ya calculamos previamente este subproblema, lo devuelvo
        if (memo[k][capacity]!=-1){
            return memo[k][capacity];
        }
        else{
            //beneficio  sin incluir el item k-1
            int vWithout = solveAux(mochila, memo, k-1, capacity);


            int vWith = -1;
            // Si podemos agregar al ítem k-1 sin superar la capacidad de la mochila, calculo el beneficio incluyéndolo
            if (mochila.getWeight(k-1)<=capacity){
                vWith = mochila.getProfit(k-1) + solveAux(mochila, memo, k-1, capacity-mochila.getWeight(k-1));
            }

            // Guardamos en la matriz el mejor beneficio entre incluir al item k o no
            memo[k][capacity] = vWithout>vWith ? vWithout : vWith;
            return memo[k][capacity];
        }
    }
}

// Reconstrucción de la solución óptima a partir de la matriz memo
void DynamicProgrammingKP01::obtainSolution(const KP01withCGInstance &mochila, Solution &S, vector<vector<int>> &memo){
    int c=mochila.getCapacity();
    int k=mochila.getNumItems();

    // Recorremos desde el último ítem hacia el primero
    while(k>0){
        S.addItem(k-1); // Agregamos el ítem k-1

        // Si al quitar el ítem k-1, el beneficio óptimo baja, es porque estaba en la solución optima
        if(c-mochila.getWeight(k-1)>=0 && memo[k-1][c] < mochila.getProfit(k-1)+memo[k-1][c-mochila.getWeight(k-1)]){
            c=c-mochila.getWeight(k-1); //Reducimos la capacidad restante ya que k pertenece a la solucion optima
        }else{
            S.removeItem(k-1); //Si no pertenece a la solucion optima lo sacamos
        }
        k--; // Paso al ítem anterior
    }
}   
Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    Solution ret(1); //Creamos una solucion vacia
    ret.setMochila(instance); // Asociamos la instancia del problema a la solución

    int numItems = instance.getNumItems();
    int maxCapacity = instance.getCapacity();

    vector<vector<int>> memo= vector<vector<int>>(numItems+1, vector<int>(maxCapacity+1, -1 )); // Creamos la matriz memo inicializada en -1 para indicar que no se ha calculado ninguno de los subproblemas
    solveAux(instance,memo, numItems, maxCapacity);     // Llamamos a la función auxiliar para llenar la matriz
    obtainSolution(instance, ret, memo);     // Reconstruimos la solución óptima a partir de la matriz
    return ret;

}

Solution ret(1);  
ret.setMochila(instance); 
solveAux(instance, 0, ret, ret); // Iniciamos la recursión desde el ítem 0


/*
int main(){
    KP01withCGInstance instance(0,0);
    instance.setInstance("instances/costo_peso_correlaciona_n30_star.txt");
    DynamicProgrammingKP01 solver_dp;
    int numItems = instance.getNumItems();
    int maxCapacity = instance.getCapacity();
    vector<vector<int>> memo= vector<vector<int>>(numItems+1, vector<int>(maxCapacity+1, -1 ));
    int ret = solver_dp.solveAux(instance, memo, numItems, maxCapacity);
    cout<<ret<<"\n";
}


*/


// main.cpp
#include "KP01withCGInstance.h"
#include "Solution.h"
#include "DynamicProgrammingKP01.h"
#include "BacktrackingKP01wCG.h"
#include "BruteForceKP01wCG.h"

#include <iostream>

int main(int argc, char* argv[]) {
    // Verificamos que se pasen al menos dos parametros (el algoritmo y el nombre de la instancia)
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <algorithm> <instance>\n";
        std::cerr << "Available algorithms: dp (Dynamic Programming), bt (Backtracking), bf (Brute Force)\n";
        return 1; // Terminamos el programa si faltan parametros
    }

    std::string algorithm = argv[1];  // Algoritmo elegido por el usuario
    std::string instance_name = argv[2]; // Nombre del archivo de la instancia

    // Creamos una instancia vacía del problema y la inicializamos leyendo desde el archivo
    KP01withCGInstance instance(0,0);
    instance.setInstance(instance_name);

    std::cout <<"Num items: " <<instance.getNumItems() << std::endl;
    std::cout <<"Max capacity: " <<instance.getCapacity() << std::endl;

    // Creamos una solución inicializada con el número de ítems de la instancia
    Solution solution(instance.getNumItems());

    // Dependiendo del algoritmo elegido, resolvemos la instancia con el solver correspondiente
    if (algorithm == "dp") {
        DynamicProgrammingKP01 solver_dp;
        solution = solver_dp.solve(instance);
    } else if (algorithm == "bt") {
        BacktrackingKP01wCG solver_bt;
        solution = solver_bt.solve(instance);
    } else if (algorithm == "bf") {
        BruteForceKP01wCG solver_bf;
        solution = solver_bf.solve(instance);
    } else {
        std::cerr << "Unknown algorithm: " << algorithm << "\n";
        return 1;
    }

    // Mostramos los resultados de la solución obtenida 
    cout<<"Profit obtained: "<<solution.totalProfit()<<std::endl;
    cout<<"Weight used: "<<solution.totalWeight()<<std::endl;
    solution.printSolution();
    


    return 0;
}

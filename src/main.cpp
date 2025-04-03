// main.cpp
#include "KP01withCGInstance.h"
#include "Solution.h"
#include "DynamicProgrammingKP01.h"
#include "BacktrackingKP01wCG.h"
#include "BruteForceKP01wCG.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <algorithm> <instance>\n";
        std::cerr << "Available algorithms: dp (Dynamic Programming), bt (Backtracking), bf (Brute Force)\n";
        return 1;
    }

    std::string algorithm = argv[1];
    std::string instance_name = argv[2];

    KP01withCGInstance instance(0,0);
    instance.setInstance(instance_name);

    std::cout <<"Num items: " <<instance.getNumItems() << std::endl;
    std::cout <<"Max capacity: " <<instance.getCapacity() << std::endl;

    Solution solution(instance.getNumItems());

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

    cout<<"Profit obtained: "<<solution.totalProfit()<<std::endl;
    cout<<"Weight used: "<<solution.totalWeight()<<std::endl;
    solution.printSolution();
    


    return 0;
}

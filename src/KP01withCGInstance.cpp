#include "KP01withCGInstance.h"


// Constructor por defecto: inicializa con 0 ítems, 0 capacidad máxima y un grafo de conflictos vacío
KP01withCGInstance::KP01withCGInstance(): _num_items(0), _maxCapacity(0), _conflicts(Graph(0)){
    _weights=vector<int>(0);
    _profits=vector<int>(0);
}

// Constructor con parámetros: inicializa con n ítems, capacidad cap y un grafo de conflictos con n nodos
KP01withCGInstance::KP01withCGInstance(int n, int cap): _num_items(n), _maxCapacity(cap), _conflicts(Graph(n)){
    _weights=vector<int>(n);
    _profits=vector<int>(n);
}

// Carga una instancia desde un archivo de texto
void KP01withCGInstance::setInstance(string filename){
    _conflicts=Graph(0); // Reiniciamos el grafo de conflictos
    _filename = filename;
    _weights = {}; //Vaciamos los vectores
    _profits = {};

    ifstream instanceFile;
    
    instanceFile.open(filename); //Abre el archivo de instancia

    string fileLine;
    if (instanceFile.is_open()){
        
        std::getline(instanceFile, fileLine);  //Obtiene el numero de items
        _num_items = std::stoi(fileLine);
        _conflicts = Graph(_num_items);  //Inicializamos el grafo de conflictos

        std::getline(instanceFile, fileLine);  //Obtiene la capacidad maxima
        _maxCapacity = std::stoi(fileLine);


        string itemWeight;
        std::getline(instanceFile, fileLine); //Obtiene los pesos de los items
        std::stringstream weightsStream(fileLine);

        while (getline(weightsStream, itemWeight, ' ')){  //Llenamos el vector de pesos con los pesos de los items
            int intWeight = std::stoi(itemWeight);
            _weights.push_back(intWeight);

        }

        string itemProfit;
        std::getline(instanceFile, fileLine); //Obtiene los beneficios de los items
        std::stringstream profitsStream(fileLine);

        while (getline(profitsStream, itemProfit, ' ')){  //Llenamos el vector de beneficios con los beneficios de los items
            int intProfit = std::stoi(itemProfit);
            _profits.push_back(intProfit);

        }

        std::getline(instanceFile, fileLine); //Obtiene el numero de conflictos
        int conflictNumber = std::stoi(fileLine);
        

        for (int i=0; i<conflictNumber; i++){ //Itera sobre cada conflicto
            std::getline(instanceFile, fileLine);
            std::stringstream edgeStream(fileLine); 

            string vertexNumber;
            // Extrae el primer número de la línea que representa el primer ítem en conflicto
            getline(edgeStream, vertexNumber, ' '); 
            int v1 = std::stoi(vertexNumber);
            // Extrae el segundo número de la línea que representa el segundo ítem en conflicto
            getline(edgeStream, vertexNumber, ' ');
            int v2 = std::stoi(vertexNumber);

            // Añadimos una arista entre los dos ítems al grafo de conflictos para mostrar que no se pueden seleccionar ambos ítems en la solución porque tienen un conflicto
            _conflicts.addEdge(v1, v2);


        }

        
    }
}

// Establece el peso de un ítem en el índice dado
void KP01withCGInstance::setWeight(int index, int weight){
    _weights[index]=weight;
}

// Establece el beneficio de un ítem en el índice dado
void KP01withCGInstance::setProfit(int index, int profit){
    _profits[index]=profit;
}

// Devuelve el peso del ítem en el índice dado
int KP01withCGInstance::getWeight(int index) const
{
    return _weights[index];
}

// Devuelve el beneficio del ítem en el índice dado
int KP01withCGInstance::getProfit(int index) const {
    return _profits[index];
}

// Devuelve la cantidad total de ítems en la instancia
int KP01withCGInstance::getNumItems() const {
    return _num_items;
}

// Devuelve la capacidad máxima de la mochila
int KP01withCGInstance::getCapacity() const {
    return _maxCapacity;
}

// Añade un conflicto, es decir, una arista entre dos ítems
void KP01withCGInstance::addConflict(int item1, int item2) {
    _conflicts.addEdge(item1, item2);
     
}

// Elimina un conflicto, es decir, una arista entre dos ítems
void KP01withCGInstance::removeConflict(int item1, int item2) {
    _conflicts.removeEdge(item1, item2);
}

// Verifica si dos ítems están en conflicto, es decir, son adyacentes en el grafo
bool KP01withCGInstance::isConflicting(int item1, int item2){
    return _conflicts.isAdjacent(item1, item2);
}

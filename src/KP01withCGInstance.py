import numpy as np
from Graph import Graph

class KP01withCGInstance:
    def __init__(self, n=0, cap=0):
        # Constructor que inicializa la instancia con n ítems y capacidad cap
        self._num_items = n
        self._max_capacity = cap
        self._conflicts = Graph(n)
        self._weights = [0] * n
        self._profits = [0] * n
        self._filename = ""

    def set_instance(self, filename: str):
        # Carga una instancia desde un archivo de texto
        self._conflicts = Graph(0)
        self._filename = filename
        self._weights = []
        self._profits = []

        with open(filename, 'r') as instance_file:
            lines = instance_file.readlines()
            
            # Número de ítems
            self._num_items = int(lines[0].strip())
            self._conflicts = Graph(self._num_items)

            # Capacidad máxima de la mochila
            self._max_capacity = int(lines[1].strip())

            
            # Pesos de los ítems
            self._weights = list(map(int, lines[2].strip().split()))
            # Beneficios de los items
            self._profits = list(map(int, lines[3].strip().split()))

            # Cantidad de conflictos
            conflict_number = int(lines[4].strip())
            # Agrega aristas entre pares de ítems en conflicto
            for i in range(conflict_number):
                v1, v2 = map(int, lines[5 + i].strip().split())
                self._conflicts.add_edge(v1, v2)
    
     # Cambia el peso de un ítem
    def set_weight(self, index: int, weight: int):
        self._weights[index] = weight
    
    # Cambia el beneficio de un ítem   
    def set_profit(self, index: int, profit: int):
        self._profits[index] = profit

    # Obtiene el peso de un ítem
    def get_weight(self, index: int) -> int:
        return self._weights[index]

    # Obtiene el beneficio de un ítem
    def get_profit(self, index: int) -> int:
        return self._profits[index]

    # Obtiene el numero de ítems
    def get_num_items(self) -> int:
        return self._num_items

    # Obtiene la capacidad maxima
    def get_capacity(self) -> int:
        return self._max_capacity

    # Agrega conflicto entre dos items
    def add_conflict(self, item1: int, item2: int):
        self._conflicts.add_edge(item1, item2)

    # Elimina conflicto entre dos items
    def remove_conflict(self, item1: int, item2: int):
        self._conflicts.remove_edge(item1, item2)

    # Devuelve True si dos items estan en conflicto
    def is_conflicting(self, item1: int, item2: int) -> bool:
        return self._conflicts.is_adjacent(item1, item2)

from KP01withCGInstance import KP01withCGInstance

class Solution:
    def __init__(self, num_items: int):
        # Constructor: inicializa con cantidad de ítems, vector sin seleccionar ningun item y mochila sin bneficios ni pesos
        self._num_items = num_items
        self._items_vector = [False] * num_items
        self._mochila = KP01withCGInstance(num_items, 0)

    def num_items(self) -> int:
        # Devuelve la cantidad de ítems de la solución
        return self._num_items

    def set_mochila(self, mochila: KP01withCGInstance):
        # Asigna una nueva instancia del problema y reinicia la solución para que no haya ningun item seleccionado
        self._num_items = mochila.get_num_items()
        self._items_vector = [False] * self._num_items
        self._mochila = mochila

    def add_item(self, item: int):
        # Agrega un ítem a la solución
        self._items_vector[item] = True

    def remove_item(self, item: int):
        # Elimina un ítem de la solución
        self._items_vector[item] = False

    def contains(self, item: int) -> bool:
        # Verifica si el ítem está incluido en la solución
        return self._items_vector[item]

    def total_profit(self) -> int:
        # Calcula el beneficio total de los ítems seleccionados
        return sum(self._mochila.get_profit(i) for i in range(self._num_items) if self._items_vector[i])

    def total_weight(self) -> int:
        # Calcula el peso total de los ítems seleccionados
        return sum(self._mochila.get_weight(i) for i in range(self._num_items) if self._items_vector[i])

    def get_items_vector(self):
        # Devuelve el vector que muestra que items estan seleccionados
        return self._items_vector

    def is_valid_items(self) -> bool:
        # Verifica si la solución no tiene conflictos entre sus items 
        for i in range(self._num_items):
            for j in range(self._num_items):
                if self._items_vector[i] and self._items_vector[j] and self._mochila.is_conflicting(i, j):
                    return False
        return True

    def print_solution(self):
        # Imprime la solucion
        for i in range(self._num_items):
            print(f"{i}: {self._items_vector[i]}")

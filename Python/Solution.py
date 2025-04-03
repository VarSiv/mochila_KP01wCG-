from KP01withCGInstance import KP01withCGInstance

class Solution:
    def __init__(self, num_items: int):
        self._num_items = num_items
        self._items_vector = [False] * num_items
        self._mochila = KP01withCGInstance(num_items, 0)

    def num_items(self) -> int:
        return self._num_items

    def set_mochila(self, mochila: KP01withCGInstance):
        self._num_items = mochila.get_num_items()
        self._items_vector = [False] * self._num_items
        self._mochila = mochila

    def add_item(self, item: int):
        self._items_vector[item] = True

    def remove_item(self, item: int):
        self._items_vector[item] = False

    def contains(self, item: int) -> bool:
        return self._items_vector[item]

    def total_profit(self) -> int:
        return sum(self._mochila.get_profit(i) for i in range(self._num_items) if self._items_vector[i])

    def total_weight(self) -> int:
        return sum(self._mochila.get_weight(i) for i in range(self._num_items) if self._items_vector[i])

    def get_items_vector(self):
        return self._items_vector

    def is_valid_items(self) -> bool:
        for i in range(self._num_items):
            for j in range(self._num_items):
                if self._items_vector[i] and self._items_vector[j] and self._mochila.is_conflicting(i, j):
                    return False
        return True

    def print_solution(self):
        for i in range(self._num_items):
            print(f"{i}: {self._items_vector[i]}")

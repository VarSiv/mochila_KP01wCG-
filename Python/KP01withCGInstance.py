import numpy as np
from Graph import Graph

class KP01withCGInstance:
    def __init__(self, n=0, cap=0):
        self._num_items = n
        self._max_capacity = cap
        self._conflicts = Graph(n)
        self._weights = [0] * n
        self._profits = [0] * n
        self._filename = ""

    def set_instance(self, filename: str):
        self._conflicts = Graph(0)
        self._filename = filename
        self._weights = []
        self._profits = []

        with open(filename, 'r') as instance_file:
            lines = instance_file.readlines()
            
            self._num_items = int(lines[0].strip())
            self._conflicts = Graph(self._num_items)
            self._max_capacity = int(lines[1].strip())

            self._weights = list(map(int, lines[2].strip().split()))
            self._profits = list(map(int, lines[3].strip().split()))

            conflict_number = int(lines[4].strip())
            for i in range(conflict_number):
                v1, v2 = map(int, lines[5 + i].strip().split())
                self._conflicts.add_edge(v1, v2)
    
    def set_weight(self, index: int, weight: int):
        self._weights[index] = weight
    
    def set_profit(self, index: int, profit: int):
        self._profits[index] = profit

    def get_weight(self, index: int) -> int:
        return self._weights[index]

    def get_profit(self, index: int) -> int:
        return self._profits[index]

    def get_num_items(self) -> int:
        return self._num_items

    def get_capacity(self) -> int:
        return self._max_capacity

    def add_conflict(self, item1: int, item2: int):
        self._conflicts.add_edge(item1, item2)

    def remove_conflict(self, item1: int, item2: int):
        self._conflicts.remove_edge(item1, item2)

    def is_conflicting(self, item1: int, item2: int) -> bool:
        return self._conflicts.is_adjacent(item1, item2)

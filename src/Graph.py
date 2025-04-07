
class Graph:
    def __init__(self, n: int):
        self._n = n
        self._matrix = [[False] * n for _ in range(n)]

    def get_n(self) -> int:
        return self._n

    def add_edge(self, node1: int, node2: int):
        if node1 == node2:
            raise ValueError("can't draw edge between the same node")
        
        self._matrix[node1][node2] = True
        self._matrix[node2][node1] = True

    def remove_edge(self, node1: int, node2: int):
        self._matrix[node1][node2] = False
        self._matrix[node2][node1] = False

    def is_adjacent(self, node1: int, node2: int) -> bool:
        return self._matrix[node1][node2]

    def print_graph(self):
        print("Number of vertices:")
        print(self._n)
        for row in self._matrix:
            print(" ".join(map(str, row)))

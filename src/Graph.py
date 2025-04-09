
class Graph:
    def __init__(self, n: int):
        # Constructor que inicializa un grafo con n nodos y sin aristas
        self._n = n
        self._matrix = [[False] * n for _ in range(n)] # Matriz de adyacencia

    def get_n(self) -> int:
        # Devuelve la cantidad de nodos del grafo
        return self._n

    def add_edge(self, node1: int, node2: int):
        # Agrega una arista entre node1 y node2
        if node1 == node2:
            raise ValueError("can't draw edge between the same node")
        
        self._matrix[node1][node2] = True
        self._matrix[node2][node1] = True

    def remove_edge(self, node1: int, node2: int):
        # Elimina la arista entre node1 y node2
        self._matrix[node1][node2] = False
        self._matrix[node2][node1] = False

    def is_adjacent(self, node1: int, node2: int) -> bool:
        # Verifica si hay una arista entre node1 y node2
        return self._matrix[node1][node2]

    def print_graph(self):
        # Imprime la cantidad de nodos y la matriz de adyacencia del grafo
        print("Number of vertices:")
        print(self._n)
        for row in self._matrix:
            print(" ".join(map(str, row)))

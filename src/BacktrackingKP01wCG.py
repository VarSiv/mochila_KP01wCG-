from KP01withCGInstance import KP01withCGInstance
from Solution import Solution
import os

#4
class BacktrackingKP01wCG:
    def __init__(self):
        # Constructor vacío
        pass

    def max_profit(self, S: Solution, k: int, mochila: KP01withCGInstance) -> int:
        # Calcula el beneficio maximo que se puede obtener a partir de una solucion parcial y los items que faltan 
        n = S.num_items()
        S2 = Solution(n)
        S2.set_mochila(mochila)
        S2._items_vector = S.get_items_vector().copy()

        # El beneficio maximo (sin tener en cuenta la factibilidad) implica agregar todos los items a partir de k por lo que los agregamos y vemos el beneficio final
        for i in range(k, n):
            S2.add_item(i)
        return S2.total_profit()

    def solve_aux(self, mochila: KP01withCGInstance, k: int, B: Solution, S: Solution):
        n = mochila.get_num_items()
        
        if k == n:
            # Caso base: ya vimos todos los ítems
            if (S.total_weight() <= mochila.get_capacity() and
                S.total_profit() > B.total_profit() and
                S.is_valid_items()):
                # Si S es mejor solución y válida, la guardamos como la mejor hasta ahora                
                B.set_mochila(mochila)
                B._items_vector = S.get_items_vector().copy()
        
        # Vemos si todavía vale la pena seguir teniendo en cuenta el beneficio potencial de ese sub arbol (poda por factibilidad y optimalidad)
        elif (S.is_valid_items() and S.total_weight() <= mochila.get_capacity() and
            self.max_profit(S, k, mochila) > B.total_profit()):
            S2 = Solution(n)
            S2.set_mochila(mochila)
            S2._items_vector = S.get_items_vector().copy()
            
            # Agregamos al item k y evaluamos la solucion con este
            S2.add_item(k) 
            self.solve_aux(mochila, k + 1, B, S2)
            
            #Sacamos al item k y evaluamos la solucion sin este
            S2.remove_item(k)
            self.solve_aux(mochila, k + 1, B, S2)

    def solve(self, instance: KP01withCGInstance) -> Solution:
        ret = Solution(1) # Inicializa solución vacía
        ret.set_mochila(instance)
        self.solve_aux(instance, 0, ret, ret) # Comienza el backtracking desde el ítem 0
        return ret
    
def test_backtracking():
    # Crear una instancia de la mochila desde un archivo
    instance = KP01withCGInstance(0, 0)
    instance.set_instance("instances/test_instance.in")

    # Crear el solucionador con backtracking
    bt_solver = BacktrackingKP01wCG()
    
    # Resolver la instancia
    solution = bt_solver.solve(instance)
    
    # Imprimir la solución
    print("Total Profit:", solution.total_profit())
    print("Total Weight:", solution.total_weight())
    print("Selected Items:", solution.get_items_vector())
    print("Capacity:", instance.get_capacity())
    
    # Validar que la solución es válida
    assert solution.total_weight() <= instance.get_capacity(), "Error: Se superó la capacidad de la mochila"
    assert solution.is_valid_items(), "Error: La solución tiene elementos en conflicto"
    print("Test passed successfully!")

if __name__ == "__main__":
    file_path = input("Enter the path to the instance file: ").strip()
    if not os.path.exists(file_path):
        print(f"Error: File '{file_path}' does not exist.")
        exit(1)
    instance = KP01withCGInstance(0, 0)
    instance.set_instance(file_path)

    bt_solver = BacktrackingKP01wCG()
    solution = bt_solver.solve(instance)
    print("Weight used: ", solution.total_weight())
    print("Profit obtained: ", solution.total_profit())

    solution.print_solution()
from KP01withCGInstance import KP01withCGInstance
from Solution import Solution
import os

class DynamicProgrammingKP01:
    def __init__(self):
        pass

    def solve_aux(self, mochila, memo, k, capacity):
        if k == 0 or capacity == 0:
            memo[k][capacity] = 0
            return 0
        if memo[k][capacity] != -1:
            return memo[k][capacity]

        v_without = self.solve_aux(mochila, memo, k - 1, capacity)

        v_with = -1
        if mochila.get_weight(k - 1) <= capacity:
            v_with = mochila.get_profit(k - 1) + self.solve_aux(
                mochila, memo, k - 1, capacity - mochila.get_weight(k - 1)
            )

        memo[k][capacity] = max(v_without, v_with)
        return memo[k][capacity]

    def obtain_solution(self, mochila, S, memo):
        c = mochila.get_capacity()
        k = mochila.get_num_items()
        while k > 0:
            S.add_item(k - 1)
            if (
                c - mochila.get_weight(k - 1) >= 0
                and memo[k - 1][c]
                < mochila.get_profit(k - 1)
                + memo[k - 1][c - mochila.get_weight(k - 1)]
            ):
                c = c - mochila.get_weight(k - 1)
            else:
                S.remove_item(k - 1)
            k -= 1

    def solve(self, instance):
        ret = Solution(1)
        ret.set_mochila(instance)
        num_items = instance.get_num_items()
        max_capacity = instance.get_capacity()
        memo = [[-1 for _ in range(max_capacity + 1)] for _ in range(num_items + 1)]
        self.solve_aux(instance, memo, num_items, max_capacity)
        self.obtain_solution(instance, ret, memo)
        return ret
    
def test_dynamicP():
    # Crear una instancia de la mochila desde un archivo
    instance = KP01withCGInstance(0, 0)
    instance.set_instance("instances/mochila_chica_n10_no_conflict.txt")

    # Crear el solucionador con backtracking
    bt_solver = DynamicProgrammingKP01()
    
    # Resolver la instancia
    solution = bt_solver.solve(instance)
    
    # Imprimir la solución
    print("Total Profit:", solution.total_profit())
    print("Total Weight:", solution.total_weight())
    print("Selected Items:", solution.get_items_vector())
    print("Capacity:", instance.get_capacity())
    
    # Validar que la solución es válida
    assert solution.total_weight() <= instance.get_capacity(), "Error: Se superó la capacidad de la mochila"
    print("Test passed successfully!")

if __name__ == "__main__":
    file_path = input("Enter the path to the instance file: ").strip()
    if not os.path.exists(file_path):
        print(f"Error: File '{file_path}' does not exist.")
        exit(1)
    instance = KP01withCGInstance(0, 0)
    instance.set_instance(file_path)

    bt_solver = DynamicProgrammingKP01()
    solution = bt_solver.solve(instance)
    print("Weight used: ", solution.total_weight())
    print("Profit obtained: ", solution.total_profit())

    solution.print_solution()
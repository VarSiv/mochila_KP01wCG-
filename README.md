# El Problema

El Problema de la Mochila 0-1 con Grafo de Conflictos (KP01wCG) extiende el problema
clásico de la mochila (KP-01) al incorporar un conjunto de conflictos entre ítems. Formalmente,
se tiene un conjunto de ítems N = {1, . . . , n}, donde cada ítem i ∈ N tiene un beneficio
asociado pi > 0 y un peso wi > 0. Se dispone de una mochila con una capacidad máxima C, y
el objetivo es seleccionar un subconjunto de ítems que maximice el beneficio total sin superar
la capacidad C.

Además de esta restricción, se define un grafo de conflictos G = (N, E) sobre el conjunto de
ítems. Cada arista (i, j) ∈ E representa un conflicto entre los ítems i y j, lo que significa que
no pueden seleccionarse simultáneamente. Esta generalización modela diversos escenarios
del mundo real en los que los ítems están limitados no solo por el peso, sino también por
incompatibilidades mutuas.

Debido a su mayor complejidad, el KP01wCG requiere enfoques de solución especializados
que van más allá de los utilizados para el problema clásico KP01. Algoritmos exactos de
última generación para resolver este problema han sido propuestos recientemente en [1],
donde se desarrolla un algoritmo branch and bound para manejar de manera eficiente las
restricciones adicionales impuestas por el grafo de conflictos.

## Formateo de los datos

Para la realización del trabajo se contará con distintos conjuntos de instancias de características
diferentes para el KP01wCG. El formato de los archivos de entrada es el siguiente:
1. Primera línea: Número total de ítems, denotado como n.
2. Segunda línea: Capacidad de la mochila, denotada como C.
3. Tercera línea: Una secuencia de n enteros w1, w2, . . . , wn, donde cada wj representa el
peso del ítem j.
4. Cuarta línea: Una secuencia de n enteros p1, p2, . . . , pn, donde cada pj representa la
ganancia asociada al ítem j.
5. Quinta línea: Un entero m, que indica la cantidad de pares de ítems en conflicto.
6. Las siguientes m líneas: Cada línea contiene dos enteros u y v (0 ≤ u, v < n),
indicando que los ítems u y v están en conflicto y no pueden ser seleccionados simultáneamente
en la solución.

Ejemplo:
```
5
50
10 20 30 40 50
60 100 120 200 150
3
0 2
1 4
3 4
```

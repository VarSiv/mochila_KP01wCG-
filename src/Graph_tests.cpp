#include "Graph.h"
#include <gtest/gtest.h>
#include <iostream>

#include "Graph.h"
#include <gtest/gtest.h>

// Test del constructor y del método getN
TEST(GraphTest, Constructor) {
    Graph graph(5);
    EXPECT_EQ(graph.getN(), 5);
}

// Test para agregar y verificar aristas
TEST(GraphTest, AddEdge) {
    Graph graph(4);
    graph.addEdge(0, 1);
    EXPECT_TRUE(graph.isAdjacent(0, 1));
    EXPECT_TRUE(graph.isAdjacent(1, 0));
}

// Test para eliminar aristas
TEST(GraphTest, RemoveEdge) {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.removeEdge(0, 1);
    EXPECT_FALSE(graph.isAdjacent(0, 1));
    EXPECT_FALSE(graph.isAdjacent(1, 0));
}

// Test para evitar aristas de un nodo a sí mismo
TEST(GraphTest, SelfLoop) {
    Graph graph(3);
    EXPECT_THROW(graph.addEdge(0, 0), std::invalid_argument);
}

// Test para agregar múltiples aristas
TEST(GraphTest, MultipleEdges) {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(2, 3);
    graph.addEdge(1, 4);
    EXPECT_TRUE(graph.isAdjacent(0, 1));
    EXPECT_TRUE(graph.isAdjacent(2, 3));
    EXPECT_TRUE(graph.isAdjacent(1, 4));
    EXPECT_FALSE(graph.isAdjacent(0, 4));
}

// Test para eliminar una arista que no existe
TEST(GraphTest, RemoveNonExistingEdge) {
    Graph graph(4);
    EXPECT_NO_THROW(graph.removeEdge(1, 2));
    EXPECT_FALSE(graph.isAdjacent(1, 2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
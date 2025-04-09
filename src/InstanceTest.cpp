#include "KP01withCGInstance.h"
#include <gtest/gtest.h>

// Test 1: Constructor por defecto, la instancia debe estar vacía
TEST(KP01withCGInstanceTest, DefaultConstructor) {
    KP01withCGInstance instance;
    EXPECT_EQ(instance.getNumItems(), 0);
    EXPECT_EQ(instance.getCapacity(), 0);
}

// Test 2: Constructor con parámetros, crea una instancia con ítems y capacidad definida
TEST(KP01withCGInstanceTest, ParameterizedConstructor) {
    KP01withCGInstance instance(5, 50);
    EXPECT_EQ(instance.getNumItems(), 5);
    EXPECT_EQ(instance.getCapacity(), 50);
}

// Test 3: Asignar y devolver pesos correctamente
TEST(KP01withCGInstanceTest, SetGetWeight) {
    KP01withCGInstance instance(5, 50);
    instance.setWeight(0, 10);
    instance.setWeight(1, 20);
    EXPECT_EQ(instance.getWeight(0), 10);
    EXPECT_EQ(instance.getWeight(1), 20);
}

// Test 4: Asignar y devolver beneficios correctamente
TEST(KP01withCGInstanceTest, SetGetProfit) {
    KP01withCGInstance instance(5, 50);
    instance.setProfit(0, 60);
    instance.setProfit(1, 100);
    EXPECT_EQ(instance.getProfit(0), 60);
    EXPECT_EQ(instance.getProfit(1), 100);
}

// Test 5: Manejo de conflictos entre ítems
TEST(KP01withCGInstanceTest, ConflictManagement) {
    KP01withCGInstance instance(5, 50);
    instance.addConflict(0, 2);
    instance.addConflict(1, 4);
    EXPECT_TRUE(instance.isConflicting(0, 2));
    EXPECT_TRUE(instance.isConflicting(1, 4));
    EXPECT_FALSE(instance.isConflicting(2, 3));

    instance.removeConflict(1, 4);
    EXPECT_FALSE(instance.isConflicting(1, 4));
}

// Test 6: Lectura de instancia desde archivo
TEST(KP01withCGInstance, FileReading){
    KP01withCGInstance instance(0,0);
    instance.setInstance("instances/test_instance.in");
    EXPECT_EQ(instance.getProfit(1), 100);
    EXPECT_EQ(instance.getWeight(1), 20);
    EXPECT_EQ(instance.getCapacity(), 50);
    EXPECT_EQ(instance.getNumItems(), 5);
    EXPECT_TRUE(instance.isConflicting(2,4));
    EXPECT_FALSE(instance.isConflicting(0,4));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

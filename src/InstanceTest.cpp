#include "KP01withCGInstance.h"
#include <gtest/gtest.h>

// Test default constructor
TEST(KP01withCGInstanceTest, DefaultConstructor) {
    KP01withCGInstance instance;
    EXPECT_EQ(instance.getNumItems(), 0);
    EXPECT_EQ(instance.getCapacity(), 0);
}

// Test parameterized constructor
TEST(KP01withCGInstanceTest, ParameterizedConstructor) {
    KP01withCGInstance instance(5, 50);
    EXPECT_EQ(instance.getNumItems(), 5);
    EXPECT_EQ(instance.getCapacity(), 50);
}

// Test setting and getting weight
TEST(KP01withCGInstanceTest, SetGetWeight) {
    KP01withCGInstance instance(5, 50);
    instance.setWeight(0, 10);
    instance.setWeight(1, 20);
    EXPECT_EQ(instance.getWeight(0), 10);
    EXPECT_EQ(instance.getWeight(1), 20);
}

// Test setting and getting profit
TEST(KP01withCGInstanceTest, SetGetProfit) {
    KP01withCGInstance instance(5, 50);
    instance.setProfit(0, 60);
    instance.setProfit(1, 100);
    EXPECT_EQ(instance.getProfit(0), 60);
    EXPECT_EQ(instance.getProfit(1), 100);
}

// Test conflict management
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

//test reading from file
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

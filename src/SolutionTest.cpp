#include <gtest/gtest.h>
#include "Solution.h"

using namespace std;


// Test 1: Crear una solución vacía 
TEST(Solution_tests,test_nuevo_solucion_vacia) {
  Solution s(0);
  ASSERT_EQ(s.numItems(),0);
  ASSERT_EQ(s.totalProfit(),0);
  ASSERT_EQ(s.totalWeight(),0);
  ASSERT_EQ(s.getItemsVector().size(),0);
  ASSERT_EQ(s.isValidItems(),true);
}


// Test 2: Insertar una mochila vacía en una solución con ítems
TEST(Solution_tests,test_insertar_mochila_vacia) {
  Solution s(45);
  KP01withCGInstance mochila(0,0);
  s.setMochila(mochila);
  ASSERT_EQ(s.numItems(),0);
  ASSERT_EQ(s.totalProfit(),0);
  ASSERT_EQ(s.totalWeight(),0);
  ASSERT_EQ(s.getItemsVector().size(),0);
  ASSERT_EQ(s.isValidItems(),true);
}

// Test 3: Agregar un único ítem a la solución
TEST(Solution_tests,test_agregar_unico_elemento){
  Solution s(1);
  EXPECT_FALSE(s.contains(0));
  s.addItem(0);
  EXPECT_TRUE(s.contains(0));
}

// Test 4: Verificar que el beneficio total sea correcto al agregar ítems
TEST(Solution_tests,test_beneficio){
  KP01withCGInstance mochila(0,0);
  mochila.setInstance("instances/costo_peso_correlaciona_n20_star.txt");
  Solution s(0);
  s.setMochila(mochila);
  s.addItem(2);//g:6307
  s.addItem(6);//g:3149
  s.addItem(19);//g:277
  ASSERT_EQ(s.totalProfit(), 9733);
}

// Test 4: Verificar que el peso total sea correcto al agregar ítems
TEST(Solution_tests,test_peso){
  KP01withCGInstance mochila(0,0);
  mochila.setInstance("instances/costo_peso_correlaciona_n20_star.txt");
  Solution s(0);
  s.setMochila(mochila);
  s.addItem(2);//peso:4790 
  s.addItem(6);//peso:3124 
  s.addItem(19);//Peso:260
  ASSERT_EQ(s.totalWeight(), 8174);
}

// Test 6: Verificar que el vector donde se ve la selección de ítems sea correcto
TEST(Solution_tests,test_vector){
  Solution s(5);
  s.addItem(0);
  s.addItem(2);
  s.addItem(4);
  vector<bool> v={true, false,true,false,true};
  ASSERT_EQ(s.getItemsVector(),v);
}

// Test 7: Verificar que una solución sin conflictos sea válida
TEST(Solution_tests,test_solucion_valida){
  KP01withCGInstance mochila(0,0);
  mochila.setInstance("instances/costo_peso_correlaciona_n20_star.txt");
  Solution s(0);
  s.setMochila(mochila);
  s.addItem(4);
  s.addItem(9);
  s.addItem(0);
  EXPECT_TRUE(s.isValidItems());
}

// Test 8: Verificar que una solución con conflictos sea detectada como inválida
TEST(Solution_tests,test_solucion_no_valida){
  KP01withCGInstance mochila(0,0);
  mochila.setInstance("instances/costo_peso_correlaciona_n20_star.txt");
  Solution s(0);
  s.setMochila(mochila);
  s.addItem(4);
  EXPECT_TRUE(s.isValidItems());
  s.addItem(9);
  EXPECT_TRUE(s.isValidItems());
  s.addItem(8);
  EXPECT_FALSE(s.isValidItems());
}








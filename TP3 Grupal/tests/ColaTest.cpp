#include "gtest/gtest.h"
#include "Cola.hpp"

class ColaTest : public testing::Test {
protected:
    Cola<int> cola;
    int dato{};
};

TEST_F(ColaTest, Alta) {
    cola.alta(2);
    EXPECT_EQ(cola.primero(), 2);

    cola.alta(1);
    cola.alta(3);
    EXPECT_EQ(cola.primero(), 2);
}

TEST_F(ColaTest, PrimeroManejaColaVacia) {
    EXPECT_THROW(cola.primero(), ExcepcionCola);
}

TEST_F(ColaTest, Baja) {
    cola.alta(1);
    cola.alta(3);

    dato = cola.baja();
    EXPECT_EQ(dato, 1);
    EXPECT_EQ(cola.primero(), 3);
}

TEST_F(ColaTest, BajaManejaColaVacia) {
    EXPECT_THROW(cola.baja(), ExcepcionCola);
}

TEST_F(ColaTest, Tamanio) {
    EXPECT_EQ(cola.tamanio(), 0);

    cola.alta(1);
    cola.alta(2);
    cola.alta(3);
    EXPECT_EQ(cola.tamanio(), 3);

    cola.baja();
    EXPECT_EQ(cola.tamanio(), 2);
}

TEST_F(ColaTest, Vacio) {
    EXPECT_TRUE(cola.vacio());

    cola.alta(1);
    EXPECT_FALSE(cola.vacio());

    cola.baja();
    EXPECT_TRUE(cola.vacio());
}

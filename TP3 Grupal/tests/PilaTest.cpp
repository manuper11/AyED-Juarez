#include "gtest/gtest.h"
#include "Pila.hpp"

class PilaTest : public testing::Test {
protected:
    Pila<int> pila;
    int dato{};
};

TEST_F(PilaTest, Alta) {
    pila.alta(2);
    EXPECT_EQ(pila.primero(), 2);

    pila.alta(1);
    pila.alta(3);
    EXPECT_EQ(pila.primero(), 3);
}

TEST_F(PilaTest, PrimeroManejaPilaVacia) {
    EXPECT_THROW(pila.primero(), ExcepcionPila);
}

TEST_F(PilaTest, Baja) {
    pila.alta(1);
    pila.alta(3);

    dato = pila.baja();
    EXPECT_EQ(dato, 3);
    EXPECT_EQ(pila.primero(), 1);
}

TEST_F(PilaTest, BajaManejaPilaVacia) {
    EXPECT_THROW(pila.baja(), ExcepcionPila);
}

TEST_F(PilaTest, Tamanio) {
    EXPECT_EQ(pila.tamanio(), 0);

    pila.alta(1);
    pila.alta(2);
    pila.alta(3);
    EXPECT_EQ(pila.tamanio(), 3);

    pila.baja();
    EXPECT_EQ(pila.tamanio(), 2);
}

TEST_F(PilaTest, Vacio) {
    EXPECT_TRUE(pila.vacio());

    pila.alta(1);
    EXPECT_FALSE(pila.vacio());

    pila.baja();
    EXPECT_TRUE(pila.vacio());
}

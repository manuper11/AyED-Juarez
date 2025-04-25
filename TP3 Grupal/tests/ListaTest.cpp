#include "gtest/gtest.h"
#include "Lista.hpp"

class ListaTest : public testing::Test {
protected:
    Lista<int> lista;
    int dato{};

    void SetUp() override;
};

void ListaTest::SetUp() {
    lista.alta_final(10);
    lista.alta_final(7);
    lista.alta_final(3);
    lista.alta_final(13);
    lista.alta_final(16);
    lista.alta_final(11);
}

TEST_F(ListaTest, AltaPrincipio) {
    Lista<int> lista_;
    EXPECT_NO_THROW(lista_.alta_principio(2));
    EXPECT_NO_THROW(lista_.primero());
    EXPECT_EQ(lista_.primero(), 2);
}

TEST_F(ListaTest, AltaFinal) {
    Lista<int> lista_;
    EXPECT_NO_THROW(lista_.alta_final(2));
    EXPECT_NO_THROW(lista_.ultimo());
    EXPECT_EQ(lista_.ultimo(), 2);
}

TEST_F(ListaTest, BajaPrimero) {
    dato = lista.baja_primero();
    EXPECT_EQ(dato, 10);
    EXPECT_EQ(lista.primero(), 7);
    EXPECT_EQ(lista.ultimo(), 11);
}

TEST_F(ListaTest, BajaPrimeroManejaListaVacia) {
    Lista<int> lista_;
    EXPECT_THROW(lista_.baja_primero(), ExcepcionLista);
}

TEST_F(ListaTest, BajaUltimo) {
    dato = lista.baja_ultimo();
    EXPECT_EQ(dato, 11);
    EXPECT_EQ(lista.primero(), 10);
    EXPECT_EQ(lista.ultimo(), 16);
}

TEST_F(ListaTest, BajaUltimoManejaListaVacia) {
    Lista<int> lista_;
    EXPECT_THROW(lista_.baja_ultimo(), ExcepcionLista);
}

TEST_F(ListaTest, Insertar) {
    lista.insertar(5, 0);
    EXPECT_EQ(lista.primero(), 5);

    lista.insertar(3, 7);
    EXPECT_EQ(lista.ultimo(), 3);

    lista.insertar(9, 3);
    lista.reiniciar_cursor(true);
    for (int _ = 0; _ < 3; ++_) {
        lista.avanzar();
    }
    EXPECT_EQ(lista.elemento(), 9);
}

TEST_F(ListaTest, InsertarManejaIndiceMayor) {
    EXPECT_THROW(lista.insertar(4, 7), ExcepcionLista);
}

TEST_F(ListaTest, Eliminar) {
    dato = lista.eliminar(5);
    EXPECT_EQ(dato, 11);

    dato = lista.eliminar(0);
    EXPECT_EQ(dato, 10);

    dato = lista.eliminar(2);
    EXPECT_EQ(dato, 13);
}

TEST_F(ListaTest, EliminarManejaIndiceMayorOIgual) {
    EXPECT_THROW(lista.eliminar(6), ExcepcionLista);
}

TEST_F(ListaTest, Primero) {
    EXPECT_EQ(lista.primero(), 10);
}

TEST_F(ListaTest, PrimeroManejaListaVacia) {
    Lista<int> lista_;
    EXPECT_THROW(lista_.primero(), ExcepcionLista);
}

TEST_F(ListaTest, Ultimo) {
    EXPECT_EQ(lista.ultimo(), 11);
}

TEST_F(ListaTest, UltimoManejaListaVacia) {
    Lista<int> lista_;
    EXPECT_THROW(lista_.ultimo(), ExcepcionLista);
}

TEST_F(ListaTest, Tamanio) {
    EXPECT_EQ(lista.tamanio(), 6);
}

TEST_F(ListaTest, Vacio) {
    Lista<int> lista_;
    EXPECT_TRUE(lista_.vacio());

    EXPECT_FALSE(lista.vacio());
}

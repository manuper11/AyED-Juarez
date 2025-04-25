#include "gtest/gtest.h"
#include "Grafo.hpp"

class GrafoTest : public testing::Test {
protected:
    Grafo grafo;
    Camino resultado{};

    void generar_grafo();

    void probar_igualdad_vector(Vector<size_t> vector, std::vector<size_t> vector_esperado);
};

void GrafoTest::generar_grafo() {
    grafo = Grafo(7);
    grafo.agregar_arista(0, 1, 9);
    grafo.agregar_arista(0, 3, 7);
    grafo.agregar_arista(0, 2, 10);
    grafo.agregar_arista(1, 2, 8);
    grafo.agregar_arista(1, 5, 15);
    grafo.agregar_arista(2, 3, 9);
    grafo.agregar_arista(2, 5, 7);
    grafo.agregar_arista(3, 6, 25);
    grafo.agregar_arista(3, 5, 20);
    grafo.agregar_arista(5, 6, 12);
    grafo.agregar_arista(5, 4, 2);
    grafo.agregar_arista(2, 4, 12);
    grafo.agregar_arista(4, 6, 13);
}

void GrafoTest::probar_igualdad_vector(Vector<size_t> vector, std::vector<size_t> vector_esperado) {
    EXPECT_EQ(vector_esperado.size(), vector.tamanio());
    for (size_t i = 0; i < vector_esperado.size(); ++i) {
        EXPECT_EQ(vector_esperado[i], vector[i]);
    }
}

TEST_F(GrafoTest, CaminoMinimo) {
    generar_grafo();

    grafo.usar_floyd_warshall();
    resultado = grafo.obtener_camino_minimo(0, 6);
    probar_igualdad_vector(resultado.camino, {0, 2, 5, 6});
    EXPECT_EQ(resultado.costo_total, 29);

    grafo.usar_dijkstra();
    resultado = grafo.obtener_camino_minimo(0, 6);
    probar_igualdad_vector(resultado.camino, {0, 2, 5, 6});
    EXPECT_EQ(resultado.costo_total, 29);
}

#include "FloydWarshall.hpp"

FloydWarshall::FloydWarshall() {
}

Vector<size_t> FloydWarshall::calcular_camino_minimo(Matriz<bool>& matriz_adyacencia, Matriz<int>& matriz_pesos,
                                                     size_t origen, size_t destino, size_t vertices) {
    Matriz<int> camino(vertices);
    for (size_t i = 0; i < vertices; i++) {
        for (size_t j = 0; j < vertices; j++) {
            if (i != j && matriz_adyacencia(i, j)) {
                camino(i, j) = (int)i;
            } else {
                camino(i, j) = INFINITO;
            }
        }
    }
    for (size_t k = 0; k < vertices; k++) {
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                if (matriz_pesos(i, k) != INFINITO && matriz_pesos(k, j) != INFINITO && matriz_pesos(i, k) + matriz_pesos(k, j) < matriz_pesos(i, j)) {
                    matriz_pesos(i, j) = matriz_pesos(i, k) + matriz_pesos(k, j);
                    camino(i, j) = camino(k, j);
                }
            }
        }
    }
    Vector<size_t> camino_minimo;
    size_t vertice_actual = destino;
    if (matriz_pesos(origen, destino) == INFINITO) {
        return camino_minimo;
    }
    while (vertice_actual != origen) {
        camino_minimo.alta(vertice_actual, 0);
        vertice_actual = camino(origen, vertice_actual);
    }
    camino_minimo.alta(origen, 0);
    return camino_minimo;
}

FloydWarshall::~FloydWarshall() {
}

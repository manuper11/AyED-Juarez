#include "Dijkstra.hpp"

Dijkstra::Dijkstra() {
}

Vector<size_t> Dijkstra::calcular_camino_minimo(Matriz<bool>& matriz_adyacencia, Matriz<int>& matriz_pesos,
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
    size_t distancias[vertices];
    bool visitados[vertices];
    for (size_t i = 0; i < vertices; i++) {
        distancias[i] = INFINITO;
        visitados[i] = false;
    }
    distancias[origen] = 0;
    for (size_t i = 0; i < vertices - 1; i++) {
        size_t minimo = INFINITO;
        size_t minimo_indice = 0;
        for (size_t j = 0; j < vertices; j++) {
            if (!visitados[j] && distancias[j] <= minimo) {
                minimo = distancias[j];
                minimo_indice = j;
            }
        }
        size_t u = minimo_indice;
        visitados[u] = true;
        for (size_t v = 0; v < vertices; v++) {
            if (!visitados[v] && matriz_adyacencia(u, v) && distancias[u] != INFINITO && distancias[u] + matriz_pesos(u, v) < distancias[v]) {
                distancias[v] = distancias[u] + matriz_pesos(u, v);
                camino(v, origen) = (int)u;
            }
        }
    }
    Vector<size_t> camino_minimo;
    size_t vertice_actual = destino;
    if (distancias[destino] == INFINITO) {
        return camino_minimo;
    }
    while (vertice_actual != origen) {
        camino_minimo.alta(vertice_actual, 0);
        vertice_actual = camino(vertice_actual, origen);
    }
    camino_minimo.alta(origen, 0);
    return camino_minimo;
}

Dijkstra::~Dijkstra() {
}

#include "Grafo.hpp"
#include "FloydWarshall.hpp"
#include "Dijkstra.hpp"

Grafo::Grafo() {
    vertices = 0;
    algoritmo_camino_minimo = nullptr;
}

Grafo::Grafo(size_t cantidad_vertices) {
    matriz_adyacencia = Matriz(cantidad_vertices, false);
    matriz_pesos = Matriz(cantidad_vertices, INFINITO);
    vertices = cantidad_vertices;
    algoritmo_camino_minimo = nullptr;

    for (size_t i = 0; i < vertices; i++) {
        matriz_adyacencia(i, i) = true;
        matriz_pesos(i, i) = 0;
    }
}

int Grafo::calcular_costo_camino(Vector<size_t>& camino) {
    int peso = 0;
    if (camino.tamanio() > 1) {
        for (size_t i = 0; i < camino.tamanio() - 1; i++) {
            peso += matriz_pesos(camino[i], camino[i + 1]);
        }
    }
    return peso;
}

void Grafo::agregar_vertice() {
    vertices++;
    matriz_adyacencia.redimensionar(vertices, vertices);
    matriz_pesos.redimensionar(vertices, vertices);

    size_t nuevo_vertice = vertices - 1;
    aislar_vertice(nuevo_vertice);
    matriz_adyacencia(nuevo_vertice, nuevo_vertice) = true;
    matriz_pesos(nuevo_vertice, nuevo_vertice) = 0;
}

void Grafo::aislar_vertice(size_t vertice) {
    if (vertice >= vertices) {
        throw ExcepcionGrafo("ERROR: El vértice " + std::to_string(vertice) + " no es válido.");
    }
    for (size_t i = 0; i < vertices; i++) {
        if (i != vertice) {
            eliminar_arista(i, vertice);
            eliminar_arista(vertice, i);
        }
    }
}

void Grafo::agregar_arista(size_t origen, size_t destino, int peso) {
    if (origen >= vertices && destino >= vertices) {
        throw ExcepcionGrafo("ERROR: Los vértices " + std::to_string(origen) + " y " + std::to_string(destino) +
                             " no son válidos.");
    }
    matriz_adyacencia(origen, destino) = true;
    matriz_pesos(origen, destino) = peso;
}

void Grafo::eliminar_arista(size_t origen, size_t destino) {
    if (origen >= vertices && destino >= vertices) {
        throw ExcepcionGrafo("ERROR: Los vértices " + std::to_string(origen) + " y " + std::to_string(destino) +
                             " no son válidos.");
    }
    matriz_adyacencia(origen, destino) = false;
    matriz_pesos(origen, destino) = INFINITO;
}


void Grafo::usar_floyd_warshall() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new FloydWarshall();
}

void Grafo::usar_dijkstra() {
    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = new Dijkstra();
}

Camino Grafo::obtener_camino_minimo(size_t origen, size_t destino) {
    if (!algoritmo_camino_minimo) {
        throw ExcepcionGrafo("ERROR: No se indicó el algoritmo a usar.");
    }
    if (origen >= vertices && destino >= vertices) {
        throw ExcepcionGrafo("ERROR: Los vértices " + std::to_string(origen) + " y " + std::to_string(destino) +
                             " no son válidos.");
    }
    Vector<size_t> camino = algoritmo_camino_minimo->calcular_camino_minimo(
        matriz_adyacencia, matriz_pesos, origen, destino, vertices);
    return {camino, calcular_costo_camino(camino)};
}

Grafo::Grafo(const Grafo& grafo) {
    matriz_adyacencia = grafo.matriz_adyacencia;
    matriz_pesos = grafo.matriz_pesos;
    vertices = grafo.vertices;
    algoritmo_camino_minimo = nullptr;
}

Grafo& Grafo::operator=(const Grafo& grafo) {
    if (this != &grafo) {
        delete algoritmo_camino_minimo;
        matriz_adyacencia = grafo.matriz_adyacencia;
        matriz_pesos = grafo.matriz_pesos;
        vertices = grafo.vertices;
        algoritmo_camino_minimo = nullptr;
    }
    return *this;
}

Grafo::~Grafo() {
    delete algoritmo_camino_minimo;
}

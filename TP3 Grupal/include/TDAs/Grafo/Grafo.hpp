#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "CaminoMinimo.hpp"

class ExcepcionGrafo : public std::runtime_error {
public:
    ExcepcionGrafo(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionGrafo(): runtime_error("") {
    }
};

struct Camino {
    Vector<size_t> camino;
    int costo_total;
};

// Este grafo está implementado con una matriz de adyacencia.
// Para más información: https://es.wikipedia.org/wiki/Matriz_de_adyacencia
class Grafo {
private:
    Matriz<bool> matriz_adyacencia;
    Matriz<int> matriz_pesos;
    size_t vertices;
    CaminoMinimo* algoritmo_camino_minimo;

    // Pre: -
    // Post: Calcula y devuelve el costo total del camino.
    int calcular_costo_camino(Vector<size_t>& camino);

public:
    // Constructores.
    Grafo();

    Grafo(size_t cantidad_vertices);

    // Pre: -
    // Post: Agrega un nuevo vértice aislado al grafo.
    // NOTA: El número del vértice corresponde con el último índice agregado a las matrices.
    // Por ejemplo, si se tienen 5 vértices y se agrega uno más, ese vértice es el 5.
    void agregar_vertice();

    // Pre: El vértice debe ser válido.
    // Post: Aisla el vértice (es decir, elimina todas sus aristas).
    void aislar_vertice(size_t vertice);

    // Pre: Los vértices deben ser válidos.
    // Post: Agrega la arista desde origen a destino. Si la arista ya existía, la modifica.
    void agregar_arista(size_t origen, size_t destino, int peso);

    // Pre: Los vértices deben ser válidos.
    // Post: Elimina la arista desde origen a destino.
    void eliminar_arista(size_t origen, size_t destino);

    // Pre: -
    // Post: Selecciona el algoritmo de Floyd Warshall para calcular el camino mínimo.
    void usar_floyd_warshall();

    // Pre: -
    // Post: Selecciona el algoritmo de Dijkstra para calcular el camino mínimo.
    void usar_dijkstra();

    // Pre: Los vértices deben ser válidos.
    // Se debe haber seleccionado un algoritmo de camino mínimo.
    // Post: Devuelve el camino mínimo de origen a destino.
    Camino obtener_camino_minimo(size_t origen, size_t destino);

    // Constructor de copia.
    Grafo(const Grafo& grafo);

    // Operador de asignación.
    Grafo& operator=(const Grafo& grafo);

    ~Grafo();
};

#endif

#ifndef CAMINOMINIMO_HPP
#define CAMINOMINIMO_HPP

#include <cstddef>
#include "Matriz.hpp"
#include "Vector.hpp"

const int INFINITO = 999;

class CaminoMinimo {
public:
    // Pre: Las matrices deben ser cuadradas.
    // Origen y destino deben ser vértices válidos.
    // La cantidad de vertices debe corresponder con el tamaño de las matrices.
    // Post: Devuelve el camino mínimo desde el vértice origen al destino.
    virtual Vector<size_t>
    calcular_camino_minimo(Matriz<bool>& matriz_adyacencia,
                           Matriz<int>& matriz_pesos,
                           size_t origen,
                           size_t destino,
                           size_t vertices) = 0;

    virtual ~CaminoMinimo() = default;
};

#endif

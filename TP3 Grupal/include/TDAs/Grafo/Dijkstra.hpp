#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "CaminoMinimo.hpp"

class Dijkstra : public CaminoMinimo {
public:
    // Constructor.
    Dijkstra();

    Vector<size_t>
    calcular_camino_minimo(Matriz<bool>& matriz_adyacencia,
                           Matriz<int>& matriz_pesos,
                           size_t origen,
                           size_t destino,
                           size_t vertices) override;

    // Destructor.
    ~Dijkstra() override;
};

#endif

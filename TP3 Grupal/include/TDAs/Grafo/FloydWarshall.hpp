#ifndef FLOYDWARSHALL_HPP
#define FLOYDWARSHALL_HPP

#include "CaminoMinimo.hpp"

class FloydWarshall : public CaminoMinimo {
public:
    // Constructor.
    FloydWarshall();

    Vector<size_t>
    calcular_camino_minimo(Matriz<bool>& matriz_adyacencia,
                           Matriz<int>& matriz_pesos,
                           size_t origen,
                           size_t destino,
                           size_t vertices) override;

    // Destructor.
    ~FloydWarshall() override;
};

#endif

#ifndef GENERADORALEATORIO_HPP
#define GENERADORALEATORIO_HPP

#include <random>
#include <cstddef>
#include <stdexcept>

class ExcepcionPorcentajeNoValido : public std::runtime_error {
public:
    ExcepcionPorcentajeNoValido(std::string mensaje): runtime_error(mensaje) {
    }
};

class GeneradorAleatorio {
private:
    std::default_random_engine generador;
    std::uniform_int_distribution<> distribucion;

public:
    // Constructor.
    GeneradorAleatorio();

    // PRE: El porcentaje debe ser un número en el intervalo [0, 100].
    // POST: Devuelve true si la chance generada es exitosa,
    // con probabilidad indicada por el porcentaje.
    // Si el porcentaje es 0, siempre devuelve false.
    // Si el porcentaje es 100, siempre devuelve true.
    virtual bool generar_chance_porcentual(size_t porcentaje);

    // Destructor
    virtual ~GeneradorAleatorio() = default;
};

#endif

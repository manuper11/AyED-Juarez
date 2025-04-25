#include "GeneradorAleatorio.hpp"
#include <chrono>

GeneradorAleatorio::GeneradorAleatorio() {
    unsigned int semilla = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    generador = std::default_random_engine(semilla);
    distribucion = std::uniform_int_distribution(1, 100);
}

bool GeneradorAleatorio::generar_chance_porcentual(size_t porcentaje) {
    if (porcentaje > 100) {
        throw ExcepcionPorcentajeNoValido(
            "El porcentaje ingresado (" + std::to_string(porcentaje) +
            ") no es válido. Debe estar en el intervalo [0, 100].");
    }
    return static_cast<size_t>(distribucion(generador)) <= porcentaje;
}

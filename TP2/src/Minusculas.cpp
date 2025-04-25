#include "Minusculas.hpp"

std::string Minusculas::a_minusculas(std::string& mensaje) {
    std::transform(mensaje.begin(), mensaje.end(), mensaje.begin(), ::tolower);
    return mensaje;
}

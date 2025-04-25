#ifndef FUSIONADORENERGON_HPP
#define FUSIONADORENERGON_HPP

#include "GeneradorAleatorio.hpp"
#include "Cristal.hpp"
#include <stdexcept>

const size_t PORCENTAJE_COMUN = 50;
const size_t PORCENTAJE_RARO = 30;
const size_t PORCENTAJE_EPICO = 10;
const std::string MENSAJE_ERROR_FUSION_DISTINTAS = "Los cristales a fusionar deben ser de la misma rareza.";
const std::string MENSAJE_ERROR_FUSION_LEGENDARIO = "No se pueden fusionar cristales legendarios.";
const int FACTOR_FUSION_EXITOSA = 2;

class ExcepcionFusionadorEnergon : public std::runtime_error {
    /* Excepción específica y exclusiva para errores dentro del Fusionador.
    // Usar de la forma "throw ExcepcionFusionadorEnergon(mensaje);"
    // cuando una precondición no se cumpla.
    // Ejemplo:
    //     if (condicion_de_error) {
    //         throw ExcepcionFusionadorEnergon(mensaje);
    //     }
    // Pueden enviar por parámetro un mensaje descriptivo del error. */
public:
    ExcepcionFusionadorEnergon(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionFusionadorEnergon(): runtime_error("") {
    }
};

class FusionadorEnergon {
private:
//Atributos
    int contador_comun;
    int contador_raro;
    int contador_epico;
//Metodos
    //Pre: -
    //Post: Fusiona dos cristales de la misma rareza y devuelve uno con la rareza indicada
    Cristal fusionar_cristal(Cristal cristal_1, Cristal cristal_2, Rareza rareza);
public:
//Metodos
    //PRE: -
    //POST: Crea un objeto FusionadorEnergon con los contadores de fusiones en 0
    FusionadorEnergon();
    //PRE: -
    //POST: Fusiona dos cristales de la misma rareza y devuelve uno de rareza superior si el resultado es exitoso
    Cristal fusionar(Cristal cristal_1, Cristal cristal_2);
    //PRE: Las rarezas de los cristales deben ser iguales, la rareza de los cristales no puede ser LEGENDARIO y la rareza debe ser valida
    //POST: Fusiona dos cristales de la misma rareza y devuelve uno de rareza superior si el resultado es exitoso
    Cristal fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio& generador);
    //PRE: La probabilidad debe ser un numero en el intervalo [0, 100]
    //POST: Devuelve true si la fusion es exitosa, con probabilidad indicada por el porcentaje
    bool es_fusion_exitosa(int& contador, size_t porcentaje, GeneradorAleatorio& generador);
};

#endif
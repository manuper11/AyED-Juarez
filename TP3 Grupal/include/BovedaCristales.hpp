#ifndef BOVEDACRISTALES_HPP
#define BOVEDACRISTALES_HPP

#include <Cristal.hpp>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include "Vector.hpp"
#include "Menu.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"

const std::string ERROR_BOVEDA_LLENA = "La boveda esta llena";
const std::string ERROR_BOVEDA_VACIA = "La boveda esta vacia";
const std::string ERROR_POSICION_INVALIDA = "Posicion invalida";

class ExcepcionBovedaCristales : public std::runtime_error {
    // Excepción específica y exclusiva para errores dentro de la Bóveda.
    // Usar de la forma "throw ExcepcionBovedaCristales(mensaje);"
    // cuando una precondición no se cumpla.
    // Ejemplo:
    //     if (condicion_de_error) {
    //         throw ExcepcionBovedaCristales(mensaje);
    //     }
    // Pueden enviar por parámetro un mensaje descriptivo del error.
public:
    ExcepcionBovedaCristales(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionBovedaCristales(): runtime_error("") {
    }
};

class BovedaCristales {
private:
    Vector<Cristal> cristales;
    const size_t LIMITE_CRISTALES = 20;
public:
    //PRE: La boveda no puede estar llena
    //POST: Agrega un cristal al vector de cristales de la boveda
    void almacenar_cristal(Cristal cristal_nuevo);
    //PRE: La boveda no puede estar vacia
    //POST: Muestra por pantalla los cristales almacenados en la boveda
    void mostrar_cristales();
    //PRE: La boveda no puede estar vacia y la posicion debe ser menor a la cantidad de cristales almacenados
    //POST: Devuelve el cristal en la posicion indicada y lo elimina de la boveda
    Cristal obtener_cristal(size_t posicion);
    //PRE: -
    //POST: Exporta los cristales almacenados en la boveda a un archivo csv
    void exportar_cristales(std::string ruta);
    //PRE: La boveda no puede estar vacia
    //POST: Retorna el indice del cristal mas poderoso de la boveda.
    void cristal_mas_poderoso(bool personaje, OptimusPrime& optimus, Megatron& megatron);
    //PRE: La boveda no puede estar vacia
    //POST: Equipa un cristal de la boveda al personaje principal
    void equipar_cristal(bool personaje, OptimusPrime& optimus, Megatron& megatron);
    //PRE: -
    //POST: Muestra las estadisticas del cristal equipado en el personaje principal
    void mostrar_estadisticas_equipada(OptimusPrime& optimus, Megatron& megatron, bool personaje);
};

#endif
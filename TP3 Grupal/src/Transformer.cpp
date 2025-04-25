#include "../include/Transformer.hpp"
#include "Transformer.hpp"

Transformer::Transformer(std::string nombre,size_t fuerza,size_t defensa, size_t velocidad, bool faccion, size_t vehiculo, bool transformado){
    this->nombre = nombre;
    this->fuerza = fuerza_inicio = fuerza;
    this->defensa = defensa_inicio = defensa;
    this->velocidad = velocidad_inicio = velocidad;
    this->faccion = faccion;
    this->vehiculo = vehiculo;
    this->transformado = transformado;
}

size_t Transformer::obtener_defensa(){
    return defensa;
}

bool Transformer::obtener_faccion(){
    return faccion;
}

size_t Transformer::obtener_fuerza(){
    return fuerza;
}

std::string Transformer::obtener_nombre(){
    return nombre;
}

size_t Transformer::obtener_velocidad(){
    return velocidad;
}

size_t Transformer::obtener_vehiculo(){
    return vehiculo;
}

bool Transformer::esta_tranformado(){
    return transformado;
}

void Transformer::transformar(){
    transformado ? transformado = false : transformado = true;
    if (transformado) {
        switch (vehiculo) {
            case coche:
                fuerza /= 2;
                defensa /= 2;
                velocidad *= 4;
                break;
            case camion:
                fuerza = (fuerza*15)/10;
                defensa = (defensa*15)/10;
                velocidad /= 2;
                break;
            case tanque:
                fuerza *= 2;
                defensa *= 2;
                velocidad = 0;
                break;
            case avion:
                fuerza *= 2;
                defensa = 0;
                velocidad *= 2;
                break;
            default:
                break;
        }
    } else {
        fuerza = fuerza_inicio;
        defensa = defensa_inicio;
        velocidad = velocidad_inicio;
    }
}

size_t Transformer::obtener_poder()
{
    return fuerza + velocidad + defensa;
}
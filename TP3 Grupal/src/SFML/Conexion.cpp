//
// Created by mauro on 20/11/24.
//

#include "SFML/Conexion.hpp"

Conexion::Conexion() : _nodo1(0), _nodo2(0) {} // Definición del constructor por defecto

Conexion::Conexion(size_t nodo1, size_t nodo2){
    _nodo1 = nodo1;
    _nodo2 = nodo2;
}

size_t Conexion::obtenerNodoOrigen() const{
    return _nodo1;
}

size_t Conexion::obtenerNodoDestino() const{
    return _nodo2;
}
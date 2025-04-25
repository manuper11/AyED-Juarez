//
// Created by mauro on 20/11/24.
//

#ifndef CONEXION_H
#define CONEXION_H

#include <string.h>

class Conexion {
private:
    size_t _nodo1;
    size_t _nodo2;
public:
//Metodos
    //Constructor
    Conexion();
    //Constructor con parametros
    Conexion(size_t nodo1, size_t nodo2);
    // Getter para el nodo origen
    size_t obtenerNodoOrigen() const;
    // Getter para el nodo destino
    size_t obtenerNodoDestino() const;
};



#endif //CONEXION_H

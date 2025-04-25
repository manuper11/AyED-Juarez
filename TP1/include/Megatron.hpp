#ifndef TP1_2C2024_MEGATRON_HPP
#define TP1_2C2024_MEGATRON_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include "Funciones.hpp"

class Megatron {
private:
    std::string intencion;
    //PRE: El atributo intencion debe ser "desprecio"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_desprecio(std::string mensaje);
    //PRE: El atributo intencion debe ser "manipulacion"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_manipulacion(std::string mensaje);
    //PRE: El atributo intencion debe ser "amenaza"
    //POST: Imprime en pantalla una respuesta aleatoria entre 2 predefinidas sin importar el mensaje ingresado
    void procesar_respuesta_amenaza(std::string mensaje);
    //PRE: -
    //POST: Verifica que el string ingresado se encuentra entre las opciones dadas para modificar intencion
    bool validar_intencion(std::string intencion);
public:
    //PRE: -
    //POST: Crea un objeto Megatron con el atributo intencion en "desprecio"
    Megatron();
    //PRE: -
    //POST: Transforma el mensaje ingresado a minusculas para que sea utilizado por los otros metodos
    //      y segun la intencion actual procesa una respuesta
    void responder(std::string mensaje);
    //PRE: -
    //POST: Muestra en pantalla una sugerencia de fusion basada en la intencion actual
    void sugerir_fusion();
    //PRE: -
    //POST: Actualiza el atributo intencion de Megatron por la intencion ingresada
    void cambiar_intencion(std::string intencion);
    //PRE: El objeto funciones debe estar inicializado
    //POST: Cambia la intencion de Megatron, procesa su respuesta y sugiere una fusion
    void procesar(Funciones funciones);
};

#endif
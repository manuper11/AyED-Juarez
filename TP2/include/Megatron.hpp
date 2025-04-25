#ifndef TP1_2C2024_MEGATRON_HPP
#define TP1_2C2024_MEGATRON_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include "Menu.hpp"
#include "Minusculas.hpp"

const std::string RESPUESTA_DESPRECIO_OPTIMUS_PRIME_AUTOBOTS = "Esos debiles seran aplastados bajo mi yugo.";

const std::string RESPUESTA_MANIPULACION_PODER_ALIADO = "Unete a mi, y juntos gobernaremos este universo.";
const std::string SOLICITUD_INTENCION = "Ingrese la intención (1: desprecio / 2: manipulacion / 3: amenaza): ";
const std::string ERROR_INTENCION_INVALIDA = "Intencion invalida. Estableciendo desprecio por defecto.";

enum Intencion {
    DESPRECIO,
    MANIPULACION,
    AMENAZA
};
class Megatron {
private:
//Atributos
    Intencion intencion;
//Metodos
    //PRE: El atributo intencion debe ser "desprecio"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_desprecio(std::string& mensaje);
    //PRE: El atributo intencion debe ser "manipulacion"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_manipulacion(std::string& mensaje);
    //PRE: El atributo intencion debe ser "amenaza"
    //POST: Imprime en pantalla una respuesta aleatoria entre 2 predefinidas sin importar el mensaje ingresado
    void procesar_respuesta_amenaza(std::string& mensaje);
    //PRE: -
    //POST: Procesa la opcion 1 ingresada en el menu de opciones de Megatron
    void Opcion_1();
    //PRE: -
    //POST: Procesa la opcion 2 ingresada en el menu de opciones de Megatron
    void Opcion_2(Menu& Menu);
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
    //PRE: El objeto Menu debe estar inicializado
    //POST: Cambia la intencion de Megatron, procesa su respuesta y sugiere una fusion
    void procesar(Menu& Menu);
    //PRE: -
    //POST: Devuelve la intencion de Megatron en formato tipo string
    std::string char_a_string_intencion (char intencion);
};

#endif
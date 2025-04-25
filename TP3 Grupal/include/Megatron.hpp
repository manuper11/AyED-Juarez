#ifndef TP1_2C2024_MEGATRON_HPP
#define TP1_2C2024_MEGATRON_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include "Menu.hpp"
#include "Minusculas.hpp"
#include "Cristal.hpp"

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
    int fuerza = 40;
    int defensa = 40;
    int velocidad = 40;
    bool transformado = 0;
    bool cristal_equipado = false;
    int fuerza_equipada = 0;
    int velocidad_equipada = 0;
    int defensa_equipada = 0;
    int velocidad_inicial;
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
    //PRE: -
    //POST: Devuelve la intencion de Megatron en formato tipo string
    std::string char_a_string_intencion (char intencion);
    //PRE: -
    //POST: Procesa la opcion 1 ingresada en el menu de opciones de Megatron
    void Opcion_1();
    //PRE: -
    //POST: Suma todas las estadisticas de Megatron y las devuelve
    size_t poder();
    //PRE: -
    //POST: Equipa un cristal
    void equipar_cristal(Cristal cristal);
    //PRE: -
    //POST: Devuelve la fuerza de Megatron
    size_t get_fuerza();
    //PRE: -
    //POST: Devuelve la defensa de Megatron
    size_t get_defensa();
    //PRE: -
    //POST: Devuelve la velocidad de Megatron
    size_t get_velocidad();
    //PRE: -
    //POST: Devuelve si Megatron esta transformado
    bool get_transformado();
    //PRE: -
    //POST: Elimina las estadisticas del cristal equipado anteriormente
    void desequipar_cristal();
    //PRE: -
    //POST: Muestra las estadisticas del cristal equipado
    void mostrar_estadisticas_equipada();
    //PRE: -
    //POST: Transforma a Megatron
    void transformar();
};

#endif
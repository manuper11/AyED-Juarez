#ifndef TP1_2C2024_OPTIMUS_PRIME_HPP
#define TP1_2C2024_OPTIMUS_PRIME_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include "Menu.hpp"
#include "Minusculas.hpp"

const std::string RESPUESTA_SERENO_MEGATRON_DECEPTICONS = "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";

const std::string RESPUESTA_DETERMINADO_MEGATRON_DECEPTICONS = "Megatron sera detenido. No hay alternativa.";
const std::string SOLICITUD_ANIMO = "Ingrese el estado de animo (1: sereno / 2: determinado / 3: enfurecido): ";
const std::string ERROR_ANIMO_INVALIDO = "Animo invalido. Estableciendo sereno por defecto.";

enum Animo {
    SERENO,
    DETERMINADO,
    ENFURECIDO
};
class OptimusPrime {
private:
//Atributos
    Animo estado_animo;
//Metodos
    //PRE: El atributo animo debe ser "sereno"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_sereno(std::string& mensaje);
    //PRE: El atributo animo debe ser "determinado"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_determinado(std::string& mensaje);
    //PRE: El atributo animo debe ser "enfurecido"
    //POST: Imprime en pantalla una respuesta aleatoria entre 2 predefinidas sin importar el mensaje ingresado
    void procesar_respuesta_enfurecido(std::string& mensaje);
    //PRE: -
    //POST: Procesa la opcion 1 ingresada en el menu de opciones de Optimus Prime
    void Opcion_1();
    //PRE: -
    //POST: Procesa la opcion 2 ingresada en el menu de opciones de Optimus Prime
    void Opcion_2(Menu& menu);
public:
    //PRE: -
    //POST: Crea un objeto OptimusPrime con el atributo estado_animo en sereno
    OptimusPrime();
    //PRE: -
    //POST: Transforma el mensaje ingresado a minusculas para que sea utilizado por los otros metodos y
    //      segun el estado_animo actual procesa una respuesta
    void responder(std::string mensaje);
    //PRE: -
    //POST: Muestra en pantalla una sugerencia de fusion basada en el estado_animo actual
    void sugerir_fusion();
    //PRE: -
    //POST: Actualiza el atributo estado_animo de OptimusPrime por el string ingresado
    void cambiar_animo(std::string animo);
    //PRE: El objeto menu debe estar inicializado
    //POST: Cambia el estado de animo de Optimus, procesa su respuesta y sugiere una fusion
    void procesar(Menu& menu);
    //PRE: -
    //POST: Devuelve el estado de animo de Optimus en formato tipo string
    std::string char_a_string_animo (char animo);
};

#endif
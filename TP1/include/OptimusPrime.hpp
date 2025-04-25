#ifndef TP1_2C2024_OPTIMUS_PRIME_HPP
#define TP1_2C2024_OPTIMUS_PRIME_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include "Funciones.hpp"

class OptimusPrime {
private:
    std::string estado_animo;
    //PRE: El atributo animo debe ser "sereno"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_sereno(std::string mensaje);
    //PRE: El atributo animo debe ser "determinado"
    //POST: Imprime en pantalla una respuesta dependiendo del contenido del mensaje
    void procesar_respuesta_determinado(std::string mensaje);
    //PRE: El atributo animo debe ser "enfurecido"
    //POST: Imprime en pantalla una respuesta aleatoria entre 2 predefinidas sin importar el mensaje ingresado
    void procesar_respuesta_enfurecido(std::string mensaje);
    //PRE: -
    //POST: Verifica que el string ingresado se encuentra entre las opciones dadas para modificar estado_animo
    bool validar_animo(std::string animo);
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
    //PRE: El objeto funciones debe estar inicializado
    //POST: Cambia el estado de animo de Optimus, procesa su respuesta y sugiere una fusion
    void procesar(Funciones funciones);
};

#endif
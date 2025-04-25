#ifndef TP1_2C2024_FUNCIONES_HPP
#define TP1_2C2024_FUNCIONES_HPP

#include <iostream>
#include "Megatron.hpp"
#include "OptimusPrime.hpp"

const std::string COLOR_POR_DEFECTO = "\e[0m";
const std::string SUBRAYADO_AMARILLO = "\e[4;43;1;37m";
const std::string LETRA_EN_NEGRITA = "\e[1;37m";
const std::string RESALTADO_AZUL = "\e[44;1;37m";
const std::string RESALTADO_GRIS = "\e[100m";
const int OPCION_OPTIMUS = '1';
const int OPCION_MEGATRON = '2';
const std::string ERROR_VALIDACION = "Error al ingresar el valor. Intente nuevamente.\n";

class Funciones {
public:
    //PRE: -
    //POST: Crea un objeto Funciones
    Funciones();
    //PRE: -
    //POST: Imprime por pantalla el titulo del programa
    void imprimir_titulo();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones para elegir con quien interactuar
    void imprimir_menu_principal();
    //PRE: Opcion debe ser un valor valido entre las opciones dadas (1, 2 y 3)
    //POST: Procesa y muestra en pantalla las respuestas de los metodos asociados a Optimus o Megatron
    void procesar_respuestas(OptimusPrime optimus, Megatron megatron);
    //PRE: -
    //POST: Devuelve el mensaje ingresado por el usuario en un string
    std::string pedir_mensaje();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones de Optimus Prime
    void imprimir_menu_optimus();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones de Megatron
    void imprimir_menu_megatron();
};

#endif
#ifndef TP1_2C2024_Menu_HPP
#define TP1_2C2024_Menu_HPP

#include <iostream>

const std::string COLOR_POR_DEFECTO = "\e[0m";
const std::string SUBRAYADO_AMARILLO = "\e[4;43;1;37m";
const std::string LETRA_EN_NEGRITA = "\e[1;37m";
const std::string RESALTADO_AZUL = "\e[44;1;37m";
const std::string RESALTADO_GRIS = "\e[100;1;37m";
const std::string RESALTADO_AMARILLO = "\e[43;1;37m"; 
const std::string RESALTADO_VIOLETA = "\e[48;5;93;1;37m";
const int OPCION_OPTIMUS = '1';
const int OPCION_MEGATRON = '2';
const int OPCION_BOVEDA = '1';
const int OPCION_ROBOTS = '2';
const std::string ERROR_VALIDACION = "Error al ingresar el valor. Intente nuevamente.\n";

class Menu {
public:
//Metodos
    //PRE: -
    //POST: Crea un objeto Menu
    Menu();
    //PRE: -
    //POST: Imprime por pantalla el titulo del programa
    void imprimir_titulo();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones para elegir con quien interactuar
    void imprimir_menu_principal();
    //PRE: -
    //POST: Devuelve el mensaje ingresado por el usuario en un string
    std::string pedir_mensaje();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones de Optimus Prime
    void imprimir_menu_optimus();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones de Megatron
    void imprimir_menu_megatron();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones de los robots
    void imprimir_menu_robots();
    //PRE: -
    //POST: Imprime por pantalla el menu de opciones de la boveda
    void imprimir_menu_boveda();
};

#endif
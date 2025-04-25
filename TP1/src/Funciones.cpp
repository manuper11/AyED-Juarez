#include "Funciones.hpp"

Funciones::Funciones() {
}

void Funciones::imprimir_titulo(){
    std::cout <<'\n' <<
    "\e[41m████████╗██████╗░░█████╗░███╗░░██╗░██████╗███████╗░█████╗░██████╗░███╗░░░███╗███████╗██████╗░░██████╗\e[0m\n"
    "\e[41m╚══██╔══╝██╔══██╗██╔══██╗████╗░██║██╔════╝██╔════╝██╔══██╗██╔══██╗████╗░████║██╔════╝██╔══██╗██╔════╝\e[0m\n"
    "\e[47m░░░██║░░░██████╔╝███████║██╔██╗██║╚█████╗░█████╗░░██║░░██║██████╔╝██╔████╔██║█████╗░░██████╔╝╚█████╗░\e[0m\n"
    "\e[47m░░░██║░░░██╔══██╗██╔══██║██║╚████║░╚═══██╗██╔══╝░░██║░░██║██╔══██╗██║╚██╔╝██║██╔══╝░░██╔══██╗░╚═══██╗\e[0m\n"
    "\e[44m░░░██║░░░██║░░██║██║░░██║██║░╚███║██████╔╝██║░░░░░╚█████╔╝██║░░██║██║░╚═╝░██║███████╗██║░░██║██████╔╝\e[0m\n"
    "\e[44m░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░╚═╝░░░░░░╚════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚═╝╚═════╝░\e[0m" << std::endl;
}

void Funciones::imprimir_menu_principal() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << SUBRAYADO_AMARILLO << "\t============ MENU ============" << COLOR_POR_DEFECTO << std::endl
              << std::endl << LETRA_EN_NEGRITA << "\tCon quien desea interactuar?" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_AZUL << "\t(1) Optimus Prime" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_GRIS << "\t(2) Megatron" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t(3) Salir" << std::endl
              << std::endl;
}

void Funciones::imprimir_menu_optimus() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << RESALTADO_AZUL << "\tQue deberia hacer Optimus Prime?" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "(1) Cambiar su estado de animo\n"
              << "(2) Enviar mensajes\n"
              << "(3) Sugerir fusion\n"
              << "(4) Salir al menu principal\n" << std::endl;
}

void Funciones::imprimir_menu_megatron() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << RESALTADO_GRIS << "\tQue desea hacer con Megatron?" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "(1) Cambiar intencion\n"
              << "(2) Enviar mensajes\n"
              << "(3) Sugerir fusion\n"
              << "(4) Salir al menu principal\n" << std::endl;
}

void Funciones::procesar_respuestas(OptimusPrime optimus, Megatron megatron) {
    char opcion;
    do {
        imprimir_menu_principal();
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;
        if (opcion == OPCION_OPTIMUS) {
            optimus.procesar(*this);
        } else if (opcion == OPCION_MEGATRON) {
            megatron.procesar(*this);
        } else if (opcion != '3') {
            std::cout << "Opcion no valida. Intente nuevamente.\n";
        } else {
            std::cout << "Gracias por jugar! Hasta la proxima." << std::endl;
        }
    } while (opcion != '3');
}

std::string Funciones::pedir_mensaje() {
    std::string mensaje;
    std::cout << "Ingrese el mensaje: ";
    std::getline(std::cin, mensaje);
    return mensaje;
}
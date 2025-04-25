#include "Menu.hpp"

Menu::Menu() {
}

void Menu::imprimir_titulo(){
    std::cout <<'\n' <<
    "\e[41m████████╗██████╗░░█████╗░███╗░░██╗░██████╗███████╗░█████╗░██████╗░███╗░░░███╗███████╗██████╗░░██████╗\e[0m\n"
    "\e[41m╚══██╔══╝██╔══██╗██╔══██╗████╗░██║██╔════╝██╔════╝██╔══██╗██╔══██╗████╗░████║██╔════╝██╔══██╗██╔════╝\e[0m\n"
    "\e[47m░░░██║░░░██████╔╝███████║██╔██╗██║╚█████╗░█████╗░░██║░░██║██████╔╝██╔████╔██║█████╗░░██████╔╝╚█████╗░\e[0m\n"
    "\e[47m░░░██║░░░██╔══██╗██╔══██║██║╚████║░╚═══██╗██╔══╝░░██║░░██║██╔══██╗██║╚██╔╝██║██╔══╝░░██╔══██╗░╚═══██╗\e[0m\n"
    "\e[44m░░░██║░░░██║░░██║██║░░██║██║░╚███║██████╔╝██║░░░░░╚█████╔╝██║░░██║██║░╚═╝░██║███████╗██║░░██║██████╔╝\e[0m\n"
    "\e[44m░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░╚═╝░░░░░░╚════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚═╝╚═════╝░\e[0m" << std::endl;
}

void Menu::imprimir_menu_principal() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << SUBRAYADO_AMARILLO << "\t============ MENU PRINCIPAL ============" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\tBienvenido! Con que desea interactuar?" << std::endl
              << "\t----------------------------------" << std::endl
              << "\t(1) Boveda: Gestiona tu boveda y fusiona cristales" << std::endl
              << "\t(2) Robots: Conversa con Optimus Prime o Megatron" << std::endl
              << "\t(3) Salir" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}

void Menu::imprimir_menu_boveda() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << SUBRAYADO_AMARILLO << LETRA_EN_NEGRITA <<  "\t============ Que desea hacer en la boveda? ============" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t----------------------------------" << std::endl 
              << "\t(1) Almacenar cristal" << std::endl
              << "\t(2) Mostrar cristales almacenados" << std::endl
              << "\t(3) Exportar cristales" << std::endl
              << "\t(4) Fusionar cristales" << std::endl
              << "\t(5) Volver al menu principal" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}

void Menu::imprimir_menu_robots() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << SUBRAYADO_AMARILLO << LETRA_EN_NEGRITA << "\t============ Con quien desea interactuar? ============" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t----------------------------------" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_AZUL << "\t(1) Optimus Prime" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_GRIS << "\t(2) Megatron" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t(3) Volver al menu principal" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija un robot: ";
}

void Menu::imprimir_menu_optimus() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_AZUL << "\t===== Que desea que haga Optimus Prime? =====" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t----------------------------------" << std::endl
              << "(1) Cambiar su estado de animo" << std::endl
              << "(2) Enviar mensajes" << std::endl
              << "(3) Sugerir fusion" << std::endl
              << "(4) Volver al menu de seleccion" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}

void Menu::imprimir_menu_megatron() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_GRIS << "\t===== Que desea que haga Megatron? =====" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t----------------------------------" << std::endl
              << "(1) Cambiar intencion" << std::endl
              << "(2) Enviar mensajes" << std::endl 
              << "(3) Sugerir fusion" << std::endl
              << "(4) Volver al menu de seleccion" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}

std::string Menu::pedir_mensaje() {
    std::string mensaje;
    std::cout << "Ingrese el mensaje: ";
    std::getline(std::cin, mensaje);
    return mensaje;
}
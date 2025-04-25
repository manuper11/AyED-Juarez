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
              << LETRA_EN_NEGRITA << "\tBienvenido! Que desea hacer?" << std::endl
              << "\t----------------------------------" << std::endl
              << "\t(1) Cambiar personaje principal: Elige entre jugar con Optimus Prime o Megatron" << std::endl
              << "\t(2) Conversa con Optimus Prime o Megatron" << std::endl
              << "\t(3) Administra cristales: Almacena, muestra, fusiona y equipa cristales" << std::endl
              << "\t(4) Administrar Transformers: Crea y elimina transformers para la batalla final" << std::endl
              << "\t(5) Jugar: Inicia la batalla final" << std::endl
              << "\t(6) Mostrar tabla de clasificacion" << std::endl
              << "\t(0) Salir" << std::endl
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
              << "\t(5) Ver cristal mas poderoso cristales" << std::endl
              << "\t(6) Equipar cristales" << std::endl
              << "\t(0) Volver al menu principal" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}

void Menu::imprimir_menu_optimus() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << LETRA_EN_NEGRITA << RESALTADO_AZUL << "\t===== Que desea que haga Optimus Prime? =====" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t----------------------------------" << std::endl
              << "(1) Cambiar su estado de animo" << std::endl
              << "(2) Enviar mensajes" << std::endl
              << "(3) Sugerir fusion" << std::endl
              << "(0) Volver al menu de seleccion" << std::endl
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
              << "(0) Volver al menu de seleccion" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}

std::string Menu::pedir_mensaje() {
    std::string mensaje;
    std::cout << "Ingrese el mensaje: ";
    std::getline(std::cin, mensaje);
    return mensaje;
}

void Menu::imprimir_menu_transformers() {
    std::cout << COLOR_POR_DEFECTO << std::endl << std::endl
              << SUBRAYADO_AMARILLO << LETRA_EN_NEGRITA <<  "\t============ Menu de gestion de Transformers ============" << COLOR_POR_DEFECTO << std::endl
              << LETRA_EN_NEGRITA << "\t----------------------------------" << std::endl 
              << "\t(1) Agregar un nuevo Transformer" << std::endl
              << "\t(2) Mostrar todos los Transformers" << std::endl
              << "\t(3) Buscar un Transformer por nombre" << std::endl
              << "\t(4) Eliminar un Transformer por nombre" << std::endl
              << "\t(5) Transformar un Transformer" << std::endl
              << "\t(0) Volver al menu principal" << std::endl
              << "\t----------------------------------" << std::endl << std::endl
              << "Elija una opcion: ";
}
#include "GestorBoveda.hpp"

GestorBoveda::GestorBoveda(Menu& menu, BovedaCristales& boveda) : boveda(boveda), menu(menu) {
}

void GestorBoveda::almacenar_cristal() {
    try {
        std::cout << "Almacenando un nuevo cristal..." << std::endl;
        Cristal nuevo_cristal(COMUN);
        boveda.almacenar_cristal(nuevo_cristal);
        std::cout << "Cristal de rareza COMUN almacenado correctamente." << std::endl;
    } catch (const ExcepcionBovedaCristales& e) {
        std::cout << "Error: " << e.what() << std::endl; // Muestra el mensaje de error
    }
}

void GestorBoveda::mostrar_cristales() {
    try {
        std::cout << "Cristales almacenados: " << std::endl;
        boveda.mostrar_cristales();
    } catch (const ExcepcionBovedaCristales& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void GestorBoveda::exportar_cristales() {
    try {
        boveda.exportar_cristales(RUTA_ARCHIVO);
        std::cout << "Cristales exportados exitosamente a: " << RUTA_ARCHIVO << std::endl;
    } catch (const ExcepcionBovedaCristales& e) {
        std::cerr << "Error al exportar los cristales: " << e.what() << std::endl;
    }
}

void GestorBoveda::fusionar_cristales() {
    FusionadorEnergon fusionador;
    size_t pos1, pos2;
    Cristal fusion_cristal_1, fusion_cristal_2;
    mostrar_cristales();
    std::cout << "Selecciona la posicion del primer cristal: ";
    std::cin >> pos1;
    try {
        fusion_cristal_1 = boveda.obtener_cristal(pos1);
    } catch (const ExcepcionVector& e) {
        std::cout << "Error: " << e.what() << std::endl;
        boveda.almacenar_cristal(fusion_cristal_1);
        return;
    }
    mostrar_cristales();
    std::cout << "Selecciona la posicion del segundo cristal: ";
    std::cin >> pos2;
    try {
        fusion_cristal_2 = boveda.obtener_cristal(pos2);
    } catch (const ExcepcionVector& e) {
        std::cout << "Error: " << e.what() << std::endl;
        boveda.almacenar_cristal(fusion_cristal_1);
        return;
    }
    try {
        Cristal resultado = fusionador.fusionar(fusion_cristal_1, fusion_cristal_2);
        std::cout << "Resultado de la fusión: Cristal de rareza " << resultado.rareza_a_string() << std::endl;
        boveda.almacenar_cristal(resultado);
    } catch (const ExcepcionFusionadorEnergon& e) {
        std::cout << "Error: " << e.what() << std::endl;
        boveda.almacenar_cristal(fusion_cristal_1);
        boveda.almacenar_cristal(fusion_cristal_2);
    }
}
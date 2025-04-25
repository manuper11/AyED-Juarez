#include "BovedaCristales.hpp"

void BovedaCristales::almacenar_cristal(Cristal cristal_nuevo) {
    if (cristales.tamanio() == LIMITE_CRISTALES) {
        throw ExcepcionBovedaCristales(ERROR_BOVEDA_LLENA);
    }
    cristales.alta(cristal_nuevo);
}

void BovedaCristales::mostrar_cristales() {
    if (cristales.vacio()) {
        throw ExcepcionBovedaCristales(ERROR_BOVEDA_VACIA);
    }
    for (size_t i = 0; i < cristales.tamanio(); i++) {
        std::string color_fondo;
        switch (cristales[i].obtener_rareza()) {
            case COMUN:
                color_fondo = RESALTADO_GRIS;
                break;
            case RARO:
                color_fondo = RESALTADO_AZUL; 
                break;
            case EPICO:
                color_fondo = RESALTADO_VIOLETA;
                break;
            case LEGENDARIO:
                color_fondo = RESALTADO_AMARILLO;
                break;
            default:
                color_fondo = COLOR_POR_DEFECTO;
        }
        std::cout << std::endl << color_fondo << "Cristal " << i << ": " << cristales[i].rareza_a_string() << COLOR_POR_DEFECTO << std::endl
                  << LETRA_EN_NEGRITA << "Fuerza: " << cristales[i].get_estadistica_fuerza() << " "
                  << "Velocidad: " << cristales[i].get_estadistica_velocidad() << " "
                  << "Defensa: " << cristales[i].get_estadistica_defensa() << std::endl;
    }
}

Cristal BovedaCristales::obtener_cristal(size_t posicion) {
    if (cristales.vacio()) {
        throw ExcepcionBovedaCristales(ERROR_BOVEDA_VACIA);
    }
    if (posicion >= cristales.tamanio()) {
        throw ExcepcionBovedaCristales(ERROR_POSICION_INVALIDA);
    }
    Cristal cristal = cristales[posicion];
    cristales.baja(posicion);
    return cristal;
}


void BovedaCristales::exportar_cristales(std::string ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        throw ExcepcionBovedaCristales("No se pudo abrir el archivo.");
    }
    archivo << "Rareza;Fuerza;Velocidad;Defensa" << std::endl;
    for (size_t i = 0; i < cristales.tamanio(); i++) {
        archivo << cristales[i].rareza_a_string() << ";";
        archivo << cristales[i].get_estadistica_fuerza() << ";";
        archivo << cristales[i].get_estadistica_velocidad() << ";";
        archivo << cristales[i].get_estadistica_defensa() << std::endl;
    }
    archivo.close();
}
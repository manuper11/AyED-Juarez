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
                  << LETRA_EN_NEGRITA << "Fuerza: " << cristales[i].get_estadistica_fuerza() << " | Velocidad: " << cristales[i].get_estadistica_velocidad() << " | Defensa: " << cristales[i].get_estadistica_defensa() << std::endl;
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

void BovedaCristales::cristal_mas_poderoso(bool personaje, OptimusPrime& optimus, Megatron& megatron) {
    if (cristales.vacio()) {
        throw ExcepcionBovedaCristales(ERROR_BOVEDA_VACIA);
    }
    Cristal cristal_poderoso = cristales[0];
    size_t indice_cristal_poderoso = 0;
    for (size_t i = 1; i < cristales.tamanio(); i++) {
        if (cristales[i].poder() > cristal_poderoso.poder()) {
            cristal_poderoso = cristales[i];
            indice_cristal_poderoso = i;
        }
    }
    if (personaje) {
        optimus.mostrar_estadisticas_equipada();
    } else {
        megatron.mostrar_estadisticas_equipada();
    }
    std::cout << "El cristal más poderoso es:" << std::endl;
    std::cout << "Rareza: " << cristal_poderoso.rareza_a_string() << std::endl;
    std::cout << "Fuerza: " << cristal_poderoso.get_estadistica_fuerza() << " | Velocidad: " << cristal_poderoso.get_estadistica_velocidad() << " | Defensa: " << cristal_poderoso.get_estadistica_defensa() << std::endl;
    std::cout << "Desea equiparlo? (s/n)" << std::endl;
    char respuesta;
    std::cin >> respuesta;
    if (respuesta == 's') {
        if (personaje) {
            optimus.equipar_cristal(cristal_poderoso);
        } else {
            megatron.equipar_cristal(cristal_poderoso);
        }
        mostrar_estadisticas_equipada(optimus, megatron, personaje);
        cristales.baja(indice_cristal_poderoso);
    }
}

void BovedaCristales::equipar_cristal(bool personaje, OptimusPrime& optimus, Megatron& megatron) {
    if (cristales.vacio()) {
        throw ExcepcionBovedaCristales(ERROR_BOVEDA_VACIA);
    }
    if (personaje) {
        optimus.mostrar_estadisticas_equipada();
    } else {
        megatron.mostrar_estadisticas_equipada();
    }
    std::cout << "Esta seguro? Si equipa un cristal este se eliminara de la boveda. (s/n)" << std::endl;
    char respuesta;
    std::cin >> respuesta;
    if (respuesta != 's') {
        return;
    }
    mostrar_cristales();
    std::cout << "Seleccione el cristal a equipar: ";
    size_t posicion;
    std::cin >> posicion;
    if (posicion >= cristales.tamanio()) {
        throw ExcepcionBovedaCristales(ERROR_POSICION_INVALIDA);
    }
    if (personaje) {
        optimus.equipar_cristal(cristales[posicion]);
    } else {
        megatron.equipar_cristal(cristales[posicion]);
    }
    mostrar_estadisticas_equipada(optimus, megatron, personaje);
    cristales.baja(posicion);
}

void BovedaCristales::mostrar_estadisticas_equipada(OptimusPrime& optimus, Megatron& megatron, bool personaje) {
    std::cout << "Sus estadisticas actualizadas son: " << std::endl;
    if (personaje) {
        std::cout << "Fuerza: " << optimus.get_fuerza() << " | Velocidad: " << optimus.get_velocidad() <<" | Defensa: " << optimus.get_defensa() << std::endl;
    } else {
        std::cout << "Fuerza: " << megatron.get_fuerza() << " | Velocidad: " << megatron.get_velocidad() << " | Defensa: " << megatron.get_defensa() << std::endl;
    }
}
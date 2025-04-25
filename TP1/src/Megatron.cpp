#include "Megatron.hpp"

Megatron::Megatron() {
    this->intencion = "desprecio";
}

void Megatron::responder(std::string mensaje) {
    std::string mensaje_minuscula = mensaje;
    std::transform(mensaje_minuscula.begin(), mensaje_minuscula.end(), mensaje_minuscula.begin(), ::tolower);
    if (intencion == "desprecio") {
        procesar_respuesta_desprecio(mensaje_minuscula);
    } else if (intencion == "manipulacion") {
        procesar_respuesta_manipulacion(mensaje_minuscula);
    } else if (intencion == "amenaza") {
        procesar_respuesta_amenaza(mensaje_minuscula);
    }
}

void Megatron::sugerir_fusion() {
    if (intencion == "desprecio") {
        std::cout << "Fusiona cristales comunes para mejorar tus capacidades basicas.";
    } else if (intencion == "manipulacion") {
        std::cout << "Fusiona cristales raros para obtener un poder significativo.";
    } else if (intencion == "amenaza") {
        std::cout << "Realiza fusiones arriesgadas para obtener una ventaja poderosa.";
    }
}

void Megatron::cambiar_intencion(std::string intencion) {
    this->intencion = intencion;
}

void Megatron::procesar_respuesta_desprecio(std::string mensaje) {
    if (mensaje.find("optimus prime") != std::string::npos || mensaje.find("autobots") != std::string::npos) {
        std::cout << "Esos debiles seran aplastados bajo mi yugo.";
    } else if (mensaje.find("cybertron") != std::string::npos) {
        std::cout << "Cybertron sera mio, a cualquier costo.";
    } else {
        std::cout << "Eres insignificante.";
    }
}

void Megatron::procesar_respuesta_manipulacion(std::string mensaje) {
    if (mensaje.find("poder") != std::string::npos || mensaje.find("aliado") != std::string::npos) {
        std::cout << "Unete a mi, y juntos gobernaremos este universo.";
    } else if (mensaje.find("fuerza") != std::string::npos) {
        std::cout << "Solo el mas fuerte merece sobrevivir.";
    } else {
        std::cout << "Puedo darte lo que buscas, si estas dispuesto a arrodillarte.";
    }
}

void Megatron::procesar_respuesta_amenaza(std::string mensaje) {
    if (rand() % 2 == 0) {
        std::cout << "Atrevete a desafiarme, y conoceras el verdadero terror.";
    } else {
        std::cout << "No hay lugar para los debiles en mi imperio.";
    }
}

void Megatron::procesar(Funciones funciones) {
    char opcion;
    do {
        funciones.imprimir_menu_megatron();
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();
        switch (opcion) {
        case '1': {
            std::string intencion;
            std::cout << "Ingrese la intencion (desprecio/manipulacion/amenaza): ";
            std::cin >> intencion;
            while (!validar_intencion(intencion)) {
                std::cout << ERROR_VALIDACION;
                std::cout << "Ingrese la intención (desprecio/manipulacion/amenaza): ";
                std::cin >> intencion;
            }
            cambiar_intencion(intencion);
            break;
        }
        case '2': {
            std::string mensaje;
            std::cout << std::endl << "\e[41m-1 para dejar de mandar mensajes" << COLOR_POR_DEFECTO << std::endl << std::endl;
            do {
                mensaje = funciones.pedir_mensaje();
                if (mensaje != "-1") {
                    std::cout << RESALTADO_GRIS;
                    responder(mensaje);
                    std::cout << COLOR_POR_DEFECTO << std::endl;
                }
            } while (mensaje != "-1");
            break;
        }
        case '3': {
            std::cout << RESALTADO_GRIS;
            sugerir_fusion();
            std::cout << COLOR_POR_DEFECTO;
            break;
        }
        case '4': {
            std::cout << "Saliendo..." << std::endl;
            break;
        }
        default: {
            std::cout << "Error. Ingrese una opcion valida.\n";
            break;
        }
        }
    } while (opcion != '4');
}

bool Megatron::validar_intencion(std::string intencion) {
    if (intencion == "desprecio" ||
    intencion == "manipulacion" ||
    intencion == "amenaza") {
        return true;
    }
    return false;
}
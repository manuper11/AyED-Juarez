#include "OptimusPrime.hpp"

OptimusPrime::OptimusPrime() {
    this->estado_animo = "sereno";
}

void OptimusPrime::responder(std::string mensaje) {
    std::string mensaje_minuscula = mensaje;
    std::transform(mensaje_minuscula.begin(), mensaje_minuscula.end(), mensaje_minuscula.begin(), ::tolower);
    if (estado_animo == "sereno") {
        procesar_respuesta_sereno(mensaje_minuscula);
    } else if (estado_animo == "determinado") {
        procesar_respuesta_determinado(mensaje_minuscula);
    } else if (estado_animo == "enfurecido") {
        procesar_respuesta_enfurecido(mensaje_minuscula);
    }
}

void OptimusPrime::sugerir_fusion() {
    if (estado_animo == "sereno") {
        std::cout << "Te recomiendo fusionar cristales comunes para comenzar a mejorar tu arsenal.";
    } else if (estado_animo == "determinado") {
        std::cout << "Te sugiero fusionar cristales raros para prepararte para la batalla.";
    } else if (estado_animo == "enfurecido") {
        std::cout << "Fusiona cristales de alto riesgo para obtener una ventaja decisiva.";
    }
}

void OptimusPrime::cambiar_animo(std::string animo) {
    estado_animo = animo;
}

void OptimusPrime::procesar_respuesta_sereno(std::string mensaje) {
    if (mensaje.find("megatron") != std::string::npos || mensaje.find("decepticons") != std::string::npos) {
        std::cout << "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";
    } else if (mensaje.find("autobots") != std::string::npos) {
        std::cout << "Los Autobots estan aqui para proteger a todos los seres vivos.";
    } else if (mensaje.find("cybertron") != std::string::npos) {
        std::cout << "Cybertron es nuestro hogar, pero nuestra mision esta aqui.";
    } else {
        std::cout << "En que puedo ayudarte, humano?";
    }
}

void OptimusPrime::procesar_respuesta_determinado(std::string mensaje) {
    if (mensaje.find("megatron") != std::string::npos || mensaje.find("decepticons") != std::string::npos) {
        std::cout << "Megatron sera detenido. No hay alternativa.";
    } else if (mensaje.find("autobots") != std::string::npos) {
        std::cout << "Los Autobots son la luz en medio de la oscuridad.";
    } else if (mensaje.find("cybertron") != std::string::npos) {
        std::cout << "Cybertron sobrevivira, como lo hemos hecho antes.";
    } else {
        std::cout << "Nuestra lucha es por la libertad de todos los seres.";
    }
}

void OptimusPrime::procesar_respuesta_enfurecido(std::string mensaje) {
    if (std::rand() % 2 == 0) {
        std::cout << "No tengo tiempo para estas trivialidades.";
    } else {
        std::cout << "La batalla es inminente. Preparate.";
    }
}

void OptimusPrime::procesar(Funciones funciones) {
    char opcion;
    do {
        funciones.imprimir_menu_optimus();
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();
        switch (opcion) {
        case '1': {
            std::string animo;
            std::cout << "Ingrese el estado de animo (sereno/determinado/enfurecido): ";
            std::cin >> animo;
            while (!validar_animo(animo)) {
                std::cout << ERROR_VALIDACION;
                std::cout << "Ingrese el estado de animo (sereno/determinado/enfurecido): ";
                std::cin >> animo;
            }
            cambiar_animo(animo);
            break;
        }
        case '2': {
            std::string mensaje;
            std::cout << std::endl << "\e[41m-1 para dejar de mandar mensajes" << COLOR_POR_DEFECTO << std::endl << std::endl;
            do {
                mensaje = funciones.pedir_mensaje();
                if (mensaje != "-1") {
                    std::cout << RESALTADO_AZUL;
                    responder(mensaje);
                    std::cout << COLOR_POR_DEFECTO << std::endl;
                }
            } while (mensaje != "-1");
            break;
        }
        case '3': {
            std::cout << RESALTADO_AZUL;
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

bool OptimusPrime::validar_animo(std::string animo) {
    if (animo == "sereno" ||
    animo == "determinado" ||
    animo == "enfurecido") {
        return true; 
    }
    return false;
}
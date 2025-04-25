#include "Megatron.hpp"

const std::string INTENCION_DESPRECIO = "desprecio";
const std::string INTENCION_MANIPULACION = "manipulacion";
const std::string INTENCION_AMENAZA = "amenaza";

const std::string RESPUESTA_DESPRECIO_CYBERTRON = "Cybertron sera mio, a cualquier costo.";
const std::string RESPUESTA_DESPRECIO_GENERICA = "Eres insignificante.";
const std::string SUGERENCIA_FUSION_DESPRECIO = "Fusiona cristales comunes para mejorar tus capacidades basicas.";

const std::string RESPUESTA_MANIPULACION_FUERZA = "Solo el mas fuerte merece sobrevivir.";
const std::string RESPUESTA_MANIPULACION_GENERICA = "Puedo darte lo que buscas, si estas dispuesto a arrodillarte.";
const std::string SUGERENCIA_FUSION_MANIPULACION = "Fusiona cristales raros para obtener un poder significativo.";

const std::string RESPUESTA_AMENAZA_GENERICA_1 = "Atrevete a desafiarme, y conoceras el verdadero terror.";
const std::string RESPUESTA_AMENAZA_GENERICA_2 = "No hay lugar para los debiles en mi imperio.";
const std::string SUGERENCIA_FUSION_AMENAZA = "Realiza fusiones arriesgadas para obtener una ventaja poderosa.";

Megatron::Megatron() {
    this->intencion = DESPRECIO;
}

void Megatron::responder(std::string mensaje) {
    Minusculas minusculas;
    std::string mensaje_minuscula = minusculas.a_minusculas(mensaje);
    switch (intencion) {
        case DESPRECIO:
            procesar_respuesta_desprecio(mensaje_minuscula);
            break;
        case MANIPULACION:
            procesar_respuesta_manipulacion(mensaje_minuscula);
            break;
        case AMENAZA:
            procesar_respuesta_amenaza(mensaje_minuscula);
    }
}

void Megatron::sugerir_fusion() {
    switch (intencion) {
        case DESPRECIO:
            std::cout << SUGERENCIA_FUSION_DESPRECIO;
            break;
        case MANIPULACION:
            std::cout << SUGERENCIA_FUSION_MANIPULACION;
            break;
        case AMENAZA:
            std::cout << SUGERENCIA_FUSION_AMENAZA;
    }
}

void Megatron::cambiar_intencion(std::string intencion) {
    if (intencion == INTENCION_DESPRECIO) {
        this->intencion = DESPRECIO;
    } else if (intencion == INTENCION_MANIPULACION) {
        this->intencion = MANIPULACION;
    } else if (intencion == INTENCION_AMENAZA) {
        this->intencion = AMENAZA;
    } else {
        std::cout << "Intencion invalida. Estableciendo desprecio por defecto.\n";
        this->intencion = DESPRECIO;
    }
}

void Megatron::procesar_respuesta_desprecio(std::string& mensaje) {
    if (mensaje.find("optimus prime") != std::string::npos || mensaje.find("autobots") != std::string::npos) {
        std::cout << RESPUESTA_DESPRECIO_OPTIMUS_PRIME_AUTOBOTS;
    } else if (mensaje.find("cybertron") != std::string::npos) {
        std::cout << RESPUESTA_DESPRECIO_CYBERTRON;
    } else {
        std::cout << RESPUESTA_DESPRECIO_GENERICA;
    }
}

void Megatron::procesar_respuesta_manipulacion(std::string& mensaje) {
    if (mensaje.find("poder") != std::string::npos || mensaje.find("aliado") != std::string::npos) {
        std::cout << RESPUESTA_MANIPULACION_PODER_ALIADO;
    } else if (mensaje.find("fuerza") != std::string::npos) {
        std::cout << RESPUESTA_MANIPULACION_FUERZA;
    } else {
        std::cout << RESPUESTA_MANIPULACION_GENERICA;
    }
}

void Megatron::procesar_respuesta_amenaza(std::string& mensaje) {
    if (rand() % 2 == 0) {
        std::cout << RESPUESTA_AMENAZA_GENERICA_1;
    } else {
        std::cout << RESPUESTA_AMENAZA_GENERICA_2;
    }
}

void Megatron::procesar(Menu& menu) {
    char opcion;
    do {
        menu.imprimir_menu_megatron();
        std::cin >> opcion;
        std::cin.ignore();
        switch (opcion) {
        case '1': {
            Opcion_1();
            break;
        }
        case '2': {
            Opcion_2(menu);
            break;
        }
        case '3': {
            std::cout << RESALTADO_GRIS;
            sugerir_fusion();
            std::cout << COLOR_POR_DEFECTO;
            break;
        }
        case '4': {
            std::cout << "Volviendo al menu principal..." << std::endl;
            break;
        }
        default: {
            std::cout << "Error. Ingrese una opcion valida.\n";
        }
        }
    } while (opcion != '4');
}

std::string Megatron::char_a_string_intencion (char intencion) {
    std::string string_intencion;
    switch (intencion) {
        case '1':
            string_intencion = INTENCION_DESPRECIO;
            break;
        case '2': 
            string_intencion = INTENCION_MANIPULACION;
            break;
        case '3':
            string_intencion = INTENCION_AMENAZA;
            break;
        default:
            string_intencion = INTENCION_DESPRECIO;
            std::cout << std::endl << ERROR_INTENCION_INVALIDA << std::endl;
    }
    return string_intencion;
}

void Megatron::Opcion_1() {
    std::string ingreso_intencion;
    std::cout << SOLICITUD_INTENCION << std::endl;
    std::cin >> ingreso_intencion;
    std::string intencion = char_a_string_intencion(ingreso_intencion[0]);
    cambiar_intencion(intencion);
}

void Megatron::Opcion_2(Menu& menu) {
    std::string mensaje;
    std::cout << std::endl << "\e[41m-1 para dejar de mandar mensajes" << COLOR_POR_DEFECTO << std::endl << std::endl;
    do {
        mensaje = menu.pedir_mensaje();
        if (mensaje != "-1") {
            std::cout << RESALTADO_GRIS;
            responder(mensaje);
            std::cout << COLOR_POR_DEFECTO << std::endl;
        }
    } while (mensaje != "-1");
}
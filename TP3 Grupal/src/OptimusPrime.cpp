#include "OptimusPrime.hpp"

const std::string ANIMO_SERENO = "sereno";
const std::string ANIMO_DETERMINADO = "determinado";
const std::string ANIMO_ENFURECIDO = "enfurecido";

const std::string RESPUESTA_SERENO_AUTOBOTS = "Los Autobots estan aqui para proteger a todos los seres vivos.";
const std::string RESPUESTA_SERENO_CYBERTRON = "Cybertron es nuestro hogar, pero nuestra mision esta aqui.";
const std::string RESPUESTA_SERENO_GENERICA = "En que puedo ayudarte, humano?";
const std::string SUGERENCIA_FUSION_SERENO = "Te recomiendo fusionar cristales comunes para comenzar a mejorar tu arsenal.";

const std::string RESPUESTA_DETERMINADO_AUTOBOTS = "Los Autobots son la luz en medio de la oscuridad.";
const std::string RESPUESTA_DETERMINADO_CYBERTRON = "Cybertron sobrevivira, como lo hemos hecho antes.";
const std::string RESPUESTA_DETERMINADO_GENERICA = "Nuestra lucha es por la libertad de todos los seres.";
const std::string SUGERENCIA_FUSION_DETERMINADO = "Te sugiero fusionar cristales raros para prepararte para la batalla.";

const std::string RESPUESTA_ENFURECIDO_GENERICA_1 = "No tengo tiempo para estas trivialidades.";
const std::string RESPUESTA_ENFURECIDO_GENERICA_2 = "La batalla es inminente. Preparate.";
const std::string SUGERENCIA_FUSION_ENFURECIDO = "Fusiona cristales de alto riesgo para obtener una ventaja decisiva.";

OptimusPrime::OptimusPrime() {
    this->estado_animo = SERENO;
}

void OptimusPrime::responder(std::string mensaje) {
    Minusculas minusculas;
    std::string mensaje_minuscula = minusculas.a_minusculas(mensaje);
    switch (estado_animo) {
    case SERENO:
        procesar_respuesta_sereno(mensaje_minuscula);
        break;
    case DETERMINADO:
        procesar_respuesta_determinado(mensaje_minuscula);
        break;
    case ENFURECIDO:
        procesar_respuesta_enfurecido(mensaje_minuscula);
    }
}

void OptimusPrime::sugerir_fusion() {
    switch (estado_animo) {
    case SERENO:
        std::cout << SUGERENCIA_FUSION_SERENO;
        break;
    case DETERMINADO:
        std::cout << SUGERENCIA_FUSION_DETERMINADO;
        break;
    case ENFURECIDO:
        std::cout << SUGERENCIA_FUSION_ENFURECIDO;
    }
}

void OptimusPrime::cambiar_animo(std::string animo) {
    if (animo == ANIMO_SERENO) {
        this->estado_animo = SERENO;
    } else if (animo == ANIMO_DETERMINADO) {
        this->estado_animo = DETERMINADO;
    } else if (animo == ANIMO_ENFURECIDO) {
        this->estado_animo = ENFURECIDO;
    } else {
        std::cout << ERROR_ANIMO_INVALIDO;
        this->estado_animo = SERENO;
    }
}

void OptimusPrime::procesar_respuesta_sereno(std::string& mensaje) {
    if (mensaje.find("megatron") != std::string::npos || mensaje.find("decepticons") != std::string::npos) {
        std::cout << RESPUESTA_SERENO_MEGATRON_DECEPTICONS;
    } else if (mensaje.find("autobots") != std::string::npos) {
        std::cout << RESPUESTA_SERENO_AUTOBOTS;
    } else if (mensaje.find("cybertron") != std::string::npos) {
        std::cout << RESPUESTA_SERENO_CYBERTRON;
    } else {
        std::cout << RESPUESTA_SERENO_GENERICA;
    }
}

void OptimusPrime::procesar_respuesta_determinado(std::string& mensaje) {
    if (mensaje.find("megatron") != std::string::npos || mensaje.find("decepticons") != std::string::npos) {
        std::cout << RESPUESTA_DETERMINADO_MEGATRON_DECEPTICONS;
    } else if (mensaje.find("autobots") != std::string::npos) {
        std::cout << RESPUESTA_DETERMINADO_AUTOBOTS;
    } else if (mensaje.find("cybertron") != std::string::npos) {
        std::cout << RESPUESTA_DETERMINADO_CYBERTRON;
    } else {
        std::cout << RESPUESTA_DETERMINADO_GENERICA;
    }
}

void OptimusPrime::procesar_respuesta_enfurecido(std::string& mensaje) {
    if (std::rand() % 2 == 0) {
        std::cout << RESPUESTA_ENFURECIDO_GENERICA_1;
    } else {
        std::cout << RESPUESTA_ENFURECIDO_GENERICA_2;
    }
}

std::string OptimusPrime::char_a_string_animo(char animo) {
    std::string string_animo;
    switch (animo) {
    case '1':
        string_animo = ANIMO_SERENO;
        break;
    case '2':
        string_animo = ANIMO_DETERMINADO;
        break;
    case '3':
        string_animo = ANIMO_ENFURECIDO;
        break;
    default:
        string_animo = ANIMO_SERENO;
        std::cout << ERROR_ANIMO_INVALIDO;
    }
    return string_animo;
}

void OptimusPrime::Opcion_1() {
    std::string ingreso_animo;
    std::cout << SOLICITUD_ANIMO << std::endl;
    std::cin >> ingreso_animo;
    std::string animo = char_a_string_animo(ingreso_animo[0]);
    cambiar_animo(animo);
}

size_t OptimusPrime::poder() {
    return fuerza + defensa + velocidad;
}

void OptimusPrime::equipar_cristal(Cristal cristal) {
    if (cristal_equipado) {
        desequipar_cristal();
    }
    fuerza += cristal.get_estadistica_fuerza();
    velocidad += cristal.get_estadistica_velocidad();
    defensa += cristal.get_estadistica_defensa();

    cristal_equipado = true;
    fuerza_equipada = cristal.get_estadistica_fuerza();
    velocidad_equipada = cristal.get_estadistica_velocidad();
    defensa_equipada = cristal.get_estadistica_defensa();
}

size_t OptimusPrime::get_fuerza() {
    return fuerza;
}

size_t OptimusPrime::get_defensa() {
    return defensa;
}

size_t OptimusPrime::get_velocidad() {
    return velocidad;
}


bool OptimusPrime::get_transformado() {
    return transformado;
}

void OptimusPrime::desequipar_cristal() {
    fuerza -= fuerza_equipada;
    velocidad -= velocidad_equipada;
    defensa -= defensa_equipada;
    
    cristal_equipado = false;
}

void OptimusPrime::mostrar_estadisticas_equipada() {
    std::cout << std::endl << "Optimus Prime tiene un cristal de las siguientes caracteristicas: " << std::endl;
    std::cout << "Fuerza: " << fuerza_equipada << " | Velocidad: " << velocidad_equipada << " | Defensa: " << defensa_equipada << std::endl << std::endl;
}

void OptimusPrime::transformar(){
    transformado ? transformado = false : transformado = true;
    if(transformado){
        fuerza = (fuerza*15)/10;
        defensa = (defensa*15)/10;
        velocidad /= 2;
    }
    else{
        fuerza = (fuerza*10)/15;
        defensa = (defensa*10)/15;
        velocidad *= 2;
    }
}
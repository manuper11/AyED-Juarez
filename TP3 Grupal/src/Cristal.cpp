#include "Cristal.hpp"

const int FACTOR_FUERZA = 10;
const int FACTOR_VELOCIDAD = 5;
const int FACTOR_DEFENSA = 10;

Cristal::Cristal() {
    this->rareza = COMUN;
    estadistica_fuerza = (rareza + 1) * FACTOR_FUERZA;
    estadistica_velocidad = (rareza + 1) * FACTOR_VELOCIDAD;
    estadistica_defensa = (rareza + 1) * FACTOR_DEFENSA;
}

Cristal::Cristal(Rareza rareza) {
    this->rareza = rareza;
    estadistica_fuerza = (rareza + 1) * FACTOR_FUERZA;
    estadistica_velocidad = (rareza + 1) * FACTOR_VELOCIDAD;
    estadistica_defensa = (rareza + 1) * FACTOR_DEFENSA;
}
// setter de la caracteristica fuerza
void Cristal::set_estadistica_fuerza(int fuerza){
    this->estadistica_fuerza = fuerza;
}

// setter de la caracteristica velocidad
void Cristal::set_estadistica_velocidad(int velocidad){
    this->estadistica_velocidad = velocidad;
}

// setter de la caracteristica defensa
void Cristal::set_estadistica_defensa(int defensa){
    this->estadistica_defensa = defensa;
}

//getter de la caracteristica fuerza
int Cristal::get_estadistica_fuerza(){
    return this->estadistica_fuerza;
}

//getter de la caracteristica velocidad
int Cristal::get_estadistica_velocidad(){
    return this->estadistica_velocidad;
}

//getter de la caracteristica defensa
int Cristal::get_estadistica_defensa(){
    return this->estadistica_defensa;
}

bool Cristal::operator==(Rareza rareza) {
    return this->rareza == rareza;
}

Rareza Cristal::obtener_rareza() {
    return rareza;
}

std::string Cristal::rareza_a_string() {
    std::string rareza_string;
    switch (rareza) {
    case COMUN:
        rareza_string = "COMUN";
        break;
    case RARO:
        rareza_string = "RARO";
        break;
    case EPICO:
        rareza_string = "EPICO";
        break;
    case LEGENDARIO:
        rareza_string = "LEGENDARIO";
        break;
    }
    return rareza_string;
}

int Cristal::poder(){
    return this->estadistica_fuerza + this->estadistica_velocidad + this->estadistica_defensa;
}
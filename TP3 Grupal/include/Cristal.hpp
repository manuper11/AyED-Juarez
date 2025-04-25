#ifndef CRISTAL_HPP
#define CRISTAL_HPP

#include <string>

enum Rareza {
    COMUN,
    RARO,
    EPICO,
    LEGENDARIO
};

class Cristal {
private:
    Rareza rareza;
    int estadistica_fuerza;
    int estadistica_velocidad;
    int estadistica_defensa;
public:
    //PRE: -
    //POST: Crea un objeto Cristal con rareza comun y estadisticas por defecto
    Cristal();
    //PRE: -
    //POST: Crea un objeto Cristal con la rareza indicada y estadisticas acordes a la rareza
    Cristal(Rareza rareza);
    //PRE: -
    //POST: Devuelve true si la rareza del cristal es igual a la rareza ingresada
    bool operator==(Rareza rareza);
    //PRE: -
    //POST: Devuelve la rareza del cristal
    Rareza obtener_rareza();
    //PRE: -
    //POST: Setea la estadistica de fuerza del cristal
    void set_estadistica_fuerza(int fuerza);
    //PRE: -
    //POST: Setea la estadistica de velocidad del cristal
    void set_estadistica_velocidad(int velocidad);
    //PRE: -
    //POST: Setea la estadistica de defensa del cristal
    void set_estadistica_defensa(int defensa);
    //PRE: -
    //POST: Devuelve la estadistica de fuerza del cristal
    int get_estadistica_fuerza();
    //PRE: -
    //POST: Devuelve la estadistica de velocidad del cristal
    int get_estadistica_velocidad();
    //PRE: -
    //POST: Devuelve la estadistica de defensa del cristal
    int get_estadistica_defensa();
    //PRE: -
    //POST: Devuelve la rareza del cristal en formato tipo string
    std::string rareza_a_string();
    //PRE: -
    //POST: Devuelve la suma de las estadisticas del cristal
    int poder();
};

#endif
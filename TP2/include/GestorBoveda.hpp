#ifndef GESTORBOVEDA_HPP
#define GESTORBOVEDA_HPP

#include "Menu.hpp"
#include "BovedaCristales.hpp"
#include "FusionadorEnergon.hpp"

const std::string RUTA_ARCHIVO = "cristales.csv";

class GestorBoveda {
private:
    BovedaCristales& boveda;
    Menu& menu;
public:
    //PRE: -
    //POST: Crea un objeto GestorBoveda con la boveda y el menu pasados por referencia
    GestorBoveda(Menu& menu, BovedaCristales& boveda);
    //PRE: La boveda no puede estar llena
    //POST: Almacena un cristal comun en la boveda y lo comunica por pantalla
    void almacenar_cristal();
    //PRE: La boveda no puede estar vacia
    //POST: Muestra los cristales almacenados en la boveda por pantalla
    void mostrar_cristales();
    //PRE: -
    //POST: Exporta los cristales almacenados en la boveda a un archivo csv
    void exportar_cristales();
    //PRE: Los cristales deben ser de la misma rareza, uno no puede ser legendario
    //     La boveda no puede estar vacia y la posicion debe ser una posicion valida
    //POST: Fusiona dos cristales de la boveda y almacena el resultado de dicha fusion en la boveda
    void fusionar_cristales();

};

#endif

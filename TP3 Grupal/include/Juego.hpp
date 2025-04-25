#ifndef JUEGO_H
#define JUEGO_H

#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Menu.hpp"
#include "Cristal.hpp"
#include "BovedaCristales.hpp"
#include "GestorBoveda.hpp"
#include "ManejoTransformer.hpp"
#include "Batalla.hpp"
#include "SFML/MapaGrafo.hpp"

class Juego {
private:
    //atributos:
    Menu menu;
    std::string nombre_jugador;
    BovedaCristales boveda;
    OptimusPrime optimus;
    Megatron megatron;
    ManejoTransformer manejo_transformer;
    bool personaje = true;  //True para optimus.
    Batalla batalla_final;
    Camino camino_minimo;
    Archivo tabla_clasificaciones;

public:
//metodos:
    //constructor
    Juego();
    //PRE: -
    //POST: Cambia el personaje principal
    void cambiar_personaje();
    //PRE: -
    //POST: Procesa las opciones del menu principal y llama a los metodos correspondientes
    void procesar_menu_principal();
    //PRE: -
    //POST: Procesa las opciones de Optimus y Megatron y llama a los metodos de los personajes
    void procesar_personajes();
    //PRE: -
    //POST: Procesa las opciones del menu de la boveda y llama a los metodos de la boveda
    void procesar_boveda(GestorBoveda& gestor_boveda);
    //PRE: -
    //POST: Procesa las opciones del menu de transformers y llama a los metodos de manejo de transformers
    void procesar_transformers();
    //PRE: -
    //POST: Inicia la muestra del grafo de batalla y el camino minimo
    void iniciar_ventana_grafica(bool personaje, Camino camino_min);
};

#endif //JUEGO_H
#ifndef BATALLA_HPP
#define BATALLA_HPP

#include "Grafo.hpp"
#include "ManejoTransformer.hpp"
#include "Transformer.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"
#include "Vector.hpp"
#include "BovedaCristales.hpp"
#include "Archivos.hpp"

class Batalla{
private:
// Atributos:
    Grafo mapa_batalla;
    Vector<Transformer *> listado;
    bool personaje; // Personaje con el que se va a jugar.
    size_t poder_personaje_principal;
    size_t energia_energon;
    size_t puntaje;

    size_t nodo_origen;
    size_t nodo_final;

    size_t defensa_personaje;
    size_t velocidad_personaje;
    size_t fuerza_personaje;

    Archivo tabla_clasificaciones;

    std::string nombre_jugador;
// Metodos: 
    //Post: Imprime los dialogos iniciales.
    void imprimir_dialogos();

    //Post: Carga por orden de aparicion los personajes en el grafo.
    void carga_personajes();

    //Pre: Recibe un vector de estadisticas de un transformer
    //Post: Devuelve el puntaje de un enfrentamiento entre el personaje principal y un transformer.
    int enfrentamiento(size_t estadisticas_contrincante[3]);
    
    //Post: Muestra el puntaje actual de una pelea.
    void mostrar_puntaje(int puntaje);
    //Pre: Recibe la posicion del contrincante, y los persoanjes principals.
    //Post: Actualiza las estadisticas si son aceptadas..
    void transformar(size_t indice_lucha, OptimusPrime &optimus, Megatron &megatron);
    //Pre: Recibe la posicion del contrincante.
    //Post: Transforma al contrincante.
    void transformar_intermedios(size_t indice_lucha);
    //Pre: recibe al personaje principal y al jefe final.
    //Post: Ejecuta la pelea final.
    void pelea_final(OptimusPrime &optimus, Megatron &megatron);
    //pre: Recibe los personajes principales.
    //post: Actualiza las estadisticas de los personajes principales.
    void carga_estadisticas(OptimusPrime &optimus, Megatron &megatron);
    // Pre: Recibe el nodo posterior al origen del cual se necesita el peso.
    // Post: Retorna el peso correspondiente de la arista que conecta el origen cn el nodo posterior.
    int eleccion_peso(size_t indice_nodo);
public:
    // Constructor
    Batalla();
    //Constructor
    Batalla(bool personaje, size_t poder_personaje, ManejoTransformer &manejo, std::string nombre_jugador);
    // pre: -
    // post: Retorna un camino con los nodos involucrados en el nuevo camino y su peso correspondiente.
    Camino proxima_jugada();
    //Pre: Recibe el camino minimo, el personaje principal y el jefe final.
    //post: Ejecuta las peleas del camino minimo.
    void Pelea(Vector<size_t> camino_actual, OptimusPrime &optimus, Megatron &megatron);
    //Post: Retorna la tabla de clasificaciones.
    Archivo get_tabla();
};

#endif
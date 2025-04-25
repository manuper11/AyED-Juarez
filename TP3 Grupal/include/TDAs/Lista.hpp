#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"
template<typename Dato>
class Lista {
private:
    NodoLista<Dato>* primer_nodo;
    NodoLista<Dato>* ultimo_nodo;
    size_t cantidad_datos;

    //PRE: La posicion debe ser menor que la cantidad de datos.
    //POST: Retorna un puntero al nodo de esa posicion.
    NodoLista<Dato>* obtener_nodo(int posicion);

public:
    // Post: Agrega el dato al principio de la lista.
    void alta_principio(Dato dato);

    // Post: Agrega el dato al final de la lista.
    void alta_final(Dato dato);

    // Pre: La posición debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada.
    void alta(Dato dato, int posicion);

    // Post: Retorna true si la lista está vacía, false en caso contrario.
    bool vacio();

};

template<typename Dato>
NodoLista<Dato>* Lista<Dato>::obtener_nodo(int posicion){
    NodoLista<T>* nodo = primer_nodo;
    for(size_t i = 0; i < posicion; i++){
        nodo = nodo -> obtener_siguiente();
    }
    return nodo;
}


template<typename Dato>
void Lista<Dato>::alta_principio(Dato dato) {
    NodoLista<Dato>* nuevo_nodo = new NodoLista<Dato>(dato);

    if(vacio()) {
        primer_nodo = nuevo_nodo;
        ultimo_nodo = nuevo_nodo;
    }else {
        nuevo_nodo->cambiar_siguiente(primer_nodo->obtener_siguiente());
        primer_nodo -> cambiar_anterior(nuevo_nodo);
        primer_nodo = nuevo_nodo;
    }
    cantidad_datos++;
}


template<typename Dato>
void Lista<Dato>::alta_final(Dato dato) {
    NodoLista<Dato>* nuevo_nodo = new NodoLista<Dato>(dato);
    
    if(vacio()){
        primer_nodo = ultimo_nodo = nuevo_nodo;
    }else{
        nuevo_nodo -> cambiar_anterior(ultimo_nodo);
        ultimo_nodo ->cambiar_siguiente(nuevo_nodo);
        ultimo_nodo = nuevo_nodo;
    }
    cantidad_datos++;
}

template<typename Dato>
void Lista<Dato>::alta(Dato dato, int posicion) {
    if(cantidad_datos == posicion) {
        alta_final(dato);
    }
    else if (posicion == 0) {
        alta_principio(dato);
    }
    else {
        NodoLista<T>* nuevo_nodo = new NodoLista<Dato>(dato);
        NodoLista<T>* nodo_anterior = obtener_nodo(posicion - 1);
        nuevo_nodo -> cambiar_siguiente(nodo_anterior -> obtener_siguiente());
        nuevo_nodo -> cambiar_anterior(nodo_anterior);
        nodo_anterior -> obtener_siguiente() -> cambiar_anterior(nuevo_nodo);
        nodo_anterior -> cambiar_siguiente(nuevo_nodo);
        cantidad_datos ++;
    }
}

template<typename Dato>
bool Lista<Dato>::vacio() {
    return (cantidad_datos == 0);
}

#endif //LISTA_HPP
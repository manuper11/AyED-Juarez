#ifndef PILA_HPP
#define PILA_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoLista.hpp"

class ExcepcionPila : public std::runtime_error {
public:
    ExcepcionPila(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionPila(): runtime_error("") {
    }
};

template<typename T>
class Pila {
private:
    NodoLista<T>* ultimo_nodo;
    size_t cantidad_datos;

public:
    // Constructor.
    Pila();

    // Pre: -
    // Post: Agrega el dato al final de la pila.
    void alta(T dato);

    // Pre: La pila no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la pila.
    T baja();

    // Pre: La pila no puede estar vacía.
    // Post: Devuelve el primer dato de la pila.
    T primero();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la pila.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la pila esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Pila(const Pila& pila) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Pila& pila) = delete;

    // Destructor.
    ~Pila();
};

template<typename T>
Pila<T>::Pila() {
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void Pila<T>::alta(T dato) {
    NodoLista<T>* nuevo_nodo = new NodoLista<T>(dato);
    if (!vacio()) {
        nuevo_nodo->cambiar_anterior(ultimo_nodo);
        ultimo_nodo->cambiar_siguiente(nuevo_nodo);
    }
    ultimo_nodo = nuevo_nodo;
    cantidad_datos++;
}

template<typename T>
T Pila<T>::baja() {
    if (vacio()) {
        throw ExcepcionPila("No se puede eliminar elemento, la pila esta vacia.");
    }
    T dato = ultimo_nodo->obtener_dato();
    NodoLista<T>* nodo_a_eliminar = ultimo_nodo;
    ultimo_nodo = ultimo_nodo->obtener_anterior();
    if (ultimo_nodo != nullptr) {
        ultimo_nodo->cambiar_siguiente(nullptr);
    }
    delete nodo_a_eliminar;
    cantidad_datos--;
    return dato;
}

template<typename T>
T Pila<T>::primero() {
    if (vacio()) {
        throw ExcepcionPila("No se puede obtener el primer elemento, la pila esta vacia.");
    }
    return ultimo_nodo->obtener_dato();
}

template<typename T>
size_t Pila<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Pila<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
Pila<T>::~Pila() {
    while (!vacio()) {
        baja();
    }
}

#endif

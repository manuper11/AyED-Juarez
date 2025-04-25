#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

template<typename T>
class NodoLista {
private:
    T dato;
    NodoLista* anterior;
    NodoLista* siguiente;

public:
    // Constructores.
    NodoLista(T dato);

    NodoLista(T dato, NodoLista* anterior, NodoLista* siguiente);

    // Getters y setters.
    T& obtener_dato();

    void cambiar_dato(T dato);

    NodoLista* obtener_anterior();

    void cambiar_anterior(NodoLista* anterior);

    NodoLista* obtener_siguiente();

    void cambiar_siguiente(NodoLista* siguiente);
};

template<typename T>
NodoLista<T>::NodoLista(T dato) {
    this->dato = dato;
    anterior = nullptr;
    siguiente = nullptr;
}

template<typename T>
NodoLista<T>::NodoLista(T dato, NodoLista* anterior, NodoLista* siguiente) {
    this->dato = dato;
    this->anterior = anterior;
    this->siguiente = siguiente;
}

template<typename T>
T& NodoLista<T>::obtener_dato() {
    return dato;
}

template<typename T>
void NodoLista<T>::cambiar_dato(T dato) {
    this->dato = dato;
}

template<typename T>
NodoLista<T>* NodoLista<T>::obtener_anterior() {
    return anterior;
}

template<typename T>
void NodoLista<T>::cambiar_anterior(NodoLista* anterior) {
    this->anterior = anterior;
}

template<typename T>
NodoLista<T>* NodoLista<T>::obtener_siguiente() {
    return siguiente;
}

template<typename T>
void NodoLista<T>::cambiar_siguiente(NodoLista* siguiente) {
    this->siguiente = siguiente;
}

#endif

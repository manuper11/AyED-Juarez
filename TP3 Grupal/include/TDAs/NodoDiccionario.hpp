#ifndef NODODICCIONARIO_HPP
#define NODODICCIONARIO_HPP

template<typename Clave, typename T>
class NodoDiccionario {
private:
    Clave clave;
    T dato;
    NodoDiccionario* padre;
    NodoDiccionario* hijo_izquierdo;
    NodoDiccionario* hijo_derecho;

public:
    // Constructores.
    NodoDiccionario(Clave clave, T dato);

    NodoDiccionario(Clave clave, T dato, NodoDiccionario* padre, NodoDiccionario* hijo_izquierdo,
                    NodoDiccionario* hijo_derecho);

    // Getters y setters.
    Clave obtener_clave();

    void cambiar_clave(Clave clave);

    T& obtener_dato();

    void cambiar_dato(T dato);

    NodoDiccionario* obtener_padre();

    void cambiar_padre(NodoDiccionario* padre);

    NodoDiccionario* obtener_hijo_izquierdo();

    void cambiar_hijo_izquierdo(NodoDiccionario* hijo_izquierdo);

    NodoDiccionario* obtener_hijo_derecho();

    void cambiar_hijo_derecho(NodoDiccionario* hijo_derecho);
};

template<typename Clave, typename T>
NodoDiccionario<Clave, T>::NodoDiccionario(Clave clave, T dato) {
    this->clave = clave;
    this->dato = dato;
    padre = nullptr;
    hijo_izquierdo = nullptr;
    hijo_derecho = nullptr;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>::NodoDiccionario(Clave clave, T dato, NodoDiccionario* padre, NodoDiccionario* hijo_izquierdo,
                                           NodoDiccionario* hijo_derecho) {
    this->clave = clave;
    this->dato = dato;
    this->padre = padre;
    this->hijo_izquierdo = hijo_izquierdo;
    this->hijo_derecho = hijo_derecho;
}

template<typename Clave, typename T>
Clave NodoDiccionario<Clave, T>::obtener_clave() {
    return clave;
}

template<typename Clave, typename T>
void NodoDiccionario<Clave, T>::cambiar_clave(Clave clave) {
    this->clave = clave;
}

template<typename Clave, typename T>
T& NodoDiccionario<Clave, T>::obtener_dato() {
    return dato;
}

template<typename Clave, typename T>
void NodoDiccionario<Clave, T>::cambiar_dato(T dato) {
    this->dato = dato;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* NodoDiccionario<Clave, T>::obtener_padre() {
    return padre;
}

template<typename Clave, typename T>
void NodoDiccionario<Clave, T>::cambiar_padre(NodoDiccionario* padre) {
    this->padre = padre;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* NodoDiccionario<Clave, T>::obtener_hijo_izquierdo() {
    return hijo_izquierdo;
}

template<typename Clave, typename T>
void NodoDiccionario<Clave, T>::cambiar_hijo_izquierdo(NodoDiccionario* hijo_izquierdo) {
    this->hijo_izquierdo = hijo_izquierdo;
}

template<typename Clave, typename T>
NodoDiccionario<Clave, T>* NodoDiccionario<Clave, T>::obtener_hijo_derecho() {
    return hijo_derecho;
}

template<typename Clave, typename T>
void NodoDiccionario<Clave, T>::cambiar_hijo_derecho(NodoDiccionario* hijo_derecho) {
    this->hijo_derecho = hijo_derecho;
}

#endif

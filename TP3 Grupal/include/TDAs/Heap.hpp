#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef>
#include <stdexcept>
#include "Vector.hpp"

class ExcepcionHeap : public std::runtime_error {
public:
    ExcepcionHeap(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionHeap(): runtime_error("") {
    }
};

const bool MAXIMA = true;
const bool MINIMA = false;

// El dato debe implementar el operator<() y el operator>().
template<typename T>
class Heap {
private:
    Vector<T> datos;
    size_t cantidad_de_datos;
    bool tipo_de_heap;

    //Pre: Recibe un indice menor a la cantidad de datos.
    //Post: Reordena el vector para cumplir con las restricciones del heap.
    void restauracion_hacia_arriba(size_t indice_dato);

    //Pre: Recibe un indice menor a la cantidad de datos.
    //Post: Reordena el vector para cumplir con las restricciones del heap.
    void restauracion_hacia_abajo(size_t indice_dato);

    //Pre: Recibe dos indice dentro del rango valido.
    //Post: Intercambia el elemento de la poscion i con la posicion j. 
    void swap(size_t i, size_t j);

public:
    // Constructor default.
    Heap();

    // Constructor. El parámetro indica si el heap es de máxima o de mínima.
    // Si es de máxima, utiliza el operador >. Si es de mínima, utiliza el <.
    Heap(bool maxima);

    // Pre: -
    // Post: Agrega el dato al heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // Destructor.
    ~Heap();
};


template <typename T>
Heap<T>::Heap()
{
    Heap(MINIMA);
}

template<typename T>
Heap<T>::Heap(bool maxima) {
     // Si máxima es true => tipo de heap es de maxima . sino el heap sera de minima.
    tipo_de_heap = maxima;
    cantidad_de_datos = 0;
}

template<typename T>
void Heap<T>::alta(T dato) {
    if(vacio()){
        datos.alta(dato);
    }
    else
    {
        datos.alta(dato);
        size_t indice_dato = datos.tamanio() - 1;
        restauracion_hacia_arriba(indice_dato);
    }
    cantidad_de_datos++;
}

template<typename T>
T Heap<T>::baja() {
     if(vacio())
        throw ExcepcionHeap("El heap esta vacio.");
    T dato_a_devolver = datos[0];
    swap(0,datos.tamanio()-1);
    datos.baja();
    restauracion_hacia_abajo(0);
    cantidad_de_datos--;
    return dato_a_devolver;
}

template<typename T>
T Heap<T>::primero() {
    if(vacio())
        throw ExcepcionHeap("El heap esta vacio.");
    return datos[0];
}

template<typename T>
bool Heap<T>::vacio() {
    return (cantidad_de_datos == 0);
}

template<typename T>
size_t Heap<T>::tamanio() {
    return cantidad_de_datos;
}

template<typename T>
Heap<T>::~Heap() {
    while(!vacio()){
        datos.baja();
        cantidad_de_datos--;
    }
}

template <typename T>
void Heap<T>::restauracion_hacia_arriba(size_t indice_dato){

    if(indice_dato > 0){    //Caso distinto de raiz.

         size_t indice_padre = (indice_dato - 1)/2;

        if(tipo_de_heap){   //CASO HEAP MAXIMA.
            if( (datos[indice_dato] - datos[indice_padre] ) > 0 ){
                swap(indice_dato, indice_padre);
                restauracion_hacia_arriba(indice_padre);
            }
        }
        else    //CASO HEAP MINIMA
        {
            if( (datos[indice_dato] - datos[indice_padre] ) < 0 ){
                swap(indice_dato, indice_padre);
                restauracion_hacia_arriba(indice_padre);
            }
        }
    }
}

template <typename T>
void Heap<T>::restauracion_hacia_abajo(size_t indice_dato){
    if(!vacio()){
        size_t indice_hijo_izquierdo = (2*indice_dato) + 1;
        size_t indice_hijo_derecho = (2*indice_dato) + 2;

        size_t indice_hijo_mayor;
        size_t indice_hijo_menor;
         //CASO 2 HIJOS:
        if(indice_hijo_izquierdo < datos.tamanio() && indice_hijo_derecho < datos.tamanio() ){
            if(tipo_de_heap){
                indice_hijo_mayor = (datos[indice_hijo_izquierdo] > datos[indice_hijo_derecho]) ? indice_hijo_izquierdo : indice_hijo_derecho;

                if(datos[indice_dato] < datos[indice_hijo_mayor]){
                    swap(indice_hijo_mayor,indice_dato);
                    restauracion_hacia_abajo(indice_hijo_mayor);
                }
            }else{
                indice_hijo_menor = (datos[indice_hijo_izquierdo] < datos[indice_hijo_derecho]) ? indice_hijo_izquierdo : indice_hijo_derecho;

                if(datos[indice_dato] > datos[indice_hijo_mayor]){
                     swap(indice_hijo_menor,indice_dato);
                     restauracion_hacia_abajo(indice_hijo_menor);
                }
            }
        }   //CASO 1 SOLO HIJO.
        else if(indice_hijo_izquierdo  < datos.tamanio()){
            if(tipo_de_heap){
                if(datos[indice_hijo_izquierdo] > datos[indice_dato]){
                    swap(indice_hijo_izquierdo,indice_dato);
                    restauracion_hacia_abajo(indice_hijo_izquierdo);
                }
            }else{
                if(datos[indice_hijo_izquierdo] < datos[indice_dato]){
                    swap(indice_hijo_izquierdo,indice_dato);
                    restauracion_hacia_abajo(indice_hijo_izquierdo);
                }
            }
        }
    }
}


template <typename T>
void Heap<T>::swap(size_t i, size_t j){
    T dato_intercambio = datos[i];
    datos[i] = datos[j];
    datos[j] = dato_intercambio;
}

#endif

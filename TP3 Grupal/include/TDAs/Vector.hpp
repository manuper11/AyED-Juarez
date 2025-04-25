#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <stdexcept>

class ExcepcionVector : public std::runtime_error {
public:
    ExcepcionVector(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionVector(): runtime_error("") {
    }
};

template<typename T>
class Vector {
private:
    T* datos;
    size_t tamanio_logico;
    size_t tamanio_fisico;
    //Metodos
    //PRE: -
    //POST: Redimensiona el vector al tamaño indicado
    void redimensionar(size_t nuevo_tamanio);

public:
    // Constructor.
    Vector();
    Vector(size_t tamanio);
    // PRE: -
    // POST: Agrega el dato al final del vector.
    void alta(T dato);

    // PRE: El índice debe ser menor o igual que la cantidad de datos.
    // POST: Agrega el dato en el índice indicado,
    // moviendo todos los elementos siguientes.
    // Ejemplo:
    //      >> 1 3 2 7 0
    // alta(9, 2);
    //      >> 1 3 9 2 7 0
    void alta(T dato, size_t indice);

    // PRE: El vector no puede estar vacío.
    // POST: Elimina el último dato y lo devuelve.
    T baja();

    // PRE: El índice debe ser menor que la cantidad de datos.
    // POST: Elimina el dato en la posición indicada,
    // moviendo todos los elementos siguientes, y lo devuelve.
    // Ejemplo:
    //      >> 1 3 2 7 0
    // baja(1);
    //      >> 1 2 7 0
    T baja(size_t indice);

    // PRE: -
    // POST: Devuelve true si el vector está vacío (es decir, si no hay datos).
    bool vacio();

    // PRE: -
    // POST: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // PRE: El índice debe ser menor que la cantidad de datos.
    // POST: Devuelve una referencia al dato indicado.
    T& operator[](size_t indice);

    // Constructor de copia (ya implementado).
    Vector(const Vector& vector);

    // Operador de asignación (ya implementado).
    Vector& operator=(const Vector& vector);

    //PRE: -
    //POST: Devuelve un vector con los elementos invertidos.
    Vector<T> invertir(Vector<T> vector);


    // Destructor.
    ~Vector();
};

template<typename T>
Vector<T>::Vector() {
    datos = nullptr;
    tamanio_logico = 0;
    tamanio_fisico = 1;
    datos = new T[tamanio_fisico];
}

template<typename T>
Vector<T>::Vector(size_t tamanio_fisico) {
    datos = nullptr;
    tamanio_logico = tamanio_fisico;
    this -> tamanio_fisico = tamanio_fisico;
    datos = new T[tamanio_fisico];
}

template<typename T>
void Vector<T>::redimensionar(size_t nuevo_tamanio) {
    T* datos_nuevos = new T[nuevo_tamanio];
    for (size_t i = 0; i < tamanio_logico; i++) {
        datos_nuevos[i] = datos[i];
    }
    delete[] datos;
    datos = datos_nuevos;
    tamanio_fisico = nuevo_tamanio;
}

template<typename T>
void Vector<T>::alta(T dato) {
    if (tamanio_logico == tamanio_fisico) {
        redimensionar(tamanio_fisico * 2);
    }
    datos[tamanio_logico] = dato;
    tamanio_logico++;
}

template<typename T>
void Vector<T>::alta(T dato, size_t indice) {
    if (indice > tamanio_logico) {
        throw ExcepcionVector("Indice fuera de rango.");
    }
    if (tamanio_logico == tamanio_fisico) {
        redimensionar(tamanio_fisico * 2);
    }
    for (size_t i = tamanio_logico; i > indice; i--) {
        datos[i] = datos[i - 1];
    }
    datos[indice] = dato;
    tamanio_logico++;
}

template<typename T>
T Vector<T>::baja() {
    if (vacio()) {
        throw ExcepcionVector("El vector esta vacio.");
    }
    tamanio_logico--;
    return datos[tamanio_logico];
}

template<typename T>
T Vector<T>::baja(size_t indice) {
    if (indice >= tamanio_logico) {
        throw ExcepcionVector("Indice fuera de rango.");
    }
    T dato = datos[indice];
    for (size_t i = indice; i < tamanio_logico - 1; i++) {
        datos[i] = datos[i + 1];
    }
    tamanio_logico--;
    return dato;
}

template<typename T>
bool Vector<T>::vacio() {
    return tamanio_logico == 0;
}

template<typename T>
size_t Vector<T>::tamanio() {
    return tamanio_logico;
}

template<typename T>
T& Vector<T>::operator[](size_t indice) {
    if (indice >= tamanio_logico) {
        throw ExcepcionVector("Indice fuera de rango");
    }
    return datos[indice];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] datos;
}

template<typename T>
Vector<T>::Vector(const Vector& vector) {
    datos = nullptr;
    tamanio_logico = vector.tamanio_logico;
    tamanio_fisico = vector.tamanio_fisico;
    if (tamanio_fisico) {
        datos = new T[tamanio_fisico];
        for (size_t i = 0; i < tamanio_logico; i++) {
            datos[i] = vector.datos[i];
        }
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) {
    if (this != &vector) {
        delete[] datos;
        datos = nullptr;
        tamanio_logico = vector.tamanio_logico;
        tamanio_fisico = vector.tamanio_fisico;
        if (tamanio_fisico) {
            datos = new T[tamanio_fisico];
            for (size_t i = 0; i < tamanio_logico; i++) {
                datos[i] = vector.datos[i];
            }
        }
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::invertir(Vector<T> vector)
{
    if(vector.tamanio() == 0) throw ExcepcionVector("El vector esta vacio.");

    T dato;
    size_t contador = vector.tamanio();

    for (size_t i = 0; i < contador; i++)
    {
        dato = vector[i];
        vector[i] = vector[contador - 1];
        vector[contador - 1] = dato;
        contador--;
    }
    
    return vector;
}

#endif

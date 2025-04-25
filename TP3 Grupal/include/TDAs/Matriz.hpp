#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <cstddef>
#include <stdexcept>

class ExcepcionMatriz : public std::runtime_error {
public:
    ExcepcionMatriz(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionMatriz(): runtime_error("") {
    }
};

template<typename T>
class Matriz {
protected:
    T* datos;
    size_t filas;
    size_t columnas;

    // Pre: -
    // Post: Devuelve true si el indice es valido (0 <= i < filas, 0 <= j < columnas).
    bool indice_valido(size_t i, size_t j);

    // Pre: El índice bidimensional debe ser válido.
    // Post: Devuelve el índice unidimensional equivalente al ingresado.
    size_t calcular_indice(size_t i, size_t j);

public:
    // Constructor default.
    // NOTA: No tiene sentido una matríz 0x0, por lo que no se debería usar directamente.
    // Está implementado solamente por temas de C++ (default-constructible).
    Matriz();

    // Pre: El tamaño no puede ser 0.
    // Post: Genera una matriz cuadrada con el tamaño indicado, inicializada con el valor ingresado.
    Matriz(size_t tamanio, T valor);

    // Pre: El tamaño no puede ser 0.
    // Post: Genera una matriz cuadrada vacía con el tamaño indicado.
    Matriz(size_t tamanio);

    // Pre: Ninguna de las dimensiones puede ser 0.
    // Post: Genera una matriz con las dimensiones indicadas, inicializada con el valor ingresado.
    Matriz(size_t filas, size_t columnas, T valor);

    // Pre: Ninguna de las dimensiones puede ser 0.
    // Post: Genera una matriz vacía con las dimensiones indicadas.
    Matriz(size_t fila, size_t columna);

    // Constructor de copia.
    Matriz(const Matriz& matriz);

    // Operador de asignación.
    Matriz& operator=(const Matriz& matriz);

    // Pre: El índice debe ser válido, es decir, 0 <= i < filas, 0 <= j < columnas.
    // Post: Devuelve una referencia al elemento accedido.
    T& operator()(size_t i, size_t j);

    // Pre: Ninguna de las dimensiones puede ser menor que 1.
    // Post: Redimensiona la matriz al tamaño deseado. Los datos anteriores son copiados, de ser posible.
    void redimensionar(size_t filas, size_t columnas);

    // Pre: -
    // Post: Devuelve la cantidad de filas de la matriz.
    size_t obtener_filas();

    // Pre: -
    // Post: Devuelve la cantidad de columnas de la matriz.
    size_t obtener_columnas();

    // Destructor.
    ~Matriz();
};

template<typename T>
Matriz<T>::Matriz() {
    filas = 0;
    columnas = 0;
    datos = nullptr;
}

template<typename T>
Matriz<T>::Matriz(size_t filas, size_t columnas, T valor) {
    if (filas < 1 || columnas < 1) {
        throw ExcepcionMatriz("ERROR: las dimensiones no son válidas.");
    }
    this->filas = filas;
    this->columnas = columnas;
    datos = new T[filas * columnas];
    for (size_t i = 0; i < filas * columnas; i++) {
        datos[i] = valor;
    }
}

template<typename T>
Matriz<T>::Matriz(size_t fila, size_t columna) : Matriz(fila, columna, T()) {
}

template<typename T>
Matriz<T>::Matriz(size_t tamanio, T valor) : Matriz(tamanio, tamanio, valor) {
}

template<typename T>
Matriz<T>::Matriz(size_t tamanio) : Matriz(tamanio, tamanio, T()) {
}

template<typename T>
Matriz<T>::Matriz(const Matriz& matriz) {
    filas = matriz.filas;
    columnas = matriz.columnas;
    datos = nullptr;
    if (matriz.datos) {
        datos = new T[filas * columnas];
        for (size_t i = 0; i < filas * columnas; i++) {
            datos[i] = matriz.datos[i];
        }
    }
}

template<typename T>
Matriz<T>& Matriz<T>::operator=(const Matriz& matriz) {
    if (this != &matriz) {
        delete[] datos;
        filas = matriz.filas;
        columnas = matriz.columnas;
        datos = nullptr;
        if (matriz.datos) {
            datos = new T[filas * columnas];
            for (size_t i = 0; i < filas * columnas; i++) {
                datos[i] = matriz.datos[i];
            }
        }
    }
    return *this;
}

template<typename T>
bool Matriz<T>::indice_valido(size_t i, size_t j) {
    return i < filas && j < columnas;
}

template<typename T>
size_t Matriz<T>::calcular_indice(size_t i, size_t j) {
    return i * columnas + j;
}

template<typename T>
T& Matriz<T>::operator()(size_t i, size_t j) {
    if (!(i < filas && j < columnas)) {
        throw ExcepcionMatriz("ERROR: el índice ingresado no es válido.");
    }
    return datos[calcular_indice(i, j)];
}

template<typename T>
void Matriz<T>::redimensionar(size_t filas, size_t columnas) {
    if (filas < 1 || columnas < 1) {
        throw ExcepcionMatriz("ERROR: las dimensiones no son válidas.");
    }
    T* aux = new T[filas * columnas];
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            try {
                aux[i * columnas + j] = (*this)(i, j);
            } catch (ExcepcionMatriz& _) {
                aux[i * columnas + j] = T();
            }
        }
    }
    this->filas = filas;
    this->columnas = columnas;
    delete[] datos;
    datos = aux;
}

template<typename T>
size_t Matriz<T>::obtener_filas() {
    return filas;
}

template<typename T>
size_t Matriz<T>::obtener_columnas() {
    return columnas;
}

template<typename T>
Matriz<T>::~Matriz() {
    delete[] datos;
}

#endif

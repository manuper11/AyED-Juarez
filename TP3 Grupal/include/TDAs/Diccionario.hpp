#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

#include <cstddef>
#include <stdexcept>
#include "NodoDiccionario.hpp"
#include "Vector.hpp"
#include "Cola.hpp"

class ExcepcionDiccionario : public std::runtime_error {
public:
    ExcepcionDiccionario(std::string mensaje): runtime_error(mensaje) {
    }

    ExcepcionDiccionario(): runtime_error("") {
    }
};

// La clave debe implementar el operator<() y el operator==().
// Las claves menores a la clave de la raíz iran al subárbol izquierdo,
// mientras que las mayores iran al derecho.
template<typename Clave, typename T>
class Diccionario {
private:
    NodoDiccionario<Clave, T>* raiz;
    std::size_t cantidad_datos;

    
    //Post: Destruye los nodos.
    void destruir(NodoDiccionario<Clave, T>* nodo);

    // Pre: La clave no puede existir en el diccionario.
    // Post: Agrega el dato asociado a la clave al diccionario. Si no hay datos, crea una nueva raíz.
    void alta_recursiva(Clave clave, T dato, NodoDiccionario<Clave, T>* padre);

    // Post: Devuelve el recorrido inorder.
    void inorder_recursivo(NodoDiccionario<Clave,T>* raiz, Vector<T>& vector);

    // Post: Devuelve el recorrido postrder.
    void postorder_recursivo(NodoDiccionario<Clave,T>* raiz, Vector<T>& vector);

    // Post: Devuelve el recorrido preorder.
    void preorder_recursivo(NodoDiccionario<Clave,T>* raiz, Vector<T>& vector);

    //Post: Retorna nullptr si la clave no existe, de lo contario devuelve el nodo asociado a la clave.
    NodoDiccionario<Clave,T>* consulta_recursiva(Clave clave, NodoDiccionario<Clave,T>* raiz);

    //Post: Retorna el nodo inmediatamente mayor al ingresado.
    NodoDiccionario<Clave,T>* inmediato_sucesor(NodoDiccionario<Clave,T>* nodo);

    //Post: Retorna el nodo inmediatamente menor al ingresado.
    NodoDiccionario<Clave,T>* inmediato_predecesor(NodoDiccionario<Clave,T>* nodo);


    // Pre: La clave debe existir en el diccionario.
    // Post: Elimina el dato asociado a la clave del diccionario y devuelve la nueva raiz.
    NodoDiccionario<Clave,T>* baja_recursiva(NodoDiccionario<Clave,T>* nodo, Clave clave, T& dato_a_devolver);


public:
    // Constructor.
    Diccionario();

    // Pre: La clave no puede existir en el diccionario.
    // Post: Agrega el dato asociado a la clave al diccionario. Si no hay datos, crea una nueva raíz.
    void alta(Clave clave, T dato);

    // Pre: La clave debe existir en el diccionario.
    // Post: Elimina el dato asociado a la clave del diccionario y lo devuelve.
    // NOTA: El caso de baja con dos hijos se resuelve con sucesor inmediato. Se puede hacer swap del dato.
    T baja(Clave clave);

    // Pre: La clave debe existir en el diccionario.
    // Post: Devuelve una referencia al valor asociado a la clave.
    T& operator[](Clave clave);

    // Pre: -
    // Post: Devuelve el recorrido inorder.
    Vector<T> inorder();

    // Pre: -
    // Post: Devuelve el recorrido preorder.
    Vector<T> preorder();

    // Pre: -
    // Post: Devuelve el recorrido postorder.
    Vector<T> postorder();

    // Pre: -
    // Post: Devuelve el recorrido en ancho (por niveles).
    Vector<T> ancho();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el diccionario.
    std::size_t tamanio();

    // Pre: -
    // Post: Devuelve true si el diccionario está vacío.
    bool vacio();

    // El constructor de copia está deshabilitado.
    Diccionario(const Diccionario& diccionario) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Diccionario& diccionario) = delete;

    //Post: Devuelve true si existe la clave, o false si la clave no esta guardada.
    bool consulta(Clave clave);

    // Destructor.
    ~Diccionario();
};

template<typename Clave, typename T>
Diccionario<Clave, T>::Diccionario() {
    raiz = nullptr;
    cantidad_datos = 0;
}

template<typename Clave, typename T>
void Diccionario<Clave, T>::alta(Clave clave, T dato) {
      if(raiz){
          alta_recursiva(clave,dato,raiz);
      }
      else{
          raiz = new NodoDiccionario<Clave, T>(clave,dato,raiz,nullptr,nullptr);
      }
      cantidad_datos ++;
}

template<typename Clave, typename T>
T Diccionario<Clave, T>::baja(Clave clave) {
    if(consulta(clave)){
        T dato_a_devolver;
        raiz = baja_recursiva(raiz,clave,dato_a_devolver);
        cantidad_datos--;
        //Si no hay sucesor buscar el predecesor.
        return dato_a_devolver;
    }
    throw ExcepcionDiccionario("El diccionario no contine a esa clave.");
}

template<typename Clave, typename T>
T& Diccionario<Clave, T>::operator[](Clave clave) {
    if(!consulta(clave))
        throw ExcepcionDiccionario("La clave no existe");
    NodoDiccionario<Clave, T>* nodo = consulta_recursiva(clave,raiz);
    return nodo -> obtener_dato();
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::inorder() {
    if(vacio())
        throw ExcepcionDiccionario("El diccionario esta vacio!");
    Vector<T> recorrido;
    inorder_recursivo(raiz,recorrido);
    return recorrido;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::preorder() {
    if(vacio())
        throw ExcepcionDiccionario("El diccionario esta vacio!");
    Vector<T> recorrido;
    preorder_recursivo(raiz,recorrido);
    return recorrido;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::postorder() {
    if(vacio())
        throw ExcepcionDiccionario("El diccionario esta vacio!");
    Vector<T> recorrido;
    postorder_recursivo(raiz,recorrido);
    return recorrido;
}

template<typename Clave, typename T>
Vector<T> Diccionario<Clave, T>::ancho() {
    Vector<T> recorrido;
    Cola<NodoDiccionario<Clave, T>*> nodos;
    if(raiz)
        nodos.alta(raiz);
    while(!nodos.vacio()){
        NodoDiccionario<Clave,T>* nodo_actual = nodos.baja();

        if(nodo_actual -> obtener_hijo_izquierdo()){
            nodos.alta(nodo_actual -> obtener_hijo_izquierdo());
        }

        if(nodo_actual -> obtener_hijo_derecho()){
            nodos.alta(nodo_actual -> obtener_hijo_derecho());
        }
        recorrido.alta(nodo_actual -> obtener_clave());
    }
    return recorrido;

}

template<typename Clave, typename T>
std::size_t Diccionario<Clave, T>::tamanio() {
    return cantidad_datos;
}

template<typename Clave, typename T>
bool Diccionario<Clave, T>::vacio() {
    return (cantidad_datos == 0);
}

template <typename Clave, typename T>
bool Diccionario<Clave, T>::consulta(Clave clave)
{
    return (consulta_recursiva(clave,raiz));
}

template <typename Clave, typename T>
Diccionario<Clave, T>::~Diccionario()
{
    destruir(raiz);
}

template <typename Clave, typename T>
void Diccionario<Clave, T>::destruir(NodoDiccionario<Clave, T>* nodo) {
    if (nodo) {
        destruir(nodo->obtener_hijo_izquierdo());
        destruir(nodo->obtener_hijo_derecho());
        delete nodo;
    }
}

//Metodos recursivos:
template<typename Clave, typename T>
void Diccionario<Clave, T>::alta_recursiva(Clave clave, T dato, NodoDiccionario<Clave,T>* nodo){
    if(nodo -> obtener_clave() == clave){
        throw ExcepcionDiccionario("Clave repetida");
    }

    if(clave > nodo -> obtener_clave() ){
        if(!nodo -> obtener_hijo_derecho())
            nodo -> cambiar_hijo_derecho(new NodoDiccionario<Clave,T>(clave,dato,nodo,nullptr,nullptr));
        else 
            alta_recursiva(clave,dato, nodo -> obtener_hijo_derecho());
    }
    else {
        if(!nodo -> obtener_hijo_izquierdo())
            nodo -> cambiar_hijo_izquierdo(new NodoDiccionario<Clave,T>(clave,dato,nodo,nullptr,nullptr));
        else 
            alta_recursiva(clave,dato, nodo -> obtener_hijo_izquierdo());
    }
}

template <typename Clave, typename T>
void Diccionario<Clave, T>::inorder_recursivo(NodoDiccionario<Clave,T> *raiz, Vector<T> &vector)
{
    if( raiz -> obtener_hijo_izquierdo() != nullptr){
        inorder_recursivo(raiz -> obtener_hijo_izquierdo(), vector);
    }
    vector.alta(raiz ->obtener_dato());
    if( raiz -> obtener_hijo_derecho() != nullptr){
        inorder_recursivo(raiz -> obtener_hijo_derecho(), vector);
    }
}

template <typename Clave, typename T>
void Diccionario<Clave, T>::postorder_recursivo(NodoDiccionario<Clave, T> *raiz, Vector<T> &vector)
{
    if( raiz -> obtener_hijo_izquierdo() != nullptr){
       postorder_recursivo(raiz -> obtener_hijo_izquierdo(), vector);
   }
   if( raiz -> obtener_hijo_derecho() != nullptr){
       postorder_recursivo(raiz -> obtener_hijo_derecho(), vector);
   }
   vector.alta(raiz ->obtener_dato());
}

template <typename Clave, typename T>
void Diccionario<Clave, T>::preorder_recursivo(NodoDiccionario<Clave, T> *raiz, Vector<T> &vector)
{
   vector.alta(raiz ->obtener_dato());
    if( raiz -> obtener_hijo_izquierdo() != nullptr){
       preorder_recursivo(raiz -> obtener_hijo_izquierdo(), vector);
   }
   if( raiz -> obtener_hijo_derecho() != nullptr){
       preorder_recursivo(raiz -> obtener_hijo_derecho(), vector);
   }
}

template <typename Clave, typename T>
NodoDiccionario<Clave, T>* Diccionario<Clave, T>::consulta_recursiva(Clave clave, NodoDiccionario<Clave, T> *raiz)
{
    
    if(!raiz)   //Caso vacio.
        return raiz;

   if(raiz -> obtener_clave() == clave){
        return raiz;
   }

    if(clave > raiz -> obtener_clave()){
        return consulta_recursiva(clave,raiz -> obtener_hijo_derecho());
    }
    else{
        return consulta_recursiva(clave, raiz -> obtener_hijo_izquierdo());
    }
}


template <typename Clave, typename T>
NodoDiccionario<Clave, T> *Diccionario<Clave, T>::inmediato_predecesor(NodoDiccionario<Clave, T> * nodo){
    NodoDiccionario<Clave, T>* nodo_sucesor = nodo;
     if(nodo -> obtener_hijo_izquierdo() != nullptr ){
        nodo_sucesor = nodo -> obtener_hijo_izquierdo();
             while(nodo_sucesor ->obtener_hijo_derecho() != nullptr){
                 nodo_sucesor = nodo_sucesor -> obtener_hijo_derecho();
             }
     }
    return nodo_sucesor;
}

template <typename Clave, typename T>
NodoDiccionario<Clave, T>* Diccionario<Clave, T>::baja_recursiva(NodoDiccionario<Clave, T> *nodo, Clave clave, T &dato_a_devolver)
{
     if (nodo == nullptr) {
        throw ExcepcionDiccionario("Clave no encontrada");
    }

    if (clave < nodo-> obtener_clave()) {
        nodo->cambiar_hijo_izquierdo( baja_recursiva(nodo->obtener_hijo_izquierdo(), clave, dato_a_devolver) );
    } else if (clave > nodo -> obtener_clave()) {
        nodo->cambiar_hijo_derecho(baja_recursiva(nodo->obtener_hijo_derecho(), clave, dato_a_devolver));
    } else {
        dato_a_devolver = nodo-> obtener_dato();
        if (nodo-> obtener_hijo_izquierdo() == nullptr) {
            NodoDiccionario<Clave, T>* nueva_raiz_del_subarbol = nodo->obtener_hijo_derecho();
            delete nodo;
            return nueva_raiz_del_subarbol;
        } else if (nodo->obtener_hijo_derecho() == nullptr) {
            NodoDiccionario<Clave, T>* nueva_raiz_del_subarbol = nodo-> obtener_hijo_izquierdo();
            delete nodo;
            return nueva_raiz_del_subarbol;
        } else {
            NodoDiccionario<Clave, T>* sucesor = inmediato_sucesor(nodo);
            nodo-> cambiar_clave(sucesor -> obtener_clave());
            nodo-> cambiar_dato(sucesor-> obtener_dato());
            nodo->cambiar_hijo_derecho(  baja_recursiva(nodo->obtener_hijo_derecho(), sucesor-> obtener_clave(), dato_a_devolver) );
        }
    }
    return nodo;
}

template <typename Clave, typename T>
NodoDiccionario<Clave, T> *Diccionario<Clave, T>::inmediato_sucesor(NodoDiccionario<Clave, T> * nodo){
    NodoDiccionario<Clave, T>* nodo_sucesor = nodo;
     if(nodo -> obtener_hijo_derecho() != nullptr ){
        nodo_sucesor = nodo -> obtener_hijo_derecho();
             while(nodo_sucesor ->obtener_hijo_izquierdo() != nullptr){
                 nodo_sucesor = nodo_sucesor -> obtener_hijo_izquierdo();
             }
     }
    return nodo_sucesor;
}

#endif

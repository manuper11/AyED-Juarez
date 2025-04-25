//
// Created by mauro on 12/11/24.
//
#ifndef MANEJOTRANSFORMER_H
#define MANEJOTRANSFORMER_H

#include "Transformer.hpp"
#include "Diccionario.hpp"
#include "Vector.hpp"

const std::string RUTA_TRANSFORMERS = "transformers.csv";

class ManejoTransformer {
private:
    //atributos:
    Diccionario<std::string,Transformer*> transformers;
    size_t cantidad_transformers;
    Vector<Transformer*> listado;
    //metodos privados
    //pre:-
    //post: actualiza el archivo de transformers secundarios.
    void actualizar_archivo();
    //pre:-
    //post: carga los datos desde el archivo de transformers.
    void cargar_archivo();

public:
    //constructor
    ManejoTransformer();
    //pre:-
    //post: muestra todos los transformers del listado.
    void mostrar_listado_transformers();
    //pre:-
    //post: devuelve la cantidad de transformers en el listado.
    size_t obtener_cantidad_transformer();
    //pre:-
    //post: devuelve el transformer si esta en el listado.
    Transformer* busqueda_transformer(std::string nombre);
    //pre:-
    //post: agrega el transformer al listado.
    void alta_transformer(std::string nombre,size_t fuerza,size_t defensa, size_t velocidad, size_t faccion, size_t vehiculo, bool transformado);
    //pre:-
    //post: elimina el transformer del listado.
    void baja_transformer(std::string nombre);
    //pre:-
    //post: transforma el transformer.
    void transformar_transformer(Transformer* transformer);
    //Destructor
    ~ManejoTransformer();
    //pre:-
    //post: devuelve un vector con los transformers.
    Vector<Transformer*> obtener_transformers();
};

#endif //MANEJOTRANSFORMER_H
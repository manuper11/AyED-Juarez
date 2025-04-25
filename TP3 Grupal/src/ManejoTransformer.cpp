#include "ManejoTransformer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

ManejoTransformer::ManejoTransformer(){
    cargar_archivo();
    if(transformers.tamanio() == 0){
        cantidad_transformers = 0;
    } else{
        cantidad_transformers = transformers.tamanio();
    }
}

void ManejoTransformer::cargar_archivo(){
    std::ifstream archivo(RUTA_TRANSFORMERS, std::ios::in);

    if(archivo.is_open()){
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream stream(linea);
            std::string nombre, faccion_str, vehiculo_str, transformado_str;
            size_t fuerza, defensa, velocidad, vehiculo;
            bool faccion;
            bool transformado;

            std::getline(stream, nombre, ',');
            stream >> fuerza;
            stream.ignore(1, ',');//permite que se pueda el dato como size_t
            stream >> defensa;
            stream.ignore(1, ',');
            stream >> velocidad;
            stream.ignore(1, ',');
            std::getline(stream, faccion_str, ',');
            std::getline(stream, vehiculo_str, ',');
            std::getline(stream, transformado_str, ',');

            faccion = (faccion_str == "Autobots") ? true : false;

            if (vehiculo_str == "Auto") vehiculo = coche;
            else if (vehiculo_str == "Camion") vehiculo = camion;
            else if (vehiculo_str == "Tanque") vehiculo = tanque;
            else vehiculo = avion;

            transformado = (transformado_str == "Si") ? true : false;

            Transformer* transformer = new Transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo, transformado);
            listado.alta(transformer);
            transformers.alta(nombre, transformer);
        }
        archivo.close();
    } else{
        std::cout << "No se pudo abrir el archivo" << std::endl;
    }
}

void ManejoTransformer::actualizar_archivo(){
    std::ofstream archivo(RUTA_TRANSFORMERS, std::ios::out);
    if(archivo.is_open()){
        Vector<Transformer*> listado = transformers.inorder();
        for(size_t i = 0; i < transformers.tamanio(); i++){
            archivo << listado[i]->obtener_nombre() << "," << listado[i]->obtener_fuerza() << ","
                  << listado[i]->obtener_defensa() << "," << listado[i]->obtener_velocidad() << ",";

            listado[i]->obtener_faccion() == true ? archivo << "Autobots," : archivo << "Decepticons,";

            if(listado[i]->obtener_vehiculo() == coche) archivo << "Auto,";
            else if(listado[i]->obtener_vehiculo() == camion) archivo << "Camion,";
            else if(listado[i]->obtener_vehiculo() == tanque) archivo << "Tanque,";
            else archivo << "Avion,";

            listado[i]->esta_tranformado() ? archivo << "Si" : archivo << "No";

            archivo << std::endl;
        }
        archivo.close();
    } else{
        std::cout << "No se pudo abrir el archivo" << std::endl;
    }
}

void ManejoTransformer::mostrar_listado_transformers(){
    Vector<Transformer*> listado = transformers.inorder();
    for(size_t i = 0; i < cantidad_transformers; i++){
        std::cout << "Nombre: " << listado[i]->obtener_nombre() << std::endl;
        std::cout << "Fuerza: " << listado[i]->obtener_fuerza() << std::endl;
        std::cout << "Defensa: " << listado[i]->obtener_defensa() << std::endl;
        std::cout << "Velocidad: " << listado[i]->obtener_velocidad() << std::endl;

        std::cout << "Faccion: ";
        listado[i]->obtener_faccion() == true ? std::cout << "Autobots" << std::endl : std::cout << "Decepticons" << std::endl;

        std::cout << "Vehiculo: ";
        if(listado[i]->obtener_vehiculo() == coche) std::cout << "Auto" << std::endl;
        else if(listado[i]->obtener_vehiculo() == camion) std::cout << "Camion" << std::endl;
        else if(listado[i]->obtener_vehiculo() == tanque) std::cout << "Tanque" << std::endl;
        else std::cout << "Avion" << std::endl;

        listado[i]->esta_tranformado() ? std::cout << "Transformado: Si" << std::endl : std::cout << "Transformado: No" << std::endl;
        std::cout << std::endl;
    }
}

size_t ManejoTransformer::obtener_cantidad_transformer(){
    return cantidad_transformers;
}

Transformer* ManejoTransformer::busqueda_transformer(std::string nombre){
    return transformers[nombre];
}

void ManejoTransformer::alta_transformer(std::string nombre, size_t fuerza, size_t defensa, size_t velocidad, size_t faccion, size_t vehiculo, bool transformado){
    Transformer* transformer = new Transformer(nombre, fuerza, defensa, velocidad, faccion, vehiculo, transformado);
    transformers.alta(nombre, transformer);
    listado.alta(transformer);
    cantidad_transformers++;
    actualizar_archivo();
}

void ManejoTransformer::baja_transformer(std::string nombre){
    size_t i = 0;
    bool encontrado = false;
    while (i < listado.tamanio() && !encontrado) {
        if (listado[i]->obtener_nombre() == nombre) {
            delete listado[i];
            listado.baja(i);
            encontrado = true;
        }
        i++;
    }
    transformers.baja(nombre);
    cantidad_transformers--;
    actualizar_archivo();
}


void ManejoTransformer::transformar_transformer(Transformer* transformer){
    transformer->transformar();
    actualizar_archivo();
}

Vector<Transformer*> ManejoTransformer::obtener_transformers() {
    return listado;
}

ManejoTransformer::~ManejoTransformer(){
    Vector<Transformer*> listado = transformers.inorder();
    for(size_t i = 0; i < cantidad_transformers; i++){
        delete listado[i];
    }
}
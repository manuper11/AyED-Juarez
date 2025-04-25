#ifndef ARCHIVOS_HPP
#define ARCHIVOS_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include "TDAs/Diccionario.hpp"

const std::string RUTA_TABLA = "tabla_clasificaciones.csv";

class Archivo{
private:
    Diccionario<std::string, Vector<std::string>>* partida;
    size_t id;
public:
    //Constructor
    Archivo();
    //PRE: -
    //POST: Carga los datos del archivo en un diccionario de vectores
    void guardar_datos_en_diccionario();
    //PRE: -
    //POST: Imprime por pantalla el contenido del archivo
    void mostrar_contenido();
    //PRE: -
    //POST: Guarda los datos del archivo en un string
    std::string preservar_datos();
    //PRE: -
    //POST: Guarda los datos de la partida en el archivo
    void guardar_datos(std::string datos_guardados, bool personaje, std::string nombre_jugador, size_t puntaje);
    //Destructor
    ~Archivo();
};
#endif
#include "Archivos.hpp"
#include <sstream>
void Archivo::mostrar_contenido(){
    if (partida == nullptr)
        guardar_datos_en_diccionario();
    if(partida){
        Vector<Vector<std::string>> jugadores; 
        jugadores = jugadores.invertir(partida->inorder());
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|  Jugador  |   Puntaje  |    Personaje Principal  |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        for(size_t i = 0; i < jugadores.tamanio(); i++){
            Vector<std::string> jugador = jugadores[i];
            std::cout << "| " << std::setw(9) << std::left << jugador[0] << " | " << std::setw(10) << std::right << jugador[1] << " | " << std::setw(23) << std::left << jugador[2] << " |" << std::endl;

        }
        std::cout << "----------------------------------------------------" << std::endl;
    }else{
        std::cout<<"La tabla esta vacia" <<std::endl;
    }
}

Archivo::Archivo(){
    id = 0;
    partida = nullptr;
}

void Archivo::guardar_datos_en_diccionario()
{
    std::ifstream archivo(RUTA_TABLA);
    partida = new Diccionario<std::string, Vector<std::string>>();
    Vector<std::string> datos_jugador;
    if(archivo.is_open()){
        if(archivo.peek() == EOF){
            std::cout << "No hay datos registrados, tabla vacia" << std::endl;
        }
        std::string nombre_jugador;
        std::string personaje;
        std::string puntaje;
        std::string id;
        while(getline(archivo, nombre_jugador, ',')){
            getline(archivo, puntaje, ',');
            getline(archivo, personaje, ',');
            getline(archivo,id);
            datos_jugador.alta(nombre_jugador);
            datos_jugador.alta(puntaje);
            datos_jugador.alta(personaje);
            std::string clave_unica = puntaje +'_'+ id;
            partida->alta(clave_unica, datos_jugador);
            datos_jugador.baja();
            datos_jugador.baja();
            datos_jugador.baja();
        }
    }
    archivo.close();
}

std::string Archivo::preservar_datos(){
    std::ifstream archivo(RUTA_TABLA);
    std::string preservo_archivo;

    if(archivo.is_open()){
        std::string nombre_jugador;
        std::string personaje;
        std::string puntaje;
        std::string id;
        while(getline(archivo, nombre_jugador, ',')){
            getline(archivo, puntaje, ',');
            getline(archivo, personaje, ',');
            getline(archivo, id);
            preservo_archivo += nombre_jugador + ',' + puntaje + ',' + personaje + ',' + id + '\n';
        }
        size_t num;
        std::stringstream ss(id);
        ss >> num;
        this -> id = num;
    }
    archivo.close();
    return preservo_archivo;
}

void Archivo::guardar_datos(std::string datos_guardados, bool personaje, std::string nombre_jugador, size_t puntaje){
    std::ofstream archivo_clasificaciones(RUTA_TABLA);
    std::string personaje_principal;
    if(personaje){
        personaje_principal = "OptimusPrime";
    }else{
        personaje_principal = "Megatron";
    }
    if(archivo_clasificaciones.is_open()){
        archivo_clasificaciones << datos_guardados;
        archivo_clasificaciones << nombre_jugador << ',';
        archivo_clasificaciones << puntaje << ',';
        archivo_clasificaciones << personaje_principal << ',';
        id++;
        archivo_clasificaciones << id << '\n';
    }
    archivo_clasificaciones.close();
}

Archivo::~Archivo(){
    delete partida;
}
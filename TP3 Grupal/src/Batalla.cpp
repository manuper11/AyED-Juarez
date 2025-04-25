#include "Batalla.hpp"
#include "ManejoTransformer.hpp"
#include "Vector.hpp"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

const int PESO_MISMA_FACCION = 30;
const int PESO_MISMO_PODER = 50;
const int PESO_MINIMO = 10;
const int PESO_MAXIMO = 100;

const int NODOS_MAX_POR_NIVEL = 3;

const int PUNTAJE_MAXIMO = 50;
const int PUNTAJE_MINIMO = 25;

Batalla::Batalla(bool personaje, size_t poder, ManejoTransformer& manejo, std::string nombre_jugador){
    this -> personaje = personaje;
    this -> nombre_jugador = nombre_jugador;
    poder_personaje_principal = poder;
    listado = manejo.obtener_transformers();
    mapa_batalla = Grafo(listado.tamanio() + 2);
    carga_personajes();
    energia_energon = 500;
    puntaje = 0;
}

Batalla::Batalla()
{
}

int Batalla::eleccion_peso(size_t indice_nodo)
{
    int peso = PESO_MINIMO;
   
    if (indice_nodo == listado.tamanio()) {
        peso = PESO_MISMO_PODER;
    } else {
        if (listado[indice_nodo]->obtener_faccion() == personaje) {
            peso = PESO_MISMA_FACCION;
        } else {
            double total_poder = (double)poder_personaje_principal + (double)listado[indice_nodo]->obtener_poder();
            double proporcion = (std::abs((double)poder_personaje_principal - (double)listado[indice_nodo]->obtener_poder()) / total_poder)*2;
            if (listado[indice_nodo]->obtener_poder() == poder_personaje_principal) {
                peso = PESO_MISMO_PODER;
            }
            else if (poder_personaje_principal > listado[indice_nodo]->obtener_poder()) {
                peso = PESO_MISMO_PODER - static_cast<int>(proporcion * 40);  // 40 es el rango de ajuste
                peso = (peso < PESO_MINIMO) ? PESO_MINIMO : peso;
            } else {
                peso = PESO_MISMO_PODER + static_cast<int>(proporcion * 50);  // 50 es el rango de ajuste
                peso = (peso > PESO_MAXIMO) ? PESO_MAXIMO : peso;
            }
        }
    }
    return peso;
}


Camino Batalla::proxima_jugada()
{
    mapa_batalla.usar_dijkstra();
    Camino nuevo_camino;
    nuevo_camino = mapa_batalla.obtener_camino_minimo(nodo_origen,nodo_final);
    return nuevo_camino;
}

void Batalla::carga_personajes() {

    int peso;
    size_t nodo_numero = 0;
    size_t i;
    size_t nivel;
    size_t num_nodos;
    size_t siguiente_nodo;
    size_t nodo;

    size_t total_nodos = listado.tamanio() + 2;

    size_t nivel_max = (total_nodos / NODOS_MAX_POR_NIVEL) + 2; // Cantidad de niveles
    // +2 porque hay que tomar en cuenta las puntas, 1 para el origen y 1 para el final.

    Vector<size_t> nodos_por_nivel(nivel_max);  // Aseguramos que el vector tiene espacio

    nodos_por_nivel[0] = 1; // En el nivel 0 va a estar solo el origen.
    nodos_por_nivel[nivel_max - 1] = 1; // En el último nivel estará el nodo final.

    size_t nodos_restantes = listado.tamanio();

    for (i = 1; i < nivel_max - 1; i++) {
        if (nodos_restantes >= NODOS_MAX_POR_NIVEL) {
            nodos_por_nivel[i] = NODOS_MAX_POR_NIVEL;
            nodos_restantes -= NODOS_MAX_POR_NIVEL;
        } else {
            nodos_por_nivel[i] = nodos_restantes;
            nodos_restantes = 0;
        }
    }

    Vector<Vector<size_t>> nodos;  // Vector de vectores para almacenar los nodos por nivel, cada vector represneta un nivel y dentro de este vector se encuentran los nodos.

    // Construir los nodos por nivel
    for (nivel = 0; nivel < nivel_max; nivel++) {
        num_nodos = nodos_por_nivel[nivel]; // Número de nodos por nivel

        nodos.alta(Vector<size_t>());
        for (i = 0; i < num_nodos; i++) {
            nodos[nivel].alta(nodo_numero + i);
        }
        nodo_numero += num_nodos;
    }

    nodo_origen = nodos[0][0];
    nodo_final = nodos[nivel_max - 1][nodos[nivel_max - 1].tamanio() - 1]; // El último nodo del último nivel

    // Conexiones de nodos
    for (nivel = 0; nivel < nivel_max - 1; nivel++) {
        for (i = 0; i < nodos[nivel].tamanio(); i++) {
            nodo = nodos[nivel][i];
            for (size_t j = 0; j < nodos[nivel + 1].tamanio(); j++) {
                siguiente_nodo = nodos[nivel + 1][j];
                peso = eleccion_peso(siguiente_nodo - 1);
                mapa_batalla.agregar_arista(nodo, siguiente_nodo, peso);
            }
        }
    }
}


void Batalla::Pelea(Vector<size_t> camino, OptimusPrime& optimus, Megatron& megatron){
    carga_estadisticas(optimus,megatron);

    int puntaje_diferencia = 0;
    puntaje = 0;
    size_t indice;

        for (size_t i = 1; i < camino.tamanio()-1; i++){
            std::cout << "\033[1;36m Tu Poder: \033[0m" << poder_personaje_principal << std::endl;
            indice = camino[i] - 1;
            if (listado[indice]->obtener_faccion() == personaje) {
                puntaje += PUNTAJE_MINIMO;
                std::cout << "\033[0;37mAvance libre, aliado a la vista!\033[0m" << std::endl;
            }
            else {
                transformar(indice,optimus,megatron); //Opcion para preguntarle al personaje principal si desea transformarse.
                if(rand() % 2 == 0 )  // 50% de probabilidad de transformarse
                    transformar_intermedios(indice);
                size_t estadisticas_contrincante[] = {listado[indice]->obtener_fuerza(), listado[indice]->obtener_defensa(), listado[indice]->obtener_velocidad()};
                puntaje_diferencia = enfrentamiento(estadisticas_contrincante);
                imprimir_dialogos();
                mostrar_puntaje(puntaje_diferencia);
            }
            std::cout << "\033[1;36mPuntaje: \033[0m" << puntaje << std::endl;
            std::cout << "\033[1;36m--------------------------------------------------------------------------------------------------------------------------------------------------\033[0m" << std::endl;
        }
        std::cout << "\n\n";
        std::cout << "\033[1;31m+-------------------------->Pelea Jefe Final<--------------------------+\033[0m" << std::endl;
        
        pelea_final(optimus,megatron);

        std::cout << "\033[1;36mPuntaje final: \033[0m" << puntaje << std::endl;
        std::string datos;
        datos = tabla_clasificaciones.preservar_datos();
        tabla_clasificaciones.guardar_datos(datos, personaje, nombre_jugador, puntaje);
}

Archivo Batalla::get_tabla()
{
    return tabla_clasificaciones;
}

void Batalla::pelea_final(OptimusPrime& optimus, Megatron& megatron){
    int puntaje_diferencia = 0;
    for(size_t i = 0; i < 3; i++){
        if(personaje){
            size_t estadisticas_megatron[] = {megatron.get_fuerza(), megatron.get_defensa(), megatron.get_velocidad()};
            puntaje_diferencia = enfrentamiento(estadisticas_megatron);
            if(rand() % 3 == 0 )  // 33% de probabilidad de transformarse
                megatron.transformar();
        } else {
            size_t estadisticas_optimus[] = {optimus.get_fuerza(), optimus.get_defensa(), optimus.get_velocidad()};
            puntaje_diferencia = enfrentamiento(estadisticas_optimus);
            if(rand() % 3 == 0 )  // 33% de probabilidad de transformarse
                optimus.transformar();
        }
        imprimir_dialogos();
        mostrar_puntaje(puntaje_diferencia);
        std::cout << "\033[1;36mPuntaje batalla\033[0m \033[1;36m" << i + 1 << "\033[0m: " << puntaje << std::endl;
    }
}

void Batalla::mostrar_puntaje(int puntaje_diferencia){
    if (puntaje_diferencia < 0) {
        if(puntaje >= PUNTAJE_MAXIMO)
            puntaje -= PUNTAJE_MAXIMO;
        else
            puntaje = 0;
        std::cout << "\033[1;32m" << "Perdiste la batalla" << "\033[0m" << std::endl; 
    } else if (puntaje_diferencia> 0) {
        std::cout << "\033[1;32m" <<"Ganaste la batalla" << "\033[0m" << std::endl; 
        puntaje += PUNTAJE_MAXIMO;
    } else {
        std::cout << "\033[1;32m" << "Empate" << "\033[0m" << std::endl; 
    }
}


int Batalla::enfrentamiento(size_t estadisticas_contrincante[3])
{      
    int puntaje_parcial = 0;
    int puntaje_contrincante = 0;
    size_t estadisticas_personaje[3] = {fuerza_personaje, defensa_personaje, velocidad_personaje};

    for (int i = 0; i < 3; i++) {
        if (estadisticas_personaje[i] > estadisticas_contrincante[i]) {
            puntaje_parcial++;
        } else if (estadisticas_personaje[i] < estadisticas_contrincante[i]) {
            puntaje_contrincante++;
        }
    }

    return puntaje_parcial - puntaje_contrincante;
}

void Batalla::transformar(size_t indice_lucha, OptimusPrime &optimus, Megatron &megatron) {
    std::string respuesta;
    std::cout << "\033[1;33mEl poder de tu contrincante es de " << listado[indice_lucha]->obtener_poder() << "\033[0m" << std::endl;
    std::cout << "\033[1;34mDesea transformarse (perderá 10 puntos) (s/n): \033[0m";
    std::cin >> respuesta;
    if (respuesta == "s") {
        (puntaje >= 10) ? puntaje -= 10 : puntaje = 0;
        if (personaje) {
            optimus.transformar();
        } else {
            megatron.transformar();
        }
        carga_estadisticas(optimus, megatron);
    }
}

void Batalla::transformar_intermedios(size_t indice_lucha){
    listado[indice_lucha]->transformar();
}


void Batalla::imprimir_dialogos()
{
        std::cout << "\033[1;31mFaccion Decepticons ataca!\033[0m" << std::endl;
        std::cout << "\033[4;34mFaccion Autubots responde!\033[0m" << std::endl;
        std::cout << "\033[1;32;40mFaccion Decepticons golpea con fuerza!\033[0m" << std::endl; 
    std::cout << "\033[1;36;40mFaccion Autobots esquiva ágilmente!\033[0m" << std::endl; 
    std::cout << "\033[5;33mEl combate se intensifica...\033[0m" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\033[0m" << std::endl;

}

void Batalla::carga_estadisticas(OptimusPrime& optimus, Megatron& megatron){
    if(personaje){
        defensa_personaje = optimus.get_defensa();
        velocidad_personaje = optimus.get_velocidad();
        fuerza_personaje = optimus.get_fuerza();
    }else{
        defensa_personaje = megatron.get_defensa();
        velocidad_personaje = megatron.get_velocidad();
        fuerza_personaje = megatron.get_fuerza();
    }
    poder_personaje_principal = defensa_personaje + velocidad_personaje + fuerza_personaje;
}
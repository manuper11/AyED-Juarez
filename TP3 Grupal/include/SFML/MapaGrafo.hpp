#ifndef MAPAGRAFO_HPP
#define MAPAGRAFO_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TDAs/Vector.hpp"
#include "NodoGrafico.hpp"
#include "Figura.hpp"
#include "Conexion.hpp"
#include "Transformer.hpp"
#include "Grafo.hpp"
#include <vector>
// Configuración de grafo
const float RADIO_NODO = 30;           // Radio de los nodos
const float ESPACIO_ENTRE_NIVEL = 110;        // Espaciado entre niveles
const float ESPACIO_ENTRE_NODOS = 200;   // Espaciado horizontal entre nodos
const size_t MAX_NODOS_POR_NIVEL = 3;        // Máximo de nodos por nivel

class MapaGrafo {
private:
    sf::RenderWindow window;   // Ventana principal
    Vector<Figura> figuras;    // Vector de figuras
    Vector<size_t> nodos_por_nivel;        // Nodos por nivel
    Vector<NodoGrafico> nodos;
    Vector<Conexion> aristas_entre_niveles;
    Vector<Transformer*> transformers;
    //POST: Carga las figuras en el grafo segun la faccion con el vector de transformers
    void carga_faccion(bool faccion);

    //Agrego para probar
    Vector<size_t> camino_minimo;
    int peso_recorrido_minimo;
    //POST: Muestra el camino minimo en la ventana como un grafo
    void graficar_camino_minimo(Vector<size_t>& camino_minimo, sf::RenderWindow& window, sf::Font font);

public:
    // Constructor
    MapaGrafo(bool faccion, Camino camino_minimo);

    //POST: Dibuja el grafo en la ventana
    void iniciar_ventana();

};

#endif 
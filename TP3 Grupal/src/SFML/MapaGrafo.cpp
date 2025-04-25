#include <SFML/Graphics.hpp>
#include "SFML/MapaGrafo.hpp"
#include "ManejoTransformer.hpp"
#include <iostream>
#include <algorithm>
#include "Batalla.hpp"

// Clase MapaGrafo
MapaGrafo::MapaGrafo(bool faccion, Camino camino_minimo) {
    //aca obtiene el vector de transformers
    ManejoTransformer manejoTransformer = ManejoTransformer();
    transformers = manejoTransformer.obtener_transformers();
    transformers = transformers.invertir(transformers);

    //luego aca recibe el camino uso el struct siiii
    this->camino_minimo = camino_minimo.camino;

    this->peso_recorrido_minimo = camino_minimo.costo_total;
    carga_faccion(faccion);

    // Calcular la distribución de nodos por niveles
    nodos_por_nivel.alta(1); // Nivel superior con 1 nodo
    size_t cantidad_nodos = (figuras.tamanio()) - 2; //total de figuras menos los nodos op y m
    size_t nivel_minimo = cantidad_nodos % MAX_NODOS_POR_NIVEL;
    if (nivel_minimo == 0) {
        nivel_minimo = MAX_NODOS_POR_NIVEL;
    }
    nodos_por_nivel.alta(nivel_minimo);
    while (cantidad_nodos > nivel_minimo) {
        size_t nodos_nivel = std::min(MAX_NODOS_POR_NIVEL, cantidad_nodos);
        nodos_por_nivel.alta(nodos_nivel);
        cantidad_nodos -= nodos_nivel;
    }
    nodos_por_nivel.alta(1); // Nivel inferior con 1 nodo



    // Crear nodos gráficos a partir de las figuras
    size_t contador_nodos = 0;
    for (size_t nivel = 0; nivel < nodos_por_nivel.tamanio(); ++nivel) {
        size_t nodos_nivel = nodos_por_nivel[nivel];
        float y = std::min(900.0f, 100.0f + static_cast<float>(nivel) * ESPACIO_ENTRE_NIVEL); // Altura del nivel
        float x_comienzo = std::max(0.0f, 400.0f - static_cast<float>(nodos_nivel - 1) * (ESPACIO_ENTRE_NODOS / 2));

        for (size_t i = 0; i < nodos_nivel; ++i) {
            if (!(contador_nodos >= figuras.tamanio())){
                float x = std::min(800.0f, x_comienzo + static_cast<float>(i) * ESPACIO_ENTRE_NODOS);
                const Figura& figura = figuras[contador_nodos];
                nodos.alta(NodoGrafico(x, y, figura.getLabel(), RADIO_NODO, figura.getColor(), figura.getIndice()));
                contador_nodos++;
            }
        }
    }

    // Generar conexiones entre niveles consecutivos
    size_t indice_inicial = 0;
    for (size_t nivel = 0; nivel < nodos_por_nivel.tamanio() - 1; ++nivel) {
        size_t cantidad_nodos_actual = nodos_por_nivel[nivel];
        size_t proximo_nivel_nodos = nodos_por_nivel[nivel + 1];
        size_t nextLevelStartIndex = indice_inicial + cantidad_nodos_actual;

        for (size_t i = 0; i < cantidad_nodos_actual; ++i) {
            for (size_t j = 0; j < proximo_nivel_nodos; ++j) {
                if ((indice_inicial + i) < nodos.tamanio() && (nextLevelStartIndex + j) < nodos.tamanio()) {
                    aristas_entre_niveles.alta(Conexion(indice_inicial + i, nextLevelStartIndex + j));
                }
            }
        }
        indice_inicial += cantidad_nodos_actual;
    }
}

void MapaGrafo::carga_faccion(bool faccion){
    size_t indice_grafo = transformers.tamanio() + 1;
    if (faccion){ // Autobots

        figuras.alta(Figura(sf::Color::Red, "M", indice_grafo));
        indice_grafo--;

        for (size_t i = 0; i < transformers.tamanio(); i++){

            if (transformers[i]->obtener_faccion() == 1){
                figuras.alta(Figura(sf::Color::Blue, std::to_string(indice_grafo), indice_grafo));

            } else{
                figuras.alta(Figura(sf::Color::Red, std::to_string(indice_grafo),indice_grafo));

            }
            indice_grafo--;
        }
        figuras.alta(Figura(sf::Color::Blue, "OP",indice_grafo));
    } else { // Decepticons

        figuras.alta(Figura(sf::Color::Blue, "OP", indice_grafo));
        indice_grafo--;
        for (int i = int(indice_grafo) -1 ; i >= 0; --i){

            if (transformers[i]->obtener_faccion() == 1){
                figuras.alta(Figura(sf::Color::Blue, std::to_string(i+1), i+1));

            } else{
                figuras.alta(Figura(sf::Color::Red, std::to_string(i+1), i+1));
            }
        }
        figuras.alta(Figura(sf::Color::Red, "M", 0));
    }
    
    
}

void MapaGrafo::iniciar_ventana() {
    sf::RenderWindow window(sf::VideoMode(800, 1000), "La batalla final!");
    window.setPosition(sf::Vector2i(
    (sf::VideoMode::getDesktopMode().width - window.getSize().x) / 2, 
    (sf::VideoMode::getDesktopMode().height - window.getSize().y) / 2
));
    sf::Font font;
    if (!font.loadFromFile("ChakraPetch-LightItalic.ttf")) { // Asegúrate de tener la fuente en tu directorio
        return;
    }

    bool mostrarNuevoContenido = true;

    while (window.isOpen()) {
        

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            // Detectar tecla presionada
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    // Cambiar el estado de cambiarColor

                    mostrarNuevoContenido = !mostrarNuevoContenido;
                }
            }
        }


        window.clear(sf::Color::White);
        if(mostrarNuevoContenido){
            sf::Text text;
            // Dibujar titulo camino minimo
            text.setFont(font);
            text.setString("Batalla final");
            text.setCharacterSize(35);
            text.setFillColor(sf::Color::Black);
            text.setPosition(100, 100);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);

            // Dibujar leyenda personajes
            text.setFont(font);
            text.setString("Autobots");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Blue);
            text.setPosition(650, 110);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);

            text.setFont(font);
            text.setString("Decepticons");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Red);
            text.setPosition(650, 140);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);

            // Dibujar conexiones entre nodos
            for (size_t i = 0; i < aristas_entre_niveles.tamanio(); i++) {
                size_t nodoOrigen = aristas_entre_niveles[i].obtenerNodoOrigen();
                size_t nodoDestino = aristas_entre_niveles[i].obtenerNodoDestino();
                if (nodoOrigen < nodos.tamanio() && nodoDestino < nodos.tamanio()) {
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(std::min(800.0f, nodos[nodoOrigen].getX()), std::min(1000.0f, nodos[nodoOrigen].getY())), sf::Color::Black),
                        sf::Vertex(sf::Vector2f(std::min(800.0f, nodos[nodoDestino].getX()), std::min(1000.0f, nodos[nodoDestino].getY())), sf::Color::Black)
                    };
                    window.draw(line, 2, sf::Lines);
                }
            }

            // Dibujar nodos
            for (size_t i = 0; i < nodos.tamanio(); i++) {
                window.draw(nodos[i].getCirculo());
                window.draw(nodos[i].crear_etiqueta(nodos[i].getEtiqueta(), nodos[i].getX(), nodos[i].getY(), font, 20));
            }
            // Dibujar leyendas:
            text.setFont(font);
            text.setString("Presione 'Espacio' para cambiar de vista");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(150, 930);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras
            window.draw(text);
            text.setFont(font);
            text.setString("Presione 'Esc' para volver al menu principal");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(150, 960);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);
        }else{
            sf::Text text;
            // Dibujar titulo camino minimo
            text.setFont(font);
            text.setString("Camino minimo");
            text.setCharacterSize(35);
            text.setFillColor(sf::Color::Black);
            text.setPosition(100, 100);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);


            // Dibujar peso camino minimo
            text.setFont(font);
            text.setString("Costo total: " + std::to_string(peso_recorrido_minimo));
            text.setCharacterSize(25);
            text.setFillColor(sf::Color::Red);
            text.setPosition(100, 140);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);


            // Dibujar leyenda personajes
            text.setFont(font);
            text.setString("Autobots");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Blue);
            text.setPosition(650, 110);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);
            text.setFont(font);
            text.setString("Decepticons");
            text.setCharacterSize(20);
            text.setFillColor(sf::Color::Red);
            text.setPosition(650, 140);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras
            window.draw(text);
            // Camino minimo
            graficar_camino_minimo(camino_minimo, window, font);

            // Dibujar leyendas:
            text.setFont(font);
            text.setString("Presione 'Espacio' para cambiar de vista");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(150, 930);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);
            text.setFont(font);
            text.setString("Presione 'Esc' para volver al menu principal");
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(150, 960);
            text.setStyle(sf::Text::Bold); // Aumentar el grosor de las letras

            window.draw(text);
        }

        window.display();
    } 

}  

void MapaGrafo::graficar_camino_minimo(Vector<size_t>& camino_minimo, sf::RenderWindow& window, sf::Font font) {
    // 1. Dibujar las aristas del camino mínimo
    size_t nodoOrigen = nodos.tamanio() -1;       // Nodo en la posición i
    size_t nodoDestino;
    for (size_t i = 0; i < camino_minimo.tamanio(); i++) {
        for (size_t j = 0 ; j < nodos.tamanio(); j++){
            if(nodos[j].obtener_indice() == camino_minimo[i]){
                nodoDestino = j;  // Nodo en la posición i+1 (siguiente)
                // Dibujar la línea entre los dos nodos consecutivos
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(std::min(800.0f, nodos[nodoOrigen].getX()), std::min(1000.0f, nodos[nodoOrigen].getY())), sf::Color::Green),  // Color de la conexión
                    sf::Vertex(sf::Vector2f(std::min(800.0f, nodos[nodoDestino].getX()), std::min(1000.0f, nodos[nodoDestino].getY())), sf::Color::Green) // Color de la conexión
                };
                window.draw(line, 2, sf::Lines);  // Dibuja la línea entre los dos nodos
                j = nodos.tamanio();
            }
        }
        nodoOrigen = nodoDestino;

    }

    // 2. Destacar los nodos del camino mínimo
    for (size_t j =0 ; j < camino_minimo.tamanio(); j++){

        for (size_t i = 0; i < nodos.tamanio(); i++) {
            if (camino_minimo[j] == nodos[i].obtener_indice())
            {
                size_t nodo = i;
                sf::CircleShape nodoDestacado = nodos[nodo].getCirculo();
                nodoDestacado.setOutlineThickness(2); // Engrosar el borde
                window.draw(nodoDestacado);

                // Redibujar la etiqueta del nodo
                window.draw(nodos[nodo].crear_etiqueta(nodos[nodo].getEtiqueta(), nodos[nodo].getX(), nodos[nodo].getY(), font, 20));

            }

        }
    }
}

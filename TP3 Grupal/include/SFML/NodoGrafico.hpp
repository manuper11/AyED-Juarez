#ifndef NODOGRAFICO_HPP
#define NODOGRAFICO_HPP

#include <SFML/Graphics.hpp>

// Estructura para representar un nodo gráfico
class NodoGrafico
{
private:
    float x; 
    float y;      // Coordenadas del nodo
    sf::CircleShape circulo;    // Círculo que representa el nodo
    std::string etiqueta;           // Etiqueta del nodo
    size_t indice;
public:
    NodoGrafico(); // Constructor por defecto

    NodoGrafico(float x, float y, std::string label, float radius, sf::Color color, size_t indice); // Constructor con parámetros
    // Función para crear un nodo gráfico
    static sf::CircleShape crear_nodo(float x, float y, float radius, sf::Color color);
    // Función para crear etiquetas
    static sf::Text crear_etiqueta(const std::string& label, float x, float y, sf::Font& font, float fontSize);
    // Getter para las coordenadas X e Y
    float getX();
    float getY();
    // Getter para el círculo
    sf::CircleShape getCirculo();
    // Getter para la etiqueta
    std::string getEtiqueta() const;
    // Getter para el índice
    size_t obtener_indice();

};




#endif // NODOGRAFICO_HPP

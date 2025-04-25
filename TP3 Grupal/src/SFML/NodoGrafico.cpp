#include "SFML/NodoGrafico.hpp"
NodoGrafico::NodoGrafico() : x(0), y(0), circulo(), etiqueta() {} // Definición del constructor por defecto

NodoGrafico::NodoGrafico(float x, float y, std::string label, float radius, sf::Color color, size_t indice) {
    this->x = x;
    this->y = y;
    this->etiqueta = label;
    circulo = crear_nodo(x, y, radius, color);
    this -> indice = indice;
}

// Función para crear un nodo gráfico
sf::CircleShape NodoGrafico::crear_nodo(float x, float y, float radius, sf::Color color) {
    sf::CircleShape node(radius);
    node.setPosition(x - radius, y - radius); // Centrar el círculo
    node.setFillColor(color);
    node.setOutlineThickness(2);
    node.setOutlineColor(sf::Color::Black);

    return node;
}

// Función para crear etiquetas
sf::Text NodoGrafico::crear_etiqueta(const std::string& label, float x, float y, sf::Font& font, float fontSize) {
    sf::Text text;
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(static_cast<unsigned int>(fontSize));
    text.setFillColor(sf::Color::Black);
    text.setPosition(x - fontSize / 2, y - fontSize / 2); // Centrar texto
    return text;
}

sf::CircleShape NodoGrafico::getCirculo()
{
    return circulo;
}

std::string NodoGrafico::getEtiqueta() const
{
    return etiqueta;
}

float NodoGrafico::getX()
{
    return x;
}

float NodoGrafico::getY()
{
    return y;
}

size_t NodoGrafico::obtener_indice()
{
    return indice;
}

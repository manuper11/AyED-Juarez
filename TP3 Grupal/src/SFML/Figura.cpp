#include "SFML/Figura.hpp"

Figura::Figura(sf::Color color, const std::string& etiqueta, size_t indice) : _color(color), etiqueta(etiqueta), indice(indice) {}

Figura::Figura() : _color(sf::Color::White), etiqueta("") {} // Definición del constructor por defecto

sf::Color Figura::getColor() const {
    return _color;
}

std::string Figura::getLabel() const
{
    return etiqueta;
}

size_t Figura::getIndice() const
{
    return indice;
}

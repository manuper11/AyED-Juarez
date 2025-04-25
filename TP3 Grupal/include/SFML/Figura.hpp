#ifndef FIGURA_HPP
#define FIGURA_HPP

#include <SFML/Graphics.hpp>

class Figura {
private:
    sf::Color _color;  // Color de la figura
    std::string etiqueta; // Etiqueta de la figura
    size_t indice;

public:
    // Constructor
    Figura(); // Constructor por defecto

    Figura(sf::Color color, const std::string& label, size_t indice); // Constructor con parámetros

    // Getter para el color
    sf::Color getColor() const;

    // Getter para la etiqueta
    std::string getLabel() const;

    // Getter para el índice
    size_t getIndice() const;
};

#endif
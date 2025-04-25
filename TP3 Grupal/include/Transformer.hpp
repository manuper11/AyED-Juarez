
#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP
#include <string>

enum facciones{
    autobots = 1,
    decepticons
  };
enum vehiculos{
    coche = 1,
    camion,
    tanque,
    avion
  };

class Transformer{
private:
//Atributos
    std::string nombre;
    size_t fuerza;
    size_t defensa;
    size_t velocidad;
    bool faccion;
    size_t vehiculo;
    bool transformado;
    size_t fuerza_inicio;
    size_t defensa_inicio;
    size_t velocidad_inicio;
public:
//Metodos
    //Constructor
    Transformer(std::string nombre,size_t fuerza,size_t defensa, size_t velocidad, bool faccion, size_t vehiculo, bool transformado);
    //pre: -
    //post: devuelve el nombre del transformer.
    std::string obtener_nombre();
    //pre: -
    //post: devuelve la fuerza del transformer.
    size_t obtener_fuerza();
    //pre: -
    //post: devuelve la defensa del transformer.
    size_t obtener_defensa();
    //pre: -
    //post: devuelve la velocidad del transformer.
    size_t obtener_velocidad();
    //pre: -
    //post: devuelve la faccion del transformer.
    bool obtener_faccion();
    //pre: -
    //post: devuelve el vehiculo del transformer.
    size_t obtener_vehiculo();
    //pre: -
    //post: devuelve si el transformer esta transformado.
    bool esta_tranformado();
    //pre: -
    //post: transforma el transformer.
    void transformar();
    //pre: -
    //post: devuelve la faccion del transformer.
    size_t obtener_poder();
};

#endif
#include "Funciones.hpp"
#include "OptimusPrime.hpp"
#include "Megatron.hpp"

int main() {
    OptimusPrime optimus;
    Megatron megatron;
    Funciones funcion;
    funcion.imprimir_titulo();
    funcion.procesar_respuestas(optimus, megatron);
    return 0;
}
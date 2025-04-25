#include "FusionadorEnergon.hpp"

FusionadorEnergon::FusionadorEnergon() {
    this->contador_comun = 0;
    this->contador_raro = 0;
    this->contador_epico = 0;
}

Cristal FusionadorEnergon::fusionar(Cristal cristal_1, Cristal cristal_2) {
    GeneradorAleatorio generador;
    return fusionar(cristal_1, cristal_2, generador);
}

Cristal FusionadorEnergon::fusionar(Cristal cristal_1, Cristal cristal_2, GeneradorAleatorio& generador) {
    Cristal cristal_resultante;
    Rareza rareza = cristal_1.obtener_rareza();
    if (cristal_1.obtener_rareza() != cristal_2.obtener_rareza()) {
        throw ExcepcionFusionadorEnergon(MENSAJE_ERROR_FUSION_DISTINTAS);
    }
    if (rareza == LEGENDARIO) {
        throw ExcepcionFusionadorEnergon(MENSAJE_ERROR_FUSION_LEGENDARIO);
    }
    bool exito = false;
    switch (rareza) {
    case COMUN:
        exito = es_fusion_exitosa(contador_comun, 50, generador);
        cristal_resultante = exito ? fusionar_cristal(cristal_1, cristal_2, RARO) : Cristal(COMUN);
        if (!exito) contador_comun++;
        break;
    case RARO:
        exito = es_fusion_exitosa(contador_raro, 30, generador);
        cristal_resultante = exito ? fusionar_cristal(cristal_1, cristal_2, EPICO) : Cristal(COMUN);
        if (!exito) contador_raro++;
        break;
    case EPICO:
        exito = es_fusion_exitosa(contador_epico, 10, generador);
        cristal_resultante = exito ? fusionar_cristal(cristal_1, cristal_2, LEGENDARIO) : Cristal(RARO);
        if (!exito) contador_epico++;
        break;
    default:
        throw ExcepcionFusionadorEnergon("Rareza desconocida");
    }
    return cristal_resultante;
}

Cristal FusionadorEnergon::fusionar_cristal(Cristal cristal_1, Cristal cristal_2, Rareza nueva_rareza) {
    Cristal cristal_resultante(nueva_rareza);
    cristal_resultante.set_estadistica_fuerza((cristal_1.get_estadistica_fuerza() + cristal_2.get_estadistica_fuerza())*15/10);
    cristal_resultante.set_estadistica_velocidad((cristal_1.get_estadistica_velocidad() + cristal_2.get_estadistica_velocidad())*15/10);
    cristal_resultante.set_estadistica_defensa((cristal_1.get_estadistica_defensa() + cristal_2.get_estadistica_defensa())*15/10);
    return cristal_resultante;
}

bool FusionadorEnergon::es_fusion_exitosa(int& contador, size_t porcentaje, GeneradorAleatorio& generador) {
    bool fusion_exitosa = false;
    if (contador == 3) {
        fusion_exitosa = true;
        contador = 0;
    } else {
        fusion_exitosa = generador.generar_chance_porcentual(porcentaje);
    }
    return fusion_exitosa;
}
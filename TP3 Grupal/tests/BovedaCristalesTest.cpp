#include "gtest/gtest.h"
#include "BovedaCristales.hpp"
#include <sstream>

class BovedaCristalesTest : public testing::Test {
protected:
    BovedaCristales boveda;
    const size_t LIMITE_CRISTALES = 20;

    std::string generar_error_excepcion(std::string motivo, bool esperado);
};

std::string BovedaCristalesTest::generar_error_excepcion(std::string motivo, bool esperado) {
    std::stringstream salida;
    salida << "Se esperaba que la bóveda " << (esperado ? "" : "no ")
            << "lance una excepción de tipo ExcepcionBovedaCristales al " << motivo << " pero "
            << (esperado ? "no " : "") << "se lanzó " << (esperado ? "ninguna." : "una.");
    return salida.str();
}

TEST_F(BovedaCristalesTest, AlmacenarCristal) {
    EXPECT_NO_THROW(boveda.almacenar_cristal({COMUN})) << generar_error_excepcion("almacenar un cristal", false);
}

TEST_F(BovedaCristalesTest, NoSePuedenAlmacenarMasDeVeinteCristales) {
    for (size_t i = 0; i < LIMITE_CRISTALES; ++i) {
        EXPECT_NO_THROW(boveda.almacenar_cristal({COMUN})) << generar_error_excepcion("almacenar un cristal", false);
    }
    EXPECT_THROW(boveda.almacenar_cristal({COMUN}), ExcepcionBovedaCristales) << generar_error_excepcion(
                                                                                 "almacenar más de " + std::to_string(
                                                                                     LIMITE_CRISTALES) + " cristales",
                                                                                 true);
}

TEST_F(BovedaCristalesTest, ObtenerCristal) {
    boveda.almacenar_cristal({COMUN});
    EXPECT_NO_THROW(boveda.obtener_cristal(0)) << generar_error_excepcion("obtener un cristal", false);
}

TEST_F(BovedaCristalesTest, ObtenerUnCristalLoQuitaDeLaBoveda) {
    boveda.almacenar_cristal({COMUN});
    boveda.obtener_cristal(0);
    EXPECT_THROW(boveda.obtener_cristal(0), ExcepcionBovedaCristales) << generar_error_excepcion(
                                                                         "obtener un cristal con la bóveda vacía",
                                                                         true);
}

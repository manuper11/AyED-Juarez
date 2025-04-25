#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "FusionadorEnergon.hpp"
#include <sstream>

class GeneradorAleatorioMock : public GeneradorAleatorio {
public:
    MOCK_METHOD(bool, generar_chance_porcentual, (size_t porcentaje), (override));
};

class FusionadorEnergonTest : public testing::Test {
protected:
    GeneradorAleatorioMock generador_mock;
    FusionadorEnergon fusionador;
    const size_t LIMITE_SISTEMA_FALLA = 3;

    void configurar_generador_mock(size_t porcentaje, int veces, bool retorno);

    std::string convertir_rareza(Rareza rareza);

    std::string generar_error_rareza(Rareza fusion, bool exito, bool pity);

    std::string generar_error_excepcion(Rareza cristal_1, Rareza cristal_2);

    void probar_excepcion_fusion(Rareza cristal_1, Rareza cristal_2);
};

void FusionadorEnergonTest::configurar_generador_mock(size_t porcentaje, int veces, bool retorno) {
    EXPECT_CALL(generador_mock, generar_chance_porcentual(porcentaje))
            .Times(veces)
            .WillRepeatedly(testing::Return(retorno));
}

std::string FusionadorEnergonTest::convertir_rareza(Rareza rareza) {
    std::string resultado;
    switch (rareza) {
        case COMUN:
            resultado = "común";
            break;
        case RARO:
            resultado = "raro";
            break;
        case EPICO:
            resultado = "épico";
            break;
        case LEGENDARIO:
            resultado = "legendario";
            break;
    }
    return resultado;
}

std::string FusionadorEnergonTest::generar_error_rareza(Rareza fusion, bool exito, bool pity) {
    std::string rareza_fusion;
    std::string rareza_esperada;
    switch (fusion) {
        case COMUN:
            rareza_fusion = "comunes";
            rareza_esperada = exito | pity ? "raro" : "común";
            break;
        case RARO:
            rareza_fusion = "raros";
            rareza_esperada = exito | pity ? "épico" : "común";
            break;
        case EPICO:
            rareza_fusion = "épicos";
            rareza_esperada = exito | pity ? "legendario" : "raro";
            break;
        case LEGENDARIO:
            break;
    }
    return "Se esperaba un cristal " + rareza_esperada + " al " +
           (exito | pity ? "fusionar exitosamente" : "fallar la fusión de") +
           " cristales " + rareza_fusion + (pity ? " por el sistema de falla." : ".");
}

std::string FusionadorEnergonTest::generar_error_excepcion(Rareza cristal_1, Rareza cristal_2) {
    std::stringstream salida;
    salida << "Se esperaba que se lance una excepción de tipo ExcepcionFusionadorEnergon al fusionar un cristal "
            << convertir_rareza(cristal_1) << " y un cristal " << convertir_rareza(cristal_2) <<
            " pero no se lanzó ninguna.";
    return salida.str();
}

void FusionadorEnergonTest::probar_excepcion_fusion(Rareza cristal_1, Rareza cristal_2) {
    EXPECT_THROW(fusionador.fusionar({cristal_1}, {cristal_2}), ExcepcionFusionadorEnergon)
    << generar_error_excepcion(cristal_1, cristal_2);
}

TEST_F(FusionadorEnergonTest, FusionExitosaCristalesComunes) {
    configurar_generador_mock(50, 1, true);

    Cristal cristal = fusionador.fusionar({COMUN}, {COMUN}, generador_mock);
    EXPECT_TRUE(cristal == RARO) << generar_error_rareza(COMUN, true, false);
}

TEST_F(FusionadorEnergonTest, FusionExitosaCristalesRaros) {
    configurar_generador_mock(30, 1, true);

    Cristal cristal = fusionador.fusionar({RARO}, {RARO}, generador_mock);
    EXPECT_TRUE(cristal == EPICO) << generar_error_rareza(RARO, true, false);
}

TEST_F(FusionadorEnergonTest, FusionExitosaCristalesEpicos) {
    configurar_generador_mock(10, 1, true);

    Cristal cristal = fusionador.fusionar({EPICO}, {EPICO}, generador_mock);
    EXPECT_TRUE(cristal == LEGENDARIO) << generar_error_rareza(EPICO, true, false);
}

TEST_F(FusionadorEnergonTest, FusionFallidaCristalesComunes) {
    configurar_generador_mock(50, 1, false);

    Cristal cristal = fusionador.fusionar({COMUN}, {COMUN}, generador_mock);
    EXPECT_TRUE(cristal == COMUN) << generar_error_rareza(COMUN, false, false);
}

TEST_F(FusionadorEnergonTest, FusionFallidaCristalesRaros) {
    configurar_generador_mock(30, 1, false);

    Cristal cristal = fusionador.fusionar({RARO}, {RARO}, generador_mock);
    EXPECT_TRUE(cristal == COMUN) << generar_error_rareza(RARO, false, false);
}

TEST_F(FusionadorEnergonTest, FusionFallidaCristalesEpicos) {
    configurar_generador_mock(10, 1, false);

    Cristal cristal = fusionador.fusionar({EPICO}, {EPICO}, generador_mock);
    EXPECT_TRUE(cristal == RARO) << generar_error_rareza(EPICO, false, false);
}

TEST_F(FusionadorEnergonTest, NoSePuedeFusionarCristalesDeRarezasDistintas) {
    probar_excepcion_fusion(COMUN, RARO);
    probar_excepcion_fusion(COMUN, EPICO);
    probar_excepcion_fusion(COMUN, LEGENDARIO);
    probar_excepcion_fusion(RARO, COMUN);
    probar_excepcion_fusion(EPICO, COMUN);
    probar_excepcion_fusion(LEGENDARIO, COMUN);
    probar_excepcion_fusion(RARO, EPICO);
    probar_excepcion_fusion(RARO, LEGENDARIO);
    probar_excepcion_fusion(EPICO, RARO);
    probar_excepcion_fusion(LEGENDARIO, RARO);
    probar_excepcion_fusion(EPICO, LEGENDARIO);
    probar_excepcion_fusion(LEGENDARIO, EPICO);
}

TEST_F(FusionadorEnergonTest, NoSePuedeFusionarCristalesDeRarezaLegendaria) {
    probar_excepcion_fusion(LEGENDARIO, LEGENDARIO);
}

TEST_F(FusionadorEnergonTest, SistemaDeFallaCristalesComunes) {
    configurar_generador_mock(50, 3, false);
    configurar_generador_mock(30, 1, false);
    configurar_generador_mock(10, 1, false);

    for (size_t i = 0; i < LIMITE_SISTEMA_FALLA; i++) {
        fusionador.fusionar({COMUN}, {COMUN}, generador_mock);
    }

    Cristal cristal_fusion_comun = fusionador.fusionar({COMUN}, {COMUN}, generador_mock);
    Cristal cristal_fusion_raro = fusionador.fusionar({RARO}, {RARO}, generador_mock);
    Cristal cristal_fusion_epico = fusionador.fusionar({EPICO}, {EPICO}, generador_mock);

    EXPECT_TRUE(cristal_fusion_comun == RARO) << generar_error_rareza(COMUN, false, true);
    EXPECT_TRUE(cristal_fusion_raro == COMUN) << generar_error_rareza(RARO, false, false);
    EXPECT_TRUE(cristal_fusion_epico == RARO) << generar_error_rareza(EPICO, false, false);
}

TEST_F(FusionadorEnergonTest, SistemaDeFallaCristalesRaros) {
    configurar_generador_mock(50, 1, false);
    configurar_generador_mock(30, 3, false);
    configurar_generador_mock(10, 1, false);

    for (size_t i = 0; i < LIMITE_SISTEMA_FALLA; i++) {
        fusionador.fusionar({RARO}, {RARO}, generador_mock);
    }

    Cristal cristal_fusion_comun = fusionador.fusionar({COMUN}, {COMUN}, generador_mock);
    Cristal cristal_fusion_raro = fusionador.fusionar({RARO}, {RARO}, generador_mock);
    Cristal cristal_fusion_epico = fusionador.fusionar({EPICO}, {EPICO}, generador_mock);

    EXPECT_TRUE(cristal_fusion_comun == COMUN) << generar_error_rareza(COMUN, false, false);
    EXPECT_TRUE(cristal_fusion_raro == EPICO) << generar_error_rareza(RARO, false, true);
    EXPECT_TRUE(cristal_fusion_epico == RARO) << generar_error_rareza(EPICO, false, false);
}

TEST_F(FusionadorEnergonTest, SistemaDeFallaCristalesEpicos) {
    configurar_generador_mock(50, 1, false);
    configurar_generador_mock(30, 1, false);
    configurar_generador_mock(10, 3, false);

    for (size_t i = 0; i < LIMITE_SISTEMA_FALLA; i++) {
        fusionador.fusionar({EPICO}, {EPICO}, generador_mock);
    }

    Cristal cristal_fusion_comun = fusionador.fusionar({COMUN}, {COMUN}, generador_mock);
    Cristal cristal_fusion_raro = fusionador.fusionar({RARO}, {RARO}, generador_mock);
    Cristal cristal_fusion_epico = fusionador.fusionar({EPICO}, {EPICO}, generador_mock);

    EXPECT_TRUE(cristal_fusion_comun == COMUN) << generar_error_rareza(COMUN, false, false);
    EXPECT_TRUE(cristal_fusion_raro == COMUN) << generar_error_rareza(RARO, false, false);
    EXPECT_TRUE(cristal_fusion_epico == LEGENDARIO) << generar_error_rareza(EPICO, false, true);
}

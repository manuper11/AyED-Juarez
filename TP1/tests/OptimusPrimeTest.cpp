#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "OptimusPrime.hpp"
#include <sstream>
#include <vector>
#include <ranges>

const std::string ANIMO_SERENO = "sereno";
const std::string ANIMO_DETERMINADO = "determinado";
const std::string ANIMO_ENFURECIDO = "enfurecido";

const std::string RESPUESTA_SERENO_MEGATRON = "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";
const std::string RESPUESTA_SERENO_DECEPTICONS =
        "La paz siempre es nuestra prioridad, pero no dudaremos en defendernos.";
const std::string RESPUESTA_SERENO_AUTOBOTS = "Los Autobots estan aqui para proteger a todos los seres vivos.";
const std::string RESPUESTA_SERENO_CYBERTRON = "Cybertron es nuestro hogar, pero nuestra mision esta aqui.";
const std::string RESPUESTA_SERENO_GENERICA = "En que puedo ayudarte, humano?";
const std::string SUGERENCIA_FUSION_SERENO =
        "Te recomiendo fusionar cristales comunes para comenzar a mejorar tu arsenal.";

const std::string RESPUESTA_DETERMINADO_MEGATRON = "Megatron sera detenido. No hay alternativa.";
const std::string RESPUESTA_DETERMINADO_DECEPTICONS = "Megatron sera detenido. No hay alternativa.";
const std::string RESPUESTA_DETERMINADO_AUTOBOTS = "Los Autobots son la luz en medio de la oscuridad.";
const std::string RESPUESTA_DETERMINADO_CYBERTRON = "Cybertron sobrevivira, como lo hemos hecho antes.";
const std::string RESPUESTA_DETERMINADO_GENERICA = "Nuestra lucha es por la libertad de todos los seres.";
const std::string SUGERENCIA_FUSION_DETERMINADO =
        "Te sugiero fusionar cristales raros para prepararte para la batalla.";

const std::string RESPUESTA_ENFURECIDO_GENERICA_1 = "No tengo tiempo para estas trivialidades.";
const std::string RESPUESTA_ENFURECIDO_GENERICA_2 = "La batalla es inminente. Preparate.";
const std::string SUGERENCIA_FUSION_ENFURECIDO = "Fusiona cristales de alto riesgo para obtener una ventaja decisiva.";

class OptimusPrimeTest : public testing::Test {
protected:
    OptimusPrime optimus_prime;
    std::string animo, mensaje, esperado, respuesta, sugerencia;
    std::vector<std::string> esperados;
    std::vector<bool> respuestas_obtenidas;
    size_t limite_intentos = 0;

    std::string generar_error_respuesta();

    std::string generar_error_respuesta_aleatoria();

    std::string generar_error_sugerencia();

    std::string generar_error_aleatoriedad();

    std::string capturar_respuesta();

    std::string capturar_sugerencia();

    void probar_respuesta();

    void probar_respuesta_aleatoria();

    void probar_sugerencia();

    bool validar_respuestas_obtenidas();
};

std::string OptimusPrimeTest::generar_error_respuesta() {
    std::stringstream salida;
    salida << "El ánimo de Optimus Prime es: " << animo << "\n";
    salida << "La respuesta esperada al mensaje:" << "\n";
    salida << "\t" << mensaje << "\n";
    salida << "es:" << "\n";
    salida << "\t" << esperado << "\n";
    salida << "pero la respuesta obtenida fue: " << "\n";
    salida << "\t" << respuesta << "\n";
    salida << "Verificá que la respuesta coincida exactamente"
            " con la esperada y que no tenga un salto de línea.";
    return salida.str();
}

std::string OptimusPrimeTest::generar_error_respuesta_aleatoria() {
    std::stringstream salida;
    salida << "El ánimo de Optimus Prime es: " << animo << "\n";
    salida << "La respuesta esperada al mensaje:" << "\n";
    salida << "\t" << mensaje << "\n";
    salida << "es:" << "\n";
    for (auto it = esperados.begin(); it < esperados.end(); ++it) {
        if (it != esperados.begin()) {
            salida << "o:" << "\n";
        }
        salida << "\t" << *it << "\n";
    }
    salida << "pero la respuesta obtenida fue: " << "\n";
    salida << "\t" << respuesta << "\n";
    salida << "Verificá que la respuesta coincida exactamente con alguna"
            " de las esperadas y que no tenga un salto de línea.";
    return salida.str();
}

std::string OptimusPrimeTest::generar_error_sugerencia() {
    std::stringstream salida;
    salida << "El ánimo de Optimus Prime es: " << animo << "\n";
    salida << "La sugerencia esperada es:" << "\n";
    salida << "\t" << esperado << "\n";
    salida << "pero la sugerencia obtenida fue: " << "\n";
    salida << "\t" << sugerencia << "\n";
    salida << "Verificá que la sugerencia coincida exactamente"
            " con la esperada y que no tenga un salto de línea.";
    return salida.str();
}

std::string OptimusPrimeTest::generar_error_aleatoriedad() {
    std::stringstream salida;
    salida << "El ánimo de Optimus Prime es: " << animo << "\n";
    salida << "El mensaje es:" << "\n";
    salida << "\t" << mensaje << "\n";
    salida << "Se esperaban las siguientes respuestas:" << "\n";
    for (auto it = esperados.begin(); it < esperados.end(); ++it) {
        salida << "\t" << *it << "\n";
    }
    salida << "pero solo se obtuvieron las siguientes: " << "\n";
    for (size_t i = 0; i < respuestas_obtenidas.size(); i++) {
        if (respuestas_obtenidas[i]) {
            salida << "\t" << esperados[i] << "\n";
        }
    }
    salida << "en " << limite_intentos << " intentos." << "\n";
    salida << "Verificá que la respuesta se esté generando aleatoriamente.";
    return salida.str();
}

std::string OptimusPrimeTest::capturar_respuesta() {
    testing::internal::CaptureStdout();
    optimus_prime.responder(mensaje);
    return testing::internal::GetCapturedStdout();
}

std::string OptimusPrimeTest::capturar_sugerencia() {
    testing::internal::CaptureStdout();
    optimus_prime.sugerir_fusion();
    return testing::internal::GetCapturedStdout();
}

void OptimusPrimeTest::probar_respuesta() {
    optimus_prime.cambiar_animo(animo);
    respuesta = capturar_respuesta();
    ASSERT_EQ(esperado, respuesta) << generar_error_respuesta();
}

void OptimusPrimeTest::probar_respuesta_aleatoria() {
    optimus_prime.cambiar_animo(animo);
    respuesta = capturar_respuesta();
    ASSERT_THAT(esperados, testing::Contains(respuesta)) << generar_error_respuesta_aleatoria();
}

void OptimusPrimeTest::probar_sugerencia() {
    optimus_prime.cambiar_animo(animo);
    sugerencia = capturar_sugerencia();
    ASSERT_EQ(esperado, sugerencia) << generar_error_sugerencia();
}

bool OptimusPrimeTest::validar_respuestas_obtenidas() {
    return std::ranges::all_of(respuestas_obtenidas, [](bool i) { return i; });
}

// Las pruebas empiezan a partir de acá //

// SERENO //

TEST_F(OptimusPrimeTest, RespuestaSerenoMegatron) {
    animo = ANIMO_SERENO;
    mensaje = "megatron";
    esperado = RESPUESTA_SERENO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoMegatronCaseSensitive) {
    animo = ANIMO_SERENO;
    mensaje = "MeGaTRon";
    esperado = RESPUESTA_SERENO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoMegatronCasoDeUso) {
    animo = ANIMO_SERENO;
    mensaje = "Megatron esta preparandose para atacarnos";
    esperado = RESPUESTA_SERENO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoDecepticons) {
    animo = ANIMO_SERENO;
    mensaje = "decepticons";
    esperado = RESPUESTA_SERENO_DECEPTICONS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoDecepticonsCaseSensitive) {
    animo = ANIMO_SERENO;
    mensaje = "DeCepTIConS";
    esperado = RESPUESTA_SERENO_DECEPTICONS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoDecepticonsCasoDeUso) {
    animo = ANIMO_SERENO;
    mensaje = "Los Decepticons estan preparandose para atacarnos";
    esperado = RESPUESTA_SERENO_DECEPTICONS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoAutobots) {
    animo = ANIMO_SERENO;
    mensaje = "autobots";
    esperado = RESPUESTA_SERENO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoAutobotsCaseSensitive) {
    animo = ANIMO_SERENO;
    mensaje = "aUToBoTS";
    esperado = RESPUESTA_SERENO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoAutobotsCasoDeUso) {
    animo = ANIMO_SERENO;
    mensaje = "Los Autobots defenderemos la tierra";
    esperado = RESPUESTA_SERENO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoCybertron) {
    animo = ANIMO_SERENO;
    mensaje = "cybertron";
    esperado = RESPUESTA_SERENO_CYBERTRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoCybertronCaseSensitive) {
    animo = ANIMO_SERENO;
    mensaje = "cYbeRTroN";
    esperado = RESPUESTA_SERENO_CYBERTRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoCybertronCasoDeUso) {
    animo = ANIMO_SERENO;
    mensaje = "Cybertron esta a nuestro alcance";
    esperado = RESPUESTA_SERENO_CYBERTRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoGenerica) {
    animo = ANIMO_SERENO;
    mensaje = "hola";
    esperado = RESPUESTA_SERENO_GENERICA;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoGenericaCasoDeUso) {
    animo = ANIMO_SERENO;
    mensaje = "Nuestra victoria es inminente";
    esperado = RESPUESTA_SERENO_GENERICA;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoPrioridadMegatronDecepticons) {
    animo = ANIMO_SERENO;
    mensaje = "Megatron estan llegando a Cybertron, los Autobots deben prepararse";
    esperado = RESPUESTA_SERENO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaSerenoPrioridadAutobots) {
    animo = ANIMO_SERENO;
    mensaje = "Los Autobots defenderemos Cybertron";
    esperado = RESPUESTA_SERENO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, SugerenciaFusionSereno) {
    animo = ANIMO_SERENO;
    esperado = SUGERENCIA_FUSION_SERENO;
    probar_sugerencia();
}

// DETERMINADO //

TEST_F(OptimusPrimeTest, RespuestaDeterminadoMegatron) {
    animo = ANIMO_DETERMINADO;
    mensaje = "megatron";
    esperado = RESPUESTA_DETERMINADO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoMegatronCaseSensitive) {
    animo = ANIMO_DETERMINADO;
    mensaje = "MeGaTRon";
    esperado = RESPUESTA_DETERMINADO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoMegatronCasoDeUso) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Megatron esta preparandose para atacarnos";
    esperado = RESPUESTA_DETERMINADO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoDecepticons) {
    animo = ANIMO_DETERMINADO;
    mensaje = "decepticons";
    esperado = RESPUESTA_DETERMINADO_DECEPTICONS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoDecepticonsCaseSensitive) {
    animo = ANIMO_DETERMINADO;
    mensaje = "DeCepTIConS";
    esperado = RESPUESTA_DETERMINADO_DECEPTICONS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoDecepticonsCasoDeUso) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Los Decepticons estan preparandose para atacarnos";
    esperado = RESPUESTA_DETERMINADO_DECEPTICONS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoAutobots) {
    animo = ANIMO_DETERMINADO;
    mensaje = "autobots";
    esperado = RESPUESTA_DETERMINADO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoAutobotsCaseSensitive) {
    animo = ANIMO_DETERMINADO;
    mensaje = "aUToBoTS";
    esperado = RESPUESTA_DETERMINADO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoAutobotsCasoDeUso) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Los Autobots defenderemos la tierra";
    esperado = RESPUESTA_DETERMINADO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoCybertron) {
    animo = ANIMO_DETERMINADO;
    mensaje = "cybertron";
    esperado = RESPUESTA_DETERMINADO_CYBERTRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoCybertronCaseSensitive) {
    animo = ANIMO_DETERMINADO;
    mensaje = "cYbeRTroN";
    esperado = RESPUESTA_DETERMINADO_CYBERTRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoCybertronCasoDeUso) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Cybertron esta a nuestro alcance";
    esperado = RESPUESTA_DETERMINADO_CYBERTRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoGenerica) {
    animo = ANIMO_DETERMINADO;
    mensaje = "hola";
    esperado = RESPUESTA_DETERMINADO_GENERICA;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoGenericaCasoDeUso) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Nuestra victoria es inminente";
    esperado = RESPUESTA_DETERMINADO_GENERICA;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoPrioridadMegatronDecepticons) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Megatron estan llegando a Cybertron, los Autobots deben prepararse";
    esperado = RESPUESTA_DETERMINADO_MEGATRON;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, RespuestaDeterminadoPrioridadAutobots) {
    animo = ANIMO_DETERMINADO;
    mensaje = "Los Autobots defenderemos Cybertron";
    esperado = RESPUESTA_DETERMINADO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(OptimusPrimeTest, SugerenciaFusionDeterminado) {
    animo = ANIMO_DETERMINADO;
    esperado = SUGERENCIA_FUSION_DETERMINADO;
    probar_sugerencia();
}

// ENFURECIDO //

TEST_F(OptimusPrimeTest, RespuestaEnfurecido) {
    animo = ANIMO_ENFURECIDO;
    mensaje = "hola";
    esperados = {RESPUESTA_ENFURECIDO_GENERICA_1, RESPUESTA_ENFURECIDO_GENERICA_2};
    probar_respuesta_aleatoria();
}

TEST_F(OptimusPrimeTest, RespuestaEnfurecidoCasoDeUso) {
    animo = ANIMO_ENFURECIDO;
    mensaje = "Nuestra victoria es inminente";
    esperados = {RESPUESTA_ENFURECIDO_GENERICA_1, RESPUESTA_ENFURECIDO_GENERICA_2};
    probar_respuesta_aleatoria();
}

TEST_F(OptimusPrimeTest, RespuestaEnfurecidoEsAleatoria) {
    animo = ANIMO_ENFURECIDO;
    mensaje = "Nuestra victoria es inminente";
    esperados = {RESPUESTA_ENFURECIDO_GENERICA_1, RESPUESTA_ENFURECIDO_GENERICA_2};

    respuestas_obtenidas = std::vector(esperados.size(), false);
    optimus_prime.cambiar_animo(animo);

    size_t indice;
    size_t i = 0;
    limite_intentos = 100;
    while (i < limite_intentos && !validar_respuestas_obtenidas()) {
        respuesta = capturar_respuesta();
        auto it = std::ranges::find(esperados, respuesta);
        indice = it - esperados.begin();
        if (indice < respuestas_obtenidas.size()) {
            respuestas_obtenidas[indice] = true;
        }
        i++;
    }

    ASSERT_TRUE(validar_respuestas_obtenidas()) << generar_error_aleatoriedad();
}

TEST_F(OptimusPrimeTest, SugerenciaFusionEnfurecido) {
    animo = ANIMO_ENFURECIDO;
    esperado = SUGERENCIA_FUSION_ENFURECIDO;
    probar_sugerencia();
}

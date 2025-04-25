#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Megatron.hpp"
#include <sstream>
#include <vector>
#include <ranges>

const std::string INTENCION_DESPRECIO = "desprecio";
const std::string INTENCION_MANIPULACION = "manipulacion";
const std::string INTENCION_AMENAZA = "amenaza";

const std::string RESPUESTA_DESPRECIO_OPTIMUS_PRIME = "Esos debiles seran aplastados bajo mi yugo.";
const std::string RESPUESTA_DESPRECIO_AUTOBOTS = "Esos debiles seran aplastados bajo mi yugo.";
const std::string RESPUESTA_DESPRECIO_CYBERTRON = "Cybertron sera mio, a cualquier costo.";
const std::string RESPUESTA_DESPRECIO_GENERICA = "Eres insignificante.";
const std::string SUGERENCIA_FUSION_DESPRECIO = "Fusiona cristales comunes para mejorar tus capacidades basicas.";

const std::string RESPUESTA_MANIPULACION_PODER = "Unete a mi, y juntos gobernaremos este universo.";
const std::string RESPUESTA_MANIPULACION_ALIADO = "Unete a mi, y juntos gobernaremos este universo.";
const std::string RESPUESTA_MANIPULACION_FUERZA = "Solo el mas fuerte merece sobrevivir.";
const std::string RESPUESTA_MANIPULACION_GENERICA = "Puedo darte lo que buscas, si estas dispuesto a arrodillarte.";
const std::string SUGERENCIA_FUSION_MANIPULACION = "Fusiona cristales raros para obtener un poder significativo.";

const std::string RESPUESTA_AMENAZA_GENERICA_1 = "Atrevete a desafiarme, y conoceras el verdadero terror.";
const std::string RESPUESTA_AMENAZA_GENERICA_2 = "No hay lugar para los debiles en mi imperio.";
const std::string SUGERENCIA_FUSION_AMENAZA = "Realiza fusiones arriesgadas para obtener una ventaja poderosa.";

class MegatronTest : public testing::Test {
protected:
    Megatron megatron;
    std::string intencion, mensaje, esperado, respuesta, sugerencia;
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

std::string MegatronTest::generar_error_respuesta() {
    std::stringstream salida;
    salida << "La intención de Megatron es: " << intencion << "\n";
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

std::string MegatronTest::generar_error_respuesta_aleatoria() {
    std::stringstream salida;
    salida << "La intención de Megatron es: " << intencion << "\n";
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

std::string MegatronTest::generar_error_sugerencia() {
    std::stringstream salida;
    salida << "La intención de Megatron es: " << intencion << "\n";
    salida << "La sugerencia esperada es:" << "\n";
    salida << "\t" << esperado << "\n";
    salida << "pero la sugerencia obtenida fue: " << "\n";
    salida << "\t" << sugerencia << "\n";
    salida << "Verificá que la sugerencia coincida exactamente"
            " con la esperada y que no tenga un salto de línea.";
    return salida.str();
}

std::string MegatronTest::generar_error_aleatoriedad() {
    std::stringstream salida;
    salida << "La intención de Megatron es: " << intencion << "\n";
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

std::string MegatronTest::capturar_respuesta() {
    testing::internal::CaptureStdout();
    megatron.responder(mensaje);
    return testing::internal::GetCapturedStdout();
}

std::string MegatronTest::capturar_sugerencia() {
    testing::internal::CaptureStdout();
    megatron.sugerir_fusion();
    return testing::internal::GetCapturedStdout();
}

void MegatronTest::probar_respuesta() {
    megatron.cambiar_intencion(intencion);
    respuesta = capturar_respuesta();
    EXPECT_EQ(esperado, respuesta) << generar_error_respuesta();
}

void MegatronTest::probar_respuesta_aleatoria() {
    megatron.cambiar_intencion(intencion);
    respuesta = capturar_respuesta();
    EXPECT_THAT(esperados, testing::Contains(respuesta)) << generar_error_respuesta_aleatoria();
}

void MegatronTest::probar_sugerencia() {
    megatron.cambiar_intencion(intencion);
    sugerencia = capturar_sugerencia();
    EXPECT_EQ(esperado, sugerencia) << generar_error_sugerencia();
}

bool MegatronTest::validar_respuestas_obtenidas() {
    return std::ranges::all_of(respuestas_obtenidas, [](bool i) { return i; });
}

// Las pruebas empiezan a partir de acá //

// DESPRECIO //

TEST_F(MegatronTest, RespuestaDesprecioOptimusPrime) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "optimus prime";
    esperado = RESPUESTA_DESPRECIO_OPTIMUS_PRIME;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioOptimusPrimeCaseSensitive) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "OpTimUs PrimE";
    esperado = RESPUESTA_DESPRECIO_OPTIMUS_PRIME;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioOptimusPrimeCasoDeUso) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "Optimus Prime esta preparandose para atacarnos";
    esperado = RESPUESTA_DESPRECIO_OPTIMUS_PRIME;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioAutobots) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "autobots";
    esperado = RESPUESTA_DESPRECIO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioAutobotsCaseSensitive) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "AuTobOtS";
    esperado = RESPUESTA_DESPRECIO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioAutobotsCasoDeUso) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "Los Autobots estan preparandose para atacarnos";
    esperado = RESPUESTA_DESPRECIO_AUTOBOTS;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioCybertron) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "cybertron";
    esperado = RESPUESTA_DESPRECIO_CYBERTRON;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioCybertronCaseSensitive) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "cYbeRTroN";
    esperado = RESPUESTA_DESPRECIO_CYBERTRON;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioCybertronCasoDeUso) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "Cybertron esta a nuestro alcance";
    esperado = RESPUESTA_DESPRECIO_CYBERTRON;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioGenerica) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "hola";
    esperado = RESPUESTA_DESPRECIO_GENERICA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioGenericaCasoDeUso) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "Nuestra victoria es inminente";
    esperado = RESPUESTA_DESPRECIO_GENERICA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaDesprecioPrioridad) {
    intencion = INTENCION_DESPRECIO;
    mensaje = "Optimus Prime junto a los Autobots estan llegando a Cybertron";
    esperado = RESPUESTA_DESPRECIO_OPTIMUS_PRIME;
    probar_respuesta();
}

TEST_F(MegatronTest, SugerenciaFusionDesprecio) {
    intencion = INTENCION_DESPRECIO;
    esperado = SUGERENCIA_FUSION_DESPRECIO;
    probar_sugerencia();
}

// MANIPULACIÓN //

TEST_F(MegatronTest, RespuestaManipulacionPoder) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "poder";
    esperado = RESPUESTA_MANIPULACION_PODER;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionPoderCaseSensitive) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "pOdER";
    esperado = RESPUESTA_MANIPULACION_PODER;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionPoderCasoDeUso) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "Somos poderosos, ganaremos";
    esperado = RESPUESTA_MANIPULACION_PODER;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionAliado) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "aliado";
    esperado = RESPUESTA_MANIPULACION_ALIADO;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionAliadoCaseSensitive) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "AlIAdO";
    esperado = RESPUESTA_MANIPULACION_ALIADO;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionAliadoCasoDeUso) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "Todos aquellos que deseen destruccion son nuestros aliados";
    esperado = RESPUESTA_MANIPULACION_ALIADO;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionFuerza) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "fuerza";
    esperado = RESPUESTA_MANIPULACION_FUERZA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionFuerzaCaseSensitive) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "FuERza";
    esperado = RESPUESTA_MANIPULACION_FUERZA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionFuerzaCasoDeUso) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "Nuestra fuerza es inigualable";
    esperado = RESPUESTA_MANIPULACION_FUERZA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionGenerica) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "hola";
    esperado = RESPUESTA_MANIPULACION_GENERICA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionGenericaCasoDeUso) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "Nuestra victoria es inminente";
    esperado = RESPUESTA_MANIPULACION_GENERICA;
    probar_respuesta();
}

TEST_F(MegatronTest, RespuestaManipulacionPrioridad) {
    intencion = INTENCION_MANIPULACION;
    mensaje = "Con este poder y fuerza los Autobots no tienen oportunidad";
    esperado = RESPUESTA_MANIPULACION_PODER;
    probar_respuesta();
}

TEST_F(MegatronTest, SugerenciaFusionManipulacion) {
    intencion = INTENCION_MANIPULACION;
    esperado = SUGERENCIA_FUSION_MANIPULACION;
    probar_sugerencia();
}

// AMENAZA //

TEST_F(MegatronTest, RespuestaAmenazaGenerica) {
    intencion = INTENCION_AMENAZA;
    mensaje = "hola";
    esperados = {RESPUESTA_AMENAZA_GENERICA_1, RESPUESTA_AMENAZA_GENERICA_2};
    probar_respuesta_aleatoria();
}

TEST_F(MegatronTest, RespuestaAmenazaGenericaCasoDeUso) {
    intencion = INTENCION_AMENAZA;
    mensaje = "Nuestra victoria es inminente";
    esperados = {RESPUESTA_AMENAZA_GENERICA_1, RESPUESTA_AMENAZA_GENERICA_2};
    probar_respuesta_aleatoria();
}

TEST_F(MegatronTest, RespuestaAmenazaEsAleatoria) {
    intencion = INTENCION_AMENAZA;
    mensaje = "Nuestra victoria es inminente";
    esperados = {RESPUESTA_AMENAZA_GENERICA_1, RESPUESTA_AMENAZA_GENERICA_2};

    respuestas_obtenidas = std::vector(esperados.size(), false);
    megatron.cambiar_intencion(intencion);

    size_t indice;
    size_t i = 0;
    limite_intentos = 1000;
    while (i < limite_intentos && !validar_respuestas_obtenidas()) {
        respuesta = capturar_respuesta();
        auto it = std::ranges::find(esperados, respuesta);
        indice = static_cast<size_t>(it - esperados.begin());
        if (indice < respuestas_obtenidas.size()) {
            respuestas_obtenidas[indice] = true;
        }
        i++;
    }

    EXPECT_TRUE(validar_respuestas_obtenidas()) << generar_error_aleatoriedad();
}

TEST_F(MegatronTest, SugerenciaFusionAmenaza) {
    intencion = INTENCION_AMENAZA;
    esperado = SUGERENCIA_FUSION_AMENAZA;
    probar_sugerencia();
}

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Vector.hpp"
#include <vector>
#include <sstream>

class VectorTest : public testing::Test {
protected:
    Vector<int> vector;
    int dato{};

    std::string generar_error_igualdad_dato(size_t indice, int esperado);

    std::string generar_error_igualdad_dato_eliminado(size_t indice, int esperado);

    std::string generar_error_excepcion(std::string motivo, bool esperado);

    std::string generar_error_vacio(bool esperado);

    std::string generar_error_tamanio(size_t esperado);

    void probar_igualdad_vector(std::vector<int> vector_esperado);
};

std::string VectorTest::generar_error_igualdad_dato(size_t indice, int esperado) {
    std::stringstream salida;
    salida << "El valor esperado en el índice " << indice << " es:" << "\n";
    salida << "\t" << esperado << "\n";
    salida << "Pero el obtenido fue:" << "\n";
    salida << "\t" << vector[indice] << "\n";
    salida << "El vector tiene los siguientes valores:" << "\n";
    salida << "\t" << "[";
    for (size_t i = 0; i < vector.tamanio(); i++) {
        salida << std::to_string(vector[i]);
        if (i < vector.tamanio() - 1) {
            salida << ", ";
        }
    }
    salida << "]";
    return salida.str();
}

std::string VectorTest::generar_error_igualdad_dato_eliminado(size_t indice, int esperado) {
    std::stringstream salida;
    salida << "El valor esperado del dato eliminado en el índice " << indice << " es:" << "\n";
    salida << "\t" << esperado << "\n";
    salida << "Pero el obtenido fue:" << "\n";
    salida << "\t" << dato << "\n";
    salida << "El vector tiene los siguientes valores (luego de eliminar):" << "\n";
    salida << "\t" << "[";
    for (size_t i = 0; i < vector.tamanio(); i++) {
        salida << std::to_string(vector[i]);
        if (i < vector.tamanio() - 1) {
            salida << ", ";
        }
    }
    salida << "]";
    return salida.str();
}

std::string VectorTest::generar_error_excepcion(std::string motivo, bool esperado) {
    std::stringstream salida;
    salida << "Se esperaba que el vector "
            << (esperado ? "" : "no ")
            << "lance una excepción de tipo ExcepcionVector al " << motivo << " pero "
            << (esperado ? "no " : "") << "se lanzó " << (esperado ? "ninguna." : "una.");
    return salida.str();
}

std::string VectorTest::generar_error_vacio(bool esperado) {
    std::stringstream salida;
    salida << "Se esperaba que el vector "
            << (esperado ? "" : "no ")
            << "estuviera vacío pero tiene tamaño:" << "\n";
    salida << "\t" << vector.tamanio() << "\n";
    salida << "El vector tiene los siguientes valores:" << "\n";
    salida << "\t" << "[";
    for (size_t i = 0; i < vector.tamanio(); i++) {
        salida << std::to_string(vector[i]);
        if (i < vector.tamanio() - 1) {
            salida << ", ";
        }
    }
    salida << "]";
    return salida.str();
}

std::string VectorTest::generar_error_tamanio(size_t esperado) {
    std::stringstream salida;
    salida << "Se esperaba que el vector tenga tamaño:" << "\n";
    salida << "\t" << esperado << "\n";
    salida << "Pero tiene tamaño:" << "\n";
    salida << "\t" << vector.tamanio() << "\n";
    salida << "El vector tiene los siguientes valores:" << "\n";
    salida << "\t" << "[";
    for (size_t i = 0; i < vector.tamanio(); i++) {
        salida << std::to_string(vector[i]);
        if (i < vector.tamanio() - 1) {
            salida << ", ";
        }
    }
    salida << "]";
    return salida.str();
}

void VectorTest::probar_igualdad_vector(std::vector<int> vector_esperado) {
    EXPECT_EQ(vector_esperado.size(), vector.tamanio()) << generar_error_tamanio(vector_esperado.size());
    for (size_t i = 0; i < vector_esperado.size(); ++i) {
        EXPECT_EQ(vector_esperado[i], vector[i]) << generar_error_igualdad_dato(i, vector_esperado[i]);
    }
}

TEST_F(VectorTest, Alta) {
    vector.alta(1);
    EXPECT_EQ(vector[0], 1) << generar_error_igualdad_dato(0, 1);

    vector.alta(2);
    EXPECT_EQ(vector[1], 2) << generar_error_igualdad_dato(1, 2);

    vector.alta(3);
    EXPECT_EQ(vector[2], 3) << generar_error_igualdad_dato(2, 3);
}

TEST_F(VectorTest, AltaIndice) {
    vector.alta(1, 0);
    EXPECT_EQ(vector[0], 1) << generar_error_igualdad_dato(0, 1);

    vector.alta(2, 0);
    EXPECT_EQ(vector[0], 2) << generar_error_igualdad_dato(0, 2);

    vector.alta(3, 1);
    EXPECT_EQ(vector[1], 3) << generar_error_igualdad_dato(1, 3);

    vector.alta(4, 3);
    EXPECT_EQ(vector[3], 4) << generar_error_igualdad_dato(3, 4);
}

TEST_F(VectorTest, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector.alta(1, 1), ExcepcionVector) << generar_error_excepcion(
                                                        "agregar un elemento a un índice mayor a la cantidad de datos",
                                                        true);

    vector.alta(1);
    EXPECT_THROW(vector.alta(2, 2), ExcepcionVector) << generar_error_excepcion(
                                                        "agregar un elemento a un índice mayor a la cantidad de datos",
                                                        true);
}

TEST_F(VectorTest, OperadorAcceso) {
    vector.alta(1);
    vector.alta(2, 0);
    vector.alta(3);

    EXPECT_EQ(vector[0], 2) << generar_error_igualdad_dato(0, 2);
    EXPECT_EQ(vector[1], 1) << generar_error_igualdad_dato(1, 1);
    EXPECT_EQ(vector[2], 3) << generar_error_igualdad_dato(2, 3);
}

TEST_F(VectorTest, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector[0], ExcepcionVector) << generar_error_excepcion(
                                                "acceder a un elemento en un vector vacío", true);
}

TEST_F(VectorTest, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);

    EXPECT_NO_THROW(vector[0]) << generar_error_excepcion(
                                  "acceder a un elemento en un índice válido",
                                  false);
    EXPECT_THROW(vector[1], ExcepcionVector) << generar_error_excepcion(
                                                "acceder a un elemento en un índice mayor o igual a la cantidad de datos",
                                                true);
    EXPECT_THROW(vector[2], ExcepcionVector) << generar_error_excepcion(
                                                "acceder a un elemento en un índice mayor o igual a la cantidad de datos",
                                                true);
}

TEST_F(VectorTest, Baja) {
    vector.alta(1);
    vector.alta(2);

    dato = vector.baja();
    EXPECT_EQ(dato, 2) << generar_error_igualdad_dato_eliminado(1, 2);

    dato = vector.baja();
    EXPECT_EQ(dato, 1) << generar_error_igualdad_dato_eliminado(0, 1);
}

TEST_F(VectorTest, BajaIndice) {
    vector.alta(1);
    vector.alta(2);
    vector.alta(3);
    vector.alta(4);

    dato = vector.baja(1);
    EXPECT_EQ(dato, 2) << generar_error_igualdad_dato_eliminado(1, 2);

    dato = vector.baja(0);
    EXPECT_EQ(dato, 1) << generar_error_igualdad_dato_eliminado(0, 1);

    dato = vector.baja(1);
    EXPECT_EQ(dato, 4) << generar_error_igualdad_dato_eliminado(1, 4);

    dato = vector.baja(0);
    EXPECT_EQ(dato, 3) << generar_error_igualdad_dato_eliminado(0, 3);
}

TEST_F(VectorTest, BajaManejaVectorVacio) {
    EXPECT_THROW(vector.baja(), ExcepcionVector) << generar_error_excepcion(
                                                    "eliminar un elemento en un vector vacío",
                                                    true);
}


TEST_F(VectorTest, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector.baja(0), ExcepcionVector) << generar_error_excepcion(
                                                     "eliminar un elemento en un vector vacío",
                                                     true);
}

TEST_F(VectorTest, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector.alta(1);
    EXPECT_THROW(vector.baja(1), ExcepcionVector) << generar_error_excepcion(
                                                     "eliminar un elemento en un índice mayor o igual a la cantidad de datos",
                                                     true);
    EXPECT_THROW(vector.baja(2), ExcepcionVector) << generar_error_excepcion(
                                                     "eliminar un elemento en un índice mayor o igual a la cantidad de datos",
                                                     true);
    EXPECT_NO_THROW(vector.baja(0)) << generar_error_excepcion(
                                       "eliminar un elemento en un índice válido",
                                       false);
}

TEST_F(VectorTest, Vacio) {
    EXPECT_TRUE(vector.vacio()) << generar_error_vacio(true);

    vector.alta(1);
    EXPECT_FALSE(vector.vacio()) << generar_error_vacio(false);

    vector.baja();
    EXPECT_TRUE(vector.vacio()) << generar_error_vacio(true);
}

TEST_F(VectorTest, Tamanio) {
    EXPECT_EQ(vector.tamanio(), 0) << generar_error_tamanio(0);

    vector.alta(1);
    vector.alta(2);
    vector.alta(3);
    EXPECT_EQ(vector.tamanio(), 3) << generar_error_tamanio(3);

    vector.baja();
    EXPECT_EQ(vector.tamanio(), 2) << generar_error_tamanio(2);
}

TEST_F(VectorTest, CasoDeUso) {
    vector.alta(1);
    vector.alta(5);
    vector.alta(2);
    vector.alta(3);
    vector.alta(9);
    probar_igualdad_vector({1, 5, 2, 3, 9});

    vector.alta(7, 3);
    vector.baja(2);
    vector.alta(8, 0);
    probar_igualdad_vector({8, 1, 5, 7, 3, 9});

    vector.baja();
    vector.baja(4);
    vector.baja(1);
    probar_igualdad_vector({8, 5, 7});

    vector.baja(2);
    vector.baja(0);
    vector.baja();
    EXPECT_TRUE(vector.vacio()) << generar_error_vacio(true);
}

TEST_F(VectorTest, StressTest) {
    int cantidad_datos = 1000;
    std::vector<int> vector_esperado;
    for (int i = 0; i < cantidad_datos; i++) {
        vector.alta(i, 0);
        vector_esperado.insert(vector_esperado.begin(), i);
    }
    probar_igualdad_vector(vector_esperado);
    for (int i = 0; i < cantidad_datos; i++) {
        vector.baja(0);
    }
    EXPECT_TRUE(vector.vacio()) << generar_error_vacio(true);
}

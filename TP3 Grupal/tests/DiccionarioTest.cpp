#include "gtest/gtest.h"
#include "Diccionario.hpp"

class DiccionarioTest : public testing::Test {
protected:
    Diccionario<int, int> diccionario;

    void SetUp() override;

    void probar_igualdad_vector(Vector<int> vector, std::vector<int> vector_esperado);
};

void DiccionarioTest::probar_igualdad_vector(Vector<int> vector, std::vector<int> vector_esperado) {
    EXPECT_EQ(vector_esperado.size(), vector.tamanio());
    for (size_t i = 0; i < vector_esperado.size(); ++i) {
        EXPECT_EQ(vector_esperado[i], vector[i]);
    }
}

void DiccionarioTest::SetUp() {
    diccionario.alta(10, 10);
    diccionario.alta(7, 7);
    diccionario.alta(3, 3);
    diccionario.alta(13, 13);
    diccionario.alta(16, 16);
    diccionario.alta(11, 11);
}

TEST_F(DiccionarioTest, Alta) {
    EXPECT_NO_THROW(diccionario.alta(8, 8));
    EXPECT_NO_THROW(diccionario[8]);
}

TEST_F(DiccionarioTest, AltaManejaClaveRepetida) {
    EXPECT_THROW(diccionario.alta(10, 10), ExcepcionDiccionario);
}

TEST_F(DiccionarioTest, OperadorAcceso) {
    EXPECT_EQ(diccionario[10], 10);
}

TEST_F(DiccionarioTest, OperadorAccesoManejaClaveNoExistente) {
    EXPECT_THROW(diccionario[8], ExcepcionDiccionario);
}

TEST_F(DiccionarioTest, RecorridoInorder) {
    probar_igualdad_vector(diccionario.inorder(), {3, 7, 10, 11, 13, 16});
}

TEST_F(DiccionarioTest, RecorridoPreorder) {
    probar_igualdad_vector(diccionario.preorder(), {10, 7, 3, 13, 11, 16});
}

TEST_F(DiccionarioTest, RecorridoPostorder) {
    probar_igualdad_vector(diccionario.postorder(), {3, 7, 11, 16, 13, 10});
}

TEST_F(DiccionarioTest, RecorridoEnAncho) {
    probar_igualdad_vector(diccionario.ancho(), {10, 7, 13, 3, 11, 16});
}

TEST_F(DiccionarioTest, Tamanio) {
    EXPECT_EQ(diccionario.tamanio(), 6);
}

TEST_F(DiccionarioTest, Vacio) {
    Diccionario<int, int> diccionario_;
    EXPECT_TRUE(diccionario_.vacio());
    diccionario_.alta(1, 1);
    EXPECT_FALSE(diccionario_.vacio());
}

TEST_F(DiccionarioTest, Baja) {
    diccionario.baja(10);
    probar_igualdad_vector(diccionario.inorder(), {3, 7, 11, 13, 16});
    probar_igualdad_vector(diccionario.preorder(), {11, 7, 3, 13, 16});
    probar_igualdad_vector(diccionario.postorder(), {3, 7, 16, 13, 11});
    probar_igualdad_vector(diccionario.ancho(), {11, 7, 13, 3, 16});

    diccionario.baja(13);
    probar_igualdad_vector(diccionario.inorder(), {3, 7, 11, 16});
    probar_igualdad_vector(diccionario.preorder(), {11, 7, 3, 16});
    probar_igualdad_vector(diccionario.postorder(), {3, 7, 16, 11});
    probar_igualdad_vector(diccionario.ancho(), {11, 7, 16, 3});

    diccionario.baja(16);
    probar_igualdad_vector(diccionario.inorder(), {3, 7, 11});
    probar_igualdad_vector(diccionario.preorder(), {11, 7, 3});
    probar_igualdad_vector(diccionario.postorder(), {3, 7, 11});
    probar_igualdad_vector(diccionario.ancho(), {11, 7, 3});
}

TEST_F(DiccionarioTest, BajaManejaClaveNoExistente) {
    EXPECT_THROW(diccionario.baja(1), ExcepcionDiccionario);
}

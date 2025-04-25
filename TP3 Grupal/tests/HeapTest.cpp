#include "gtest/gtest.h"
#include "Heap.hpp"

class HeapTest : public testing::Test {
protected:
    Heap<int> heap{true};

    void SetUp() override;
};

void HeapTest::SetUp() {
    heap.alta(10);
    heap.alta(7);
    heap.alta(3);
    heap.alta(13);
    heap.alta(16);
    heap.alta(11);
}

TEST_F(HeapTest, Alta) {
    heap.alta(8);
    EXPECT_EQ(heap.primero(), 16);
    EXPECT_EQ(heap.tamanio(), 7);

    heap.alta(20);
    EXPECT_EQ(heap.primero(), 20);
    EXPECT_EQ(heap.tamanio(), 8);
}

TEST_F(HeapTest, Baja) {
    EXPECT_EQ(heap.baja(), 16);
    EXPECT_EQ(heap.tamanio(), 5);
}

TEST_F(HeapTest, BajaManejaHeapVacio) {
    Heap<int> heap_(true);
    EXPECT_THROW(heap_.baja(), ExcepcionHeap);
}

TEST_F(HeapTest, Primero) {
    EXPECT_EQ(heap.primero(), 16);
}

TEST_F(HeapTest, PrimeroManejaHeapVacio) {
    Heap<int> heap_(true);
    EXPECT_THROW(heap_.primero(), ExcepcionHeap);
}

TEST_F(HeapTest, Vacio) {
    Heap<int> heap_(true);
    EXPECT_TRUE(heap_.vacio());
    heap_.alta(1);
    EXPECT_FALSE(heap_.vacio());
}

TEST_F(HeapTest, Tamanio) {
    EXPECT_EQ(heap.tamanio(), 6);
}

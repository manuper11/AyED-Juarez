project(TP_TESTS)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG a1e255a582377e1006bb88a408ac3f933ba7c916
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

enable_testing()

add_executable(TP_TESTS
        MegatronTest.cpp
        OptimusPrimeTest.cpp
        VectorTest.cpp
        FusionadorEnergonTest.cpp
        BovedaCristalesTest.cpp
        GrafoTest.cpp
        ColaTest.cpp
        PilaTest.cpp
        DiccionarioTest.cpp
        HeapTest.cpp
        ListaTest.cpp
        ../src/Transformer.cpp
        ../include/Transformer.hpp
)

target_link_libraries(TP_TESTS
        GTest::gtest_main
        GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(TP_TESTS)
cmake_minimum_required(VERSION 3.22)
project(AYED_TP2_2C2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)

# Tienen que agregar acá todos los archivos que necesiten compilar, con el siguiente formato:
#   directorio/archivo1.cpp
#   directorio/archivo2.cpp
#   ...
set(ARCHIVOS_FUENTE
        src/Megatron.cpp
        src/OptimusPrime.cpp
        include/Vector.hpp
        src/GeneradorAleatorio.cpp
        src/FusionadorEnergon.cpp
        src/Cristal.cpp
        src/BovedaCristales.cpp
        src/Menu.cpp
        src/Minusculas.cpp
        src/GestorBoveda.cpp
)

add_executable(AYED_TP2_2C2024
        ${ARCHIVOS_FUENTE}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

add_subdirectory(tests)

target_sources(TP_TESTS PRIVATE ${ARCHIVOS_FUENTE})
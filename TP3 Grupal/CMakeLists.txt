cmake_minimum_required(VERSION 3.22)
project(AYED_TPG_2C2024)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

# Opciones de compilación
add_compile_options(-Wall -Werror -Wconversion)

# Incluir directorios
include_directories(include)
include_directories(include/TDAs)
include_directories(include/TDAs/Grafo)

# Buscar la biblioteca SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Lista de archivos fuente
set(ARCHIVOS_FUENTE
        include/TDAs/Vector.hpp
        include/TDAs/Cola.hpp
        include/TDAs/Pila.hpp
        include/TDAs/Lista.hpp
        include/TDAs/NodoLista.hpp
        include/TDAs/Diccionario.hpp
        include/TDAs/NodoDiccionario.hpp
        include/TDAs/Heap.hpp
        include/TDAs/Matriz.hpp
        include/TDAs/Grafo/CaminoMinimo.hpp
        include/TDAs/Grafo/Dijkstra.hpp
        include/TDAs/Grafo/FloydWarshall.hpp
        include/TDAs/Grafo/Grafo.hpp
        src/Grafo/Dijkstra.cpp
        src/Grafo/FloydWarshall.cpp
        src/Grafo/Grafo.cpp
        src/Megatron.cpp
        src/OptimusPrime.cpp
        src/GeneradorAleatorio.cpp
        src/FusionadorEnergon.cpp
        src/Cristal.cpp
        src/BovedaCristales.cpp
        src/GestorBoveda.cpp
        src/Minusculas.cpp
        src/Menu.cpp
        src/Transformer.cpp
        src/ManejoTransformer.cpp
        include/Transformer.hpp
        include/ManejoTransformer.hpp
        src/Juego.cpp
        include/Batalla.hpp
        src/Batalla.cpp
        include/SFML/Conexion.hpp
        include/SFML/Figura.hpp
        include/SFML/NodoGrafico.hpp
        include/SFML/MapaGrafo.hpp
        src/SFML/Conexion.cpp
        src/SFML/Figura.cpp
        src/SFML/NodoGrafico.cpp
        src/SFML/MapaGrafo.cpp
        src/Archivos.cpp
)

# Agregar el ejecutable principal
add_executable(AYED_TPG_2C2024
        ${ARCHIVOS_FUENTE}
        main.cpp
)

# Enlazar bibliotecas necesarias (SFML)
target_link_libraries(AYED_TPG_2C2024 sfml-graphics sfml-window sfml-system)

# Establecer propiedades del ejecutable
set_target_properties(AYED_TPG_2C2024 PROPERTIES OUTPUT_NAME "main")

# Subdirectorio para pruebas
add_subdirectory(tests)

# Configurar pruebas
target_sources(TP_TESTS PRIVATE ${ARCHIVOS_FUENTE})
target_link_libraries(TP_TESTS sfml-graphics sfml-window sfml-system)

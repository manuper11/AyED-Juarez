[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mpISVoEK)
# AYED - TPG 2c2024 - Grupo PATEA

<p align="center">
   <img src="Banner.jpg" alt="TPG: La batalla final"><br>
</p>

## Integrantes:

### Pili, Alfonso - 112182 (Delegado)

### Duarte Brizuela, Mauro Agustin - 112010

### Mayuri Pajuelo, Andy Rodrigo - 111492

### Perez Martinez, Emanuel - 111855

## Entregables:

1. [Informe de complejidad algorítmica](https://docs.google.com/document/d/1piF0MZd1XcytugBAaE4txONFCkuDQZa6_w9lTFVnLLs/edit?usp=sharing)
2. [Video de demostración del programa](https://drive.google.com/file/d/1884E86LIB9m2hCcibaFSSmU3Xkn1Odg4/view?usp=sharing)


## Justificación de las estructuras de datos y algoritmos

1. Decidimos utilizar un diccionario para almacenar el listado de Transformers, ya que nos permite usar sus nombres como claves. Además, esta estructura ofrece una búsqueda más eficiente en comparación con un array u otras estructuras desarrolladas. Dado que manejamos una cantidad reducida de Transformers con nombres únicos, las claves estarán bien distribuidas, maximizando su eficiencia.
2. Optamos por utilizar el TDA Vector en muchas de las clases debido a su mejor eficiencia espacial en comparación con los vectores estándar. Además, al ser una estructura dinámica, ofrece un manejo más sencillo y flexible.
3. Decidimos utilizar el algoritmo de Dijkstra para encontrar el camino mínimo porque se enfoca en identificar el trayecto más corto entre un nodo origen y los demás nodos. En cambio, el algoritmo de Floyd-Warshall calcula todos los caminos mínimos entre todos los pares de nodos, lo cual sería innecesario para nuestro caso y menos eficiente.
## Compilación
> [!WARNING]
> Para su correcta compilacion es necesario instalar la libreria SFML:
> ```
> sudo apt-get install libsfml-dev  
> ```

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

```g++ -I include -I include/TDAs -I include/TDAs/Grafo src/SFML/*.cpp src/*.cpp src/Grafo/*.cpp main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system -Wall -Werror -Wconversion```

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

## Aclaraciones adicionales:

// ACLARACIONES ADICIONALES PARA EL CORRECTOR, COMO DECISIONES O SUPUESTOS QUE CONSIDERARON //
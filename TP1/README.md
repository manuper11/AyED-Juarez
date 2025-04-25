[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/f5GN_WfX)
# AYED - TP1 2c2024 - PEREZ MARTINEZ, EMANUEL - 111855

<p align="center">
   <img src="Banner.jpg" alt="TP1: Interacción con Transformers"><br>
</p>

## Compilación

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

g++ -I include src/*.cpp main.cpp -o main -Wall -Werror -Wconversion

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

## Aclaraciones adicionales:

Al comienzo, utilicé funciones para manejar las interacciones con el usuario. Posteriormente decidí transformar estas funciones en una clase llamada **Funciones**, que se especializa en mostrar información en pantalla y en el procesamiento de las respuestas del usuario

Tambien tras reflexionar sobre la estructura del menú, concluí que era más apropiado dividir la interacción en dos menús distintos: uno para seleccionar el personaje y otro para determinar las acciones a realizar con ese personaje. Esta separación mejora la fluidez de la conversacion ya que no pregunta al usuario si quiere mandar un nuevo mensaje y evita que el método de sugerencia de fusión se ejecute de forma constante
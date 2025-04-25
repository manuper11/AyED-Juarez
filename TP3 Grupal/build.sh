#!/bin/bash

ROJO='\033[0;31m'
VERDE='\033[0;32m'
SC='\033[0m'

# Función para instalar SFML si no está presente
install_sfml() {
  echo -e "${VERDE}Verificando SFML...${SC}"
  if ! dpkg -l | grep -q "libsfml-dev"; then
    echo -e "${VERDE}Instalando SFML...${SC}"
    sudo apt update
    sudo apt install -y libsfml-dev
    if [ $? -ne 0 ]; then
      echo -e "${ROJO}ERROR: No se pudo instalar SFML.${SC}"
      exit 1
    fi
  else
    echo -e "${VERDE}SFML ya está instalada.${SC}"
  fi
}

# Verificar si SFML está instalada
install_sfml

# Crear directorio build si no existe
if [ ! -d "build" ]; then
  mkdir build
fi

# Configurar y compilar el proyecto
cd build && cmake ..
if ! cmake --build .; then
  echo -e "${ROJO}ERROR: El proyecto no compiló.${SC}"
  exit 1
fi

echo -e "${VERDE}El proyecto compiló correctamente.${SC}"

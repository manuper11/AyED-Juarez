#!/bin/bash

ROJO='\033[0;31m'
VERDE='\033[0;32m'
SC='\033[0m'

if [ ! -d "build" ]; then
  mkdir build
fi

cd build && cmake ..

if ! cmake --build .; then
  echo -e "${ROJO}ERROR: El proyecto no compiló.${SC}"
  exit 1
fi

echo -e "${VERDE}El proyecto compiló correctamente.${SC}"
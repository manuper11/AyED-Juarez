#!/bin/bash

ROJO='\033[0;31m'
VERDE='\033[0;32m'
CELESTE='\033[1;34m'
SC='\033[0m'

if ! ./build.sh; then
  exit 1
fi

echo -e "${CELESTE}\n========= EJECUTANDO VALGRIND =========\n${SC}"

valgrind --leak-check=yes --error-exitcode=2 ./build/TP_TESTS --gtest_color=yes

if [ $? -eq 2 ]; then
  echo -e "${ROJO}ERROR: Hay pérdidas de memoria (o el programa terminó de forma abrupta).${SC}"
  exit 1
fi

echo -e "${VERDE}No se detectaron pérdidas de memoria.${SC}"
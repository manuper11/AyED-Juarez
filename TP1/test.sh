#!/bin/bash

ROJO='\033[0;31m'
VERDE='\033[0;32m'
CELESTE='\033[1;34m'
SC='\033[0m'

if ! ./build.sh; then
  exit 1
fi

echo -e "${CELESTE}\n========= EJECUTANDO PRUEBAS =========\n${SC}"

if ! ./build/TP_TESTS --gtest_color=yes --gtest_output="json:../test_output.json"; then
  echo -e "${ROJO}ERROR: Hay pruebas que fallaron.${SC}"
  exit 1
fi

echo -e "${VERDE}Todas las pruebas pasaron correctamente.${SC}"
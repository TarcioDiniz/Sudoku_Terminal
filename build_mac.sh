#!/bin/bash

# Configurações do compilador
COMPILER_COMMAND=gcc
COMPILER_FLAGS="-std=c11 -Wall"
OUTPUT_EXECUTABLE=gerador_sudoku

# Compilação do programa
$COMPILER_COMMAND $COMPILER_FLAGS -Iinclude src/criador.c src/solucionador.c src/historico.c src/game_dao.c main.c -o $OUTPUT_EXECUTABLE

# Execução do programa
./$OUTPUT_EXECUTABLE

@echo off

rem Configurações do compilador
set COMPILER_COMMAND=gcc
set COMPILER_FLAGS=-std=c11 -Wall
set OUTPUT_EXECUTABLE=gerador_sudoku.exe

rem Compilação dos arquivos
%COMPILER_COMMAND% %COMPILER_FLAGS% -Iinclude -o %OUTPUT_EXECUTABLE% src/criador.c src/solucionador.c src/historico.c src/game_dao.c main.c

rem Execução do programa
.\%OUTPUT_EXECUTABLE%

pause

@echo off

rem Configurações do compilador
set COMPILER_COMMAND=gcc
set COMPILER_FLAGS=-std=c11 -Wall
set OUTPUT_EXECUTABLE=gerador_sudoku.exe

rem Compilação do programa
%COMPILER_COMMAND% %COMPILER_FLAGS% -Iinclude src/criador.c src/solucionador.c src/historico.c src/game_dao.c main.c -o %OUTPUT_EXECUTABLE%

rem Execução do programa
.\%OUTPUT_EXECUTABLE%

pause

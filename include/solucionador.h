#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H

#include <stdbool.h>
#include "historico.h"
#include "sudokugrid.h"

bool solucionarSudoku(SudokuGrid* grade);
bool ehSeguro(SudokuGrid* grade, int linha, int coluna, int num);
bool encontrarProximaCelulaVazia(SudokuGrid* grade, int* linha, int* coluna);
int getDica(SudokuGrid grade, int linha, int coluna);
bool verificarJogada(SudokuGrid grade, int linha, int coluna, int valor);
bool jogoConcluido(SudokuGrid* grade);
void setGrade(SudokuGrid* grade, int linha, int coluna, int valor);

bool verificarLinha(SudokuGrid* grade, int linha, int num);
bool verificarColuna(SudokuGrid* grade, int coluna, int num);
bool verificarSubGrade(SudokuGrid* grade, int linha, int coluna, int num);

#endif /* SOLUCIONADOR_H */

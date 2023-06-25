#ifndef CRIADOR_H
#define CRIADOR_H

/* Níveis de Dificuldade no Sudoku
// Fácil: 40 números preenchidos na grade.
// Médio: 30 números preenchidos na grade.
// Difícil: 20 números preenchidos na grade. */

#define DIFICULDADE 20

#include "solucionador.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "criador.h"


SudokuGrid gerarGradeSudoku ();
void preencherGradeZerada (SudokuGrid *);
void preencherDiagonal (SudokuGrid *);
void definirDificuldade (SudokuGrid *);
int gerarNumeroAleatorio (int, int);
void imprimirGrade (SudokuGrid *);

#endif /* CRIADOR_H */

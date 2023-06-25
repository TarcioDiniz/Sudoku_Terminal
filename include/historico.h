#ifndef HISTORICO_H
#define HISTORICO_H

#include "sudokugrid.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Jogada {
    int linha;
    int coluna;
    int valor;
    struct Jogada* anterior;
    struct Jogada* proxima;
} Jogada;

typedef struct {
    Jogada* primeiro;
    Jogada* atual;
    Jogada* ultima;
} Historico;

void inicializarHistorico(Historico* historico);
void adicionarJogada(Historico* historico, int linha, int coluna, int valor);
bool retrocederJogada(Historico* historico, SudokuGrid* grade);
bool avancarJogada(Historico* historico, SudokuGrid* grade);
void limparHistorico(Historico* historico);
void imprimirHistorico(Historico* historico);

#endif  // HISTORICO_H

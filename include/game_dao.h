#ifndef GAME_DAO_H
#define GAME_DAO_H

#include "sudokugrid.h"
#include "historico.h"
#include <stdbool.h>

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <malloc.h>

#define DIRETORIO_JOGOS "jogos"

bool diretorioExiste();
bool criarDiretorio();
bool salvarJogo(const SudokuGrid* grade, const Historico* historico, const char* nomeArquivo);
bool carregarJogo(SudokuGrid* grade, Historico* historico, const char* nomeArquivo);
void imprimirListaJogos();
bool excluirJogo(const char* nomeArquivo);

#endif  // GAME_DAO_H

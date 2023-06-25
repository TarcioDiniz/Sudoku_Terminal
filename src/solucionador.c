#include "solucionador.h"

bool solucionarSudoku(SudokuGrid* grade) {
    int linha, coluna;

    if (!encontrarProximaCelulaVazia(grade, &linha, &coluna))
        return true; // O Sudoku está resolvido

    // Teste números de 1 a 9 para preencher a célula vazia
    for (int num = 1; num <= 9; num++) {
        if (ehSeguro(grade, linha, coluna, num)) {
            grade->grid[linha][coluna] = num; // Preenche a célula com o número

            if (solucionarSudoku(grade))
                return true; // Encontrou uma solução

            grade->grid[linha][coluna] = 0; // Não encontrou solução, reverte o preenchimento
        }
    }

    return false; // Não encontrou solução para a grade
}

bool encontrarProximaCelulaVazia(SudokuGrid* grade, int* linha, int* coluna) {
    for (*linha = 0; *linha < 9; (*linha)++) {
        for (*coluna = 0; *coluna < 9; (*coluna)++) {
            if (grade->grid[*linha][*coluna] == 0)
                return true;
        }
    }
    return false;
}

bool ehSeguro(SudokuGrid* grade, int linha, int coluna, int num) {
    int subLinha = linha - linha % 3;
    int subColuna = coluna - coluna % 3;
    if (verificarLinha(grade, linha, num) && verificarColuna(grade, coluna, num) && verificarSubGrade(grade, subLinha, subColuna, num))
        return true;
    return false;
}

bool verificarLinha(SudokuGrid* grade, int linha, int num) {
    for (int i = 0; i < 9; i++) {
        if (grade->grid[linha][i] == num)
            return false;
    }
    return true;
}

bool verificarColuna(SudokuGrid* grade, int coluna, int num) {
    for (int i = 0; i < 9; i++) {
        if (grade->grid[i][coluna] == num)
            return false;
    }
    return true;
}

bool verificarSubGrade(SudokuGrid* grade, int subLinha, int subColuna, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (grade->grid[i + subLinha][j + subColuna] == num) {
                return false;
            }
    }
    return true;
}

int getDica(SudokuGrid grade, int linha, int coluna) {
    if (linha < 0 || linha >= 9 || coluna < 0 || coluna >= 9)
        return -1; // Posição inválida

    if (grade.grid[linha][coluna] != 0)
        return -1; // Célula já preenchida

    SudokuGrid gradeProxy = grade; // Cria uma cópia da grade atual para realizar análises

    // Tenta preencher a célula com números de 1 a 9
    for (int num = 1; num <= 9; num++) {
        if (ehSeguro(&gradeProxy, linha, coluna, num)) {
            gradeProxy.grid[linha][coluna] = num;
            if (solucionarSudoku(&gradeProxy)) // Verifica se a grade é solucionável
                return num;
        }
    }
    return -1;
}

bool jogoConcluido(SudokuGrid* grade) {
    // Verificar se todas as células estão preenchidas
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            if (grade->grid[linha][coluna] == 0) {
                return false; // Ainda há células vazias, o jogo não está concluído
            }
        }
    }

    // Verificar se a grade atual é uma solução válida
    SudokuGrid gradeCopia = *grade; // Copiar a grade para evitar modificações indesejadas
    return solucionarSudoku(&gradeCopia); // Retorna true se a grade atual for uma solução válida
}

void setGrade(SudokuGrid* grade, int linha, int coluna, int valor) {
    grade->grid[linha][coluna] = valor;
}

bool verificarJogada(SudokuGrid grade, int linha, int coluna, int valor) {
    // Verifica se a jogada é válida
    if (linha < 0 || linha >= 9 || coluna < 0 || coluna >= 9)
        return false; // Posição inválida

    if (valor < 1 || valor > 9)
        return false; // Valor inválido

    if (grade.grid[linha][coluna] != 0)
        return false; // Célula já preenchida

    // Verifica se o número já está presente na mesma linha
    for (int i = 0; i < 9; i++) {
        if (grade.grid[linha][i] == valor) {
            return false;
        }
    }

    // Verifica se o número já está presente na mesma coluna
    for (int i = 0; i < 9; i++) {
        if (grade.grid[i][coluna] == valor) {
            return false;
        }
    }

    // Verifica se o número já está presente no mesmo bloco 3x3
    int inicioLinha = linha - linha % 3;
    int inicioColuna = coluna - coluna % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grade.grid[i + inicioLinha][j + inicioColuna] == valor) {
                return false;
            }
        }
    }

    // Jogada válida, atualiza a grade
    grade.grid[linha][coluna] = valor;

    return true;
}

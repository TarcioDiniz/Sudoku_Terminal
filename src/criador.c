#include "criador.h"

SudokuGrid gerarGradeSudoku() {
    srand(time(NULL));
    SudokuGrid grid;
    SudokuGrid *gridPtr = &grid;
    
    preencherGradeZerada(gridPtr);
    preencherDiagonal(gridPtr);
    if (!solucionarSudoku(gridPtr)) {
        printf("Não foi possível resolver a grade inicialmente preenchida. Gerando uma nova grade.\n");
        return gerarGradeSudoku(); 
    }
    definirDificuldade(gridPtr);

    return grid;
}

void preencherGradeZerada (SudokuGrid *grade) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grade -> grid[i][j] = 0;
        }
    }
}

void preencherDiagonal (SudokuGrid *grade) {
    for (int i = 0; i < 9; i += 3) {
        int num = gerarNumeroAleatorio(1, 9);
        grade -> grid[i][i] = num;
    }
}

void definirDificuldade (SudokuGrid *grade) {
    int numerosParaRemover = 81 - DIFICULDADE;
    while (numerosParaRemover > 0) {
        int i = gerarNumeroAleatorio(0, 8);
        int j = gerarNumeroAleatorio(0, 8);
        if (grade -> grid[i][j] != 0) {
            grade -> grid[i][j] = 0;
            numerosParaRemover--;
        }
    }
}

int gerarNumeroAleatorio (int min, int max) {
    return rand() % (max - min + 1) + min; // assegura que o valor retornado esteja entre min e max
}

void imprimirGrade(SudokuGrid *grid) {
    printf("\n ----------------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf(" |");
        for (int j = 0; j < 9; j++) {
            if (grid->grid[i][j] != 0) {
                printf(" %2d", grid->grid[i][j]);
            } else {
                printf("  .");
            }
            if ((j + 1) % 3 == 0) {
                printf(" |");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf(" ----------------------------------\n");
        }
    }
    printf("\n");
}

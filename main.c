#include <stdio.h>
#include <stdbool.h>
#include "sudokugrid.h"
#include "historico.h"
#include "game_dao.h"
#include "solucionador.h"
#include "criador.h"

void imprimirMenu() {
    printf("Digite uma acao:\n"
           "1 - Preencher celula\n"
           "2 - Retroceder jogada\n"
           "3 - Avancar jogada\n"
           "4 - Salvar jogo\n"
           "5 - Carregar jogo\n"
           "6 - Excluir jogo\n"
           "7 - Dar uma dica\n"
           "8 - Resolver o Sudoku\n"
           "9 - Sair do jogo\n");
}

void preencherCelula(SudokuGrid* grade, Historico* historico) {
    int linha, coluna, valor;
    printf("Digite a posicao (linha e coluna) e o valor a ser preenchido:\n");
    scanf("%d %d %d", &linha, &coluna, &valor);

    if (verificarJogada(*grade, linha, coluna, valor)) {
        setGrade(grade, linha, coluna, valor);
        adicionarJogada(historico, linha, coluna, valor);
    } else {
        printf("Jogada invalida. Tente novamente.\n");
    }
}

void retrocederJogadaMain(Historico* historico, SudokuGrid* grade) {
    if (retrocederJogada(historico, grade)) {
        printf("Jogada retrocedida com sucesso.\n");
    } else {
        printf("Nao ha jogadas para retroceder.\n");
    }
}

void avancarJogadaMain(Historico* historico, SudokuGrid* grade) {
    if (avancarJogada(historico, grade)) {
        printf("Jogada avancada com sucesso.\n");
    } else {
        printf("Nao ha jogadas para avancar.\n");
    }
}

void salvarJogoMain(SudokuGrid* grade, Historico* historico) {
    char nomeArquivo[100];
    printf("Digite o nome do arquivo para salvar o jogo:\n");
    scanf("%s", nomeArquivo);

    if (salvarJogo(grade, historico, nomeArquivo)) {
        printf("Jogo salvo com sucesso.\n");
    } else {
        printf("Erro ao salvar o jogo.\n");
    }
}

void carregarJogoMain(SudokuGrid* grade, Historico* historico) {
    printf("Lista de jogos disponiveis:\n");
    imprimirListaJogos();

    char nomeArquivo[100];
    printf("Digite o nome do arquivo para carregar o jogo:\n");
    scanf("%s", nomeArquivo);

    if (carregarJogo(grade, historico, nomeArquivo)) {
        printf("Jogo carregado com sucesso.\n");
    } else {
        printf("Erro ao carregar o jogo.\n");
    }
}

void excluirJogoMain() {
    printf("Lista de jogos disponiveis:\n");
    imprimirListaJogos();

    char nomeArquivo[100];
    printf("Digite o nome do arquivo para excluir o jogo:\n");
    scanf("%s", nomeArquivo);

    if (excluirJogo(nomeArquivo)) {
        printf("Jogo excluido com sucesso.\n");
    } else {
        printf("Erro ao excluir o jogo.\n");
    }
}

void darDica(SudokuGrid grade) {
    int linha, coluna;
    printf("Digite a posicao (linha e coluna) para obter uma dica:\n");
    scanf("%d %d", &linha, &coluna);

    int dica = getDica(grade, linha, coluna);
    if (dica != 0) {
        printf("Dica: Preencha a celula com o valor %d.\n", dica);
    } else {
        printf("Nao ha dicas disponiveis para essa celula.\n");
    }
}

void resolverSudoku(SudokuGrid* grade) {
    if (solucionarSudoku(grade)) {
        printf("O Sudoku foi resolvido com sucesso.\n");
    } else {
        printf("Nao foi possivel resolver o Sudoku.\n");
    }
}

int main() {
    SudokuGrid grade = gerarGradeSudoku();
    Historico historico;
    inicializarHistorico(&historico);

    if (!diretorioExiste()) {
        if (!criarDiretorio()) {
            printf("Erro ao criar o diretorio de jogos.\n");
            return 1;
        }
    }

    while (true) {
        imprimirGrade(&grade);

        if (jogoConcluido(&grade)) {
            printf("Parabens! Voce concluiu o jogo!\n");
            break;
        }

        imprimirMenu();
        int acao;
        scanf("%d", &acao);

        switch (acao) {
            case 1:
                preencherCelula(&grade, &historico);
                break;
            case 2:
                retrocederJogadaMain(&historico, &grade);
                break;
            case 3:
                avancarJogadaMain(&historico, &grade);
                break;
            case 4:
                salvarJogoMain(&grade, &historico);
                break;
            case 5:
                carregarJogoMain(&grade, &historico);
                break;
            case 6:
                excluirJogoMain();
                break;
            case 7:
                darDica(grade);
                break;
            case 8:
                resolverSudoku(&grade);
                break;
            case 9:
                printf("Saindo do jogo...\n");
                return 0;
            default:
                printf("Acao invalida. Tente novamente.\n");
                break;
        }
    }

    limparHistorico(&historico);

    return 0;
}

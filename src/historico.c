#include "historico.h"

void inicializarHistorico(Historico *historico) {
    historico->primeiro = NULL;
    historico->atual = NULL;
}

void adicionarJogada(Historico *historico, int linha, int coluna, int valor) {
    Jogada *novaJogada = (Jogada *) malloc(sizeof(Jogada));
    novaJogada->linha = linha;
    novaJogada->coluna = coluna;
    novaJogada->valor = valor;
    novaJogada->anterior = historico->atual;
    novaJogada->proxima = NULL;

    historico->atual = novaJogada;

    if (historico->primeiro == NULL) {
        historico->primeiro = novaJogada;
    }

    if (novaJogada->anterior != NULL) {
        novaJogada->anterior->proxima = novaJogada;
    }

    historico->ultima = novaJogada;  // Atualiza a última jogada

    imprimirHistorico(historico);
}

bool retrocederJogada(Historico *historico, SudokuGrid *grade) {
    if (historico->ultima == NULL) {
        return false; // Não há jogadas no histórico
    }

    Jogada *ultimaJogada = historico->ultima;

    // Restaurar a grade para o estado anterior
    grade->grid[ultimaJogada->linha][ultimaJogada->coluna] = 0;

    // Atualizar o ponteiro atual do histórico
    historico->atual = ultimaJogada->anterior;
    historico->ultima = ultimaJogada->anterior;

    imprimirHistorico(historico);
    return true;
}

bool avancarJogada(Historico *historico, SudokuGrid *grade) {
    imprimirHistorico(historico);
    if (historico->atual == NULL || historico->atual->proxima == NULL) {
        return false; // Não há próxima jogada no histórico
    }

    Jogada *proximaJogada = historico->atual->proxima;

    // Atualizar a grade com o valor da próxima jogada
    grade->grid[proximaJogada->linha][proximaJogada->coluna] = proximaJogada->valor;

    // Atualizar o ponteiro atual do histórico
    historico->atual = proximaJogada;
    historico->ultima = proximaJogada;  // Atualiza a última jogada

    return true;
}

void limparHistorico(Historico *historico) {
    Jogada *atual = historico->primeiro;
    while (atual != NULL) {
        Jogada *proxima = atual->proxima;
        free(atual);
        atual = proxima;
    }
    historico->primeiro = NULL;
    historico->atual = NULL;
}

void imprimirHistorico(Historico *historico) {
    Jogada *jogadaAtual = historico->primeiro;

    printf("Histórico de jogadas:\n");

    while (jogadaAtual != NULL) {
        printf("Linha: %d, Coluna: %d, Valor: %d\n", jogadaAtual->linha, jogadaAtual->coluna, jogadaAtual->valor);
        jogadaAtual = jogadaAtual->proxima;
    }
}

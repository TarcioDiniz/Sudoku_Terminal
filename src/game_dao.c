#include "game_dao.h"

char diretorio[PATH_MAX];

bool diretorioExiste() {
    char diretorioAtual[PATH_MAX];
    if (getcwd(diretorioAtual, sizeof(diretorioAtual)) == NULL) {
        perror("Erro ao obter o diretorio atual");
        return false;
    }

    snprintf(diretorio, sizeof(diretorio), "%s/%s", diretorioAtual, DIRETORIO_JOGOS);

    struct stat st;
    return stat(diretorio, &st) == 0 && S_ISDIR(st.st_mode);
}

bool criarDiretorio() {
    char diretorioAtual[PATH_MAX];
    if (getcwd(diretorioAtual, sizeof(diretorioAtual)) == NULL) {
        perror("Erro ao obter o diretorio atual");
        return false;
    }

    snprintf(diretorio, sizeof(diretorio), "%s/%s", diretorioAtual, DIRETORIO_JOGOS);

    if (mkdir(diretorio) != 0) {
        return false;
    }

    return true;
}

bool salvarJogo(const SudokuGrid* grade, const Historico* historico, const char* nomeArquivo) {
    char nomeArquivoCompleto[PATH_MAX];
    snprintf(nomeArquivoCompleto, sizeof(nomeArquivoCompleto), "%s/%s", diretorio, nomeArquivo);

    FILE* arquivo = fopen(nomeArquivoCompleto, "wb");
    if (arquivo == NULL) {
        return false; // Não foi possível abrir o arquivo
    }

    // Escreve os dados do jogo no arquivo
    fwrite(grade, sizeof(SudokuGrid), 1, arquivo);

    Jogada* jogadaAtual = historico->primeiro;
    while (jogadaAtual != NULL) {
        fwrite(jogadaAtual, sizeof(Jogada), 1, arquivo);
        jogadaAtual = jogadaAtual->proxima;
    }

    fclose(arquivo);
    return true;
}

bool carregarJogo(SudokuGrid* grade, Historico* historico, const char* nomeArquivo) {
    char nomeArquivoCompleto[PATH_MAX];
    snprintf(nomeArquivoCompleto, sizeof(nomeArquivoCompleto), "%s/%s", diretorio, nomeArquivo);

    FILE* arquivo = fopen(nomeArquivoCompleto, "rb");
    if (arquivo == NULL) {
        return false; // Não foi possível abrir o arquivo
    }

    // Lê os dados do jogo do arquivo
    fread(grade, sizeof(SudokuGrid), 1, arquivo);

    Jogada jogada;
    while (fread(&jogada, sizeof(Jogada), 1, arquivo) == 1) {
        adicionarJogada(historico, jogada.linha, jogada.coluna, jogada.valor);
    }

    fclose(arquivo);
    return true;
}

void imprimirListaJogos() {
    DIR* dir = opendir(diretorio);
    if (dir == NULL) {
        printf("Diretorio de jogos nao encontrado.\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
#ifdef _DIRENT_HAVE_D_TYPE
        if (entry->d_type == DT_REG) {
#else
        char arquivoCompleto[PATH_MAX];
        snprintf(arquivoCompleto, sizeof(arquivoCompleto), "%s/%s", diretorio, entry->d_name);

        struct stat st;
        if (stat(arquivoCompleto, &st) == 0 && S_ISREG(st.st_mode)) {
#endif
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

bool excluirJogo(const char* nomeArquivo) {
    char nomeArquivoCompleto[PATH_MAX];
    snprintf(nomeArquivoCompleto, sizeof(nomeArquivoCompleto), "%s/%s", diretorio, nomeArquivo);

    if (remove(nomeArquivoCompleto) == 0) {
        printf("Arquivo excluido com sucesso.\n");
        return true;
    } else {
        printf("Falha ao excluir o arquivo.\n");
        return false;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "sequencial.h"
#include "encadeada.h"
#define TAM 15

int main()
{
    Encadeada lista;
    FILE *arquivo = leArquivo();
    int nLinhas = quantidadeDeLinhas(arquivo);

    printf("Quantidade de linhas: %d\n", nLinhas);

    arquivoParaEncadeada(&lista, arquivo, nLinhas);
    printf("Tamanho: %d\n", lista.tamanho);
    exibeEncadeada(&lista);
    free(arquivo);
    return 0;
}

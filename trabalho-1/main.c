#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "sequencial.h"
#define TAM 15

int main()
{
    Sequencial lista;
    FILE *arquivo = leArquivo();
    int nLinhas = quantidadeDeLinhas(arquivo);

    printf("Quantidade de linhas: %d\n", nLinhas);

    arquivoParaSequencial(&lista, arquivo, nLinhas);
    printf("Tamanho: %d\n", lista.nMax);
    exibeSequencial(&lista);
    free(arquivo);
    return 0;
}

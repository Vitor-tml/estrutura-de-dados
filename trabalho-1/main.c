#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "sequencial.h"
#include "encadeada.h"
#define TAM 15

int main()
{
    /*
    Encadeada lista;
    FILE *arquivo = leArquivo();
    FILE *output;
    int nLinhas = quantidadeDeLinhas(arquivo);
    char nome[TAM] = "Vitor";
    int rg = 132957;
    criaArquivo();
        
    printf("Quantidade de linhas: %d\n", nLinhas);

    arquivoParaEncadeada(&lista, arquivo, nLinhas);
    printf("Tamanho: %d\n", lista.tamanho);
    exibeEncadeada(&lista);
    adicionaInicioEncadeada(nome, rg, &lista);
    printf("----------------------------------\n");
    printf("Segunda\n");
    printf("----------------------------------\n");
    exibeEncadeada(&lista);
    output = criaArquivo();
    encadeadaParaArquivo(&lista, output);

    fclose(output);
    fclose(arquivo);
    */

    Sequencial lista;

    iniciaSequencial(&lista, 10);
    preencheSequencial(&lista);
    exibeSequencial(&lista);

    FILE *output = criaArquivo();
    sequencialParaArquivo(&lista, output);
    return 0;
}

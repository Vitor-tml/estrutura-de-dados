#include <stdio.h>
#include "cadeia.h"
FILE *leArquivo()
{
    FILE *arquivo;
    char nome[15];
    printf("Qual o nome do arquivo?");
    scanf("%s", nome);

    arquivo = fopen(nome, "r");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    return arquivo;
}

void adicionarLinha(EntradaPalavra* entrada, int numeroLinha) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->numeroLinha = numeroLinha;
    novoNo->proximo = entrada->linhas;
    entrada->linhas = novoNo;
}

EntradaPalavra* encontrarPalavra(EntradaPalavra* indiceInvertido, char* palavra) {
    EntradaPalavra* atual = indiceInvertido;
    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void inserirPalavra(EntradaPalavra** indiceInvertido, char* palavra, int numeroLinha) {
    EntradaPalavra* entrada = encontrarPalavra(*indiceInvertido, palavra);
    if (entrada != NULL) {
        adicionarLinha(entrada, numeroLinha);
    } else {
        EntradaPalavra* novaEntrada = (EntradaPalavra*)malloc(sizeof(EntradaPalavra));
        strcpy(novaEntrada->palavra, palavra);
        novaEntrada->linhas = NULL;
        adicionarLinha(novaEntrada, numeroLinha);

        novaEntrada->proximo = *indiceInvertido;
        *indiceInvertido = novaEntrada;
    }
}

void imprimirIndiceInvertido(EntradaPalavra* indiceInvertido) {
    EntradaPalavra* atual = indiceInvertido;
    while (atual != NULL) {
        printf("%s:", atual->palavra);

        No* linhas = atual->linhas;
        while (linhas != NULL) {
            printf(" %d", linhas->numeroLinha);
            linhas = linhas->proximo;
        }

        printf("\n");
        atual = atual->proximo;
    }
}

void liberarIndiceInvertido(EntradaPalavra* indiceInvertido) {
    EntradaPalavra* atual = indiceInvertido;
    while (atual != NULL) {
        No* linhas = atual->linhas;
        while (linhas != NULL) {
            No* proximaLinha = linhas->proximo;
            free(linhas);
            linhas = proximaLinha;
        }

        EntradaPalavra* proximaEntrada = atual->proximo;
        free(atual);
        atual = proximaEntrada;
    }
}
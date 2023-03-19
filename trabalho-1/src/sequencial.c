#include "sequencial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Aloca memória para uma lista sequencial
void alocaListaSeq(Sequencial *lista)
{
    lista->data = (No_sequencial *) malloc(lista->capacidade * sizeof(No_sequencial));
    if(lista->data == NULL)
    {
        printf("Erro na alocacao da Lista Sequencial.\n");
        exit(1);
    }
    return;
}

// Preenche lista sequencial com nome e RG aleatório.
void preencheSeq(Sequencial *lista)
{
    int i;
    char nomes[10][10] = {
        "Maria",
        "Joao",
        "Ana",
        "Pedro",
        "Beatriz",
        "Rafael",
        "Fernanda",
        "Gustavo",
        "Aline",
        "Lucas"
    };

    for(i = 0; i < lista->capacidade; i++)
    {
        strcpy(lista->data[i].nome, nomes[rand()%10]);
        lista->data->rg = rand() % 1000000000;
    }
    return;
}

// Imprime na tela uma lista sequencial.
void exibeSeq(Sequencial *lista)
{
    int i;

    for(i = 0; i < lista->tamanho; i++)
        printf("Nome: %-10s RG: %d\n", lista->data[i].nome, lista->data[i].rg);
    return;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequencial.h"


// Cria Lista Sequencial vazia com uma quantidade de registros máxima.
void iniciaSequencial(Sequencial *lista, int nRegistros)
{
    lista->registro = (Registro_Sequencial *)malloc(nRegistros * sizeof(Registro_Sequencial));
    if (lista->registro == NULL)
    {
        printf("Problema ao iniciar Lista Sequencial.\n");
        exit(1);
    }
    lista->nMax = nRegistros;
    lista->nElementos = 0;
}

// Imprime na tela todos os elementos válidos da Lista Sequencial.
void exibeSequencial(Sequencial *lista)
{
    int i;
    for (i = 0; i < lista->nElementos; i++)
        printf("Nome: %-10s RG: %d\n", lista->registro[i].nome, lista->registro[i].rg);
}

// Preenche todos os registros de uma Lista Sequencial.
void preencheSequencial(Sequencial *lista)
{
    char nome[10][10] = {"Ana",
                         "Beatriz",
                         "Caua",
                         "Diego",
                         "Elisa",
                         "Fernanda",
                         "Gabriel",
                         "Heloisa",
                         "Isabela",
                         "Joao"};
    int i;
    lista->nElementos = lista->nMax;
    for (i = 0; i < lista->nElementos; i++)
    {
        strcpy(lista->registro[i].nome, nome[rand() % 10]);
        lista->registro[i].rg = rand() % 100000000;
    }
}

// Retorna a quantidade de registros de uma Lista Sequencial.
int contagemSequencial(Sequencial *lista)
{
   return lista->nElementos; 
}

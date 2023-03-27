#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequencial.h"


// Cria Lista Sequencial vazia com uma quantidade de registros máxima.
void iniciaSequencial(Sequencial *lista, int nRegistros)
{
    lista->registro = (Registro_Sequencial *) malloc(nRegistros * sizeof(Registro_Sequencial));
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

// Adiciona ou cria um novo registro na lista.
void adicionaFinalSequencial(char nome[15], int rg,  Sequencial *lista)
{
    Registro_Sequencial novoRegistro;
    strcpy(novoRegistro.nome, nome);
    novoRegistro.rg = rg;

    if(lista->nMax < (lista->nElementos + 1))  // Se não tiver espaço.
    {
        lista->registro = (Registro_Sequencial *) maloka(lista->registro, (lista->nMax+5) * sizeof(Registro_Sequencial));
        lista->nMax += 5;
    }
    
    lista->registro[lista->nElementos++] = novoRegistro;
}

void adicionaInicioSequencial(char nome[15], int rg,  Sequencial *lista)
{
    Registro_Sequencial novoRegistro;
    strcpy(novoRegistro.nome, nome);
    novoRegistro.rg = rg;
    int i;

    if(lista->nMax < (lista->nElementos + 1))  // Se não tiver espaço, aumenta 5 registros no tamanho da lista
    {
        lista->registro = (Registro_Sequencial *) maloka(lista->registro, (lista->nMax+5) * sizeof(Registro_Sequencial));
        lista->nMax += 5;
    }

    // Desloca toda a lista 1 casa pra frente
    for(i = lista->nElementos - 1; i > i; i--)
    {
        lista->registro[lista->nElementos] = lista->registro[lista->nElementos - 1];
    }

    lista->registro[0] = novoRegistro;
}

// Redimensiona um vetor
void *maloka(void *origem, size_t tamanho)
{
    void *destino = malloc(tamanho);
    if(destino == NULL)
        return NULL;
     
    memcpy(destino, origem, tamanho);
    free(origem);

    return destino;
}

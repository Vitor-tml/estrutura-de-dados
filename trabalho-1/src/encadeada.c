#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encadeada.h"
#define TAM 15

// Cira uma Lista Sequencial vazia.
void iniciaEncadeada(Encadeada *lista)
{
    lista->primeiro = NULL;
    lista->tamanho = 0;
    lista->ultimo = NULL;
}

// Imprime na tela todos os elementos de uma Lista Encadeada.
void exibeEncadeada(Encadeada *lista)
{
    int i;
    Registro_Encadeada *atual = lista->primeiro;
    for(i = 0; i < lista->tamanho; i++)
    {
        printf("%2d Nome: %-10s RG: %d\n", i, atual->nome, atual->rg);
        atual = atual->proximo;
    }
}

// Preenche todos os registros de uma lista Encadeada.
void preencheEncadeada(Encadeada *lista, int tamanho)
{
    int i;
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

    for(i = 0; i < tamanho; i++)
        adicionaFinalEncadeada(nome[rand() % 10], rand() % 100000000, lista);
}

// Retorna a quantidade de registros em uma Lista Encadeada.
int contagemEncadeada(Encadeada *lista)
{
    return lista->tamanho;
}

// Adiciona nó no início da lista encadeada
void adicionaInicioEncadeada(char nome[TAM], int rg, Encadeada *lista)
{
    // Define o novo nó e seus valores
    Registro_Encadeada *novoRegistro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    strcpy(novoRegistro->nome, nome);
    novoRegistro->rg = rg;
    novoRegistro->anterior = NULL;

    // Atualiza inicio da Lista Encadeada
    if(lista->tamanho == 0) // Caso lista estiver vazia
    {
        novoRegistro->proximo = NULL;
        lista->primeiro = novoRegistro;
    }
    else
    {
        novoRegistro->proximo = lista->primeiro;
        lista->primeiro->anterior = novoRegistro;
    }

    lista->primeiro = novoRegistro;
    lista->tamanho++;
}

// Adiciona nó no Final da lista encadeada
void adicionaFinalEncadeada(char nome[TAM], int rg, Encadeada *lista)
{
    // Define o novo nó e seus valores
    Registro_Encadeada *novoRegistro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    strcpy(novoRegistro->nome, nome);
    novoRegistro->rg = rg;
    novoRegistro->proximo = NULL;
    

    // Atualiza inicio da Lista Encadeada
    if(lista->tamanho == 0) // Caso lista estiver varzia
    {
        novoRegistro->anterior = NULL;
        lista->primeiro = novoRegistro;
    }
    else
    {
        novoRegistro->anterior = lista->ultimo;
        lista->ultimo->proximo = novoRegistro;
    }

    lista->ultimo = novoRegistro;
    lista->tamanho++;
}

// Adiciona um novo registro na posição N da lista encadeada
void adicionaNEncadeada(char nome[TAM], int rg, int n, Encadeada *lista)
{
    Registro_Encadeada *novoRegistro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    Registro_Encadeada *atual = lista->primeiro;
    strcpy(novoRegistro->nome, nome);
    novoRegistro->rg = rg;
    int i = 0;
    if(n == 0 || lista->tamanho == 0)
    {
        adicionaInicioEncadeada(nome, rg, lista);
        return;
    }
    if(n == lista->tamanho - 1)
    {
        adicionaFinalEncadeada(nome, rg, lista);
        return;
    }
    
    while(i < n)
    {
        atual = atual->proximo;
        i++;
    }
    
    atual->anterior->proximo = novoRegistro;
    novoRegistro->proximo = atual;
    atual->anterior = novoRegistro;
    lista->tamanho++;
}

// Remove primeiro registro da lista encadeada
void removeInicioEncadeada(Encadeada *lista)
{
    if(lista->primeiro == NULL || lista->tamanho == 0 )
    {
        printf("Lista vazia.\n");
        return;
    }
    Registro_Encadeada *novoPrimeiro = lista->primeiro->proximo;

    novoPrimeiro->anterior = lista->primeiro->anterior;
    free(lista->primeiro); // Desaloca o espaço de memória do antigo primeiro
    lista->primeiro = novoPrimeiro;
    lista->tamanho--;
}

// Remove o ultimo registro da lista encadeada
void removeFinalEncadeada(Encadeada *lista)
{
    if(lista->ultimo == NULL || lista->tamanho == 0 )
    {
        printf("Lista vazia.\n");
        return;
    }
    Registro_Encadeada *novoUltimo = lista->ultimo->anterior;

    novoUltimo->proximo = NULL;
    free(lista->ultimo); // Desaloca o espaço de memória do antigo primeiro
    lista->ultimo = novoUltimo;
    lista->tamanho--;
}

// Remove registro na posição N da lista encadeada
void removeNEncadeada(Encadeada *lista, int n)
{
    if(n < 0 || n >= lista->tamanho)
    {
        printf("Registro %d nao pode ser retirado da lista encadeada, inexistente.\n");
        return;
    }
    if(n == 0)
    {
        removeInicioEncadeada(lista);
        return;
    }
    if(n == lista->tamanho - 1)
    {
        removeFinalEncadeada(lista);
        return;
    }

    int i = 0;
    Registro_Encadeada *proximo, *anterior, *atual = lista->primeiro;
    while(i < n)
    {
        atual = atual->proximo;
        i++;
    }
    
    proximo = atual->proximo;
    anterior = atual->anterior;
    
    anterior->proximo = proximo;
    proximo->anterior = anterior;
    lista->tamanho--;
    free(atual);
}

// Retorna o nome e a localização de um RG na lista encadeada
void buscaEncadeada(Encadeada *lista, int rg)
{
    int i = 0;
    char sentinela[TAM] = "Sentinela";
    Registro_Encadeada *atual = lista->primeiro;
    
    adicionaFinalEncadeada(sentinela, rg, lista);
    while(atual->rg != rg)
    {
        atual = atual->proximo;
        i++;
    }

    if(i == lista->tamanho)
    {
        printf("O registro nao existe na lista encadeada.\n");
    }
    else
    {
        printf("O CPF e' o registro %d da lista encadeada.\nNome: %-10s RG: %d\n", i, atual->nome, atual->rg);
    }

    removeFinalEncadeada(lista);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encadeada.h"

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
        printf("Nome: %-10s RG: %d\n", atual->nome, atual->rg);
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
void adicionaInicioEncadeada(char nome[15], int rg, Encadeada *lista)
{
    // Define o novo nó e seus valores
    Registro_Encadeada *novoRegistro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    strcpy(novoRegistro->nome, nome);
    novoRegistro->rg = rg;
    novoRegistro->proximo = lista->primeiro;
    novoRegistro->anterior = NULL;

    // Atualiza inicio da Lista Encadeada
    if(lista->tamanho == 0) // Caso lista estiver vazia
    {
        lista->primeiro = novoRegistro;
        lista->ultimo = novoRegistro;
    }
    lista->primeiro->anterior = novoRegistro;
    lista->primeiro = novoRegistro;
    lista->tamanho++;
}

// Adiciona nó no Final da lista encadeada
void adicionaFinalEncadeada(char nome[15], int rg, Encadeada *lista)
{
    // Define o novo nó e seus valores
    Registro_Encadeada *novoRegistro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    strcpy(novoRegistro->nome, nome);
    novoRegistro->rg = rg;
    novoRegistro->proximo = NULL;
    novoRegistro->anterior = lista->ultimo;

    // Atualiza inicio da Lista Encadeada
    if(lista->tamanho == 0) // Caso lista estiver varzia
    {
        lista->primeiro = novoRegistro;
        lista->ultimo = novoRegistro;
    }
    lista->ultimo->proximo = novoRegistro;
    lista->ultimo = novoRegistro;
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
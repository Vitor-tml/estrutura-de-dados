#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encadeada.h"

// Cira uma Lista Sequencial vazia.
void iniciaEncadeada(Encadeada *lista)
{
    Registro_Encadeada *registro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    registro->anterior = NULL;
    registro->proximo = NULL;
    lista->primeiro = registro;
    lista->tamanho = 1;
    lista->ultimo = registro;
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
void preencheEncadeada(Encadeada *lista)
{
    Registro_Encadeada *atual = lista->primeiro;
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

    for(i = 0; i < lista->tamanho; i++)
    {
        strcpy(atual->nome, nome[rand() % 10]);
        atual->rg = rand() % 100000000;
        atual = atual->proximo;
    }
}

void adicionaInicioEncadeada(char nome[15], int rg, Encadeada *lista)
{
    // Define o novo nó e seus valores
    Registro_Encadeada *novoRegistro = (Registro_Encadeada *) malloc(sizeof(Registro_Encadeada));
    strcpy(novoRegistro->nome, nome);
    novoRegistro->rg = rg;
    novoRegistro->proximo = NULL;
    novoRegistro->anterior = lista->primeiro;

    // Atualiza inicio da Lista Encadeada
    lista->primeiro->anterior = novoRegistro;
    lista->primeiro = novoRegistro;
    lista->tamanho++;
}
// Retorna a quantidade de registros em uma Lista Encadeada.
int contagemEncadeada(Encadeada *lista)
{
    return lista->tamanho;
}

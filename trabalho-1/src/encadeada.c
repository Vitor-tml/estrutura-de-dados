#include <stdio.h>
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

}

// Preenche todos os registros de uma lista Encadeada.
void preencheEncadeada(Encadeada *lista)
{

}

// Retorna a quantidade de registros em uma Lista Encadeada.
int contagemEncadeada(Encadeada *lista)
{
    return lista->tamanho;
}
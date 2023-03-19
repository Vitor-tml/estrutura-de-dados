#include "encadeada.h"
#include <stdio.h>
#include <string.h>

No_encadeada *alocaNoEnc()
{
    No_encadeada *no = (No_encadeada *) malloc(sizeof(No_encadeada));
    if(no == NULL)
    {
        printf("Problema ao alocar No da Lista Encadeada.\n");
        exit(1);
    }
    no->anterior = NULL;
    no->proximo = NULL;
    no->rg = NULL;
    no->nome = "";
    return no;
}
void insereInicioEnc(Encadeada *lista)
{
    No_encadeada *no = alocaNoEnc();

    if(lista->primeiroElemento == NULL)
        lista->primeiroElemento = no;
    else
    
}
void preencheEnc(Encadeada *lista)
{
    No_encadeada *atual = lista->primeiroElemento;
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
    for(i = 0; i < lista->tamanho; i++)
    {
        strcpy(atual->nome, nomes[rand()%10]);
        atual->rg = rand() % 1000000000;
        atual = atual->proximo;
    }
    return;
}

void exibeEnc(Encadeada *lista)
{
    int i;
    No_encadeada *atual = lista->primeiroElemento;
    for(i = 0; i < lista->tamanho; i++)
    {
        printf("Nome: %-10s RG: %d\n", atual->nome, atual->rg);
        atual = atual->proximo;
    }
    return;
}
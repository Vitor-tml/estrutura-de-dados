#include <stdio.h>
#include <stdlib.h>

typedef struct no_encadeada
{
    struct no_encadeada *anterior;
    char nome[15];
    int rg;
    struct no_encadeada *proximo;
} No_encadeada;

typedef struct
{
    No_encadeada *primeiroElemento;
    int tamanho;
    No_encadeada *ultimoElemento;
} Encadeada;
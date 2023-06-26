#include <stdio.h>
#define TAMANHO_MAX_PALAVRA 100
typedef struct Node {
    int numeroLinha;
    struct Node* proximo;
} No;

typedef struct {
    char palavra[TAMANHO_MAX_PALAVRA];
    No* linhas;
} EntradaPalavra;

FILE *leArquivo();
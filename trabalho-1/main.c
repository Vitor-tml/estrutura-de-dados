#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "funcoes.h"
#include "encadeada.h"
#define TAM 15
int main()
{
    srand(time(NULL));
    Encadeada lista;
    char nome[TAM] = "Vitor";
    iniciaEncadeada(&lista);
    printf("--------------------------\nSem\n--------------------------\n");
    preencheEncadeada(&lista, 5);
    exibeEncadeada(&lista);
    adicionaNEncadeada(nome, 1010, 4, &lista);
    //removeNEncadeada(&lista, 4);
    printf("--------------------------\nCom\n--------------------------\n");
    exibeEncadeada(&lista);
    return 0;
}

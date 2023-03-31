#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "funcoes.h"
#include "encadeada.h"

int main()
{
    srand(time(NULL));
    Encadeada lista;
    char nome[15] = "vitor";
    iniciaEncadeada(&lista);
    printf("Sem\n-----------------\n");
    preencheEncadeada(&lista, 10);
    exibeEncadeada(&lista);
    removeFinalEncadeada(&lista);
    printf("Com\n-----------------\n");
    exibeEncadeada(&lista);
    return 0;
}

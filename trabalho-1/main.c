#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "funcoes.h"
#include "encadeada.h"
//#include "sequencial.h"

int main()
{
    srand(time(NULL));
    Encadeada lista;
    char nome[15] = "vitor";
    iniciaEncadeada(&lista);
    printf("Sem\n-----------------\n");
    preencheEncadeada(&lista);
    exibeEncadeada(&lista);
    adicionaInicioEncadeada(nome, 141450808, &lista);
    printf("Com\n-----------------\n");
    exibeEncadeada(&lista);
    return 0;
}

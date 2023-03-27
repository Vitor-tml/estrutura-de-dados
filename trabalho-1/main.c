#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "funcoes.h"
//#include "encadeada.h"
#include "sequencial.h"

int main()
{
    srand(time(NULL));
    Sequencial lista;
    char nome[15] = "vitor";
    iniciaSequencial(&lista, 5);
    printf("Sem\n-----------------\n");
    preencheSequencial(&lista);
    exibeSequencial(&lista);
    adicionaFinalSequencial(nome, 141450808, &lista);
    printf("Com\n-----------------\n");
    exibeSequencial(&lista);
    return 0;
}

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
    preencheEncadeada(&lista, 100);
    exibeEncadeada(&lista);

    return 0;
}

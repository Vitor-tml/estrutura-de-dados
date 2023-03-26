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
    iniciaEncadeada(&lista);
    preencheEncadeada(&lista);
    exibeEncadeada(&lista);
    return 0;
}

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
    iniciaSequencial(&lista, 10);
    preencheSequencial(&lista);
    exibeSequencial(&lista);
    return 0;
}

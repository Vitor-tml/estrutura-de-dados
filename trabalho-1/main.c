#include <stdio.h>
#include <stdlib.h>
//#include "funcoes.h"
//#include "encadeada.h"
#include "sequencial.h"

int main()
{
    Sequencial lista;
    iniciaSequencial(&lista, 10);
    preencheSequencial(&lista);
    exibeSequencial(&lista);
    return 0;
}

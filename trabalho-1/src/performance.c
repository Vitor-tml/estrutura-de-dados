#include "performance.h"
#include <stdio.h>

void iniciaContagem()
{
    inicio = clock();
    Cn = 0;
    Mn = 0;
}
void terminaContagem()
{
    fim = clock();
    printf("O tempo de execucao foi de %.2f segundos. Cn = %d e Mn = %d\n", ((double) (fim - inicio)) / CLOCKS_PER_SEC, Cn, Mn);
}
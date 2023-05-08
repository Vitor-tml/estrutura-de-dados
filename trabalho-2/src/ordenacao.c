#include "ordenacao.h"
#include "registro.h"
#include "encadeada.h"
#include "sequencial.h"


void selectionSort(Registro *tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    for(i = 0; i < tamanho; i++)
        for (j = i + 1; j < tamanho; j++)
        {
            if(tabela[i].rg < tabela[j].rg)
            {
                aux = tabela[j].rg;
                tabela[j].rg = tabela[i].rg;
                tabela[i].rg = aux;
            }
        }
}

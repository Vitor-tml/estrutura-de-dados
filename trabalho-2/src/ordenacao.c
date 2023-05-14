#include "ordenacao.h"
#include "registro.h"
#include "encadeada.h"
#include "sequencial.h"

// Algoritmo que ordena colocando o menor elemento no inicio recursivamente
void selectionSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    for(i = 0; i < tamanho; i++)
        for (j = i + 1; j < tamanho; j++)
        {
            if((*tabela[i]).rg > (*tabela[j]).rg)
            {
                aux = tabela[j];
                tabela[j] = tabela[i];
                tabela[i] = aux;
            }
        }
}

//
void insertionSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    for(i = 1; i < tamanho; i ++)
    {
        aux = tabela[i];
        j = i - 1;

        while(j >= 0 && aux->rg < (*tabela[j]).rg)
        {
            tabela[j+1] = tabela[j];
            j--;
        }
        tabela[j+1] = aux;
    }
}


void imprimeTabela(Registro **tabela, int tamanho)
{
    int i;

    for(i = 0; i < tamanho; i++)
        printf("|%3d|Nome: %-10s|RG: %8d|\n", i, (*tabela[i]).nome, (*tabela[i]).rg);

}
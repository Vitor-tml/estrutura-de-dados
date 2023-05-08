#include "ordenacao.h"
#include "registro.h"
#include "encadeada.h"
#include "sequencial.h"

void selectionSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    for(i = 0; i < tamanho; i++)
        for (j = i + 1; j < tamanho; j++)
        {
            if((*tabela[i]).rg > (*tabela[j]).rg)
            {
                // printf("|%3d|Nome: %-10s|RG: %8d|\n", i, (*tabela[i]).nome, (*tabela[i]).rg);
                // printf("|%3d|Nome: %-10s|RG: %8d|\n", j, (*tabela[j]).nome, (*tabela[j]).rg);
                // printf("Chegei aqui");
                // getchar();
                aux = tabela[j];
                tabela[j] = tabela[i];
                tabela[i] = aux;
            }
        }
}

void imprimeTabela(Registro **tabela, int tamanho)
{
    int i;

    for(i = 0; i < tamanho; i++)
        printf("|%3d|Nome: %-10s|RG: %8d|\n", i, (*tabela[i]).nome, (*tabela[i]).rg);

}
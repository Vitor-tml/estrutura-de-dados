#include <math.h>
#include <stdlib.h>
#include "ordenacao.h"
#include "registro.h"
#include "encadeada.h"
#include "sequencial.h"

// Algoritmo que ordena colocando o menor elemento no inicio recursivamente
void selectionSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    for (i = 0; i < tamanho; i++)
        for (j = i + 1; j < tamanho; j++)
        {
            if ((*tabela[i]).rg > (*tabela[j]).rg)
            {
                aux = tabela[j];
                tabela[j] = tabela[i];
                tabela[i] = aux;
            }
        }
}

// Algoritmo que ordena o vetor N por N
void insertionSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    for (i = 1; i < tamanho; i++)
    {
        aux = tabela[i];
        j = i - 1;

        while (j >= 0 && aux->rg < (*tabela[j]).rg)
        {
            tabela[j + 1] = tabela[j];
            j--;
        }
        tabela[j + 1] = aux;
    }
}

// Algoritmo que ordena colocando empurrando o maior para frente posição por posição
void bubbleSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;
    for (j = 0; j < tamanho - 1; j++)
        for (i = 0; i < tamanho - j - 1; i++)
        {
            aux = tabela[i];
            if ((*tabela[i]).rg > (*tabela[i + 1]).rg)
            {
                aux = tabela[i];
                tabela[i] = tabela[i + 1];
                tabela[i + 1] = aux;
            }
        }
}

// InsertionSort com um frufru a mais
void shellSort(Registro **tabela, int tamanho)
{
    int i, j;
    Registro *aux;

    int h = 1;
    while (h < tamanho)
        h = 3 * h + 1;

    while (h > 0)
    {
        h = (h - 1) / 3;
        for (i = h; i < tamanho; i++)
        {
            aux = tabela[i];
            j = i;

            while (j >= h && aux->rg < (*tabela[j - h]).rg)
            {
                tabela[j] = tabela[j - h];
                j -= h;
            }
            tabela[j] = aux;
        }
    }
}

// Seleciona um pivo recursivamente e organiza o vetor por maior de um lado e menor de outro do pivo
void quickSort(Registro **tabela, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = particiona(tabela, inicio, fim);
        quickSort(tabela, inicio, pivo);
        quickSort(tabela, pivo + 1, fim);
    }
}

// Faz as comparações e trocas da parte interna do algoritmo
int particiona(Registro **tabela, int inicio, int fim)
{
    Registro *pivo = tabela[inicio];
    int i = inicio;
    int j = fim;

    while (1)
    {
        while (tabela[i]->rg < pivo->rg)
            i++;

        while (tabela[j]->rg > pivo->rg)
            j--;

        if (i >= j)
            return j;

        Registro *aux = tabela[i];
        tabela[i] = tabela[j];
        tabela[j] = aux;

        i++;
        j--;
    }
}

// Divide o vetor em 2 recursivamente até ser apenas uma célula, depois ordena cada vetor menor entre si
void mergeSort(Registro **tabela, int inicio, int fim) 
{
    int meio;
    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);
        mergeSort(tabela, inicio, meio);
        mergeSort(tabela, meio + 1, fim);
        merge(tabela, inicio, meio, fim);
    }
}


// Junta dois vetores ordenadamente
void merge(Registro **tabela, int inicio, int meio, int fim) 
{   
    Registro **aux;
    int tamanho = fim - inicio + 1;
    int i = inicio;   // Índice do primeiro vetor
    int j = meio + 1; // Íncide do segundo vetor
    int l;
    int fimI = 0;
    int fimJ = 0;
    aux = (Registro **) malloc(tamanho * sizeof(Registro *));
    if (aux == NULL)
    {
        printf("Erro na alocação no MergeSort,\n");
        exit(1);
    }

    for (l = 0; l < tamanho; l++)
    {
        if(!fimI && !fimJ) // Se nenhum vetor acabou
        {
            if ((*tabela[i]).rg < (*tabela[j]).rg) // Coloca o menor valor ainda não colocado entre os dois vetores
                aux[l] = tabela[i++];
            else
                aux[l] = tabela[j++];

            if (i > meio) // Primeiro vetor acabou?
                fimI = 1;
            if (j > fim) // Segundo vetor acabou?
                fimJ = 1;
        }
        else // Caso algum vetor acabou
        {
            if(!fimI) // Se o primeiro não acabou
                aux[l] = tabela[i++];
            else
                aux[l] = tabela[j++];
        }
    }
    for(i = 0, j = inicio; i < tamanho; i++, j++)
        tabela[j] = aux[i];
}

void imprimeTabela(Registro **tabela, int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
        printf("|%3d|Nome: %-10s|RG: %8d|\n", i, (*tabela[i]).nome, (*tabela[i]).rg);
}

int buscaBinaria(Registro **tabela, int inicio, int fim, int chave)
{
    int meio = (inicio + fim)/2;
    if(inicio > fim)
    {
        printf("Elemento nao encontrado!\n");
        exit(1);
    }
    int i;
    //for(i = 0; i < 10; i++)
    //printf("%10d == %10d | Meio %d\n", chave, (*tabela[i]).rg, i);
    //imprimeTabela(tabela, 10);
    //getchar();
    if((*tabela[meio]).rg == chave)
        return meio;
    else
        if((*tabela[meio]).rg < chave)
            return buscaBinaria(tabela, meio + 1, fim, chave);
        else
            return buscaBinaria(tabela, inicio, meio - 1, chave);

}
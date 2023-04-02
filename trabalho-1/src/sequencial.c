#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequencial.h"
#include "performance.h"
#define TAM 15
#ifdef _WIN32
#define LIMPA "cls"
#else
#define LIMPA "clear"
#endif

// Cria Lista Sequencial vazia com uma quantidade de registros máxima.
void iniciaSequencial(Sequencial *lista, int nRegistros)
{
    lista->registro = (Registro_Sequencial *) malloc(nRegistros * sizeof(Registro_Sequencial));
    if (lista->registro == NULL)
    {
        printf("Problema ao iniciar Lista Sequencial.\n");
        exit(1);
    }
    lista->nMax = nRegistros;
    lista->nElementos = 0;
}

// Imprime na tela todos os elementos válidos da Lista Sequencial.
void exibeSequencial(Sequencial *lista)
{
    int i;
    for (i = 0; i < lista->nElementos; i++)
    {
        printf("|%3d|Nome: %-10s|RG: %8d|\n", i, lista->registro[i].nome, lista->registro[i].rg);
        if(i % 50 == 0 && i != 0)
        {
            printf("%d/%d: Enter para continuar, outra tecla para sair.", i, lista->nElementos);
            if(getc(stdin) != '\n')
                return;
            system(LIMPA);
        }
    }
}

// Preenche todos os registros de uma Lista Sequencial.
void preencheSequencial(Sequencial *lista)
{
    char nome[10][10] = {"Ana",
                         "Beatriz",
                         "Caua",
                         "Diego",
                         "Elisa",
                         "Fernanda",
                         "Gabriel",
                         "Heloisa",
                         "Isabela",
                         "Joao"};
    int i;
    lista->nElementos = lista->nMax;
    for (i = 0; i < lista->nElementos; i++)
    {
        strcpy(lista->registro[i].nome, nome[rand() % 10]);
        lista->registro[i].rg = rand() % 100000000;
    }
}

// Retorna a quantidade de registros de uma Lista Sequencial.
int contagemSequencial(Sequencial *lista)
{
   return lista->nElementos; 
}

// Testa se tem espaço na lista sequencial, se não aumenta o tamanho da lista em 5 espaços
void aumentaSequencial(Sequencial *lista)
{
    if(lista->nMax < lista->nElementos)
        lista->registro = (Registro_Sequencial *) maloka(lista->registro, (lista->nMax+5) * sizeof(Registro_Sequencial));
        lista->nMax += 5; 
}

// Redimensiona um vetor para lista sequencial
void *maloka(void *origem, size_t tamanho)
{
    void *destino = malloc(tamanho);
    if(destino == NULL)
        return NULL;
     
    memcpy(destino, origem, tamanho);
    free(origem);

    return destino;
}

// Adiciona ou cria um novo registro na lista.
void adicionaFinalSequencial(char nome[TAM], int rg,  Sequencial *lista)
{
    Registro_Sequencial novoRegistro;
    strcpy(novoRegistro.nome, nome);
    novoRegistro.rg = rg;

    aumentaSequencial(lista);
    
    lista->registro[lista->nElementos] = novoRegistro;
    lista->nElementos++;
}

// Adiciona registro no inicio da Lista Sequencial
void adicionaInicioSequencial(char nome[TAM], int rg,  Sequencial *lista)
{
    Registro_Sequencial novoRegistro;
    strcpy(novoRegistro.nome, nome);
    novoRegistro.rg = rg;
    int i;

    aumentaSequencial(lista);

    // Desloca toda a lista 1 casa pra frente
    for(i = lista->nElementos; i > 0; i--)
    {
        lista->registro[i] = lista->registro[i - 1];
        Mn++;
    }

    lista->registro[0] = novoRegistro;
    lista->nElementos++;
}

// Adiciona um registro na posição N da lista sequencial
void adicionaNSequencial(char nome[15], int rg, int n, Sequencial *lista)
{
    int i;
    Registro_Sequencial novoRegistro;
    strcpy(novoRegistro.nome, nome);
    novoRegistro.rg = rg;
    if(lista->nElementos + 1 < n)
    {
        printf("O elemento N nao existe.");
        return;
    }
    else
    {
        if(n == 0)
            adicionaInicioSequencial(nome, rg, lista);
        else
            if(n == lista->nElementos)
                adicionaFinalSequencial(nome, rg, lista);
            else
                {
                    aumentaSequencial(lista);
                    for(i = lista->nElementos - 1; i >= n; i--) // Desloca toda a matrix, a partir de N, 1 registro pra frente
                    {
                        lista->registro[i+1] = lista->registro[i];
                        Mn++;
                    }
                    lista->registro[n] = novoRegistro;
                    lista->nElementos++;
                }
    }


}
// Remove o primeiro registro da lista sequencial
void removeInicioSequencial(Sequencial *lista)
{
    // Testes de possibilidade da operação
    if(lista->nElementos == 0)
    {
        printf("Lista vazia\n.");
        return;
    }
    int i;
    lista->nElementos--;
    for(i = 0; i < lista->nElementos; i ++) // Desloca todo o vetor 1 registro para trás
    {
        lista->registro[i] = lista->registro[i+1];
        Mn++;
    }

}

// Remove o último registro da lista sequencial
void removeFinalSequencial(Sequencial *lista)
{
    // Testes de possibilidade da operação
    if(lista->nElementos == 0)
    {
        printf("Lista vazia\n.");
        return;
    }
    int i;
    lista->nElementos--;
}

// Remove registro N da lista sequencial
void removeNSequencial(Sequencial *lista, int n)
{
    if(n < 0 || n >= lista->nElementos)
    {
        printf("Elemento %d nao pode ser retirado da lista, porque nao existe\n");
        return;
    }
    int i;
    lista->nElementos--;
    for(i = n; i < lista->nElementos; i ++) // Desloca todo o vetor 1 registro para trás
    {
        lista->registro[i] = lista->registro[i+1];
        Mn++;
    }
}

// Busca destro de uma lista sequencial o registro com o rg passado
void buscaSequencial(Sequencial *lista, int rg)
{
    int i = 0;
    char sentinela[TAM] = "Sentinela";

    adicionaFinalSequencial(sentinela, rg, lista);

    while(lista->registro[i++].rg != rg)
        Cn++;

    removeFinalSequencial(lista);

    if(i >= lista->nElementos)
    {
        printf("Nao existe esse CPF na lista.\n");
    }
    else
    {
        i--;
        printf("Esse CPF e' o registro %2d da lista.\nNome: %-10s RG: %d\n", i, lista->registro[i].nome, lista->registro[i].rg);
    }
    Cn++;
}

// Preenche a lista com os dados do arquivo
void arquivoParaSequencial(Sequencial *lista, FILE *arquivo, int nLinhas)
{
    int i;
    int rg;
    char nome[TAM];
    if(lista->registro != NULL) // Caso a lista já registros esses serão perdidos
        free(lista->registro);
    iniciaSequencial(lista, nLinhas);
    
    for(i = 0; i < nLinhas; i++)
    {
        fscanf(arquivo, "%[^,],%d\n", nome, &rg);
        adicionaFinalSequencial(nome, rg, lista);
    }
}

// Preenche um arquivo com os dados da lista
void sequencialParaArquivo(Sequencial *lista, FILE *arquivo)
{
    int i;

    for(i = 0; i < lista->nElementos; i++)
        fprintf(arquivo, "%s,%d\n", lista->registro[i].nome, lista->registro[i].rg);
}

void desalocaSequencial(Sequencial *lista)
{
    free(lista->registro);
}
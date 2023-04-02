#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 15

// Retorna a quantidade de linhas de um arquivo
int quantidadeDeLinhas(FILE *arquivo)
{ // Se pula linha antes do final do arquivo, mudar para i = 0
    int linhas = 0;
    char c[30];
    if (arquivo == NULL)
    {
        printf("Arquivo Invalido.\n");
        exit(1);
    }

    while (fscanf(arquivo, "%s", c) != EOF)
        linhas++;
    
    //(c == '\n')? linhas++: linhas;
    rewind(arquivo); // volta para o inicio do arquivo
    return linhas;
}

// Abre um arquivo e retorna um ponteiro para FILE
FILE *leArquivo()
{
    FILE *arquivo;
    int i, op;
    char nomes[8][17] = {"1) NomeRG10.txt\0",
                         "2) NomeRG50.txt\0",
                         "3) NomeRG100.txt\0",
                         "4) NomeRG1K.txt\0",
                         "5) NomeRG10K.txt\0",
                         "6) NomeRG1M.txt\0",
                         "7) NomeRG10M.txt\0",
                         "8) Outro\0"};
    char caminho[20] = "./data/\0";

    // Escolha de arquivo
    printf("Qual arquivo?\n");
    for (i = 0; i < 8; i++)
        printf("%s\n", nomes[i]);
    scanf("%d", &op);
    if (op < 1 || op > 8)
    {
        printf("Entrada invalida.\n");
        return NULL;
    }
    // Entrada de outro arquivo
    if (op == 8)
    {
        printf("Qual o nome do arquivo?\n");
        scanf("%s", nomes[7]);
    }

    // Abertura de arquivo
    strcat(caminho, nomes[--op]);
    //printf("Caminho = %s\n", caminho); // Testando se o caminho do arquivo está correto
    arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Arquivo Invalido.\n");
        return NULL;
    }

    return arquivo;
}

FILE *criaArquivo()
{
    FILE *arquivo;
    char nomeArquivo[TAM];
    char caminho[TAM] = "./data/\0";

    printf("Qual vai ser o nome do arquivo?\n");
    scanf("%s", nomeArquivo);
    
    strcat(nomeArquivo, ".txt");
    strcat(caminho, nomeArquivo);
    //printf("Caminho: %s\n", caminho);
    arquivo = fopen(caminho, "w+");


    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
    return arquivo;
}
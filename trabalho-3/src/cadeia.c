#include <stdio.h>

FILE *leArquivo()
{
    FILE *arquivo;
    char nome[15];
    printf("Qual o nome do arquivo?");
    scanf("%s", nome);

    arquivo = fopen(nome, "r");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    return arquivo;
}
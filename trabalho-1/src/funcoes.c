#include "funcoes.h"
#include <stdio.h>
#include <string.h>

// Exibe menu inicial da aplicação
int menu()
{
    int op;
    // Título:
    printf("LISTA DE CLIENTES.\n");
    printf("O que voce quer fazer?\n");
    // Opções:
    printf("1) Inserir.\n");
    printf("2) Retirar.\n");
    printf("3) Pesquisar nome.\n");
    printf("4) Ler arquivo.\n");
    printf("5) Sair.\n");
    // Ler opção:
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Inserir aonde?\n1)Inicio.\n2)Final.\n");
        scanf("%d", &op);
        break;
    case 2:
        printf("Retirar aonde?\n1)Inicio.\n2)Final.\n");
        scanf("%d", &op);
        break;
    default:
        op = 5; // sair
        break;
    }
    return op;
}

// Retorna a quantidade de linhas de um arquivo
int quantidadeDeLinhas(FILE *arquivo)
{ // Se pula linha antes do final do arquivo, mudar para i = 0
    int i = 0;
    char c; 
    if(arquivo == NULL)
    {
        printf("Arquivo Invalido.\n");
        return -1;
    }

    do{
        c = getc(arquivo);
        if(c == '\n')
            i++;
    }while(c != EOF);
    return i;
}

// Abre um arquivo e retorna um ponteiro para FILE
FILE *leArquivo()
{
    FILE *arquivo;
    int i, op;
    char nomes[8][17] ={"1) NomeRG10.txt\0",
                        "2) NomeRG50.txt\0",
                        "3) NomeRG100.txt\0",
                        "4) NomeRG1K.txt\0",
                        "5) NomeRG10K.txt\0",
                        "6) NomeRG1M.txt\0",
                        "7) NomeRG10M.txt\0",
                        "8) Outro\0"};
    char caminho[20] = "../\0";
    // Escolha de arquivo
    printf("Qual arquivo?\n");
    for(i = 0; i < 8; i++)
        printf("%s\n", nomes[i]);
    scanf("%d", &op);
    if( op < 1 || op > 8)
    {
        printf("Entrada invalida.\n");
        return NULL;
    }
    // Entrada de outro arquivo
    if(op == 8)
    {
        printf("Qual o nome do arquivo?\n");
        scanf("%s", nomes[7]);

    }
    // Abertura de arquivo
    strcat(caminho, nomes[--op]);
    // printf("Caminho = %s\n", caminho); // Testando se o caminho do arquivo está correto
    arquivo = fopen(caminho, "r");
    if(arquivo == NULL)
    {
        printf("Arquivo Invalido.\n");
        return NULL;
    }

    return arquivo;
}
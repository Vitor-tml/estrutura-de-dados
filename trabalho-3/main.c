#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PALAVRA 100

typedef struct no{
    char palavra[MAX_PALAVRA];
    int tamanho;
}Dicionario;

int contaPalavras(FILE *arquivo);

void main()
{
    FILE *arquivo = fopen("./data/lerolero.txt", "r");
    Dicionario *arquivoInvertido;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    arquivoInvertido = malloc(contaPalavras(arquivo) * sizeof(Dicionario));

}

int contaPalavras(FILE *arquivo)
{
    int i = 0;
    char palavra[MAX_PALAVRA];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        i++;
    }
    fseek(arquivo, 0, SEEK_SET);
    return i;
}

void preencheDicionario(FILE *origem, Dicionario *destino)
{
    char palavra[MAX_PALAVRA];
    int i = 0, j, existe;
    while (fscanf(origem, "%s", palavra) != EOF) {
        for(j = 0; j < i; j++)
            if(strcmp(destino[i].palavra, palavra) && strstr(destino[i].palavra, palavra))
                existe = 1;
        if(!existe)
            strcpy(destino[i++].palavra, palavra);
        existe = 0;
    }
}
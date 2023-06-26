#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 100
#define MAX_OCORRENCIA 100

typedef struct no {
    char palavra[MAX_PALAVRA];
    int ocorrencia[MAX_OCORRENCIA];
    int indice;
} Dicionario;

int contaPalavras(FILE* arquivo);
int preencheDicionario(FILE* origem, Dicionario* destino);
void exibeArquivoInvertido(Dicionario* arquivo, int tamanho);

int main() {
    FILE* arquivo = fopen("./data/lerolero.txt", "r");
    Dicionario* arquivoInvertido;
    int tamanhoDicionario;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    tamanhoDicionario = contaPalavras(arquivo);
    arquivoInvertido = malloc(tamanhoDicionario * sizeof(Dicionario));

    fseek(arquivo, 0, SEEK_SET);
    tamanhoDicionario = preencheDicionario(arquivo, arquivoInvertido);

    exibeArquivoInvertido(arquivoInvertido, tamanhoDicionario);
    printf("Tamanho do dicionario: %d\n", tamanhoDicionario);

    fclose(arquivo);
    free(arquivoInvertido);

    return 0;
}

int contaPalavras(FILE* arquivo) {
    int contador = 0;
    char palavra[MAX_PALAVRA];

    while (fscanf(arquivo, "%s", palavra) != EOF) {
        contador++;
    }

    fseek(arquivo, 0, SEEK_SET);

    return contador;
}

int preencheDicionario(FILE* origem, Dicionario* destino) {
    char palavra[MAX_PALAVRA];
    int i = 0, j, existe = 0, tamanho = 0, local = 0;

    destino[i].indice = 0;

    while (fscanf(origem, "%s", palavra) != EOF) {
        for (j = 0; j < i; j++) {
            if (strcmp(destino[j].palavra, palavra) == 0) {
                existe = 1;
                destino[i].ocorrencia[destino[i].indice] = local;
                destino[j].indice++;
            }
        }

        if (!existe) {
            destino[i].ocorrencia[destino[i].indice] = local;
            destino[i].indice++;
            strcpy(destino[i].palavra, palavra);
            tamanho++;
            i++;
        }
        local++;
        existe = 0;
    }

    return tamanho;
}

void exibeArquivoInvertido(Dicionario* arquivo, int tamanho) {
    int i, j;

    printf("|%-20s  | %s |\n", "Palavra", "Índice");
    printf("---------------------------------\n");

    for (i = 0; i < tamanho; i++) 
    {
        printf("| %-20s | %d", arquivo[i].palavra, arquivo[i].ocorrencia[0]);
        for(j = 1; j < arquivo[i].indice; j++)
            printf(", %d", arquivo[i].ocorrencia[j]);
        printf("\n");
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define LIMPA "cls"
#else
#define LIMPA "clear"
#endif
#define MAX_PALAVRA 100
#define MAX_OCORRENCIA 100
#define MAX_FRASE 200

typedef struct no
{
    char palavra[MAX_PALAVRA];
    int ocorrencia[MAX_OCORRENCIA];
    int indice;
} Dicionario;

int contaPalavras(FILE *arquivo);
int preencheDicionario(FILE *origem, Dicionario *destino);
void exibeArquivoInvertido(Dicionario *arquivo, int tamanho);
void procurarPalavra(Dicionario* arquivo, int tamanho, FILE *texto);
FILE *leArquivo();

int main()
{
    FILE *arquivo;
    Dicionario *arquivoInvertido;
    int tamanhoDicionario, escolha;
    char data[] = "./data/lerolero.txt";
    arquivo = fopen(data, "r");
    do
    {
        system(LIMPA);
        printf("1) Ler um arquivo.\n");
        printf("2) Mostrar o arquivo invertido.\n");
        printf("3) Procurar ocorrencia\n");
        printf("4) Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            arquivo = leArquivo();
            tamanhoDicionario = contaPalavras(arquivo);
            fseek(arquivo, 0, SEEK_SET);
            break;
        case 2:
            arquivoInvertido = malloc(tamanhoDicionario * sizeof(Dicionario));
            tamanhoDicionario = preencheDicionario(arquivo, arquivoInvertido);
            fseek(arquivo, 0, SEEK_SET);
            exibeArquivoInvertido(arquivoInvertido, tamanhoDicionario);
            break;
        case 3:
            procurarPalavra(arquivoInvertido, tamanhoDicionario, arquivo);
            fseek(arquivo, 0, SEEK_SET);
            break;
        default:
            break;
        }
        getchar();
        getchar();

    } while (escolha != 4);
    exibeArquivoInvertido(arquivoInvertido, tamanhoDicionario);
    printf("Tamanho do dicionario: %d\n", tamanhoDicionario);

    fclose(arquivo);
    free(arquivoInvertido);

    return 0;
}

int contaPalavras(FILE *arquivo)
{
    int contador = 0;
    char palavra[MAX_PALAVRA];

    while (fscanf(arquivo, "%s", palavra) != EOF)
    {
        contador++;
    }

    fseek(arquivo, 0, SEEK_SET);

    return contador;
}

int preencheDicionario(FILE *origem, Dicionario *destino)
{
    char palavra[MAX_PALAVRA];
    int i = 0, j, existe = 0, tamanho = 0, local = 0;

    destino[i].indice = 0;

    while (fscanf(origem, "%s", palavra) != EOF)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(destino[j].palavra, palavra) == 0)
            {
                existe = 1;
                destino[j].ocorrencia[destino[j].indice] = local;
                destino[j].indice++;
            }
        }

        if (!existe)
        {
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

void exibeArquivoInvertido(Dicionario *arquivo, int tamanho)
{
    int i, j;

    printf("|%-20s  | %s |\n", "Palavra", "Índice");
    printf("---------------------------------\n");

    for (i = 0; i < tamanho; i++)
    {
        printf("| %-20s | %d", arquivo[i].palavra, arquivo[i].ocorrencia[0]);
        for (j = 1; j < arquivo[i].indice; j++)
            printf(", %d", arquivo[i].ocorrencia[j]);
        printf("\n");
    }
}

FILE *leArquivo()
{
    char nome[MAX_PALAVRA];
    char data[] = "./data/";
    FILE *arq;
    printf("Qual o nome do arquivo? ");
    scanf("%s", nome);

    strcat(data, nome);
    arq = fopen(data, "r");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    return arq;
}

void procurarPalavra(Dicionario* arquivo, int tamanho, FILE *texto) {
    int i;
    int encontrada = 0;
    char palavra[MAX_PALAVRA];
    printf("Qual a palavra? ");
    scanf("%s", palavra);
    printf("\nResultado da busca:\n");

    for (i = 0; i < tamanho; i++) {
        if (strcmp(arquivo[i].palavra, palavra) == 0) {
            printf("Palavra: %s\n", arquivo[i].palavra);
            printf("Índice: %d\n", arquivo[i].indice);
            encontrada = 1;

            // FILE* texto = fopen("./data/texto.txt", "r");
            // if (texto == NULL) {
            //     printf("Erro ao abrir o arquivo de texto.\n");
            //     return;
            // }

            char frase[MAX_FRASE];
            int linha = 0;

            while (fgets(frase, MAX_FRASE, texto) != NULL) {
                linha++;

                if (strstr(frase, palavra) != NULL) {
                    printf("Frase (linha %d): %s", linha, frase);
                    break;
                }
            }

            fclose(texto);

            break;
        }
    }

    if (!encontrada) {
        printf("A palavra '%s' não foi encontrada no arquivo invertido.\n", palavra);
    }
}
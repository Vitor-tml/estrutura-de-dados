#include <stdio.h> // Para o size_t
#define TAM 15
// Define os registros da Lista Sequencial como Nome e RG.
typedef struct no_sequencial
{
    char nome[TAM];
    int rg;
} Registro_Sequencial;

// Cabeçalho da Lista Sequencial.
typedef struct lista_sequencial
{
    Registro_Sequencial *registro;
    int nElementos;
    int nMax;
} Sequencial;

void iniciaSequencial(Sequencial *lista, int nRegistros);
void exibeSequencial(Sequencial *lista);
void preencheSequencial(Sequencial *lista);
void aumentaSequencial(Sequencial *lista);
void *maloka(void *origem, size_t tamanho);
void adicionaFinalSequencial(char nome[TAM], int rg,  Sequencial *lista);
void adicionaInicioSequencial(char nome[TAM], int rg,  Sequencial *lista);
void adicionaNSequencial(char nome[TAM], int rg, int n, Sequencial *lista);
void removeInicioSequencial(Sequencial *lista);
void removeFinalSequencial(Sequencial *lista);
void removeNSequencial(Sequencial *lista, int n);
void buscaSequencial(Sequencial *lista, int rg);
void arquivoParaSequencial(Sequencial *lista, FILE *arquivo, int nLinhas);
void sequencialParaArquivo(Sequencial *lista, FILE *arquivo);
void desalocaSequencial(Sequencial *lista);
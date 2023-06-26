#ifndef __ENCADEADA__
#define __ENCADEADA__

#include <stdio.h>
#include "registro.h" // Define o Regristro da Lista
#define TAM 15

// Cabeçalho da Lista Sequencial.
typedef struct lista_encadeada
{
    Registro *primeiro;
    Registro *ultimo;
    int tamanho;
    int ordenada;
}Encadeada;

void iniciaEncadeada(Encadeada *lista);
void exibeEncadeada(Encadeada *lista);
void preencheEncadeada(Encadeada *lista, int tamanho);
int contagemEncadeada(Encadeada *lista);
void adicionaInicioEncadeada(char nome[TAM], int rg, Encadeada *lista);
void adicionaFinalEncadeada(char nome[TAM], int rg, Encadeada *lista);
void adicionaNEncadeada(char nome[TAM], int rg, int n, Encadeada *lista);
void removeInicioEncadeada(Encadeada *lista);
void removeFinalEncadeada(Encadeada *lista);
void removeNEncadeada(Encadeada *lista, int n);
void buscaEncadeada(Encadeada *lista, int rg);
void arquivoParaEncadeada(Encadeada *lista, FILE *arquivo, int nLinhas);
void encadeadaParaArquivo(Encadeada *lista, FILE *arquivo);
void desalocaEncadeada(Encadeada *lista_encadeada);
void tabelaParaEncadeada(Encadeada *lista, Registro **tabela);
Registro **criaTabelaEncadeada(Encadeada *lista);

#endif
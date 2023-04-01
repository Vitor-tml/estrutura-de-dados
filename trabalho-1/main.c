#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arquivos.h"
#include "sequencial.h"
#include "encadeada.h"
#define TAM 15
#ifdef _WIN32
#define LIMPA "cls"
#else
#define LIMPA "clear"
#endif

void inserirEncadeada(char nome[15], int rg, int posicao,Encadeada *lista);
void inserirSequencial(char nome[15], int rg, int posicao, Sequencial *lista);
void retirarEncadeada(Encadeada *lista, int posicao);
void retirarSequencial(Sequencial *lista, int posicao);

int main()
{
    int qualLista, opcao, posicao, nLinhas;
    char nome[15];
    int rg;
    Encadeada encadeada;
    Sequencial sequencial;
    FILE *arquivo;
    // Escolher entre sequencial e encadeada
    printf("Qual implementacao vai ser usada?\n0) Sequencial.\n1) Encadeada.\n");
    scanf("%d", &qualLista);
    system(LIMPA);

    // Incia lista de acordo com a escolhida
    if(qualLista)
        iniciaEncadeada(&encadeada);
    else
        iniciaSequencial(&sequencial, 10);
    
    do{
    // Menu
    printf("LISTA DE CLIENTES.\n");
    printf("O que voce quer fazer?\n");
    // Opções:
    printf("1) Inserir.\n");
    printf("2) Retirar.\n");
    printf("3) Pesquisar nome.\n");
    printf("4) Ler arquivo.\n");
    printf("5) Imprimir arquivo.\n");
    printf("6) Imprimir na tela.\n");
    printf("7) Sair.\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: // Adicionar
        printf("Onde adicionar?\n 1) Inicio.\n 2) Fim.\n 3)Posicao N.\n");
        scanf("%d", &posicao);
        printf("Qual sera o novo registro? (Nome RG)\n");
        scanf("%s %d", nome, &rg);
        if(qualLista)
            inserirEncadeada(nome, rg, posicao, &encadeada);
        else
            inserirSequencial(nome, rg, posicao, &sequencial);
        break;
    
    case 2: // Retirar
        printf("Onde retirar?\n 1) Inicio.\n 2) Fim.\n 3) Posicao N.\n");
        scanf("%d", &posicao);
        if(qualLista)
            retirarEncadeada(&encadeada, posicao);
        else
            retirarSequencial(&sequencial, posicao);
        break;
    
    case 3: // Pesquisar
        printf("Qual o RG a ser procurado?");
        scanf("%d", &rg);
        if(qualLista)
            buscaEncadeada(&encadeada, rg);
        else
            buscaSequencial(&sequencial, rg);
        break;

    case 4: // Ler arquivo
        arquivo = leArquivo();
        nLinhas = quantidadeDeLinhas(arquivo);
        if(qualLista)
            arquivoParaEncadeada(&encadeada, arquivo, nLinhas);
        else
            arquivoParaSequencial(&sequencial, arquivo, nLinhas);
        fclose(arquivo);
        break;

    case 5:
        arquivo = criaArquivo();
        if(qualLista)
            encadeadaParaArquivo(&encadeada, arquivo);
        else
            sequencialParaArquivo(&sequencial, arquivo);
        fclose(arquivo);
        break;

    case 6: // Exibir a lista
        if(qualLista)
            exibeEncadeada(&encadeada);
        else
            exibeSequencial(&sequencial);
        break;

    case 7:
        printf("Saindo...\n");
        break;

    default:
        printf("Entrada Invalida,\n");
        break;
    }
    }while(opcao != 7);
}

// Menu para inserir na lista sequencial
void inserirSequencial(char nome[15], int rg, int posicao, Sequencial *lista)
{
    int n;

    switch(posicao)
    {
    case 1:
        adicionaInicioSequencial(nome, rg, lista);
        break;
    case 2:
        adicionaFinalSequencial(nome, rg, lista);
    default:
        printf("Em qual posicao adicionar?\n");
        scanf("%d", &n);
        adicionaNSequencial(nome, rg, n, lista);
        break;
    }
    
}

// Menu para inserir na lista encadeada
void inserirEncadeada(char nome[15], int rg, int posicao,Encadeada *lista)
{
    int n;

    switch (posicao)
    {
    case 1:
        adicionaInicioEncadeada(nome, rg, lista);
        break;
    case 2:
        adicionaFinalEncadeada(nome, rg, lista);
        break;
    default:
        printf("Em qual posicao adicionar?\n");
        scanf("%d", &n);
        adicionaNEncadeada(nome, rg, n, lista);
        break;
    }    
}

// Menu para retirar na lista sequencial
void retirarSequencial(Sequencial *lista, int posicao)
{
    int n;

    switch (posicao)
    {
    case 1:
        removeInicioSequencial(lista);
        break;
    case 2:
        removeFinalSequencial(lista);
        break;
    default:
        printf("Em qual posicao remover?\n");
        scanf("%d", &n);
        removeNSequencial(lista, n);
        break;
    }
}

// Menu para retirar na lista encadeada
void retirarEncadeada(Encadeada *lista, int posicao)
{
    int n;

    switch (posicao)
    {
    case 1:
        removeInicioEncadeada(lista);
        break;
    case 2:
        removeFinalEncadeada(lista);
        break;
    default:
        printf("Em qual posicao remover?\n");
        scanf("%d", &n);
        removeNEncadeada(lista, n);
        break;
    } 
}
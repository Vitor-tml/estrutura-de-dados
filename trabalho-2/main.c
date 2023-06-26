#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arquivos.h"
#include "sequencial.h"
#include "encadeada.h"
#include "performance.h"
#include "ordenacao.h"
#define TAM 15
#ifdef _WIN32
#define LIMPA "cls"
#else
#define LIMPA "clear"
#endif

// Variáveis globais de performance
int Mn;
int Cn;
clock_t inicio;
clock_t fim;

// Declaração de funçoes que usam as bibliotecas
void inserirEncadeada(char nome[15], int rg, int posicao, Encadeada *lista);
void inserirSequencial(char nome[15], int rg, int posicao, Sequencial *lista);
void retirarEncadeada(Encadeada *lista, int posicao);
void retirarSequencial(Sequencial *lista, int posicao);
void espera(char mensagem[]);

int main()
{
    srand(time(NULL));
    Encadeada lista;
    //Encadeada lista;
    Registro **tabela;
    iniciaEncadeada(&lista);
    preencheEncadeada(&lista, 10);
    // printf("LISTA GERADA: \n");
    // exibeEncadeada(&lista);
    tabela = criaTabelaEncadeada(&lista);
    printf("TABELA GERADA: \n");
    imprimeTabela(tabela, lista.tamanho);
    printf("Tamanho da lista: %d\n", lista.tamanho);
    quickSort(tabela, 0, lista.tamanho - 1);
    printf("TABELA ORDENADA: \n");
    imprimeTabela(tabela, lista.tamanho);
    tabelaParaEncadeada(&lista, tabela);
    printf("TABELA SALVE: \n");
    exibeEncadeada(&lista);
    
}

int maina()
{
    int qualLista, opcao, posicao, nLinhas;
    char nome[15];
    int rg;
    Encadeada encadeada;
    Sequencial sequencial;
    Registro **tabela;
    FILE *arquivo;
    // Escolher entre sequencial e encadeada
    printf("Qual implementacao vai ser usada?\n0) Sequencial.\n1) Encadeada.\n");
    scanf("%d", &qualLista);
    system(LIMPA);

    // Incia lista de acordo com a escolhida
    if (qualLista)
        iniciaEncadeada(&encadeada);
    else
        iniciaSequencial(&sequencial, 10);

    do
    {
        // Menu
        system(LIMPA);
        printf("LISTA DE CLIENTES.\n");
        printf("O que voce quer fazer?\n");
        // Opções:
        printf("1) Inserir.\n");
        printf("2) Retirar.\n");
        printf("3) Pesquisar nome.\n");
        printf("4) Ler arquivo.\n");
        printf("5) Imprimir em arquivo.\n");
        printf("6) Imprimir na tela.\n");
        printf("7) Ordenar.\n");
        printf("8) Sair.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Adicionar
            printf("Onde adicionar?\n 1) Inicio.\n 2) Fim.\n 3) Posicao N.\n");
            scanf("%d", &posicao);
            printf("Qual sera o novo registro? (Nome RG)\n");
            scanf("%s %d", nome, &rg);
            iniciaContagem();
            if (qualLista)
                inserirEncadeada(nome, rg, posicao, &encadeada);
            else
                inserirSequencial(nome, rg, posicao, &sequencial);
            terminaContagem();
            espera("Adicionado com sucesso.\n");
            break;

        case 2: // Retirar
            printf("Onde retirar?\n 1) Inicio.\n 2) Fim.\n 3) Posicao N.\n");
            scanf("%d", &posicao);
            iniciaContagem();
            if (qualLista)
                retirarEncadeada(&encadeada, posicao);
            else
                retirarSequencial(&sequencial, posicao);
            terminaContagem();
            espera("Adicionado com sucesso.\n");
            break;

        case 3: // Procurar
            printf("Qual o RG a ser procurado?\n");
            scanf("%d", &rg);
            iniciaContagem();
            if (qualLista)
                buscaEncadeada(&encadeada, rg);
            else
                buscaSequencial(&sequencial, rg);
            terminaContagem();
            espera("Busca efetuada.");
            break;

        case 4: // Ler arquivo
            arquivo = leArquivo();
            nLinhas = quantidadeDeLinhas(arquivo);
            iniciaContagem();
            if (qualLista)
                arquivoParaEncadeada(&encadeada, arquivo, nLinhas);
            else
                arquivoParaSequencial(&sequencial, arquivo, nLinhas);
            fclose(arquivo);
            terminaContagem();
            espera("Arquivo lido com sucesso.");
            break;

        case 5: // Salva em arquivo
            arquivo = criaArquivo();
            if (qualLista)
                encadeadaParaArquivo(&encadeada, arquivo);
            else
                sequencialParaArquivo(&sequencial, arquivo);
            fclose(arquivo);
            espera("Arquivo salvo com sucesso.");
            break;

        case 6: // Exibir a lista
            if (qualLista)
                exibeEncadeada(&encadeada);
            else
                exibeSequencial(&sequencial);
            espera("Fim da lista.");
            break;
        
        case 7: // Escolher ordenação
            if(qualLista)
                tabela = criaTabelaEncadeada(&encadeada);
            else
                tabela = criaTabelaSequencial(&sequencial);
            

            break;

        case 8: // Saída
            printf("Saindo...\n");
            break;

        default:
            espera("Entrada Invalida.");
            break;
        }
    } while (opcao != 7);

    if(qualLista)
        desalocaEncadeada(&encadeada);
    else
        desalocaSequencial(&sequencial);
    return 0;
}

// Menu para inserir na lista sequencial
void inserirSequencial(char nome[15], int rg, int posicao, Sequencial *lista)
{
    int n;

    switch (posicao)
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
void inserirEncadeada(char nome[15], int rg, int posicao, Encadeada *lista)
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

void ordenacao(Encadeada **tabela, int tamanho)
{
    int escolha;
    printf("Qual ordenação?");
    printf("1)Selection Sort\n");
    printf("2)Insertion Sort\n");
    printf("3)Bubble Sort\n");
    printf("4)Shell Sort\n");
    printf("5)Quick Sort\n");
    printf("6)Merge Sort\n");
    scanf("%d", &escolha);

    switch(escolha)
    {
        case 1:
            selectionSort(tabela,tamanho);
            break;
        
        case 2:
            insertionSort(tabela, tamanho);
            break;
        
        case 3:
            bubbleSort(tabela, tamanho);
            break;

        case 4:
            shellSort(tabela, tamanho);
            break;

        case 5:
            quickSort(tabela, 0, tamanho - 1);
            break;

        case 6:
            mergeSort(tabela, 0, tamanho - 1);
            break;

        default:
            printf("Escolha invalida!\n");
            break;
    }
}
void espera(char mensagem[])
{
    printf("%s\n", mensagem);
    printf("Qualquer tecla para continuar...\n");
    getchar();
    getchar();
}
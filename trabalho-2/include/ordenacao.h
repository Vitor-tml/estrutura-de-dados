#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "registro.h"

void selectionSort(Registro **tabela, int tamanho);
void insertionSort(Registro **tabela, int tamanho);
void bubbleSort(Registro **tabela, int tamanho);
void shellSort(Registro **tabela, int tamanho);
void quickSort(Registro **tabela, int inicio, int fim);
int particiona(Registro **tabela, int inicio, int fim);
void mergeSort(Registro **tabela, int inicio, int fim);
void merge(Registro **, int inicio, int meio, int fim);
void imprimeTabela(Registro **tabela, int tamanho);
int buscaBinaria(Registro **tabela, int inicio, int fim, int chave);

#endif
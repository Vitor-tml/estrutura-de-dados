#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "registro.h"

void selectionSort(Registro **tabela, int tamanho);
void insertionSort(Registro **tabela, int tamanho);
void bubbleSort(Registro **tabela, int tamanho);
void shellSort(Registro **tabela, int tamanho);

void mergeSort(Registro **tabela, int inicio, int fim);
void merge(Registro **, int inicio, int meio, int fim);
void imprimeTabela(Registro **tabela, int tamanho);

#endif
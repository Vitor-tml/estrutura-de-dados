#ifndef __REGISTRO__
#define __REGISTRO__

// Registros das Listas.
typedef struct no
{
    struct no *anterior;
    char nome[15];
    int rg;
    struct no *proximo;
} Registro;

#endif
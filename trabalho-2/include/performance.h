#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include <time.h>

extern int Mn;
extern int Cn;
extern clock_t inicio;
extern clock_t fim;

void iniciaContagem();
void terminaContagem();

#endif
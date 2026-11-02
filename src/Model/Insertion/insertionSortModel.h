#ifndef INSERTION_SORT_MODEL_H
#define INSERTION_SORT_MODEL_H

#include "../../Model/QuickSort/modelo_satelite.h"
#include <stddef.h>

#define TAMANHO_LINHA_CSV 2048

typedef struct {
    char linha[TAMANHO_LINHA_CSV];
    double risco_fogo;
} RegistroQueimada;

void ordenarRegistrosInsertionSort(RegistroQueimada registros[], int tamanho);
void ordenarFocosInsertionSort(RegistroFoco registros[], size_t tamanho);

#endif
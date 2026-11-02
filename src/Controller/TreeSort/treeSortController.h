#ifndef TREE_SORT_CONTROLLER_H
#define TREE_SORT_CONTROLLER_H

#include <stddef.h>
#include "../../Model/QuickSort/modelo_satelite.h"

int ordenarComArvore(const unsigned char* entrada, size_t tamanho, unsigned char* saida);
int ordenarRiscosComArvore(const float* entrada, size_t tamanho, float* saida);
int ordenarRegistrosComArvore(
    RegistroFoco entrada[],
    size_t tamanho
);

#endif
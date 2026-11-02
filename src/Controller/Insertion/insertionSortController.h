#ifndef INSERTION_SORT_CONTROLLER_H
#define INSERTION_SORT_CONTROLLER_H

#include "../../Model/QuickSort/modelo_satelite.h"
#include <stddef.h>

void executar_insertion_sort(RegistroFoco registros[], size_t tamanho);
void executarInsertionSortCSV(const char *caminhoArquivo, int quantidade);
void executarInsertionSortAleatorio(int quantidade);

#endif
#ifndef HEAP_SORT_CONTROLLER_S_H
#define HEAP_SORT_CONTROLLER_S_H
#include "..\..\Model\Heapsort\modelo_Satelite.h"
#include <stdlib.h>

void heapsortS(RegistroFoco *arvore, int total);
void salvar_csv_ordenado(const char* caminho, RegistroFoco* dados, int total);
RegistroFoco* carregar_dados_csv(const char* caminho_arquivo, int* total_registos);

#endif
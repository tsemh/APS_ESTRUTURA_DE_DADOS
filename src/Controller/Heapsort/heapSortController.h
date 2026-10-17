#ifndef HEAP_SORT_CONTROLLER_H
#define HEAP_SORT_CONTROLLER_H  

#include <stdbool.h>
#include <stddef.h>
#include "..\..\Model\Heapsort\bHeap.h"

bool estaVazia(bHeap* arvore);
int parente(int indice, bHeap* arvore);
void heapsort(bHeap *arvore);


#endif
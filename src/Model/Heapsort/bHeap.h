#ifndef B_HEAP_H
#define B_HEAP_H

#include <stdbool.h>
#include <stddef.h>
#include "..\..\Resource\lista.h"

typedef struct binary_heap{
    int tamanho; // 'tamanho' retorna o indice do ultimo elemento
    int no[TAMANHO_LISTA];
} bHeap;

bHeap iniciarArvore();
void preencher_Heap(bHeap *arvore, int valores[], int tamanho);

#endif
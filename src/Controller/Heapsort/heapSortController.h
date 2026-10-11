#ifndef HEAP_SORT_CONTROLLER_H
#define HEAP_SORT_CONTROLLER_H  

#include <stdbool.h>
#include <stddef.h>
#include "..\..\Model\Heapsort\bHeap.h"

bool estaVazia(bHeap* arvore);
void add(int valor, bHeap* arvore);
int parente(int indice, bHeap* arvore);
bool eMaior(int indiceFilho, int indicePai, bHeap* arvore);
void swap(int indiceFilho, int indicePai, bHeap* arvore);
void insert(int valor, bHeap* arvore);
void heapify(bHeap *arvore, int indicePai);
int heapify_i(bHeap *arvore);
void dequeue(bHeap*arvore);
void heapsort(bHeap *arvore);


#endif
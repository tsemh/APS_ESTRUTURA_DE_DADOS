#include <stdio.h>
#include <stdlib.h>
#include "bHeap.h"

bHeap iniciarArvore(){
    // Funcao para iniciar a Binary HEAP
    bHeap arvore;
    arvore.tamanho = -1;
    return arvore;
}

void preencher_Heap(bHeap *arvore, int valores[], int tamanho) {
    // Preenche a array no[] bHeap com a lista fornecida
    for (int i = 0; i < tamanho; i++) {
        arvore->no[i] = valores[i];
    }
    arvore->tamanho = tamanho-1;
}
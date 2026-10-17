#include <stdio.h>
#include "heapSortView.h"
#include "..\..\Controller\Heapsort\heapSortController.h"
#include "..\..\Resource\lista.h"


void imprimirArvore(bHeap* arvore){
    // Imprime a arvore, parentes e seus dependentes
    if(estaVazia(arvore)){
        printf(" Arvore vazia. \n");
        return;
    }
    printf("\n        === ARVORE RESULTADO === \n");
    for (int i = 0; i < TAMANHO_LISTA; i++){
        printf(" || Arvore [%d] - Elemento %d. Pai: [%d] - %d.", i, arvore->no[i], parente(i, arvore), arvore->no[parente(i, arvore)]);
    }
}

void imprimir_lista_ordenada(bHeap* arvore){
    // Imprime a lista estatica pos ordenacao
    printf("\n        === LISTA RESULTADO === \n|");
    for (int i = 0; i < TAMANHO_LISTA; i++){
        printf(" %d |", arvore->no[i]);
    }

}
void imprimir_lista_ordenadaDin(bHeapD* arvore){
    // Imprime a lista dinamica pos ordenacao
    printf("\n        === LISTA RESULTADO === \n|");
    for (int i = 0; i < TAMANHO_LISTA; i++){
        printf(" %d |", arvore->no[i]);
    }

}
#include <stdio.h>
#include <stdlib.h>
#include "bHeapD.h"

bHeapD iniciarArvoreDin(int capacidadeInicial){
    bHeapD arvore;
    
    arvore.tamanho = -1;
    arvore.capacidade = capacidadeInicial;
    arvore.no = malloc(capacidadeInicial * sizeof(int));
    
    if (arvore.no == NULL){
        arvore.capacidade = 0;
    }
    
    return arvore;
}

int aumentarCapacidade(bHeapD *arvore){
    int novaCapacidade = arvore->capacidade * 2;

    if(novaCapacidade == 0){
        novaCapacidade = 4;
    }

    int *novoNo = realloc(arvore->no, novaCapacidade * sizeof(int));

    if (novoNo == NULL){
        return 0;
    }

    arvore->no = novoNo;
    arvore->capacidade = novaCapacidade;
    return 1;
}

void preencher_HeapDin(bHeapD* arvore, int valores[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arvore->no[i] = valores[i];
    }
    arvore->tamanho = tamanho - 1;
}

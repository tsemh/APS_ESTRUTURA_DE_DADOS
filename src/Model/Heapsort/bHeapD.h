#ifndef B_HEAP_D_H
#define B_HEAP_D_H

typedef struct binary_heap_d{
    int tamanho;      // quantidade de elementos/indica o indice do ultimo elemento
    int capacidade;    // quanto o array pode guardar antes de precisar crescer
    int *no;           // ponteiro, nao array fixo
} bHeapD;

bHeapD iniciarArvoreDin(int capacidadeInicial);
int aumentarCapacidade(bHeapD *arvore); // da um realloc quando tamanho == capacidade
void preencher_HeapDin(bHeapD * arvore, int valores[], int tamanho);

#endif
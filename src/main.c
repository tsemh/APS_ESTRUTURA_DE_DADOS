#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Controller\Heapsort\heapSortController.h"
#include "View\Heapsort\heapsortView.h"
bHeap arvore;
int main(){
    /*
    BINARY HEAP - uma estrutura de dados em "ARVORE BINARIA" 
    A Origem dessa arvore gera dois dependentes (no esquerdo e no direito) e estes dependentes geram mais dois, e assim sucessivamente. 
    
    Duas configuracoes: MAX-HEAP ou MIN-HEAP.
    MAX-HEAP -> Valor origem tem que ser MENOR que seus dependentes, e o mesmo se aplica para os outros dependentes.

    MIN-HEAP -> Valor de origem tem que ser MENOR que seus dependentes, e o mesmo de aplica para os outros dependentes.

    Seguimos a lógica matemática na qual o indice logico do elemento pai, eh encontrado por P ((i-1)/2).
    traduzindo: ((indice atual - 1) divido por 2).

    Para encontrar o elemento filho partir do pai, em caso de:
    No Esquerdo (2i + 1);
    No Direito (2i + 2).
    */ 
    
    clock_t start, end;
    double time;

    printf("\n        === BINARY HEAP === \n");
    printf("     Ordenacao com Lista Pre-Determinada\n\n");
    
    preencher_Heap(&arvore, lista, TAMANHO_LISTA);

    start = clock();
    
    heapsort(&arvore);
    
    end = clock();
    time = (double)(end-start) / CLOCKS_PER_SEC;
    
    imprimir_lista_ordenada(&arvore);
    
    printf("\n\nTempo de execucao: %fs\n", time);
    
    return 0;
}
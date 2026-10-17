#include <stdio.h>
#include <stdbool.h>
#include "..\..\Model\Heapsort\bHeapD.h"
#include "heapSortControllerD.h"

bool estaVaziaDin(bHeapD* arvore){
    // Verifica se a lista esta vazia
    if (arvore->tamanho < 0){
        printf("Arvore vazia. \n");
        return true;
    }
    return false;
}

bool eMaiorDin(int indiceFilho, int indicePai, bHeapD* arvore) {
    // Verifica se o pai é maior que o filho
    return arvore->no[indiceFilho] > arvore->no[indicePai];
}

void swapDin(int indiceFilho, int indicePai, bHeapD* arvore){
    int valorNovoPai = arvore->no[indiceFilho]; // Indice filho gera uma variavel auxiliar para a troca;

    arvore->no[indiceFilho] = arvore->no[indicePai]; //Indice pai vai ficar na posicao do filho
    arvore->no[indicePai] = valorNovoPai; //Indice filho vai ficar na posicao do pai
}

void heapifyDin(bHeapD *arvore, int indicePai){
    // Verifica se o pai é maior que os filhos, e se o novo-filho é maior que seus filhos
    int maior = indicePai;
    int esquerdo = 2 * indicePai + 1; // Indice do filho esquerdo
    int direito = 2 * indicePai + 2; // Indice do filho direito
        
    if (esquerdo <= arvore->tamanho && eMaiorDin(esquerdo, maior, arvore)){
        maior = esquerdo;
    }
    if (direito <= arvore->tamanho && eMaiorDin(direito, maior, arvore)){
        maior = direito;
    }
    if (maior != indicePai){
        swapDin(maior, indicePai, arvore);
        heapifyDin(arvore, maior);
    }

}

void heapsortDin(bHeapD *arvore){
    // Inicia a ordenacao da lista, primeiramente transforma ela em binary heap
    // Depois preenche a lista com os valores ordenados.
    // A lista/arvore e refeita do final até o inicio, do maior para o menor elemento.
    if (estaVaziaDin(arvore)){
        printf("Arvore vazia. \n");
        return;
    }
    
    int ultimoIndicePai = arvore->tamanho / 2; // Busca o ultimo indice que tem filhos
    for (int i = ultimoIndicePai; i >= 0; i--){
        heapifyDin(arvore, i);
    }

    for (int i = arvore->tamanho; i >= 0; i--){
        swapDin(0, i, arvore); // O menor valor passa ser o valor de origem da binary heap.
        arvore->tamanho--;  // Binary heap diminui em 1 o seu tamanho.
        heapifyDin(arvore, 0); // A binary heap atualiza após o novo valor de origem.
    }
}
void destruirArvoreDin(bHeapD *arvore){
    free(arvore->no);

    arvore->no = NULL;
    arvore->tamanho = 0;
    arvore->capacidade = 0;
}
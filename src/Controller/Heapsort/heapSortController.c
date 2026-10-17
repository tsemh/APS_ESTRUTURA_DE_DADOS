#include "heapSortController.h"
#include <stdio.h>
#include <stdbool.h>

bool estaVazia(bHeap* arvore){
    // Verifica se a lista esta vazia
    if (arvore->tamanho < 0){
        printf("Arvore vazia. \n");
        return true;
    }
    return false;
}

bool eMaior(int indiceFilho, int indicePai, bHeap* arvore) {
    // Verifica se o pai é maior que o filho
    return arvore->no[indiceFilho] > arvore->no[indicePai];
}

void swap(int indiceFilho, int indicePai, bHeap* arvore){
    int valorNovoPai = arvore->no[indiceFilho]; // Indice filho gera uma variavel auxiliar para a troca;

    arvore->no[indiceFilho] = arvore->no[indicePai]; //Indice pai vai ficar na posicao do filho
    arvore->no[indicePai] = valorNovoPai; //Indice filho vai ficar na posicao do pai
}

int parente(int indice, bHeap* arvore){
    // O Indice Pai se encontra pela formula: 
    // numero_indice_filho - 1 dividido por 2 "(i-1)/2"
    int indicePai =((indice-1)/2); 
    return indicePai;
}

void heapify(bHeap *arvore, int indicePai){
    // Verifica se o pai é maior que os filhos, e se o novo-filho é maior que seus filhos
    int maior = indicePai;
    int esquerdo = 2 * indicePai + 1; // Indice do filho esquerdo
    int direito = 2 * indicePai + 2; // Indice do filho direito
        
    if (esquerdo <= arvore->tamanho && eMaior(esquerdo, maior, arvore)){
        maior = esquerdo;
    }
    if (direito <= arvore->tamanho && eMaior(direito, maior, arvore)){
        maior = direito;
    }
    if (maior != indicePai){
        swap(maior, indicePai, arvore);
        heapify(arvore, maior);
    }

}

void heapsort(bHeap *arvore){
    // Inicia a ordenacao da lista, primeiramente transforma ela em binary heap
    // Depois refaz a arvore com os valores ordenados.
    // A lista/arvore e refeita do final até o inicio, do maior para o menor elemento.
    if (estaVazia(arvore)){
        printf("Arvore vazia. \n");
        return;
    }
    
    int ultimoIndicePai = arvore->tamanho / 2; // Busca o ultimo indice que tem filhos
    for (int i = ultimoIndicePai; i >= 0; i--){
        heapify(arvore, i);
    }

    for (int i = arvore->tamanho; i >= 0; i--){
        swap(0, i, arvore); // O menor valor passa ser o valor de origem da binary heap.
        arvore->tamanho--;  // Binary heap diminui em 1 o seu tamanho.
        heapify(arvore, 0); // A binary heap atualiza após o novo valor de origem.
    }
}


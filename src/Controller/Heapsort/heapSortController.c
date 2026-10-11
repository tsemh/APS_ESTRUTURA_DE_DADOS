#include "heapSortController.h"
#include <stdio.h>
#include <stdbool.h>

bool estaVazia(bHeap* arvore){
    // Verifica se a lista esta vazia
    if (arvore->tamanho == -1){
        printf("Arvore vazia. \n");
        return true;
    }
    return false;
    
}

void add(int valor, bHeap* arvore){
    // Adiciona o valor na arvore
    arvore->tamanho++;
    int i = arvore->tamanho;
    arvore->no[i] = valor;
     
}

int parente(int indice, bHeap* arvore){
    // O Indice Pai se encontra pela formula: numero_indice_filho - 1 dividido por 2 "(i-1)/2"
    int indicePai =((indice-1)/2); 
    return indicePai;
}

bool eMaior(int indiceFilho, int indicePai, bHeap* arvore) {
    // Verifica se o pai é maior que o filho
    return arvore->no[indiceFilho] > arvore->no[indicePai];
}

void swap(int indiceFilho, int indicePai, bHeap* arvore){
    //Indice filho vai ficar na posicao do pai
    //Indice pai vai ficar na posicao do filho
    
    int valorNovoPai = arvore->no[indiceFilho];

    arvore->no[indiceFilho] = arvore->no[indicePai];
    arvore->no[indicePai] = valorNovoPai;
}

void insert(int valor, bHeap* arvore){
    /* Pega o valor novo para inserir na arvore
    e passa por uma checagem para garantir que esteja respeitando o MAX HEAP */ 
    add(valor, arvore);

    int i = arvore->tamanho;
    
    while (i > 0){
        int indicePai = parente(i, arvore);
        if (eMaior(i,indicePai, arvore)){
            swap(i,indicePai, arvore);
            i = indicePai;
        } else {
            break;
        }
    }
}

void heapify(bHeap *arvore, int indicePai){
    // Verifica se o pai é maior que os filhos, e se o novo-filho é maior que seus filhos
    int maior = indicePai;
    int esquerdo = 2 * indicePai + 1; 
    int direito = 2 * indicePai + 2; 
        
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

int heapify_i(bHeap *arvore){
    // Busca o ultimo indice que tem filhos
    if (arvore->tamanho <= 1){
        return 0;
    }
    int ultimoIndicePai = arvore->tamanho+1; 
    for (int i = ultimoIndicePai / 2 - 1; i >= 0; i--){ 
        heapify(arvore,i);
    }
    return 1;
}

void dequeue(bHeap*arvore){
    // Verifica se a arvore esta vazia
    // Retorna o valor de origem (que no caso é sempre o maior valor da binary heap)
    // O menor valor passa ser o valor de origem da binary heap 
    // Binary heap diminui em 1 o seu tamanho.
    // A binary heap atualiza após o novo valor de origem
    
    if(estaVazia(arvore)){
        return;
    }

    int resultado = arvore->no[0];

    arvore->no[0] = arvore->no[arvore->tamanho];
    arvore->no[arvore->tamanho] = resultado;
    arvore->tamanho--;

    heapify(arvore, 0);
}

void heapsort(bHeap *arvore){
    // Inicia a ordenacao da lista, primeiramente transforma ela em binary heap e depois preenche a lista com os valores ordenados.
    // A lista e preenchida do final até o inicio, do maior para o menor elemento.
    heapify_i(arvore);
    for (int i = arvore->tamanho; i >= 0; i--){
        dequeue(arvore);
        
    }
}


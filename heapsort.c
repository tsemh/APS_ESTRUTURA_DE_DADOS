#include <stdio.h>
#include <stdbool.h>

int listaOrdenada[10];
int totalOrdenado = 0;

typedef struct binary_heap{
    int tamanho; // 'tamanho' é retorna o indice do ultimo elemento
    int no[10];
} bHeap;


bHeap iniciarArvore(){
    bHeap arvore;
    arvore.tamanho = -1;
    return arvore;
}


void preencher_Heap(bHeap *arvore, int valores[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arvore->no[i] = valores[i];
    }

    arvore->tamanho = tamanho-1;
}

void add(int valor, bHeap* arvore){
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
}

int dequeue(bHeap*arvore){
    if(arvore->tamanho < 0){
        return 0;
    }

    int resultado = arvore->no[0];
    int tamanho_atual= arvore->tamanho;

    arvore->no[0] = arvore->no[tamanho_atual];
    arvore->tamanho--;

    heapify_i(arvore);
    return resultado;
}

void heapsort(bHeap *arvore){
    heapify_i(arvore);
    for (int i = arvore->tamanho; i > 0; i--){
        listaOrdenada[i] = dequeue(arvore);
        totalOrdenado++;
    }
}

bool estaVazia(bHeap* arvore){
    
    if (arvore->tamanho == -1){
        printf("Arvore vazia. \n");
        return true;
    }
    return false;
    
}

void imprimirArvore(bHeap* arvore){
    if(estaVazia(arvore)){
        return;
    }
    printf("\n        === ARVORE RESULTADO === \n");
    for (int i = 0; i <= arvore->tamanho; i++){
        printf("\nArvore [%d] - Elemento %d.\nPai: [%d] - %d.\n", i, arvore->no[i], parente(i, arvore), arvore->no[parente(i, arvore)]);
    }

}

void imprimir_lista_ordenada(){
    if(totalOrdenado == 0){
        return;
    }
    printf("\n        === LISTA RESULTADO === \n|");
    for (int i = 0; i <= totalOrdenado; i++){
        printf(" %d |", listaOrdenada[i]);
    }

}
int main(){
    /*BINARY HEAP - uma estrutura de dados em "ARVORE BINARIA", 
    A Origem dessa arvore gera dois dependentes (no esquerdo e no direito) e estes dependentes geram mais dois, e assim sucessivamente. 
    
    Duas configuracoes: MAX-HEAP ou MIN-HEAP.
    MAX-HEAP -> Valor origem tem que ser MENOR que seus dependentes, e o mesmo se aplica para os outros dependentes.

    MIN-HEAP -> Valor de origem tem que ser MENOR que seus dependentes, e o mesmo de aplica para os outros dependentes.


    Seguimos a lógica matemática na qual o indice logico do elemento pai, eh encontrado por P ((i-1)/2).
    traduzindo: ((indice atual - 1) divido por 2).

    Para encontrar o elemento filho partir do pai, em caso de:
    No Esquerdo (2i + 1);
    No Direito (2i + 2).*/ 
    
    bHeap arvore = iniciarArvore();
    // Lista para ser ajustada pelo Heap
    int lista[10] = {10, 54, 1,32, 11, 6, 5, 7, 89, 90};
    int listaas[10] = {1, 6, 5, 7, 10, 11, 32, 54, 89, 90};
    printf("\n        === BINARY HEAP === \n\n");
    printf("     Ordenacao a cada Elemento Adicionado\n\n");
    imprimirArvore(&arvore);
    
    int quantidade = sizeof(lista) / sizeof(lista[0]);
    for (int i = 0; i < quantidade; i++){
        printf("Indice [%d] - Elemento %d. \n", i, lista[i]);
        insert(lista[i], &arvore);
    }
    imprimirArvore(&arvore);

    // -----------------------------------------------------------------------------
    
    printf("\n        === BINARY HEAP === \n");
    printf("     Ordenacao com Lista Pre-Determinada\n\n|");

    bHeap arvore_dois;
    
    preencher_Heap(&arvore_dois, lista, sizeof(lista) / sizeof(lista[0]));
    
    for (int i = 0; i < sizeof(lista) / sizeof(lista[0]); i++){
        printf(" %d |", lista[i]);
    }
    
    heapify_i(&arvore_dois);
    imprimirArvore(&arvore_dois);

    heapsort(&arvore_dois);

    imprimir_lista_ordenada();

    return 0;
}
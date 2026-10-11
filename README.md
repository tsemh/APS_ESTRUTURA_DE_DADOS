# APS - HEAPSORT

## Introdução

Este código se trata de um projeto da matéria semestral Atividade Prática Supervisionada vinculada com a matéria Estrutura de Dados.

Foi desenvolvido um algoritmo de ordenação de dados - Heapsort.

### Heapsort
É utilizado o conceito de Binary Heap, onde os elementos são organizados por uma árvore. 
- O primeiro elemento gera dois dependentes, e estes mesmos dependentes geram mais dois outros.

- Uma binary heap pode seguir a regra de:  
    "Min-Heap" o valor do pai tem que ser MAIOR que seus dependentes
    "Max-Heap": o valor do pai tem que ser MENOR que seus dependentes.

- Podem ser armazenadas em listas simples (uma array como em C int "lista[10]").

- Seguimos a lógica matemática na qual o indice logico do elemento pai, é encontrado por P ((i-1)/2).
    (Traduzindo: ((indice atual - 1) divido por 2)).

- Para encontrar o elemento filho partir do pai, em caso de:
    No Esquerdo (2i + 1), No Direito (2i + 2).

- Heapsort tem complexidade O(n log n) no médio, pior e melhor caso.

### Estrutura de Projeto

### `TAD bHeap (binary_heap)`
Estrutura da Binary Heap que será utilizada para ordenação.

typedef struct binary_heap{
    int tamanho;
    int no[TAMANHO_LISTA];
} bHeap;

Possui um "int tamanho;" , sendo o indice do ultimo elemento. 
E também, "int no[TAMANHO_LISTA];" uma array de inteiros que seu tamanho é determinado pela constante TAMANHO_LISTA (lista.h). 

Chamada abreviada: bHeap.

### `iniciararvore()`
Função para iniciar a Binary Heap, retorna bHeap.

### `preencher_Heap()`
Preenche o array da binary heap com a lista externa (no caso Resources\lista.c)
Parâmetros: endereço da árvore, lista e Tamanho da lista.

### `heapsort()`
Inicia o HeapSort, ele executa o heapify_i() e depois entra em um laço for para ordenar a árvore. A lista é preenchida do final até o inicio. 
Parâmetros: endereço da árvore.

### `heapify_i()`
Percorre do ultimo laço pai até a origem transformando a lista em uma Binary Heap de propriedade Max-Heap.
Parâmetros: endereço da árvore.

### `heapify()`
Atualiza a Binary Heap, verifica-se o novo valor de origem está respeitando a Max-Heap e percorre alterando (caso necessário) todo o "galho" que contém os seus dependentes.
Parâmetros: endereço da árvore, indice do pai.

### `swap()`
O valor do filho passa a ficar no indice do pai e vice-versa.
Parâmetros: indice do filho, indice do pai e endereço da árvore.

### `eMaior()`
Retorna um valor verdadeiro/falso se caso o filho seja maior que o pai.
Parâmetros: indice do filho, indice do pai e endereço da árvore.

### `parente()`
Encontra o indice do pai a partir do indice de um de seus filhos.
Parâmetros: indice do filho (qualquer um), endereço da árvore.

### `add()`
Insere um valor inteiro na última posicao da árvore.
Parâmetros: valor inteiro, endereço da árvore.

### `insert()`
Após o valor novo ser inserido na Binary Heap via add() é feito a checagem se está respeitando a Max-Heap, percorrendo no novo indice até a origem, caso necessário.
Parâmetros: valor novo, endereço da árvore.

### `estaVazia()`
Retorna um valor verdadeiro/falso se a lista esta vazia.
Parâmetros: endereço da árvore.

### `dequeue()`
Processo onde a árvore é transformada em uma lista ordenada, verifica inicialmente se está vazia, o elementro de origem troca de posicao com o indice do ultimo elemento e o ultimo elemento (que é o menor de todos) passa ser a origem, a Binary Heap diminui em 1 seu tamanho e é chamada a função heapify() com argumento o indice do novo pai (indice origem 0).
Parâmetros: endereço da árvore.

### `imprimirArvore()`
Imprime na tela a árvore, parentes e seus dependentes
Parâmetros: endereço da árvore.

### `imprimir_lista_ordenada()`
Imprime a lista pós-ordenação
Parâmetros: endereço da árvore.

### `clock()`
Função da lib "<time.h>" que foi utilizado para calcular o tempo de ordenação.

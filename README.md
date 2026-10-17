# APS - HEAPSORT

## Introdução

Este código se trata de um projeto da matéria semestral Atividade Prática Supervisionada vinculada à disciplina Estrutura de Dados.

O objetivo foi implementar o algoritmo de ordenação Heapsort aplicado sobre um conjunto real de dados de focos de queimadas, lidos a partir de um arquivo CSV. Adicionalmente, a aplicação gera uma lista com dados aleatorios para teste de ordenação caso seja necessário.

### Heapsort
É utilizado o conceito de Binary Heap, onde os elementos são organizados por uma árvore. 
- O primeiro elemento gera dois dependentes, e estes mesmos dependentes geram mais dois outros.

- Uma binary heap pode seguir a regra de:

    `Min-Heap` o valor do pai tem que ser MENOR que seus dependentes;

    `Max-Heap` o valor do pai tem que ser MAIOR que seus dependentes.

- Podem ser armazenadas em listas simples (uma array como em C int "lista[10]").

- Seguimos a lógica matemática na qual o indice logico do elemento pai, é encontrado por P ((i-1)/2).

    (Traduzindo: ((indice atual - 1) divido por 2)).

- Para encontrar o elemento filho partir do pai, em caso de:

    No Esquerdo (2i + 1), No Direito (2i + 2).

- Heapsort tem complexidade O(n log n) no médio, pior e melhor caso.

## Estrutura de Projeto
```
APS_ESTRUTURA_DE_DADOS/
├── src/
│   ├── main.c
│   ├── Controller/
│   │   └── Heapsort/
│   │       ├── heapSortController.c
│   │       ├── heapSortController.h
│   │       ├── heapSortControllerD.c
│   │       └── heapSortControllerD.h
│   │       ├── heapSortControllerS.c
│   │       └── heapSortControllerS.h
│   ├── Model/
│   │   └── Heapsort/
│   │       └── bHeap.c
│   │       └── bHeap.h
│   │       └── bHeapD.c
│   │       └── bHeapD.h
│   │       └── modelo_satelite.h
│   ├── Resource/
│   │   └── dados_queimadas.csv
│   │   └── gerarDados.c
│   │   └── gerarDados.h 
│   │   └── lista.c
│   │   └── lista.h
│   └── View/
│       └── heapSortView.c
│       └── heapSortView.h
├── aps_heapsort.exe
└── README.md
```
### `TAD scructs (binary_heap)`
Estruturas de Binary Heap que será utilizada para ordenação.

```c
typedef struct binary_heap{
    int tamanho;
    int no[TAMANHO_LISTA];
} bHeap;
```
Possui um `int tamanho;` , sendo o indice do ultimo elemento.

E também, `int no[TAMANHO_LISTA];` uma array de inteiros que seu tamanho é determinado pela constante `TAMANHO_LISTA (lista.h)`. 

Chamada abreviada: `bHeap`.


```c
typedef struct binary_heap_d{
    int tamanho;
    int capacidade;
    int *no;
} bHeapD;
```
Possui um `int tamanho;` ,sendo o indice do ultimo elemento.
`int capacidade;`,determina a capacidade máxima de armazenamento.
`int *no;` ponteiro para os elementos que serão alocados na memória.


```c
typedef struct {
    float latitude;
    float longitude;
    char data_pas[25];
    char satelite[30];
    char pais[30];
    char estado[30];
    char municipio[60];
    char bioma[30];
    int numero_dias_sem_chuva;
    float precipitacao;
    float risco_fogo;
    char id_area_industrial[20]; 
    float frp;                   
} RegistroFoco;
```
Cada campo corresponde a uma coluna do arquivo CSV. O campo principal para a ordenação é o **risco_fogo**.

## Funções do Algoritmo - ESTÁTICO/DINÂMICO

### `iniciarArvore()`
Função para iniciar a Binary Heap.
**Retorno:** bHeap.

---

### `preencher_Heap()`
Preenche o array da binary heap com a lista externa (no caso Resources\lista.c)
**Parâmetros:** endereço da árvore, lista e Tamanho da lista.

---

### `heapsort()`
Inicia o HeapSort. Primeiramente ele verifica se a lista está vazia, após, utiliza dois laços `for` e `heapify()`, uma para transformar a lista em arvore, a outra para ordenar a arvore em uma lista de menor para maior. 
**Parâmetros:** endereço da árvore.

---

### `heapify()`
Atualiza a Binary Heap, verifica-se o novo valor de origem está respeitando a Max-Heap e percorre alterando (caso necessário) todo o "galho" que contém os seus dependentes.
**Parâmetros:** endereço da árvore, indice do pai.

---

### `swap()`
O valor do filho passa a ficar no indice do pai e vice-versa.
**Parâmetros:** indice do filho, indice do pai e endereço da árvore.

---

### `eMaior()`
Retorna um valor verdadeiro/falso se caso o filho seja maior que o pai.
**Parâmetros:** indice do filho, indice do pai e endereço da árvore.

---

### `parente()`
Encontra o indice do pai a partir do indice de um de seus filhos.
**Parâmetros:** indice do filho (qualquer um), endereço da árvore.

---

### `estaVazia()`
Retorna um valor verdadeiro/falso se a lista esta vazia.
**Parâmetros:** endereço da árvore.

---

### `imprimirArvore()`
Imprime na tela a árvore, parentes e seus dependentes
**Parâmetros:** endereço da árvore.

---

### `imprimir_lista_ordenada()`
Imprime a lista pós-ordenação
**Parâmetros:** endereço da árvore.

---

## Funções do Algoritmo - .CSV
### `heapsortS()`
Inicia o HeapSort. Primeiramente ele verifica se a lista está vazia, após, utiliza dois laços `for` e `heapifyS()`, uma para transformar a lista em arvore, a outra para ordenar a arvore em uma lista de menor para maior. 
**Parâmetros:** RegistroFoco, total dos dados.

---

### `heapifyS()`
Atualiza a Binary Heap, verifica-se o novo valor de origem está respeitando a Max-Heap e percorre alterando (caso necessário) todo o "galho" que contém os seus dependentes.
**Parâmetros:** RegistroFoco, tamanho, indice do pai.

---

### `swapS()`
O valor do filho passa a ficar no indice do pai e vice-versa.
**Parâmetros:** RegistroFoco, indice do filho, indice do pai.

---

### `eMaiorS()`
Retorna um valor verdadeiro/falso se caso o ".risco_fogo" do filho seja maior que o pai.
**Parâmetros:** indice do filho, indice do pai e endereço da árvore.
**Retorno:** boolean verdadeiro ou falso.

---

### `carregar_dados_csv()`
Realiza a leitura do arquivo CSV e carrega os registros na memória dinamicamente.

Aloca espaço para até 125.000 registros, lê linha por linha com fgets e tokeniza cada campo com strtok. A primeira linha do arquivo (cabeçalho) é descartada automaticamente.

**Parâmetros:** caminho do arquivo e ponteiro para o contador de registros.
**Retorno:** ponteiro para o array de RegistroFoco alocado em heap.---

---

### `salvar_csv_ordenado()`
Salva o arquivo .csv ordenado no /Resource
**Parâmetros:** caminho para salvar o arquivo, RegistroFoco, contador de registros

---

### `clock()`
Função da lib `<time.h>` que foi utilizado para calcular o tempo de ordenação.

---

## Como Compilar e Executar
Certifique-se de ter o GCC instalado, dentro da pasta /APS_ESTRUTURA_DE_DADOS faça:

```bash
gcc -o aps_heapsort.exe src\main.c src\Controller\Heapsort\heapSortController.c src\Model\Heapsort\bHeap.c src\Controller\Heapsort\heapSortControllerD.c src\Model\Heapsort\bHeapD.c src\Resource\gerarDados.c src\Resource\lista.c src\View\Heapsort\heapSortView.c src\Controller\Heapsort\heapSortControllerS.c
```

Em seguida, execute:

```bash
./aps_heapsort.exe
```
---

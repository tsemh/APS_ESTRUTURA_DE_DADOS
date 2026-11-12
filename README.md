# APS - Algoritmos de Ordenação

Projeto desenvolvido para a Atividade Prática Supervisionada da disciplina de
Estrutura de Dados. O programa lê registros de focos de queimadas ou gera
dados aleatórios e compara quatro algoritmos de ordenação pelo campo
`risco_fogo`:

- **Quick Sort**
- **Tree Sort**
- **Heap Sort**
- **Insertion Sort**

O benchmark valida o resultado de cada algoritmo, mede o tempo de execução em
diferentes cenários e apresenta um ranking geral de desempenho.

## Dados utilizados

O arquivo principal de entrada é:

```text
src/Resource/dados_queimadas.csv
```

Cada registro é representado por `RegistroFoco`, que contém os dados
geográficos, temporais e ambientais do foco de queimada. A ordenação considera
exclusivamente o campo `risco_fogo`, em ordem crescente.

O programa também oferece uma opção para gerar 12.000 valores aleatórios de
`risco_fogo`, permitindo executar o benchmark sem depender do CSV.

## Algoritmos implementados

### Quick Sort

Implementado em `src/Controller/QuickSort/quick_sort.c`. Utiliza o elemento
central do intervalo como pivô, particiona o vetor com dois ponteiros e ordena
as partições recursivamente. A ordenação ocorre **in-place** sobre os registros
completos.

| Caso             | Complexidade                     |
| ---------------- | -------------------------------- |
| Melhor caso      | O(n log n)                       |
| Caso médio       | O(n log n)                       |
| Pior caso        | O(n²)                            |
| Memória auxiliar | O(log n) em média, pela recursão |

### Tree Sort

Implementado em `src/Controller/TreeSort/treeSortController.c` e
`src/Model/TreeSort/noModel.c`. Os valores de `risco_fogo` são inseridos em uma
árvore binária de busca. Uma travessia **em ordem** recupera os valores
ordenados. Valores repetidos são armazenados no mesmo nó por meio do campo
`repeticoes`.

| Caso              | Complexidade |
| ----------------- | ------------ |
| Melhor/caso médio | O(n log n)   |
| Pior caso         | O(n²)        |
| Memória auxiliar  | O(n)         |

Os nós são liberados ao final da ordenação. A implementação também trata
falhas de alocação e libera a árvore parcial antes de retornar.

### Heap Sort

O Controller está em `src/Controller/HeapSort/heapSortController.c` e expõe
`executar_heap_sort()`. A implementação do **max-heap** está no Model, em
`src/Model/HeapSort/heapSortModel.c`, que move repetidamente o maior registro para
o final do vetor, comparando `risco_fogo`.

| Caso             | Complexidade               |
| ---------------- | -------------------------- |
| Melhor caso      | O(n log n)                 |
| Caso médio       | O(n log n)                 |
| Pior caso        | O(n log n)                 |
| Memória auxiliar | O(1) no vetor do algoritmo |

### Insertion Sort

Implementado em `src/Model/Insertion/insertionSortModel.c`. Percorre os
registros da esquerda para a direita e insere cada elemento na posição correta
da parte já ordenada. A implementação preserva o registro completo, embora
compare apenas `risco_fogo`.

| Caso             | Complexidade               |
| ---------------- | -------------------------- |
| Melhor caso      | O(n)                       |
| Caso médio       | O(n²)                      |
| Pior caso        | O(n²)                      |
| Memória auxiliar | O(1) no vetor do algoritmo |

## Benchmark

O `src/main.c` executa todos os quatro algoritmos nos mesmos dados e nos
seguintes cenários:

1. Dados não ordenados
2. Dados ordenados
3. Dados invertidos, em ordem decrescente
4. Dados semi-ordenados, com 80% ordenados e 20% aleatórios

Para cada combinação de algoritmo e cenário, o programa:

- cria uma cópia independente dos dados;
- mede o tempo com `clock_gettime(CLOCK_MONOTONIC)`;
- verifica se a saída está em ordem crescente;
- exibe os resultados individuais;
- calcula um ranking pela soma dos tempos válidos dos quatro cenários.

Também são executados testes controlados de falha de alocação para verificar o
tratamento de buffers e de nós da Tree Sort.

## Estrutura do projeto

```text
APS_ESTRUTURA_DE_DADOS/
├── src/
│   ├── main.c
│   ├── Controller/
│   │   ├── HeapSort/
│   │   │   ├── heapSortController.c
│   │   │   └── heapSortController.h
│   │   ├── Insertion/
│   │   │   ├── insertionSortController.c
│   │   │   └── insertionSortController.h
│   │   ├── QuickSort/
│   │   │   ├── dados_controller.c
│   │   │   ├── dados_controller.h
│   │   │   ├── quick_sort.c
│   │   │   └── quick_sort.h
│   │   └── TreeSort/
│   │       ├── treeSortController.c
│   │       └── treeSortController.h
│   ├── Model/
│   │   ├── HeapSort/
│   │   │   ├── heapSortModel.c
│   │   │   └── heapSortModel.h
│   │   ├── Insertion/
│   │   │   ├── insertionSortModel.c
│   │   │   └── insertionSortModel.h
│   │   ├── QuickSort/
│   │   │   └── modelo_satelite.h
│   │   └── TreeSort/
│   │       ├── noModel.c
│   │       └── noModel.h
│   └── Resource/
│       └── dados_queimadas.csv
├── benchmark.exe
└── README.md
```

O arquivo `benchmark.exe` é o executável gerado pela compilação do projeto.
Os algoritmos seguem a separação MVC: os Controllers coordenam a execução e
os Models contêm as implementações dos algoritmos e das estruturas de dados.

## Compilação

É necessário ter um compilador C compatível com C99, como o GCC. A partir da
raiz do projeto, execute:

```bash
gcc -std=c99 -Wall -Wextra -Wpedantic -Wformat=2 \
  src/main.c \
  src/Controller/Insertion/insertionSortController.c \
  src/Model/Insertion/insertionSortModel.c \
  src/Controller/QuickSort/dados_controller.c \
  src/Controller/QuickSort/quick_sort.c \
  src/Controller/TreeSort/treeSortController.c \
  src/Model/TreeSort/noModel.c \
  src/Controller/HeapSort/heapSortController.c \
  src/Model/HeapSort/heapSortModel.c \
  -lm \
  -o benchmark
```

O programa usa funções POSIX (`dup`, `dup2`, `open`, `STDOUT_FILENO` e
`getcwd`) para silenciar a mensagem duplicada do carregamento e
localizar `src/Resource/dados_queimadas.csv` relativo ao executável. Assim, o
CSV também pode ser carregado quando o programa é iniciado fora da raiz do
projeto. `PATH_MAX` recebe um valor padrão quando não é fornecido pelo sistema.
Em ambientes estritamente não POSIX, é necessária uma camada de compatibilidade
para essas funções.

## Execução

```bash
./benchmark
```

Escolha uma das opções exibidas:

```text
1 - Utilizar dados do arquivo CSV
2 - Utilizar dados aleatórios
```

O resultado contém os tempos por cenário, o resumo comparativo, o ranking dos
algoritmos e os testes de falha de memória.

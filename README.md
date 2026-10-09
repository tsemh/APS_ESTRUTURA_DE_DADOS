# APS - HEAPSORT

## Introdução

Este código se trata de um projeto da matéria semestral Atividade Prática Supervisionada vinculada com a matéria Estrutura de Dados.

Foi desenvolvido um algoritmo de ordenação de dados - Heapsort.

### Heapsort
É utilizado o conceito de Binary Heap, onde os elementos são organizados por uma arvore. 
- O primeiro elemento gera dois dependentes, e estes mesmos dependentes geram mais dois outros.

- Uma binary heap pode seguir a regra de:  
    "Min-Heap" o valor do pai tem que ser MAIOR que seus dependentes
    "Max-Heap": o valor do pai tem que ser MENOR que seus dependentes.

- Podem ser armazenadas em listas simples (uma array como em C int "lista[10]").

- Seguimos a lógica matemática na qual o indice logico do elemento pai, é encontrado por P ((i-1)/2). (Traduzindo: ((indice atual - 1) divido por 2)).

- Para encontrar o elemento filho partir do pai, em caso de:
    No Esquerdo (2i + 1), No Direito (2i + 2).

- Heapsort tem complexidade O(n log n) no médio, pior e melhor caso.
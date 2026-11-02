#include "heapSortModel.h"

static void trocar(RegistroFoco *a, RegistroFoco *b) {
    RegistroFoco temporario = *a;
    *a = *b;
    *b = temporario;
}

static void ajustarHeap(RegistroFoco dados[], size_t tamanho, size_t raiz) {
    size_t maior = raiz;
    size_t esquerda = 2 * raiz + 1;
    size_t direita = 2 * raiz + 2;

    if (esquerda < tamanho &&
        dados[esquerda].risco_fogo > dados[maior].risco_fogo) {
        maior = esquerda;
    }

    if (direita < tamanho &&
        dados[direita].risco_fogo > dados[maior].risco_fogo) {
        maior = direita;
    }

    if (maior != raiz) {
        trocar(&dados[raiz], &dados[maior]);
        ajustarHeap(dados, tamanho, maior);
    }
}

void heap_sort_model(RegistroFoco dados[], size_t tamanho) {
    if (dados == NULL || tamanho < 2) {
        return;
    }

    for (size_t i = tamanho / 2; i > 0; i--) {
        ajustarHeap(dados, tamanho, i - 1);
    }

    for (size_t fim = tamanho; fim > 1; fim--) {
        trocar(&dados[0], &dados[fim - 1]);
        ajustarHeap(dados, fim - 1, 0);
    }
}

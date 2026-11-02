#include <stdlib.h>
#include "treeSortController.h"
#include "../../Model/TreeSort/noModel.h"

int ordenarRiscosComArvore(
    const float *entrada,
    size_t tamanho,
    float *saida
) {
    if (tamanho > 0 && (entrada == NULL || saida == NULL)) {
        return 0;
    }

    NoModel *raiz = NULL;
    for (size_t i = 0; i < tamanho; i++) {
        if (!inserir(&raiz, entrada[i])) {
            destruirArvore(raiz);
            return 0;
        }
    }

    size_t indice = 0;
    emOrdem(raiz, saida, &indice);
    destruirArvore(raiz);
    return indice == tamanho;
}

int ordenarRegistrosComArvore(
    RegistroFoco entrada[],
    size_t tamanho
) {
    NoRegistroModel *raiz = NULL;
    RegistroFoco *ordenados;
    size_t indice = 0;

    if (tamanho > 0 && entrada == NULL) {
        return 0;
    }
    if (tamanho == 0) {
        return 1;
    }

    ordenados = malloc(tamanho * sizeof(*ordenados));
    if (ordenados == NULL) {
        return 0;
    }

    for (size_t i = 0; i < tamanho; i++) {
        if (!inserirRegistro(&raiz, &entrada[i])) {
            destruirArvoreRegistros(raiz);
            free(ordenados);
            return 0;
        }
    }

    emOrdemRegistros(raiz, ordenados, &indice);
    for (size_t i = 0; i < tamanho; i++) {
        entrada[i] = ordenados[i];
    }

    destruirArvoreRegistros(raiz);
    free(ordenados);
    return indice == tamanho;
}

int ordenarComArvore(
    const unsigned char *entrada,
    size_t tamanho,
    unsigned char *saida
) {
    if (tamanho > 0 && (entrada == NULL || saida == NULL)) {
        return 0;
    }
    if (tamanho == 0) {
        return 1;
    }

    float *valores = malloc(tamanho * sizeof(*valores));
    float *ordenados = malloc(tamanho * sizeof(*ordenados));
    if (valores == NULL || ordenados == NULL) {
        free(valores);
        free(ordenados);
        return 0;
    }

    for (size_t i = 0; i < tamanho; i++) {
        valores[i] = entrada[i];
    }

    int sucesso = ordenarRiscosComArvore(valores, tamanho, ordenados);
    if (sucesso) {
        for (size_t i = 0; i < tamanho; i++) {
            saida[i] = (unsigned char)ordenados[i];
        }
    }

    free(valores);
    free(ordenados);
    return sucesso;
}

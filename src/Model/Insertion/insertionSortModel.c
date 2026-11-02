#include "insertionSortModel.h"

void ordenarRegistrosInsertionSort(RegistroQueimada registros[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        RegistroQueimada chave = registros[i];
        int j = i - 1;

        while (j >= 0 && registros[j].risco_fogo > chave.risco_fogo) {
            registros[j + 1] = registros[j];
            j--;
        }

        registros[j + 1] = chave;
    }
}

void ordenarFocosInsertionSort(RegistroFoco registros[], size_t tamanho) {
    for (size_t i = 1; i < tamanho; i++) {
        RegistroFoco chave = registros[i];
        size_t j = i;

        while (j > 0 &&
               registros[j - 1].risco_fogo > chave.risco_fogo) {
            registros[j] = registros[j - 1];
            j--;
        }

        registros[j] = chave;
    }
}

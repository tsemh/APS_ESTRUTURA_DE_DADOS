#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerarDados.h"

void gerarAleatorio(int tamanho, int min, int max) {
    srand((unsigned int) time(NULL));  // semente baseada no tempo

    int range = max - min + 1;
    for (int i = 0; i < tamanho; i++) {
        // combina dois rand() para cobrir ranges maiores que RAND_MAX
        long r = ((long)rand() << 15) | rand();
        lista[i] = min + (int)(labs(r) % range);
    }
}

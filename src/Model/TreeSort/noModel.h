#ifndef NO_MODEL_H
#define NO_MODEL_H

#include <stddef.h>
#include "../QuickSort/modelo_satelite.h"

typedef struct NoModel {
    float valor;
    size_t repeticoes;
    struct NoModel *esquerda;
    struct NoModel *direita;
} NoModel;

NoModel* criarNo(float valor);
void simularFalhaNaAlocacaoDoNo(size_t numeroAlocacao);
int inserir(NoModel** raiz, float valor);
void emOrdem(const NoModel* raiz, float* saida, size_t* indice);
void destruirArvore(NoModel* raiz);

typedef struct NoRegistroModel {
    RegistroFoco registro;
    struct NoRegistroModel *esquerda;
    struct NoRegistroModel *direita;
} NoRegistroModel;

NoRegistroModel *criarNoRegistro(const RegistroFoco *registro);
int inserirRegistro(NoRegistroModel **raiz, const RegistroFoco *registro);
void emOrdemRegistros(
    const NoRegistroModel *raiz,
    RegistroFoco saida[],
    size_t *indice
);
void destruirArvoreRegistros(NoRegistroModel *raiz);

#endif
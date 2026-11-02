#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados_controller.h"

#define TAMANHO_LINHA_CSV 4096
#define QUANTIDADE_CAMPOS 13

static int proximo_campo(char **cursor, char **campo) {
    char *inicio;
    char *separador;

    if (*cursor == NULL) {
        return 0;
    }

    inicio = *cursor;
    separador = strchr(inicio, ',');
    if (separador != NULL) {
        *separador = '\0';
        *cursor = separador + 1;
    } else {
        *cursor = NULL;
    }

    *campo = inicio;
    return 1;
}

static void copiar_campo(char *destino, size_t tamanho, const char *origem) {
    if (tamanho == 0) {
        return;
    }

    snprintf(destino, tamanho, "%s", origem);
}

static int converter_float(const char *campo, float *resultado) {
    char *fim;
    double valor;

    if (*campo == '\0') {
        return 0;
    }

    errno = 0;
    valor = strtod(campo, &fim);
    if (fim == campo || *fim != '\0' || errno == ERANGE ||
        !isfinite(valor) || valor < -FLT_MAX || valor > FLT_MAX) {
        return 0;
    }

    *resultado = (float)valor;
    return 1;
}

static int converter_inteiro(const char *campo, int *resultado) {
    char *fim;
    double valor;

    if (*campo == '\0') {
        return 0;
    }

    errno = 0;
    valor = strtod(campo, &fim);
    if (fim == campo || *fim != '\0' || errno == ERANGE ||
        !isfinite(valor) || valor < INT_MIN || valor > INT_MAX ||
        floor(valor) != valor) {
        return 0;
    }

    *resultado = (int)valor;
    return 1;
}

static int converter_registro(char *linha, RegistroFoco *registro) {
    char *campos[QUANTIDADE_CAMPOS];
    char *cursor = linha;

    for (int i = 0; i < QUANTIDADE_CAMPOS; i++) {
        if (!proximo_campo(&cursor, &campos[i])) {
            return 0;
        }
    }

    if (cursor != NULL) {
        return 0;
    }

    registro->latitude = 0.0f;
    registro->longitude = 0.0f;
    registro->numero_dias_sem_chuva = 0;
    registro->precipitacao = 0.0f;
    registro->risco_fogo = 0.0f;
    registro->frp = 0.0f;

    if (!converter_float(campos[0], &registro->latitude) ||
        !converter_float(campos[1], &registro->longitude) ||
        !converter_inteiro(campos[8], &registro->numero_dias_sem_chuva) ||
        !converter_float(campos[9], &registro->precipitacao) ||
        !converter_float(campos[10], &registro->risco_fogo)) {
        return 0;
    }

    if (campos[12][0] != '\0' &&
        !converter_float(campos[12], &registro->frp)) {
        return 0;
    }

    copiar_campo(registro->data_pas, sizeof(registro->data_pas), campos[2]);
    copiar_campo(registro->satelite, sizeof(registro->satelite), campos[3]);
    copiar_campo(registro->pais, sizeof(registro->pais), campos[4]);
    copiar_campo(registro->estado, sizeof(registro->estado), campos[5]);
    copiar_campo(registro->municipio, sizeof(registro->municipio), campos[6]);
    copiar_campo(registro->bioma, sizeof(registro->bioma), campos[7]);
    copiar_campo(
        registro->id_area_industrial,
        sizeof(registro->id_area_industrial),
        campos[11]
    );

    return 1;
}

RegistroFoco *carregar_dados_csv(
    const char *caminho_arquivo,
    int *total_registos
) {
    FILE *arquivo;
    RegistroFoco *dados = NULL;
    size_t capacidade = 1024;
    size_t contador = 0;
    char linha[TAMANHO_LINHA_CSV];

    if (total_registos == NULL) {
        return NULL;
    }

    *total_registos = 0;
    arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro: Nao foi possivel abrir o ficheiro %s\n",
                caminho_arquivo);
        return NULL;
    }

    dados = malloc(capacidade * sizeof(*dados));
    if (dados == NULL) {
        fprintf(stderr, "Erro: Memoria insuficiente.\n");
        fclose(arquivo);
        return NULL;
    }

    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        free(dados);
        return NULL;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        RegistroFoco registro = {0};
        size_t tamanho = strlen(linha);

        while (tamanho > 0 &&
               (linha[tamanho - 1] == '\n' || linha[tamanho - 1] == '\r')) {
            linha[--tamanho] = '\0';
        }

        if (!converter_registro(linha, &registro)) {
            continue;
        }

        if (contador == capacidade) {
            size_t nova_capacidade = capacidade * 2;
            RegistroFoco *novo = realloc(
                dados,
                nova_capacidade * sizeof(*dados)
            );

            if (novo == NULL) {
                fprintf(stderr, "Erro: Memoria insuficiente.\n");
                free(dados);
                fclose(arquivo);
                return NULL;
            }

            dados = novo;
            capacidade = nova_capacidade;
        }

        dados[contador++] = registro;
    }

    fclose(arquivo);
    *total_registos = (int)contador;
    printf(" Carregando %d registos na memoria.\n", *total_registos);
    return dados;
}

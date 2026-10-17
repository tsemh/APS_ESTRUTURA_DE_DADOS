#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Model\Heapsort\modelo_Satelite.h"
#include "heapSortControllerS.h"

bool eMaiorS(RegistroFoco* arvore, int indiceFilho, int indicePai) {
    // Verifica se o pai é maior que o filho
    return arvore[indiceFilho].risco_fogo > arvore[indicePai].risco_fogo;
}

void swapS(RegistroFoco* arvore, int indiceFilho, int indicePai){
    //Indice filho vai ficar na posicao do pai
    //Indice pai vai ficar na posicao do filho
    RegistroFoco registroNovoPai = arvore[indiceFilho];

    arvore[indiceFilho] = arvore[indicePai];
    arvore[indicePai] = registroNovoPai;
}

void heapifyS(RegistroFoco *arvore, int tamanho, int indicePai){
    // Verifica se o pai é maior que os filhos, e se o novo-filho é maior que seus filhos
    int maior = indicePai;
    int esquerdo = 2 * indicePai + 1; 
    int direito = 2 * indicePai + 2; 
        
    if (esquerdo <= tamanho && eMaiorS(arvore, esquerdo, maior)){
        maior = esquerdo;
    }
    if (direito <= tamanho && eMaiorS(arvore, direito, maior)){
        maior = direito;
    }
    if (maior != indicePai){
        swapS(arvore, maior, indicePai);
        heapifyS(arvore, tamanho, maior);
    }

}

void heapsortS(RegistroFoco *arvore, int total){
    // Inicia a ordenacao da lista, primeiramente transforma ela em binary heap e depois preenche a lista com os valores ordenados.
    // A lista e preenchida do final até o inicio, do maior para o menor elemento.
    int tamanho = total -1; // Ultimo indice da arvore

    // Busca o ultimo indice que tem filhos
    for (int i = tamanho / 2 ; i >= 0; i--){ 
        heapifyS(arvore, tamanho, i);
    }

    for (int i = tamanho; i >= 0; i--){
        swapS(arvore, i, 0);
        heapifyS(arvore, i-1, 0);
        
    }
}

RegistroFoco* carregar_dados_csv(const char* caminho_arquivo, int* total_registos) {
    FILE* arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        printf(" Erro: Nao foi possivel abrir o ficheiro %s\n", caminho_arquivo);
        return NULL;
    }

    int capacidade = 125000; 
    RegistroFoco* dados = (RegistroFoco*) malloc(capacidade * sizeof(RegistroFoco));
    if (dados == NULL) {
        printf(" Erro: Memoria insuficiente.\n");
        fclose(arquivo);
        return NULL;
    }

    char linha[1024]; 
    int contador = 0;

    if (fgets(linha, sizeof(linha), arquivo) == NULL) {
        fclose(arquivo);
        return dados;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL && contador < capacidade) {
        char* token = strtok(linha, ",");
        if (token == NULL) continue;
        dados[contador].latitude = atof(token);
        
        token = strtok(NULL, ",");
        if (token) dados[contador].longitude = atof(token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].data_pas, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].satelite, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].pais, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].estado, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].municipio, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].bioma, token);
        
        token = strtok(NULL, ",");
        if (token) dados[contador].numero_dias_sem_chuva = atoi(token);
        
        token = strtok(NULL, ",");
        if (token) dados[contador].precipitacao = atof(token);
        
        token = strtok(NULL, ",");
        if (token) dados[contador].risco_fogo = atof(token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dados[contador].id_area_industrial, token);
        
        token = strtok(NULL, ",");
        if (token) dados[contador].frp = atof(token);

        contador++;
    }

    fclose(arquivo);
    *total_registos = contador; 
    

    printf(" Carregando %d registos na memoria.\n", contador);
    return dados;
}

void salvar_csv_ordenado(const char* caminho, RegistroFoco* dados, int total) {
    FILE* f = fopen(caminho, "w");
    if (!f) { 
        printf("Erro ao criar %s\n", caminho); 
        return; 
    }

    fprintf(f, "latitude,longitude,data_pas,satelite,pais,estado,"
               "municipio,bioma,numero_dias_sem_chuva,precipitacao,"
               "risco_fogo,id_area_industrial,frp\n");

    for (int i = 0; i < total; i++) {
        fprintf(f, "%.6f,%.6f,%s,%s,%s,%s,%s,%s,%d,%.2f,%.4f,%s,%.2f\n",
            dados[i].latitude, dados[i].longitude,
            dados[i].data_pas, dados[i].satelite,
            dados[i].pais,     dados[i].estado,
            dados[i].municipio, dados[i].bioma,
            dados[i].numero_dias_sem_chuva,
            dados[i].precipitacao, dados[i].risco_fogo,
            dados[i].id_area_industrial, dados[i].frp);
    }

    fclose(f);
    printf(" Arquivo .CSV salvo em %s\n", caminho);
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Controller\Heapsort\heapSortControllerD.h"
#include "Controller\Heapsort\heapSortController.h"
#include "Controller\Heapsort\heapSortControllerS.h"
#include "Model\Heapsort\bHeapD.h"
#include "Model\Heapsort\modelo_Satelite.h"
#include "Model\Heapsort\bHeap.h"
#include "Resource\gerarDados.h"
#include "View\Heapsort\heapSortView.h"

int main(){
    system("cls");
    // Variaveis de calculo de execucao
    clock_t start, end, start_d, end_d , start_csv, end_csv;
    double tempo, tempoD, tempoCsv;

    // Struct's do /Model
    bHeapD arvore_di;
    bHeap arvore;
    RegistroFoco* dados;

    // Endereço dos arquivos .csv !!!ATENÇÃO: Certifique-se que esta no caminho correto de acordo com sua máquina.
    // Local do arquivo para ordernar
    const char* arquivo_ordenar = "C:/Users/Lucas/VSCodeProjects/APS_ESTRUTURA_DE_DADOS/src/Resource/dados_queimadas.csv";
    
    // Local para salvar arquivo ordenado
    const char* endereco_arquivo = "C:/Users/Lucas/VSCodeProjects/APS_ESTRUTURA_DE_DADOS/src/Resource/dados_queimadas_corrigido.csv";
    
    // Variaveis auxiliares
    int resposta;
    int total = 0;
    srand((unsigned int) time(NULL));
    
    //  ---------------------------- INICIO ----------------------------
    printf("\n +============================== Log ====================================+\n");
    printf("\n Iniciando leitura dos dados e gerando lista aleatoria...\n\n");
    sleep(2);
    dados = carregar_dados_csv(arquivo_ordenar, &total);
    if (!dados) return 1;
    gerarAleatorio(TAMANHO_LISTA, MIN, MAX);
    printf("\n Algoritimo: HeapSort (Lucas L.) \n");
    printf("\n +================= Teste de Performance dos Algoritmos =================+\n\n");
    
    //  ---- .CSV ----
    printf("\n -> Inciando HeapSort - .CSV...\n\n");
    sleep(1);
    start_csv = clock();
    heapsortS(dados, total);
    end_csv = clock();
    tempoCsv = (double)(end_csv-start_csv) / CLOCKS_PER_SEC; // Calculo do tempo
    salvar_csv_ordenado(endereco_arquivo, dados, total);

    // ---- ESTATICO ----
    arvore = iniciarArvore();
    preencher_Heap(&arvore, lista, TAMANHO_LISTA); // Preenche a binary heap com os valores aleatorios
    
    printf("\n -> Inciando HeapSort (numeros aletorios)- ESTATICO...\n\n");
    sleep(1);
    start = clock(); // Incio contagem
    heapsort(&arvore); // Incio da funcao Heapsort
    end = clock(); // Final contagem
    tempo = (double)(end-start) / CLOCKS_PER_SEC; // Calculo do tempo


    // ---- DINAMICO ----
    arvore_di = iniciarArvoreDin(TAMANHO_LISTA); // Incia Arvore;
    if (arvore_di.no == NULL) {
        fprintf(stderr, " Erro: falha ao alocar heap dinamica.\n");
        return 1;
    }

    preencher_HeapDin(&arvore_di, lista, TAMANHO_LISTA); // Preenche a binary heap com os valores aleatorios
    
    printf("\n -> Inciando HeapSort (numeros aletorios) - DINAMICO...\n\n");
    sleep(1);
    start_d = clock(); // Incio contagem
    heapsortDin(&arvore_di);  // Incio da funcao Heapsort Dinamico
    end_d = clock(); // Final contagem
    tempoD = (double)(end_d-start_d) / CLOCKS_PER_SEC;
    
    while(resposta != 1 && resposta != 2){
        printf("\n Mostrar Lista [ESTATICO] ordenada?\n [1] - SIM \n [2] - NAO\n\n");
        printf(" Escolha uma opcao: ");
        

        if (scanf("%d", &resposta) != 1) {
            while (getchar() != '\n');
        }

        if (resposta != 1 && resposta != 2) {
            printf("\n Opcao invalida! Digite apenas 1 ou 2.\n\n");
            sleep(1);
        }
    }

    if (resposta == 1){
        printf("\n Imprimindo Lista Ordenada (menor -> maior).");
        sleep(2);
        imprimir_lista_ordenada(&arvore);
    }
    
    resposta = 0;

    while(resposta != 1 && resposta != 2){
        printf("\n\n Mostrar Lista [DINAMICO] ordenada?\n [1] - SIM \n [2] - NAO\n\n");
        printf(" Escolha uma opcao: ");
        

        if (scanf("%d", &resposta) != 1) {
                while (getchar() != '\n');
            }

        if (resposta != 1 && resposta != 2) {
            printf("\n Opcao invalida! Digite apenas 1 ou 2.\n\n");
            sleep(1);
        }
    }

    if (resposta == 1){
        printf("\n Imprimindo Lista Ordenada (menor -> maior).");
        sleep(2);
        imprimir_lista_ordenadaDin(&arvore_di);
    }

    // --- RESULTADO
    printf("\n +=========================== RESULTADO =================================+\n\n");
    printf(" Tamanho da arvore: %d \n",TAMANHO_LISTA);
    printf(" Capacidade atual [DINAMICO]: %d \n", arvore_di.capacidade);

    printf("\n\n Tempo de execucao [.CSV]: %fs\n", tempoCsv);
    printf(" Tempo de execucao [ESTATICO]: %fs\n", tempo);
    printf(" Tempo de execucao [DINAMICO]: %fs\n", tempoD);
    
    printf("\n O arquivo.csv ordenado esta localizado no endereco: %s \n", endereco_arquivo);
    printf("\n +=======================================================================+\n");
    destruirArvoreDin(&arvore_di);
    free(dados);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 100

void copiar_vetor(int origem[], int destino[], int n)
{
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

int main()
{
    int original[TAM], teste[TAM];
    clock_t inicio, fim;
    double tempo_gasto;

    // Inicializa gerador de números aleatórios
    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
        original[i] = rand() % 1000;

    // --- Teste Bubble Sort ---
    copiar_vetor(original, teste, TAM);
    inicio = clock();
    bubble_sort(teste, TAM);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f segundos\n", tempo_gasto);

    // --- Teste Selection Sort ---
    copiar_vetor(original, teste, TAM);
    inicio = clock();
    selection_sort(teste, TAM);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f segundos\n", tempo_gasto);

    // --- Teste Quick Sort ---
    copiar_vetor(original, teste, TAM);
    inicio = clock();
    quick_sort(teste, 0, TAM - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f segundos\n", tempo_gasto);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

int main()
{
    int vetor[TAM];
    clock_t inicio, fim;

    srand(time(NULL));
    for (int i = 0; i < TAM; i++)
        vetor[i] = rand() % 500;

    int alvo = vetor[10]; // Vamos procurar o valor que está na posição 10
    int k = 5;            // Queremos o 5º menor elemento

    // Medindo Busca Linear
    inicio = clock();
    int pos = linear_search(vetor, TAM, alvo);
    fim = clock();
    printf("Linear Search: Alvo %d encontrado na pos %d. Tempo: %f s\n",
           alvo, pos, (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Medindo Quick Select
    inicio = clock();
    int valor_k = quick_select(vetor, 0, TAM - 1, k);
    fim = clock();
    printf("Quick Select: O %do menor elemento e %d. Tempo: %f s\n",
           k, valor_k, (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}
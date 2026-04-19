#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    clock_t tempo_inicial = clock();

    int soma = 10 + 20; // 0(1)

    clock_t tempo_final = clock();

    double duracao = (double) (tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.5f seg", duracao);

    return 0;
}




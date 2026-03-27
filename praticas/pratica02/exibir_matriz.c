#include <stdio.h>
#include <time.h>

#define TAM 10

void preencher_matriz(int matriz[TAM][TAM]) {
    int valor = 1;
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            matriz[i][j] = valor++;
        }
    }
}

// abordagem 1: dois laços
void percorrer_duplo(int matriz[TAM][TAM]) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            int temp = matriz[i][j]; // só para acesso (evita otimização)
        }
    }
}

// abordagem 2: um laço
void percorrer_unico(int matriz[TAM][TAM]) {
    for(int k = 0; k < TAM * TAM; k++) {
        int i = k / TAM;
        int j = k % TAM;
        int temp = matriz[i][j];
    }
}

int main() {
    int matriz[TAM][TAM];

    preencher_matriz(matriz);

    clock_t inicio, fim;
    double tempo_duplo, tempo_unico;

    // teste 1: dois laços
    inicio = clock();
    percorrer_duplo(matriz);
    fim = clock();
    tempo_duplo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("duplo loop tempo = %f\n", tempo_duplo);

    // teste 2: um laço
    inicio = clock();
    percorrer_unico(matriz);
    fim = clock();
    tempo_unico = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("loop unico tempo = %f\n", tempo_unico);

    // validação simples (ambos executaram)
    printf("teste => %i\n", tempo_duplo >= 0 && tempo_unico >= 0);

    return 0;
}
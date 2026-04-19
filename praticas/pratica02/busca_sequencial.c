#include <stdio.h>

int busca_sequencial(int vetor[], int tamanho, int valor) {
    if(tamanho <= 0 || tamanho > 100) {
        return -1;
    }

    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] == valor) {
            return i; // retorna a posição onde encontrou
        }
    }

    return -1; // não encontrado
}

int main() {
    int posicao = -1;

    int vetor1[5] = {10, 20, 30, 40, 50};
    posicao = busca_sequencial(vetor1, 5, 10);
    printf("valor = 10, posicao = %i => %i\n", posicao, posicao == 0);

    int vetor2[5] = {10, 20, 30, 40, 50};
    posicao = busca_sequencial(vetor2, 5, 30);
    printf("valor = 30, posicao = %i => %i\n", posicao, posicao == 2);

    int vetor3[5] = {10, 20, 30, 40, 50};
    posicao = busca_sequencial(vetor3, 5, 50);
    printf("valor = 50, posicao = %i => %i\n", posicao, posicao == 4);

    int vetor4[5] = {10, 20, 30, 40, 50};
    posicao = busca_sequencial(vetor4, 5, 60);
    printf("valor = 60, posicao = %i => %i\n", posicao, posicao == -1);

    int vetor5[1] = {99};
    posicao = busca_sequencial(vetor5, 1, 99);
    printf("valor = 99, posicao = %i => %i\n", posicao, posicao == 0);

    posicao = busca_sequencial(vetor5, 101, 99);
    printf("tamanho = 101, posicao = %i => %i\n", posicao, posicao == -1);

    return 0;
}
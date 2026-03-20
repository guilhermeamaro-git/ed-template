#include <stdio.h>

// Função com a lógica do cálculo
float calcular_media(float soma, int n) {
    return (n > 0) ? (soma / n) : 0;
}

int main() {
    int n;
    float valor, soma_total = 0;

    printf("Quantos numeros (max 100)? ");
    scanf("%d", &n);

    // Validação simples
    if (n <= 0 || n > 100) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // Lendo e somando diretamente no main
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%f", &valor);
        soma_total += valor; // Acumula o valor na hora
    }

    // Exibe o resultado chamando a função de cálculo
    printf("\nMedia final: %.2f\n", calcular_media(soma_total, n));

    return 0;
}

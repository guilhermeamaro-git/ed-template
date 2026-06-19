#include <stdio.h>
#include "fila.h"

int main() {
    printf("--- Testando TDA Fila ---\n\n");

    // 1. Criar a fila
    Fila* minha_fila = fila_criar();
    if (minha_fila == NULL) {
        printf("Erro ao inicializar a fila.\n");
        return 1;
    }

    // 2. Verificar se está vazia
    printf("A fila esta vazia? %s\n", fila_esta_vazia(minha_fila) ? "Sim" : "Nao");

    // 3. Enfileirar elementos
    printf("\n>> Enfileirando os valores 10, 20 e 30...\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_exibir(minha_fila);

    // 4. Consultar o início
    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("\n>> Valor atualmente no inicio: %d\n", valor_inicio);
    }

    // 5. Desenfileirar elementos
    printf("\n>> Desenfileirando um elemento (removendo o 10)...\n");
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);

    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf(">> Novo valor no inicio: %d\n", valor_inicio);
    }

    // 6. Destruir a fila
    printf("\n>> Destruindo a fila e liberando memoria...\n");
    fila_destruir(minha_fila);
    printf("Fila liberada com sucesso.\n");

    return 0;
}
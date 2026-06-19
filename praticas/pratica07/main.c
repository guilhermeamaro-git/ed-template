#include <stdio.h>
#include "pilha.h"

int main() {
    printf("--- Testando TDA Pilha ---\n\n");

    // 1. Criar a pilha
    Pilha* minha_pilha = pilha_criar();
    if (minha_pilha == NULL) {
        printf("Erro ao inicializar a pilha.\n");
        return 1;
    }

    // 2. Verificar se está vazia
    printf("A pilha esta vazia? %s\n", pilha_esta_vazia(minha_pilha) ? "Sim" : "Nao");

    // 3. Empilhar elementos
    printf("\n>> Empilhando os valores 10, 20 e 30...\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_exibir(minha_pilha);

    // 4. Consultar o topo
    int valor_topo;
    if (pilha_topo(minha_pilha, &valor_topo)) {
        printf("\n>> Valor atualmente no topo: %d\n", valor_topo);
    }

    // 5. Desempilhar elementos
    printf("\n>> Desempilhando um elemento (removendo o 30)...\n");
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);

    if (pilha_topo(minha_pilha, &valor_topo)) {
        printf(">> Novo valor no topo: %d\n", valor_topo);
    }

    // 6. Destruir a pilha
    printf("\n>> Destruindo a pilha e liberando memoria...\n");
    pilha_destruir(minha_pilha);
    printf("Pilha liberada com sucesso.\n");

    return 0;
}
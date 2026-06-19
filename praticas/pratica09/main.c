#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    printf("--- Testando TDA Arvore Binaria ---\n\n");

    // 1. Criar a árvore
    Arvore* minha_arvore = arvore_criar();
    if (minha_arvore == NULL) {
        printf("Erro ao inicializar a arvore.\n");
        return 1;
    }

    // 2. Verificar se está vazia
    printf("A arvore esta vazia? %s\n\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");

    // 3. Inserir elementos (criando uma estrutura de teste)
    //        50
    //      /    \
    //    30      70
    //   /  \    /  \
    // 20   40  60   80
    printf(">> Inserindo os valores: 50, 30, 70, 20, 40, 60, 80...\n\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    // 4. Exibição nos diferentes percursos
    printf(">> Exibindo os percursos da arvore:\n");
    arvore_exibir_pre_ordem(minha_arvore);
    arvore_exibir_em_ordem(minha_arvore); // Na BST, a "Em-ordem" imprime de forma ordenada crescente
    arvore_exibir_pos_ordem(minha_arvore);

    // 5. Destruir a árvore
    printf("\n>> Destruindo a arvore e liberando memoria...\n");
    arvore_destruir(minha_arvore);
    printf("Arvore liberada com sucesso.\n");

    return 0;
}
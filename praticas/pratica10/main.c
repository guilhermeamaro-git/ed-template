#include <stdio.h>
#include "tabela_hash.h"

int main() {
    printf("--- Testando TDA Tabela Hash ---\n\n");

    // 1. Criar a tabela (Tamanho 7 - usar números primos reduz colisões)
    TabelaHash* minha_hash = hash_criar(7);
    if (minha_hash == NULL) {
        printf("Erro ao inicializar a tabela hash.\n");
        return 1;
    }

    // 2. Verificar se está vazia
    printf("A tabela esta vazia? %s\n", hash_esta_vazia(minha_hash) ? "Sim" : "Nao");

    // 3. Inserir elementos (Vamos forçar colisões para testar o encadeamento)
    // Valores escolhidos:
    // 10 % 7 = 3
    // 20 % 7 = 6
    // 15 % 7 = 1
    // 7 % 7 = 0
    // 14 % 7 = 0 (Colisão com o 7)
    // 21 % 7 = 0 (Colisão com o 7 e 14)
    printf("\n>> Inserindo os valores 10, 20, 15, 7, 14 e 21...\n\n");
    hash_inserir(minha_hash, 10);
    hash_inserir(minha_hash, 20);
    hash_inserir(minha_hash, 15);
    hash_inserir(minha_hash, 7);
    hash_inserir(minha_hash, 14); 
    hash_inserir(minha_hash, 21); 

    hash_exibir(minha_hash);

    // 4. Buscar elementos
    printf("\n>> Buscando o valor 14: %s\n", hash_buscar(minha_hash, 14) ? "Encontrado" : "Nao encontrado");
    printf(">> Buscando o valor 99: %s\n", hash_buscar(minha_hash, 99) ? "Encontrado" : "Nao encontrado");

    // 5. Remover elementos
    printf("\n>> Removendo o valor 14 (que esta no meio de uma colisao no indice 0)...\n\n");
    hash_remover(minha_hash, 14);
    hash_exibir(minha_hash);

    printf("\n>> Removendo o valor 15 (indice 1)...\n\n");
    hash_remover(minha_hash, 15);
    hash_exibir(minha_hash);

    // 6. Destruir a tabela
    printf("\n>> Destruindo a tabela hash e liberando memoria...\n");
    hash_destruir(minha_hash);
    printf("Tabela hash liberada com sucesso.\n");

    return 0;
}
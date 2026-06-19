#include <stdio.h>
#include "lista_linear.h"

int main()
{
    printf("--- Testando TDA Lista Linear ---\n\n");

    // 1. Criar a lista
    Lista *minha_lista = lista_criar();
    if (minha_lista == NULL)
    {
        printf("Erro ao inicializar a lista.\n");
        return 1;
    }

    // 2. Verificar se está vazia
    printf("A lista esta vazia? %s\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");

    // 3. Inserir elementos
    printf("\n>> Inserindo os valores 10, 25 e 40...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 25);
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista);

    // 4. Buscar elementos
    printf("\n>> Buscando o valor 25: %s\n", lista_buscar(minha_lista, 25) ? "Encontrado" : "Nao encontrado");
    printf(">> Buscando o valor 99: %s\n", lista_buscar(minha_lista, 99) ? "Encontrado" : "Nao encontrado");

    // 5. Remover elementos
    printf("\n>> Removendo o valor 25...\n");
    lista_remover(minha_lista, 25);
    lista_exibir(minha_lista);

    printf(">> Removendo o valor 10 (primeiro elemento)...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    // 6. Destruir a lista para evitar vazamento de memória (Memory Leak)
    printf("\n>> Destruindo a lista...\n");
    lista_destruir(minha_lista);
    printf("Lista liberada com sucesso.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Definição do nó da lista (struct interna)
typedef struct no_t
{
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} No;

// Definição da estrutura principal da lista (struct interna)
struct lista_t
{
    No *primeiro;
    No *ultimo;
};

// Cria uma lista vazia
Lista *lista_criar(void)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    }
    return lista;
}

// Verifica se a lista está vazia
bool lista_esta_vazia(Lista *lista)
{
    if (lista == NULL)
        return true;
    return lista->primeiro == NULL;
}

// Insere um elemento no final da lista
bool lista_inserir(Lista *lista, int valor)
{
    if (lista == NULL)
        return false;

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return false; // Falha na alocação

    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (lista_esta_vazia(lista))
    {
        // Se for o primeiro elemento
        novo_no->anterior = NULL;
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
    }
    else
    {
        // Insere no fim e atualiza ponteiros
        novo_no->anterior = lista->ultimo;
        lista->ultimo->proximo = novo_no;
        lista->ultimo = novo_no;
    }
    return true;
}

// Remove a primeira ocorrência do valor na lista
bool lista_remover(Lista *lista, int valor)
{
    if (lista == NULL || lista_esta_vazia(lista))
        return false;

    No *atual = lista->primeiro;

    // Procura o valor
    while (atual != NULL && atual->valor != valor)
    {
        atual = atual->proximo;
    }

    // Se não encontrou
    if (atual == NULL)
        return false;

    // Reajusta os ponteiros do nó anterior
    if (atual->anterior != NULL)
    {
        atual->anterior->proximo = atual->proximo;
    }
    else
    {
        // O nó a ser removido é o primeiro
        lista->primeiro = atual->proximo;
    }

    // Reajusta os ponteiros do nó próximo
    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = atual->anterior;
    }
    else
    {
        // O nó a ser removido é o último
        lista->ultimo = atual->anterior;
    }

    free(atual);
    return true;
}

// Busca um valor na lista (retorna true se encontrar)
bool lista_buscar(Lista *lista, int valor)
{
    if (lista == NULL || lista_esta_vazia(lista))
        return false;

    No *atual = lista->primeiro;
    while (atual != NULL)
    {
        if (atual->valor == valor)
            return true;
        atual = atual->proximo;
    }
    return false;
}

// Exibe todos os elementos da lista
void lista_exibir(Lista *lista)
{
    if (lista == NULL || lista_esta_vazia(lista))
    {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->primeiro;
    printf("[ ");
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

// Libera toda a memória alocada para a lista e seus nós
void lista_destruir(Lista *lista)
{
    if (lista != NULL)
    {
        No *atual = lista->primeiro;
        while (atual != NULL)
        {
            No *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(lista);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Definição do nó da pilha (struct interna)
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

// Definição da estrutura principal da pilha (struct interna)
struct pilha_t {
    No* topo;
};

// Cria uma pilha vazia
Pilha* pilha_criar(void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

// Verifica se a pilha está vazia
bool pilha_esta_vazia(Pilha* p) {
    if (p == NULL) return true;
    return p->topo == NULL;
}

// Insere um elemento no topo da pilha (Push)
bool pilha_empilhar(Pilha* p, int valor) {
    if (p == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return false; // Falha na alocação

    novo_no->valor = valor;
    novo_no->proximo = p->topo; // O próximo do novo nó é o antigo topo
    p->topo = novo_no;          // O novo nó passa a ser o topo

    return true;
}

// Remove o elemento do topo da pilha (Pop)
bool pilha_desempilhar(Pilha* p) {
    if (p == NULL || pilha_esta_vazia(p)) return false;

    No* no_removido = p->topo;
    p->topo = no_removido->proximo; // O topo passa a ser o elemento de baixo
    
    free(no_removido);
    return true;
}

// Consulta o valor no topo da pilha sem removê-lo (Peek)
bool pilha_topo(Pilha* p, int* valor_topo) {
    if (p == NULL || pilha_esta_vazia(p)) return false;

    *valor_topo = p->topo->valor;
    return true;
}

// Exibe todos os elementos da pilha (do topo para a base)
void pilha_exibir(Pilha* p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    No* atual = p->topo;
    printf("Topo -> [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

// Libera toda a memória alocada para a pilha e seus nós
void pilha_destruir(Pilha* p) {
    if (p != NULL) {
        No* atual = p->topo;
        while (atual != NULL) {
            No* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(p);
    }
}
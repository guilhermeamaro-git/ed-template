#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Definição do nó da fila (struct interna)
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

// Definição da estrutura principal da fila (struct interna)
struct fila_t {
    No* inicio;
    No* fim;
};

// Cria uma fila vazia
Fila* fila_criar(void) {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

// Verifica se a fila está vazia
bool fila_esta_vazia(Fila* f) {
    if (f == NULL) return true;
    return f->inicio == NULL;
}

// Insere um elemento no final da fila (Enqueue)
bool fila_enfileirar(Fila* f, int valor) {
    if (f == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return false; // Falha na alocação

    novo_no->valor = valor;
    novo_no->proximo = NULL; // O novo nó sempre será o último, logo aponta para NULL

    if (fila_esta_vazia(f)) {
        // Se a fila estava vazia, o novo nó é o início e o fim
        f->inicio = novo_no;
    } else {
        // O elemento que era o fim passa a apontar para o novo nó
        f->fim->proximo = novo_no;
    }
    
    // Atualiza o ponteiro de fim da fila
    f->fim = novo_no;

    return true;
}

// Remove o elemento do início da fila (Dequeue)
bool fila_desenfileirar(Fila* f) {
    if (f == NULL || fila_esta_vazia(f)) return false;

    No* no_removido = f->inicio;
    f->inicio = no_removido->proximo; // O novo início é o próximo nó

    // Se a fila ficou vazia após a remoção, o ponteiro 'fim' também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(no_removido);
    return true;
}

// Consulta o valor no início da fila sem removê-lo
bool fila_inicio(Fila* f, int* valor_inicio) {
    if (f == NULL || fila_esta_vazia(f)) return false;

    *valor_inicio = f->inicio->valor;
    return true;
}

// Exibe todos os elementos da fila
void fila_exibir(Fila* f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    No* atual = f->inicio;
    printf("Inicio -> [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("] <- Fim\n");
}

// Libera toda a memória alocada para a fila e seus nós
void fila_destruir(Fila* f) {
    if (f != NULL) {
        No* atual = f->inicio;
        while (atual != NULL) {
            No* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(f);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Definição do nó da árvore (struct interna)
typedef struct no_t {
    struct no_t* esquerda;
    int valor;
    struct no_t* direita;
} No;

// Definição da estrutura principal da árvore (struct interna)
struct arvore_t {
    No* raiz;
};

// Cria uma árvore vazia
Arvore* arvore_criar(void) {
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

// Verifica se a árvore está vazia
bool arvore_esta_vazia(Arvore* arvore) {
    if (arvore == NULL) return true;
    return arvore->raiz == NULL;
}

// Função auxiliar recursiva para inserir um nó (Lógica de Árvore Binária de Busca)
static No* inserir_no(No* raiz, int valor, bool* inseriu) {
    // Se chegou em um espaço vazio, cria o nó aqui
    if (raiz == NULL) {
        No* novo_no = (No*) malloc(sizeof(No));
        if (novo_no != NULL) {
            novo_no->valor = valor;
            novo_no->esquerda = NULL;
            novo_no->direita = NULL;
            *inseriu = true;
            return novo_no;
        }
        *inseriu = false;
        return NULL;
    }

    // Se o valor for menor, vai para a esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor, inseriu);
    } 
    // Se o valor for maior, vai para a direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor, inseriu);
    } 
    // Se for igual, não insere (evita duplicatas nesta implementação)
    else {
        *inseriu = false; 
    }

    return raiz;
}

// Insere um elemento na árvore
bool arvore_inserir(Arvore* arvore, int valor) {
    if (arvore == NULL) return false;
    
    bool inseriu = false;
    arvore->raiz = inserir_no(arvore->raiz, valor, &inseriu);
    return inseriu;
}

// --- Funções Auxiliares de Percurso ---

static void exibir_pre_ordem_no(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);         // Raiz
        exibir_pre_ordem_no(raiz->esquerda);  // Esquerda
        exibir_pre_ordem_no(raiz->direita);   // Direita
    }
}

static void exibir_em_ordem_no(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem_no(raiz->esquerda);   // Esquerda
        printf("%d ", raiz->valor);         // Raiz
        exibir_em_ordem_no(raiz->direita);    // Direita
    }
}

static void exibir_pos_ordem_no(No* raiz) {
    if (raiz != NULL) {
        exibir_pos_ordem_no(raiz->esquerda);  // Esquerda
        exibir_pos_ordem_no(raiz->direita);   // Direita
        printf("%d ", raiz->valor);         // Raiz
    }
}

// --- Chamadas Principais de Percurso ---

void arvore_exibir_pre_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pre-ordem: [ ");
    exibir_pre_ordem_no(arvore->raiz);
    printf("]\n");
}

void arvore_exibir_em_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Em-ordem:  [ ");
    exibir_em_ordem_no(arvore->raiz);
    printf("]\n");
}

void arvore_exibir_pos_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pos-ordem: [ ");
    exibir_pos_ordem_no(arvore->raiz);
    printf("]\n");
}

// Função auxiliar recursiva para liberar a memória
static void destruir_no(No* raiz) {
    if (raiz != NULL) {
        destruir_no(raiz->esquerda);
        destruir_no(raiz->direita);
        free(raiz);
    }
}

// Libera a memória da árvore
void arvore_destruir(Arvore* arvore) {
    if (arvore != NULL) {
        destruir_no(arvore->raiz);
        free(arvore);
    }
}
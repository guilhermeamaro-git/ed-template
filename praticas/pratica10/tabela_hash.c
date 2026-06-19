#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Definição do nó para lidar com colisões (lista encadeada)
typedef struct no_t {
    int valor;
    struct no_t* proximo;
} No;

// Definição da estrutura principal da Tabela Hash
struct hash_t {
    No** tabela;  // Vetor de ponteiros para os nós (início das listas)
    int tamanho;
};

// --- Função Hash Interna (Espalhamento) ---
// Retorna o índice no vetor garantindo que seja um valor positivo
static int funcao_hash(int valor, int tamanho) {
    int hash = valor % tamanho;
    return (hash < 0) ? hash + tamanho : hash;
}

// Cria e inicializa a tabela hash
TabelaHash* hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    TabelaHash* th = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (th != NULL) {
        th->tamanho = tamanho;
        // calloc já inicializa todos os ponteiros do vetor com NULL
        th->tabela = (No**) calloc(tamanho, sizeof(No*)); 
        
        if (th->tabela == NULL) { // Falha na alocação do vetor
            free(th);
            return NULL;
        }
    }
    return th;
}

// Verifica se a tabela inteira está vazia
bool hash_esta_vazia(TabelaHash* th) {
    if (th == NULL) return true;

    for (int i = 0; i < th->tamanho; i++) {
        if (th->tabela[i] != NULL) {
            return false; // Encontrou pelo menos um elemento
        }
    }
    return true;
}

// Insere um valor na tabela hash
bool hash_inserir(TabelaHash* th, int valor) {
    if (th == NULL) return false;

    int indice = funcao_hash(valor, th->tamanho);

    // Verifica se o valor já existe para evitar duplicatas (opcional, mas recomendado)
    No* atual = th->tabela[indice];
    while (atual != NULL) {
        if (atual->valor == valor) return false; // Valor já existe
        atual = atual->proximo;
    }

    // Cria o novo nó
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return false;

    novo_no->valor = valor;
    // Insere no início da lista encadeada daquele índice
    novo_no->proximo = th->tabela[indice]; 
    th->tabela[indice] = novo_no;

    return true;
}

// Busca um valor na tabela hash
bool hash_buscar(TabelaHash* th, int valor) {
    if (th == NULL) return false;

    int indice = funcao_hash(valor, th->tamanho);
    No* atual = th->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) return true;
        atual = atual->proximo;
    }

    return false;
}

// Remove um valor da tabela hash
bool hash_remover(TabelaHash* th, int valor) {
    if (th == NULL) return false;

    int indice = funcao_hash(valor, th->tamanho);
    No* atual = th->tabela[indice];
    No* anterior = NULL;

    // Procura o elemento na lista encadeada do índice
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se não encontrou
    if (atual == NULL) return false;

    // Se o elemento a ser removido é o primeiro da lista
    if (anterior == NULL) {
        th->tabela[indice] = atual->proximo;
    } else {
        // O elemento está no meio ou no fim da lista
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return true;
}

// Exibe a estrutura interna da tabela hash
void hash_exibir(TabelaHash* th) {
    if (th == NULL) return;

    for (int i = 0; i < th->tamanho; i++) {
        printf("[%2d]: ", i);
        No* atual = th->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Libera toda a memória alocada
void hash_destruir(TabelaHash* th) {
    if (th != NULL) {
        for (int i = 0; i < th->tamanho; i++) {
            No* atual = th->tabela[i];
            while (atual != NULL) {
                No* proximo = atual->proximo;
                free(atual);
                atual = proximo;
            }
        }
        free(th->tabela);
        free(th);
    }
}
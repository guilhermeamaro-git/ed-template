#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

// Definição do tipo opaco da Pilha
typedef struct pilha_t Pilha;

// Protótipos das funções do TDA
Pilha* pilha_criar(void);
bool pilha_empilhar(Pilha* p, int valor);
bool pilha_desempilhar(Pilha* p);
bool pilha_topo(Pilha* p, int* valor_topo);
bool pilha_esta_vazia(Pilha* p);
void pilha_exibir(Pilha* p);
void pilha_destruir(Pilha* p);

#endif // PILHA_H
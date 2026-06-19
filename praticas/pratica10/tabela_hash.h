#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdbool.h>

// Definição do tipo opaco da Tabela Hash
typedef struct hash_t TabelaHash;

// Protótipos das funções do TDA
TabelaHash* hash_criar(int tamanho);
bool hash_inserir(TabelaHash* th, int valor);
bool hash_buscar(TabelaHash* th, int valor);
bool hash_remover(TabelaHash* th, int valor);
void hash_exibir(TabelaHash* th);
bool hash_esta_vazia(TabelaHash* th);
void hash_destruir(TabelaHash* th);

#endif // TABELA_HASH_H
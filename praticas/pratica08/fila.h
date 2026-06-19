#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

// Definição do tipo opaco da Fila
typedef struct fila_t Fila;

// Protótipos das funções do TDA
Fila* fila_criar(void);
bool fila_enfileirar(Fila* f, int valor);
bool fila_desenfileirar(Fila* f);
bool fila_inicio(Fila* f, int* valor_inicio);
void fila_exibir(Fila* f); 
bool fila_esta_vazia(Fila* f);
void fila_destruir(Fila* f);

#endif // FILA_H
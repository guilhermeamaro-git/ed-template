#ifndef SELECAO_H
#define SELECAO_H

// Retorna o índice do elemento ou -1 se não encontrar
int linear_search(int v[], int n, int alvo);

// Retorna o k-ésimo menor elemento (k começa em 0)
int quick_select(int v[], int baixo, int alto, int k);

#endif
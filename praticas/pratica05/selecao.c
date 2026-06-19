#include "selecao.h"

// Função auxiliar para trocar valores
void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Busca Linear: Simples e direta
int linear_search(int v[], int n, int alvo)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == alvo)
            return i; // Encontrou!
    }
    return -1; // Não encontrado
}

// Particionamento (Lógica central do Quick Select)
int particionar(int v[], int baixo, int alto)
{
    int pivo = v[alto];
    int i = baixo;
    for (int j = baixo; j < alto; j++)
    {
        if (v[j] <= pivo)
        {
            trocar(&v[i], &v[j]);
            i++;
        }
    }
    trocar(&v[i], &v[alto]);
    return i;
}

// Quick Select: Encontra o k-ésimo menor sem ordenar tudo
int quick_select(int v[], int baixo, int alto, int k)
{
    if (k > 0 && k <= alto - baixo + 1)
    {
        int indice_pivo = particionar(v, baixo, alto);

        // Se o pivô for a posição k que queremos
        if (indice_pivo - baixo == k - 1)
            return v[indice_pivo];

        // Se k for menor, procura na esquerda
        if (indice_pivo - baixo > k - 1)
            return quick_select(v, baixo, indice_pivo - 1, k);

        // Caso contrário, procura na direita
        return quick_select(v, indice_pivo + 1, alto, k - (indice_pivo - baixo + 1));
    }
    return -1;
}
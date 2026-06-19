#include "ordenacao.h"

// Troca dois elementos de posição
void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                trocar(&v[j], &v[j + 1]);
            }
        }
    }
}

void selection_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_idx])
                min_idx = j;
        }
        trocar(&v[min_idx], &v[i]);
    }
}

void quick_sort(int v[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pivo = v[alto];
        int i = (baixo - 1);
        for (int j = baixo; j < alto; j++)
        {
            if (v[j] < pivo)
            {
                i++;
                trocar(&v[i], &v[j]);
            }
        }
        trocar(&v[i + 1], &v[alto]);
        int pi = i + 1;

        quick_sort(v, baixo, pi - 1);
        quick_sort(v, pi + 1, alto);
    }
}
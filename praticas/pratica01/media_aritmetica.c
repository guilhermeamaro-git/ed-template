#include <stdio.h>

float calcular_media_aritmetica(float numeros[], int n)
{
    if (n <= 0 || n > 100)
    {
        return 0.0f;
    }

    float soma = 0.0f;

    for (int i = 0; i < n; i++)
    {
        soma += numeros[i];
    }

    return soma / n;
}

int main()
{
    float media = 0.0f;

    float teste1[] = {10.0f, 20.0f, 30.0f};
    media = calcular_media_aritmetica(teste1, 3);
    printf("n = 3, media = %.1f => %i\n", media, media == 20);

    float teste2[] = {5.0f, 5.0f, 5.0f};
    media = calcular_media_aritmetica(teste2, 3);
    printf("n = 3, media = %.1f => %i\n", media, media == 5);

    float teste3[] = {2.0f, 4.0f, 6.0f, 8.0f};
    media = calcular_media_aritmetica(teste3, 4);
    printf("n = 4, media = %.1f => %i\n", media, media == 5);

    float teste4[] = {0.0f, 0.0f, 0.0f};
    media = calcular_media_aritmetica(teste4, 3);
    printf("n = 3, media = %.1f => %i\n", media, media == 0);

    float teste5[] = {10.0f};
    media = calcular_media_aritmetica(teste5, 1);
    printf("n = 1, media = %.1f => %i\n", media, media == 10);

    float teste6[] = {10.0f, 20.0f};
    media = calcular_media_aritmetica(teste6, 101);
    printf("n = 101, media = %.1f => %i\n", media, media == 0);

    return 0;
}
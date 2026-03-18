#include <stdio.h>

int calcular_notas(int valor)
{
    if (valor <= 0 || valor > 1000)
    {
        return 0;
    }

    int n200 = 0;
    int n100 = 0;
    int n50 = 0;
    int n20 = 0;
    int n10 = 0;
    int n5 = 0;
    int n2 = 0;

    n200 = valor / 200;
    valor %= 200;

    n100 = valor / 100;
    valor %= 100;

    n50 = valor / 50;
    valor %= 50;

    n20 = valor / 20;
    valor %= 20;

    n10 = valor / 10;
    valor %= 10;

    n5 = valor / 5;
    valor %= 5;

    n2 = valor / 2;
    valor %= 2;

    if (valor != 0)
    {
        return 0;
    }

    return n200 + n100 + n50 + n20 + n10 + n5 + n2;
}

int main()
{
    int notas = 0;

    notas = calcular_notas(0);
    printf("saque = 0, notas = %i => %i\n", notas, notas == 0);

    notas = calcular_notas(1001);
    printf("saque = 1001, notas = %i => %i\n", notas, notas == 0);

    notas = calcular_notas(200);
    printf("saque = 200, notas = %i => %i\n", notas, notas == 1);

    notas = calcular_notas(300);
    printf("saque = 300, notas = %i => %i\n", notas, notas == 2);

    notas = calcular_notas(380);
    printf("saque = 380, notas = %i => %i\n", notas, notas == 5);

    notas = calcular_notas(386);
    printf("saque = 386, notas = %i => %i\n", notas, notas == 0);

    return 0;
}
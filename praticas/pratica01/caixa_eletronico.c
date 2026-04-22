#include <stdio.h>

int calcular_notas(int valor)
{

    if (valor <= 0 || valor > 1000)
    {
        return 0;
    }

    int n200, n100, n50, n20, n10, n5, n2;
    int resto = valor;

    n200 = resto / 200;
    resto %= 200;

    n100 = resto / 100;
    resto %= 100;

    n50 = resto / 50;
    resto %= 50;

    n20 = resto / 20;
    resto %= 20;

    n10 = resto / 10;
    resto %= 10;

    n5 = resto / 5;
    resto %= 5;

    n2 = resto / 2;
    resto %= 2;

    if (resto != 0)
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

    notas = calcular_notas(380);
    printf("saque = 380, notas = %i => %i\n", notas, notas == 5);

    return 0;
}
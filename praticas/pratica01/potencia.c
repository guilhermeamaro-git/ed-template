#include <stdio.h>

float calcular_potencia(float base, int expoente) {
    if(expoente < 0) {
        return 0.0f;
    }

    float resultado = 1.0f;

    for(int i = 0; i < expoente; i++) {
        resultado = base * resultado;
    }

    return resultado;
}

int main() {
    float resultado = 0.0f;

    resultado = calcular_potencia(2.0f, -1);
    printf("base = 2, expoente = -1, resultado = %.1f => %i\n", resultado, resultado == 0);

    resultado = calcular_potencia(2.0f, 0);
    printf("base = 2, expoente = 0, resultado = %.1f => %i\n", resultado, resultado == 1);

    resultado = calcular_potencia(2.0f, 3);
    printf("base = 2, expoente = 3, resultado = %.1f => %i\n", resultado, resultado == 8);

    resultado = calcular_potencia(5.0f, 2);
    printf("base = 5, expoente = 2, resultado = %.1f => %i\n", resultado, resultado == 25);

    resultado = calcular_potencia(10.0f, 1);
    printf("base = 10, expoente = 1, resultado = %.1f => %i\n", resultado, resultado == 10);

    return 0;
}


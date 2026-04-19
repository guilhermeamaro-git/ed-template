#include <stdio.h>

long fatorial(int valor) {
    if(valor <= 1){
        return 1;
    }else {
        return valor * fatorial(valor - 1);
    }
}

int main() {
    int teste = 4;

    long n;
    
    // Testando com recursividade
    n = fatorial(teste); 

    printf("O fatorial de %d e: %ld", teste, n);

    return 0;
}


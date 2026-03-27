#include <stdio.h>

int main() {

    int teste = 6;
    
    long n = 1;
    for(int i = teste; i > 1; i--){
        n = n * i;
    } 

    printf("O fatorial de %d e: %ld",teste, n);

    return 0;
}


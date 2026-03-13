#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso em (Kg): ");
    scanf("%f", peso);
    
    if(peso <= 0){
        printf("Peso invalido, digite um valor positivo");
        return 0;
    }

    printf("Digite a altura em (M): ");
    scanf("%f",altura);

    if(altura <= 0){
        printf("Altura invalida, digite um valor positivo");
        return 0;
    }

    imc = peso / (altura * altura); 

    if(imc < 18.5) {
        printf("Abaixo do peso");
    }else if(imc >= 18.5 && imc < 25){
        printf("Peso normal");
    }else if(imc >= 25.0 && imc < 30){
        printf("Sobrepeso");
    }else{
        printf("Obesidade");
    }

    printf("O imc e: %.2f\n", imc);

    return 0;
}
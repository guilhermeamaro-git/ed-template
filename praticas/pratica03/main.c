#include <stdio.h>
#include "conta.h"

int main()
{
    Conta *minha_conta = conta_criar(1234);

    conta_depositar(minha_conta, 500.0);
    printf("Saldo apos deposito: %.2f\n", conta_ver_saldo(minha_conta));

    if (conta_sacar(minha_conta, 200.0))
    {
        printf("Saque realizado com sucesso!\n");
    }
    else
    {
        printf("Erro no saque.\n");
    }

    printf("Saldo atual: %.2f\n", conta_ver_saldo(minha_conta));

    conta_destruir(minha_conta);

    return 0;
}
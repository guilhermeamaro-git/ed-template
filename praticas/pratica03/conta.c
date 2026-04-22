#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

// Definição interna da struct
struct conta
{
    int numero;
    float saldo;
};

// Criar conta
Conta *conta_criar(int numero)
{
    Conta *c = (Conta *)malloc(sizeof(Conta));
    if (c != NULL)
    {
        c->numero = numero;
        c->saldo = 0.0;
    }
    return c;
}

// Depositar
void conta_depositar(Conta *c, float valor)
{
    if (c != NULL && valor > 0)
    {
        c->saldo += valor;
    }
}

// Sacar
int conta_sacar(Conta *c, float valor)
{
    if (c != NULL && valor > 0 && c->saldo >= valor)
    {
        c->saldo -= valor;
        return 1; // sucesso
    }
    return 0; // falha
}

// Ver saldo
float conta_ver_saldo(Conta *c)
{
    if (c != NULL)
    {
        return c->saldo;
    }
    return 0.0;
}

// Destruir conta
void conta_destruir(Conta *c)
{
    free(c);
}
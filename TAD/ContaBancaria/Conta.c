#include <stdio.h>
#include <stdlib.h>
#include "Conta.h"

struct conta {
    int num;
    double saldo;
};

Conta* criarConta(int num, double saldo) {
    Conta* novaConta = (Conta*)malloc(sizeof(Conta));
    if (novaConta != NULL) {
        novaConta->num = num;
        novaConta->saldo = saldo;
    }
    return novaConta;
}

int depositar(Conta *conta, double valor) {
    if (valor > 0) {
        conta->saldo += valor;
        return SUCCESS;
    } else {
       return ERROR;
    }
}

int sacar(Conta *conta, double valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
      return SUCCESS;
    } else  {
       return ERROR;
    }
}

int transferir(Conta *origem, Conta *destino, double valor) {
    if (valor > 0 && valor <= origem->saldo) {
        origem->saldo -= valor;
        destino->saldo += valor;
        return SUCCESS;
    } else return ERROR;
}

int obterNum(Conta *conta)
{
    if (conta!=NULL)
        return conta->num;
}

double obterSaldo(Conta * conta)
{
    if (conta!=NULL)
        return conta->saldo;
}

void liberarConta(Conta *conta)
{
    free(conta);
}

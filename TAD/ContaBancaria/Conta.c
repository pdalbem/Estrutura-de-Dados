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

void depositar(Conta *conta, double valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Deposito de R$%.2f realizado com sucesso!\n", valor);
    } else {
        printf("Valor de depósito inválido!\n");
    }
}

void sacar(Conta *conta, double valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso!\n", valor);
    } else if (valor <= 0) {
        printf("Valor de saque inválido!\n");
    } else {
        printf("Saldo insuficiente para saque!\n");
    }
}

void transferir(Conta *origem, Conta *destino, double valor) {
    if (valor > 0 && valor <= origem->saldo) {
        origem->saldo -= valor;
        destino->saldo += valor;
        printf("Transferência de R$%.2f realizada com sucesso!\n", valor);
    } else if (valor <= 0) {
        printf("Valor de transferência inválido!\n");
    } else {
        printf("Saldo insuficiente para transferência!\n");
    }
}

void exibirConta(Conta *conta) {
    printf("Conta nº %d\n", conta->num);
    printf("Saldo: R$%.2f\n", conta->saldo);
}

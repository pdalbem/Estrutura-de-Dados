#include <stdio.h>
#include "Conta.h"

int main() {
    Conta* conta1 = criarConta(1234, 500.00);  
    Conta* conta2 = criarConta(5678, 1000.00); 

    printf("Informações da Conta 1:\n");
    exibirConta(conta1);
    printf("\n");

    printf("Informações da Conta 2:\n");
    exibirConta(conta2);
    printf("\n");

    depositar(conta1, 200.00); 
    depositar(conta2, 150.00); 

    printf("Informações da Conta 1 após depósito:\n");
    exibirConta(conta1);
    printf("\n");

    printf("Informações da Conta 2 após depósito:\n");
    exibirConta(conta2);
    printf("\n");

 
    sacar(conta1, 100.00);  
    sacar(conta2, 50.00);   

    printf("Informações da Conta 1 após saque:\n");
    exibirConta(conta1);
    printf("\n");

    printf("Informações da Conta 2 após saque:\n");
    exibirConta(conta2);
    printf("\n");


    transferir(conta1, conta2, 150.00); 

    printf("Informações da Conta 1 após transferência:\n");
    exibirConta(conta1);
    printf("\n");

    printf("Informações da Conta 2 após transferência:\n");
    exibirConta(conta2);
    printf("\n");

    free(conta1);
    free(conta2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "Conta.h"

int main() {
    Conta* conta1 = criarConta(1234, 500.00);  
    Conta* conta2 = criarConta(5678, 1000.00); 

    printf("Saldo da Conta 1: %.2f \n", obterSaldo(conta1));

    printf("Saldo da Conta 2: %.2f \n", obterSaldo(conta2));
  

    if (depositar(conta1, 200.00))
        printf("Depósito efetuado com sucesso\n");

    if (depositar(conta2, 150.00))
        printf("Depósito efetuado com sucesso\n"); 

    printf("Saldo da Conta 1: %.2f \n", obterSaldo(conta1));

    printf("Saldo da Conta 2: %.2f \n", obterSaldo(conta2));
 
    sacar(conta1, 100.00);  
    sacar(conta2, 50.00);   

    printf("Saldo da Conta 1: %.2f \n", obterSaldo(conta1));

    printf("Saldo da Conta 2: %.2f \n", obterSaldo(conta2));


    transferir(conta1, conta2, 150.00); 

    printf("Saldo da Conta 1: %.2f \n", obterSaldo(conta1));

    printf("Saldo da Conta 2: %.2f \n", obterSaldo(conta2));

    liberarConta(conta1);
    liberarConta(conta2);

    return 0;
}

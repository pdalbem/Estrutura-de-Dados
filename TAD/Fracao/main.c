#include <stdlib.h>
#include <stdio.h>
#include "Fracao.h"

int main()
{
    Fracao *f1 = criarFracao(3, 4); 
    Fracao *f2 = criarFracao(1, 2); 
    
    printf("Fração 1 (f1): %d/%d \n", obterNumerador(f1),obterDenominador(f1));
    printf("Fração 2 (f2): %d/%d \n", obterNumerador(f2),obterDenominador(f2));
  
    Fracao *soma = somarFracao(f1, f2);
    simplificarFracao(soma);
    printf("Resultado de f1+f2: %d/%d \n", obterNumerador(soma),obterDenominador(soma));

  
    Fracao *subtracao = subtrairFracao(f1, f2);
    simplificarFracao(subtracao);
    printf("Resultado de f1-f2: %d/%d \n", obterNumerador(subtracao),obterDenominador(subtracao));

    Fracao *mult = multiplicarFracao(f1, f2);
    simplificarFracao(mult);
    printf("Resultado de f1*f2: %d/%d \n", obterNumerador(mult),obterDenominador(mult));

    Fracao *divisao = dividirFracao(f1, f2);
    simplificarFracao(divisao);
    printf("Resultado de f1/f2: %d/%d \n", obterNumerador(divisao),obterDenominador(divisao));


    int resultado_comparacao = compararFracao(f1, f2);
    printf("\nComparando as frações f1 e f2: ");
    if (resultado_comparacao == 1) 
        printf("f1 é maior que f2");
        else if (resultado_comparacao == -1) 
               printf("f2 é maior que f1");
                else 
                  printf("f1 e f2 são iguais");

     printf("\n");

    printf("\nf1 como decimal: %.2f", converterParaDecimal(f1));
    printf("\nf2 como decimal: %.2f", converterParaDecimal(f2));
    printf("\n");

    free(f1);
    free(f2);
    free(soma);
    free(subtracao);
    free(mult);
    free(divisao);

    return 0;
}
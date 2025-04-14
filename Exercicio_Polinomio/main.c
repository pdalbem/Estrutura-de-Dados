#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polinomio.h"

int main(){
    Polinomio *polinomio=criarPolinomio();
    inserirTermo(polinomio,3,5);
    inserirTermo(polinomio,6,2);
    inserirTermo(polinomio,1,0);
    printf("Polinômio 1: ");
    mostrarPolinomio(polinomio);

    printf("Resultado para x=2: %.2f\n", avaliarPolinomio(polinomio,2));

    liberarPolinomio(polinomio);

    printf("\n");
    polinomio=criarPolinomio();
    inserirTermo(polinomio,3,2);
    inserirTermo(polinomio,4,1);
    inserirTermo(polinomio,-5,0);

    printf("Polinômio 2: ");
    mostrarPolinomio(polinomio);

    printf("Resultado para x=3: %.2f\n", avaliarPolinomio(polinomio,3));
    return 0;
}
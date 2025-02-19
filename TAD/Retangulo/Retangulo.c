#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"


struct retangulo {
    double altura;
    double largura;
};


Retangulo* criarRetangulo(double altura, double largura) {
    Retangulo* novoRetangulo = (Retangulo*)malloc(sizeof(Retangulo));
    if (novoRetangulo != NULL) {
        novoRetangulo->altura = altura;
        novoRetangulo->largura = largura;
    }
    return novoRetangulo;
}


double calcularArea(Retangulo* retangulo) {
    return retangulo->altura * retangulo->largura;
}


double calcularPerimetro(Retangulo* retangulo) {
    return 2 * (retangulo->altura + retangulo->largura);
}

void exibirRetangulo(Retangulo* retangulo) {
    printf("Retângulo:\n");
    printf("Altura: %.2f\n", retangulo->altura);
    printf("Largura: %.2f\n", retangulo->largura);
    printf("Área: %.2f\n", calcularArea(retangulo));
    printf("Perímetro: %.2f\n", calcularPerimetro(retangulo));
}

#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

int main() {

    Retangulo* retangulo1 = criarRetangulo(5.0, 3.0);

    double area= calcularArea(retangulo1);
    double perimetro = calcularPerimetro(retangulo1);

    printf("Área: %.2f\n", area);
    printf("Perímetro: %.2f\n", perimetro);
        

    liberar(retangulo1);
  

    return 0;
}

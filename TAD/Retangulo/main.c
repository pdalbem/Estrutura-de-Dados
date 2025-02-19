#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

int main() {

    Retangulo* retangulo1 = criarRetangulo(5.0, 3.0);
    exibirRetangulo(retangulo1);
    

    free(retangulo1);
  

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include "Fracao.h"

int main()
{
    Fracao *f1 = criarFracao(1, 2); // 1/2
    Fracao *f2 = criarFracao(3, 4); // 3/4

    exibirFracao(f1);
    exibirFracao(f2);

    Fracao *soma = somarFracao(f1, f2);
    printf("Soma: ");
    exibirFracao(soma);

    free(f1);
    free(f2);
    free(soma);

    return 0;
}
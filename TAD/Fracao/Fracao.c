#include <stdlib.h>
#include <stdio.h>
#include "Fracao.h"

struct fracao
{
  int numerador, denominador;
};


Fracao* criarFracao(int num, int den)
{
    Fracao *f = (Fracao*) malloc(sizeof(Fracao));
    if (f == NULL) {
        printf("Erro de alocação de memória\n");           
         return NULL;
    }
    f->numerador=num;
    f->denominador=den;
    return f;
}

Fracao* somarFracao(Fracao *f1, Fracao *f2)
{
    int numerador = f1->numerador * f2->denominador + f2->numerador * f1->denominador;
    int denominador = f1->denominador * f2->denominador;
    return criarFracao(numerador, denominador);
}

void exibirFracao(Fracao *f)
{
    if (f != NULL) {
        printf("%d/%d\n", f->numerador, f->denominador);
    }
}
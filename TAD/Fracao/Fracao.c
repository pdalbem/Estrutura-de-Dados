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

Fracao* subtrairFracao(Fracao *f1, Fracao *f2)
{
    int numerador = f1->numerador * f2->denominador - f2->numerador * f1->denominador;
    int denominador = f1->denominador * f2->denominador;
    return criarFracao(numerador, denominador);
}

Fracao* multiplicarFracao(Fracao *f1, Fracao *f2)
{
    int numerador = f1->numerador * f2->numerador;
    int denominador = f1->denominador * f2->denominador;
    return criarFracao(numerador, denominador);
}

Fracao* dividirFracao(Fracao *f1, Fracao *f2)
{
    int numerador = f1->numerador * f2->denominador;
    int denominador = f1->denominador * f2->numerador;
    return criarFracao(numerador, denominador);
}

// Função para calcular o Máximo Divisor Comum (MDC)
int mdc(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void simplificarFracao(Fracao *f)
{
    int divisor = mdc(f->numerador, f->denominador);
    f->numerador /= divisor;
    f->denominador /= divisor;
}

int compararFracao(Fracao *f1, Fracao *f2)
{
    int resultado_f1 = f1->numerador * f2->denominador;
    int resultado_f2 = f2->numerador * f1->denominador;
    if (resultado_f1 > resultado_f2) return 1;  // f1 > f2
    if (resultado_f1 < resultado_f2) return -1; // f1 < f2
    return 0; // f1 == f2
}

float converterParaDecimal(Fracao *f)
{
    return (float) f->numerador / f->denominador;
}

void exibirFracao(Fracao *f)
{
    if (f != NULL) {
        printf("%d/%d\n", f->numerador, f->denominador);
    }
}